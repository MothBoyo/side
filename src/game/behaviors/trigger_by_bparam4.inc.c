//trigger something based on bparam2, check for objects with same bparam4

/*
bparam 1 = Star ID (in case it's used)
bparma 2 = Trigger Trig
bparam 3 = object to search index (from the whitelist array) 0 = goomba, 1 = bobomb, 2 = koopa... etc
bparam 4 = TARGET id that search for them (so if you want just ceirtain goombas, you set their bparam4 and the trigger bparam4 to the same)
*/

/*

const BehaviorScript bhvTriggerByEnemiesKilled[] = {
    BEGIN(OBJ_LIST_LEVEL),
    SET_INT(oHealth, 0),
    BEGIN_LOOP(),
        CALL_NATIVE(trigger_by_bparam4_loop),
    END_LOOP(),
};


*/


#define TRIG_STATE_COUNTING 0
#define TRIG_STATE_TRIGGER 1

#define TRIG_SPAWN_STAR 0
#define TRIG_SPAWN_1UP 1 
#define TRIG_SPAWN_PLATFORMS_COURSE1 2 //example, does nothing useful
//here each case would be more specific, like spawning ceirtain platforms in secuence, or soing something more "hardcode-ish"


// thkl if nltihp :W
//void trigger_by_bparam4_init (void) { 
   // o->oHealth = 0;    this wasn't neded
//}


void trigger_by_bparam4_loop (void) {

    //look for every object in list with the same bparam here
    //when one is killed, substract one to oHealth and oTimer to 0

    //enemies
    const BehaviorScript *whitelist[] = {
        bhvGoomba, bhvBobomb, bhvKoopa, bhvChuckya, bhvFlyGuy, bhvMrI, bhvSpindrift, bhvBoo,
        bhvScuttlebug, bhvSmallWhomp, bhvSmallBully, bhvSmallChillBully, bhvMoneybag, bhvPokey, 
        bhvSwoop, bhvEnemyLakitu, bhvMrBlizzard, bhvSnufit, bhvSkeeter
    };

    if (o->oAction == TRIG_STATE_COUNTING) {
        int enemiesAlive = 0;
        u8 targetId = GET_BPARAM4(o->oBehParams); 
        u8 whitelistIndex = GET_BPARAM3(o->oBehParams);
        
        //index of the enemie type to count
        const BehaviorScript *behaviorAddr = segmented_to_virtual(whitelist[whitelistIndex]);
        //find the list of objects
        struct ObjectNode *listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
        struct Object *obj = (struct Object *) listHead->next;
        //loop looking for given beh and bparm
        while (obj != (struct Object *) listHead) {
            if (obj->behavior == behaviorAddr && obj->activeFlags != ACTIVE_FLAG_DEACTIVATED) {
                //verifyu  the paramb
                if (GET_BPARAM4(obj->oBehParams) == targetId) {
                    enemiesAlive++; //sums
                }
            }
            obj = (struct Object *) obj->header.next;
        }

        //if every enemy is dead, then change action
        if (enemiesAlive == 0) {
            o->oAction = TRIG_STATE_TRIGGER; 
            o->oTimer = 0;  
        }
    }



    //when every of that object is killed, triggers the trigger
    if (o->oAction == TRIG_STATE_TRIGGER) {
        //hewre could use a switch case but idk since every other entry may be specific to something
        if (o->oBehParams2ndByte == TRIG_SPAWN_STAR) {
            spawn_default_star(gMarioState->pos[0], gMarioState->pos[1] + 220.0f, gMarioState->pos[2]); 
            obj_mark_for_deletion(o);
        }

        if (o->oBehParams2ndByte == TRIG_SPAWN_1UP) {
             //spawn_object_relative(behParam, relX, relY, relZ, o, MODEL_ID, bhv);
            spawn_object_relative(0, 0, 150, 0, o, MODEL_1UP, bhv1Up); 
            cur_obj_play_sound_1(SOUND_GENERAL2_1UP_APPEAR);
            obj_mark_for_deletion(o);
        }

        if (o->oBehParams2ndByte == TRIG_SPAWN_PLATFORMS_COURSE1) {
        spawn_object_relative(0, 0, 0, 0, o, MODEL_BREAKABLE_BOX, bhvBreakableBox);
        }



    }

}