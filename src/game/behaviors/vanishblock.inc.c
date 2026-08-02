#include "actors/group0.h"

void bhv_vanishblock_loop(void){
switch (o->oAction){
    case 0:
    //wait, or act
    if ((gMarioObject->platform == o) || (gMarioState->wall && gMarioState->wall->object == o)) {
    o->oAction= 1;
    }
    else{
        o->oAction= 0;
    }

    break;
    //start 4 second timer, start blinking 75% through - then disappear
    case 1:
    if (o->oTimer < 120) {
        cur_obj_wait_then_blink(60,5);
    }
    else{
        o->oAction= 2;
    }

    break;
    //be nonexistant for 4 seconds, then return
    case 2:
    if (o->oTimer < 120){
        
    }
    else{
        o->oAction= 0;
    }
}

// State Actions

//vanishblock 1
if (o->oBehParams2ndByte == 0){
switch (o->oAction){
  case 0:
  // box is active
    cur_obj_set_model(MODEL_VANISHBLOCK);
    load_object_collision_model();
    cur_obj_unhide();
break;

  case 1:
  // box is active, ALTHOUGH FLICKERING
  cur_obj_set_model(MODEL_VANISHBLOCK);
  load_object_collision_model();

break;

  case 2:
  // box is inactive

break;
        }
    }


//vanishblock 2
else if (o->oBehParams2ndByte == 1){
switch (o->oAction){
  case 0:
  // box is active
    cur_obj_set_model(MODEL_VANISHBLOCK2);
    o->collisionData = segmented_to_virtual(vanishblock2_collision);
    load_object_collision_model();
    cur_obj_unhide();
break;

  case 1:
  // box is active, ALTHOUGH FLICKERING
  cur_obj_set_model(MODEL_VANISHBLOCK2);
   o->collisionData = segmented_to_virtual(vanishblock2_collision);
   load_object_collision_model();

break;

  case 2:
  // box is inactive

break;
        }
    }


    //vanishblock 3
else if (o->oBehParams2ndByte == 2){
switch (o->oAction){
  case 0:
  // box is active
    cur_obj_set_model(MODEL_VANISHBLOCK3);
    o->collisionData = segmented_to_virtual(vanishblock3_collision);
    load_object_collision_model();
    cur_obj_unhide();
break;

  case 1:
  // box is active, ALTHOUGH FLICKERING
  cur_obj_set_model(MODEL_VANISHBLOCK3);
    o->collisionData = segmented_to_virtual(vanishblock3_collision);
   load_object_collision_model();

break;

  case 2:
  // box is inactive

break;
        }
    }


    //vanishblock 4
else if(o->oBehParams2ndByte == 3){
switch (o->oAction){
  case 0:
  // box is active
    cur_obj_set_model(MODEL_VANISHBLOCK4);
    o->collisionData = segmented_to_virtual(vanishblock4_collision);
    load_object_collision_model();
    cur_obj_unhide();
break;

  case 1:
  // box is active, ALTHOUGH FLICKERING
  cur_obj_set_model(MODEL_VANISHBLOCK4);
    o->collisionData = segmented_to_virtual(vanishblock4_collision);
  load_object_collision_model();


break;

  case 2:
  // box is inactive

break;
        }
    }
}
