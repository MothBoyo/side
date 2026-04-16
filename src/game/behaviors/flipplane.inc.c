#include "actors/group0.h"

void bhv_flipplane_loop(void) {
    // Transition Actions
    switch (o->oAction) {
        case 0:
            // Rising edge detection then switch the state
            if (((gMarioState->action == ACT_JUMP)
                 && ((gMarioState->action == ACT_JUMP) || (gMarioState->prevAction == ACT_JUMP)))
                || ((gMarioState->action == ACT_DOUBLE_JUMP)
                    && ((gMarioState->action == ACT_DOUBLE_JUMP)
                        || (gMarioState->prevAction == ACT_DOUBLE_JUMP)))
                || ((gMarioState->action == ACT_TRIPLE_JUMP)
                    && ((gMarioState->action == ACT_TRIPLE_JUMP)
                        || (gMarioState->prevAction == ACT_TRIPLE_JUMP)))
                || ((gMarioState->action == ACT_BACKFLIP)
                    && ((gMarioState->action == ACT_BACKFLIP)
                        || (gMarioState->prevAction == ACT_BACKFLIP)))
                || ((gMarioState->action == ACT_LONG_JUMP)
                    && ((gMarioState->action == ACT_LONG_JUMP)
                        || (gMarioState->prevAction == ACT_LONG_JUMP)))
                || ((gMarioState->action == ACT_STEEP_JUMP)
                    && ((gMarioState->action == ACT_STEEP_JUMP)
                        || (gMarioState->prevAction == ACT_STEEP_JUMP)))
                || ((gMarioState->action == ACT_SIDE_FLIP)
                    && ((gMarioState->action == ACT_SIDE_FLIP)
                        || (gMarioState->prevAction == ACT_SIDE_FLIP)))
                || ((gMarioState->action == ACT_WATER_JUMP)
                    && ((gMarioState->action == ACT_WATER_JUMP)
                        || (gMarioState->prevAction == ACT_WATER_JUMP)))
                || ((gMarioState->action == ACT_TOP_OF_POLE_JUMP)
                    && ((gMarioState->action == ACT_TOP_OF_POLE_JUMP)
                        || (gMarioState->prevAction == ACT_TOP_OF_POLE_JUMP)))
                || ((gMarioState->action == ACT_FLYING_TRIPLE_JUMP)
                    && ((gMarioState->action == ACT_FLYING_TRIPLE_JUMP)
                        || (gMarioState->prevAction == ACT_FLYING_TRIPLE_JUMP)))
                || ((gMarioState->action == ACT_RIDING_SHELL_JUMP)
                    && ((gMarioState->action == ACT_RIDING_SHELL_JUMP)
                        || (gMarioState->prevAction == ACT_RIDING_SHELL_JUMP)))
                || ((gMarioState->action == ACT_SPECIAL_TRIPLE_JUMP)
                    && ((gMarioState->action == ACT_SPECIAL_TRIPLE_JUMP)
                        || (gMarioState->prevAction == ACT_SPECIAL_TRIPLE_JUMP)))) {
                o->oAction = 1;
            } else {
                o->oAction = 0;
            }

            break;
        case 1:
            // Rising edge detection then switch the state
            if ((gMarioState->action != gMarioState->prevAction)
                && ((gMarioState->action == ACT_JUMP) || (gMarioState->prevAction == ACT_JUMP))) {
                o->oAction = 1;
            } else {
                o->oAction = 2;
            }

            break;
        case 2:
            // Rising edge detection then switch the state
            if ((gMarioState->action == ACT_JUMP)
                && ((gMarioState->action == ACT_JUMP) || (gMarioState->prevAction == ACT_JUMP))) {
                o->oAction = 3;
            } else {
                o->oAction = 2;
            }

            break;
        case 3:
            // Rising edge detection then switch the state
            if (gMarioState->action != gMarioState->prevAction
                && ((gMarioState->action == ACT_JUMP) || (gMarioState->prevAction == ACT_JUMP))) {
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