#include "game/camera.h"
#define CAMERA_2D_MOVE_Y_AXIS 1
#define CAMERA_2D_TARGET_LOOK_AHEAD_SPEED 400.0f
#define CAMERA_2D_Y_AXIS_OFFSET 600.0f

//custom static camera

/*
2d camera / static camera (for static camera just leave every param in 0)

bparam1: 1 =follow Z axis
bparam2: 1 =follow Y axis

*/

void bhv_2d_camera_loop(void) {
    //force static mode
    gCamera->mode    = CAMERA_MODE_STATIC;
    gCamera->defMode = CAMERA_MODE_STATIC;

    //interpolation things
    f32 lerpFactorCam = 0.05f;  //general lerp
    f32 lerpFactorLook = 0.02f; //Factor when change the focus from left to right

    //variables to remember the state of mario looking
    static f32 lookAheadZ = 0.0f;
    static f32 targetLookAheadZ = 0.0f;

    //use mario vel to determine it's velocity
    if (gMarioState->vel[2] > 2.0f) {
        targetLookAheadZ = CAMERA_2D_TARGET_LOOK_AHEAD_SPEED; //if mario looking forward, moves the cam
    } else if (gMarioState->vel[2] < -2.0f) {
        targetLookAheadZ = -CAMERA_2D_TARGET_LOOK_AHEAD_SPEED; //if mario looking backwards, moves the cam
    }

    //when mario stops, the target keeps the last value so it doesnt get dizzy fuzzy
    //transition u.u
    lookAheadZ += (targetLookAheadZ - lookAheadZ) * lerpFactorLook;

    //camera follow in Z axis
    if (GET_BPARAM1(o->oBehParams) == 1) {
    f32 targetZ = gMarioState->pos[2] + lookAheadZ;
    f32 distZ = targetZ - o->oPosZ;
    o->oPosZ += distZ * lerpFactorCam;
    }

    //follow in Y too just if bparam2 is set to 1
    if (o->oBehParams2ndByte == 1) {
        f32 targetY = gMarioState->pos[1] + CAMERA_2D_Y_AXIS_OFFSET; 
        f32 distY = targetY - o->oPosY;
        o->oPosY += distY * lerpFactorCam;
    }

    //update focus
    sStaticCamFocus[0] = o->oPosX;
    sStaticCamFocus[1] = o->oPosY;
    sStaticCamFocus[2] = o->oPosZ;

    //get dist and angle from the object and set it to obj
    f32 dist  = 1000.0f; 
    s16 yaw   = o->oFaceAngleYaw;
    s16 pitch = o->oFaceAnglePitch;

    vec3f_set_dist_and_angle(sStaticCamFocus, sStaticCamPos, dist, pitch, yaw);
}



void bhv_2d_mode_loop(void) {
    gMarioState->pos[0] = o->oPosX; 
}