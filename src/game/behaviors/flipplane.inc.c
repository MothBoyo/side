#include "actors/group0.h"

void bhv_flipplane_loop(void) {
    // Transition Actions
    switch (o->oAction) {
        case 0:
            // Rising edge detection then switch the state
            if (((gMarioState->prevAction&ACT_GROUP_MASK)!=ACT_GROUP_AIRBORNE) && ((gMarioState->action& ACT_GROUP_MASK)==ACT_GROUP_AIRBORNE)) {
                o->oAction = 1;
            } else {
                o->oAction = 0;
            }

            break;
        case 1:
            // Rising edge detection then switch the state
            if ((gMarioState->action != gMarioState->prevAction)
                && (((gMarioState->prevAction&ACT_GROUP_MASK)!=ACT_GROUP_AIRBORNE) && ((gMarioState->action& ACT_GROUP_MASK)==ACT_GROUP_AIRBORNE))) {
                o->oAction = 1;
            } else {
                o->oAction = 2;
            }

            break;
        case 2:
            // Rising edge detection then switch the state
            if (((gMarioState->prevAction&ACT_GROUP_MASK)!=ACT_GROUP_AIRBORNE) && ((gMarioState->action& ACT_GROUP_MASK)==ACT_GROUP_AIRBORNE)
                && ((gMarioState->prevAction&ACT_GROUP_MASK)!=ACT_GROUP_AIRBORNE) && ((gMarioState->action& ACT_GROUP_MASK)==ACT_GROUP_AIRBORNE)) {
                o->oAction = 3;
            } else {
                o->oAction = 2;
            }

            break;
        case 3:
            // Rising edge detection then switch the state
            if (gMarioState->action != gMarioState->prevAction
                && ((gMarioState->prevAction&ACT_GROUP_MASK)!=ACT_GROUP_AIRBORNE) && ((gMarioState->action& ACT_GROUP_MASK)==ACT_GROUP_AIRBORNE)) {
                o->oAction = 3;
            } else {
                o->oAction = 0;
            }

            break;
        default:
            break;
    }

    // State Actions
    if (BPARAM2 == 0) {
        switch (o->oAction) {
            case 0:
                cur_obj_set_model(MODEL_OUTLINES);

                break;
            case 1:
                // box is active
                cur_obj_set_model(MODEL_FLIPPLANE);
                load_object_collision_model();

                break;
            case 2:
                cur_obj_set_model(MODEL_FLIPPLANE);
                load_object_collision_model();

                break;
            case 3:
                // box is inactive
                cur_obj_set_model(MODEL_OUTLINES);

                break;
            default:
                break;
        }
    }

    if (o->oBehParams2ndByte == 0) {
        switch (o->oAction) {
            case 0:
                cur_obj_set_model(MODEL_OUTLINES);

                break;
            case 1:
                // box is active
                cur_obj_set_model(MODEL_FLIPPLANE);
                load_object_collision_model();

                break;
            case 2:
                cur_obj_set_model(MODEL_FLIPPLANE);
                load_object_collision_model();

                break;
            case 3:
                // box is inactive
                cur_obj_set_model(MODEL_OUTLINES);

                break;
            default:
                break;
        }
    }

    else {
        switch (o->oAction) {
            case 0:

                cur_obj_set_model(MODEL_FLIPPLANE2);
                load_object_collision_model();

                break;
            case 1:

                cur_obj_set_model(MODEL_OUTLINES2);

                break;
            case 2:
                cur_obj_set_model(MODEL_OUTLINES2);

                break;
            case 3:
                // box is inactive
                cur_obj_set_model(MODEL_FLIPPLANE2);
                load_object_collision_model();

                break;
            default:
                break;
        }
    }
}