#define HIDDEN_COLLECTABLE_ACT_INACTIVE 0 //start of level
#define HIDDEN_COLLECTABLE_ACT_WAITING 1 //wait for switch to be 
#define HIDDEN_COLLECTABLE_ACT_ACTIVE 2 
#define HIDDEN_COLLECTABLE_ACT_COLLECTED 3
#define HIDDEN_COLLECTABLE_ACT_FINISHED 4

#define SWITCH_COLLECTABLE_ACT_IDLE 0
#define SWITCH_COLLECTABLE_ACT_RECEDING 1
#define SWITCH_COLLECTABLE_ACT_TICKING 2
#define SWITCH_COLLECTABLE_ACT_EXTENDING 3


#define SWITCH_TIMER 560 //change thios
//bparam 1 = STAR ID


/*
bhvHiddenCollectable
bhvHiddenCollectableSwitch
*/

void bhv_hidden_collectible_loop(void) {
    struct Object *SwitchCollectable;

    switch (o->oAction) {
        case HIDDEN_COLLECTABLE_ACT_INACTIVE:
            //Become invisible and intangible
            cur_obj_disable_rendering();
            cur_obj_become_intangible();
            o->oHiddenBlueCoinSwitch = cur_obj_nearest_object_with_behavior(bhvHiddenCollectableSwitch);

            if (o->oHiddenBlueCoinSwitch != NULL) {
                o->oAction =  HIDDEN_COLLECTABLE_ACT_WAITING;
            }
            break;

        case HIDDEN_COLLECTABLE_ACT_WAITING:
            //wait until the blue coin switch starts ticking to activate.
            SwitchCollectable = o->oHiddenBlueCoinSwitch;
            if (SwitchCollectable->oAction == SWITCH_COLLECTABLE_ACT_TICKING) {
                o->oAction = HIDDEN_COLLECTABLE_ACT_ACTIVE;
            }

            //delete this part if you dont want preview
            if (gMarioObject->platform == SwitchCollectable) {
                cur_obj_enable_rendering();
            } else {
                cur_obj_disable_rendering();
            }
            //delete this part if you dont want preview    
            break;

        case HIDDEN_COLLECTABLE_ACT_ACTIVE:
            cur_obj_enable_rendering();
            cur_obj_become_tangible();

            // After SWITCH_TIMER frames of waiting and 20 2-frame blinks (for 240 frames total),
            if (cur_obj_wait_then_blink(SWITCH_TIMER, 20)) {
            cur_obj_disable_rendering();
            cur_obj_become_intangible();
            o->header.gfx.node.flags &= ~GRAPH_RENDER_INVISIBLE; //HERE LOOK 
            o->oAction =  HIDDEN_COLLECTABLE_ACT_WAITING;  
            }

            break;

        case HIDDEN_COLLECTABLE_ACT_COLLECTED:
            cur_obj_disable_rendering();
            cur_obj_become_intangible();
            SwitchCollectable = o->oHiddenBlueCoinSwitch;
            //wait for the switch to dictates its face
            if (SwitchCollectable->oAction == SWITCH_COLLECTABLE_ACT_EXTENDING) {
                    o->oAction = HIDDEN_COLLECTABLE_ACT_WAITING;
            } 
            
            break;

    }

    // Delete the coin once collected CHANGE THIS ONE
    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        spawn_object(o, MODEL_SPARKLES, bhvCoinSparklesSpawner);
        //SND
        cur_obj_play_sound_2(SOUND_GENERAL_RED_COIN);
        o->oAction =  HIDDEN_COLLECTABLE_ACT_COLLECTED;  
    }

    o->oInteractStatus = INT_STATUS_NONE;

    


}


//aux function that spit true or false
static s32 is_collectable_alive(void) {

    //basically here, copied from colorful chomps, follow the list of bojects, if finds copins ask for its oActions, if not collected
    //then ends it all.
            const BehaviorScript *managerBehavior = segmented_to_virtual(bhvHiddenCollectable);
            struct ObjectNode *listHead = &gObjectLists[get_object_list_from_behavior(managerBehavior)];
            struct Object *obj = (struct Object *) listHead->next;

            while (obj != (struct Object *) listHead) {
                if (obj->behavior == managerBehavior && obj->activeFlags != ACTIVE_FLAG_DEACTIVATED) {
                    if (obj->oAction != HIDDEN_COLLECTABLE_ACT_COLLECTED) {
                        return TRUE; //wow THIS IS WORTHLESS
                    }
                }
                obj = (struct Object *) obj->header.next;
            }


    return FALSE;
}

//siwtch function
void bhv_switch_hidden_collectable_loop(void) {
    //The switch's model is 1/3 size.
    cur_obj_scale(3.0f);

    switch (o->oAction) {
        case BLUE_COIN_SWITCH_ACT_IDLE:
            // If Mario is on the switch and has ground-pounded,recede and get ready to start ticking.
            if (gMarioObject->platform == o) {
                if (gMarioStates[0].action == ACT_GROUND_POUND_LAND) {
                    o->oAction = SWITCH_COLLECTABLE_ACT_RECEDING;
                    o->oVelY = -16.0f;
                    // Set gravity to 0 so it doesn't accelerate when receding.
                    o->oGravity = 0.0f;
                    cur_obj_play_sound_2(SOUND_GENERAL_SWITCH_DOOR_OPEN);
                }
            }
            load_object_collision_model();
            break;

        case SWITCH_COLLECTABLE_ACT_RECEDING:
            // Recede
            if (o->oTimer > 3) {
                // Set to ticking
                o->oAction = SWITCH_COLLECTABLE_ACT_TICKING;
                o->oVelY    = 0.0f;
                o->oGravity = 0.0f;
                spawn_mist_particles_variable(0, 0, 46.0f);
            } else {
                // Have collision while receding
                load_object_collision_model();
                // Recede (wtf is recede)
                cur_obj_move_using_fvel_and_gravity();
            }

            break;

        case SWITCH_COLLECTABLE_ACT_TICKING:
            // Tick faster when the blue coins start blinking
            if (o->oTimer < SWITCH_TIMER) {
                play_sound(SOUND_GENERAL2_SWITCH_TICK_FAST, gGlobalSoundSource);
            } else {
                play_sound(SOUND_GENERAL2_SWITCH_TICK_SLOW, gGlobalSoundSource);
            }

            //change the if to make sure all of them are in COLLECTED STATE INSTEAD
            if (is_collectable_alive() == FALSE) {
                spawn_mist_particles_variable(0, 0, 46.0f);
                //SPAWN STAR!! HERE
                spawn_default_star(o->oHomeX, o->oHomeY + 180.0f, o->oHomeZ);
                obj_mark_for_deletion(o);
            // Set to EXTENDING after the coins unload after the 240-frame timer expires.
            } else if (o->oTimer > SWITCH_TIMER + 40) {
                o->oAction  = SWITCH_COLLECTABLE_ACT_EXTENDING;
                o->oVelY    = 16.0f;
                o->oGravity =  0.0f;
            }
            load_object_collision_model();
            break;

        case SWITCH_COLLECTABLE_ACT_EXTENDING:
            if (is_collectable_alive() == FALSE) {
                // This code can be executed if the last blue coin is collected at the very end of the timer.
                spawn_mist_particles_variable(0, 0, 46.0f);
                //SPAWN STAR!! HERE
                spawn_default_star(o->oHomeX, o->oHomeY + 180.0f, o->oHomeZ);
                obj_mark_for_deletion(o);
            } else if (o->oTimer > 3) {
                o->oAction = SWITCH_COLLECTABLE_ACT_IDLE;
            } else {
                // Have collision while extending
                load_object_collision_model();
                cur_obj_move_using_fvel_and_gravity(); //Nintendo pls
            }
            break;
    }
}


