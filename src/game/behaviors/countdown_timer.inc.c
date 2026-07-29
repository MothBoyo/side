//bparam1           = star ID in case of needed
//bparam2 + bparam3 = seconds
//bparm4            =  MODE

#define TIMER_TRIGGER_MODE_NORMAL 0 //start counting when entering the are
#define TIMER_TRIGGER_MODE_TOUCH 1  //start counting when touched
#define TIMER_TRIGGER_MODE_KILL_ENEMIES 2 //start counting when touched. stop when all enemies in the area are killed


//util functiom
void check_for_enemies(void) {

    //whilelist of objects that counts as enemies // you could add more enmies here when you add more custom enemies :D
    //mr blizzard is bad idea, can respawn
    const BehaviorScript *whitelist[] = {
        bhvGoomba, bhvBobomb, bhvKoopa, bhvChuckya, bhvFlyGuy, bhvMrI, bhvSpindrift, bhvBoo,
        bhvScuttlebug, bhvSmallWhomp, bhvSmallBully, bhvSmallChillBully, bhvMoneybag, bhvPokey, 
        bhvSwoop, bhvEnemyLakitu, bhvMrBlizzard, bhvSnufit, bhvSkeeter                              
    };

    int enemiesAlive = 0;
    u8 maxCounter = sizeof(whitelist) / sizeof(whitelist[0]); //array size is calculed

    struct Object *obj;
    struct ObjectNode *listHead;

    //get every enemy from whilest and  count them
    for (int i = 0; i < maxCounter; i++) {
        const BehaviorScript *behaviorAddr = segmented_to_virtual(whitelist[i]);

        listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
        obj = (struct Object *) listHead->next;


        while (obj != (struct Object *) listHead) {
            if (obj->behavior == behaviorAddr && obj->activeFlags != ACTIVE_FLAG_DEACTIVATED) {
                enemiesAlive++;
                
            }
            obj = (struct Object *) obj->header.next;
        }
    }

    //if evenry enemy is ddead
    if (enemiesAlive == 0) {
        spawn_default_star(gMarioState->pos[0], gMarioState->pos[1] + 220.0f, gMarioState->pos[2]); 
        obj_mark_for_deletion(o); 
    }
}

//timer
#define PRINTX_OFFSET_TIMER 240
#define PRINTY_OFFSET_TIMER 185

void bhv_countdown_timer_init(void) {

    o->oHeldState = 0;
//init initial timer, from bparam2 + bparam3
    o->oHealth = (o->oBehParams2ndByte + GET_BPARAM3(o->oBehParams)) * 30;
    //play_music(SEQ_PLAYER_LEVEL, SEQUENCE_ARGS(4, SEQ_SPEEDY_COMET), 0);
}


void bhv_countdown_timer_loop(void) {

    //check if should start
    if (obj_check_if_collided_with_object(o, gMarioObject) || GET_BPARAM4(o->oBehParams) == TIMER_TRIGGER_MODE_NORMAL) {
        o->oHeldState = 1; //UNUSED THING USED FOR THARy
    }    
    //check if should stop
    if (GET_BPARAM4(o->oBehParams) == TIMER_TRIGGER_MODE_KILL_ENEMIES) {
        check_for_enemies();
    }

    //update the timer
    //calc seconds and mins
    u16 timerMins = o->oHealth / (30 * 60);
    u16 timerSecs = (o->oHealth - (timerMins * 1800)) / 30;


    //shake when times ticks last 10 secs
        if (o->oHealth < 300 && (o->oHealth % 30 == 0)) {
            o->oFaceAnglePitch = 1; 
            play_sound(SOUND_BANK_MOVING, gGlobalSoundSource); //SOUND?

        }

    //(if shake > 0)
    f32 shakeY = 0;
    if (o->oFaceAnglePitch > 0) {
        //move
        shakeY = sinf(gGlobalTimer * 1.4f) * o->oFaceAnglePitch;
        o->oFaceAnglePitch--; 
    }




    //if active (touched or mode is not touch mode)
    if (o->oHeldState == 1)  {
        //print the minutes
        print_text_fmt_int(PRINTX_OFFSET_TIMER, PRINTY_OFFSET_TIMER + (s32)shakeY, "%02d", timerMins);
        //print the two points glyph
        print_text(PRINTX_OFFSET_TIMER + 22, PRINTY_OFFSET_TIMER + (s32)shakeY,  ":"); 
        //print the seconds
        print_text_fmt_int(PRINTX_OFFSET_TIMER + 34, PRINTY_OFFSET_TIMER + (s32)shakeY, "%02d", timerSecs);
        }

    if (o->oHealth > 0) {
        //stop timer if you are collecting stars
        if (gMarioState->action != ACT_STAR_DANCE_EXIT && 
                gMarioState->action != ACT_STAR_DANCE_NO_EXIT && 
                    gMarioState->action != ACT_STAR_DANCE_WATER &&
                        gMarioState->action != ACT_FALL_AFTER_STAR_GRAB) {

            //if active (touched or mode is not touch mode)                
            if (o->oHeldState == 1)  {
                o->oHealth =  o->oHealth - 1;     
                }                      
            } else {
                    //lets see
                    obj_mark_for_deletion(o); 
                    }

        } else {
            //death player
            level_trigger_warp(gMarioState, WARP_OP_DEATH);
            obj_mark_for_deletion(o); 


        }


}