//balloon



//flipswap behavior

u8 flipped = 0;

void bhv_flipswap_loop(void){
    //set initial state
    cur_obj_set_model(MODEL_FLIPSWAP);
    load_object_collision_model();

    switch (o->oAction)
    {
    case 0:
        flipped = 0;

       if (((gMarioState->prevAction&ACT_GROUP_MASK)!=ACT_GROUP_AIRBORNE) && ((gMarioState->action& ACT_GROUP_MASK)==ACT_GROUP_AIRBORNE)) o->oAction = 1;
        break;

    case 1:
        flipping();
        break;

    case 2:
        flipped = 1;

       if (((gMarioState->prevAction&ACT_GROUP_MASK)!=ACT_GROUP_AIRBORNE) && ((gMarioState->action& ACT_GROUP_MASK)==ACT_GROUP_AIRBORNE)) o->oAction = 1;
        break;
    
    default:
        break;
    }
}

void flipping(void){
    if(o->oTimer < 5){
        if(flipped == 0){
            o->oFaceAnglePitch += DEGREES(36);
        } else{
            o->oFaceAnglePitch -= DEGREES(36);
        }
    } else {
        if((gMarioState->action & ACT_GROUP_MASK) == ACT_GROUP_MOVING){
        if (flipped == 0) o->oAction = 2;
        else o->oAction = 0;
        }
    }
}