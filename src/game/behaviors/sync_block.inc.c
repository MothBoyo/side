
// our function bone in blender
Gfx *sync_block_color(s32 callContext, struct GraphNode *node) {

    return 0;
}

//here put the models
#define SYNC_BLOCK_M1               MODEL_SYNC_BLOCK_BLUE
#define SYNC_BLOCK_M2               MODEL_SYNC_BLOCK_BLUE_BEEP
#define SYNC_BLOCK_2_M1             MODEL_SYNC_BLOCK_PINK
#define SYNC_BLOCK_2_M2             MODEL_SYNC_BLOCK_PINK_BEEP

#define SYNC_BLOCK_FRAME            MODEL_SYNC_BLOCK

// initiate the block and set default values
void sync_block_color_init(void) {
    o->oSyncBlockTimer = 0;
    o->oSyncBlockCycle = 0;
    o->oSyncBlockCurrentBlinkColor = 0;
    o->oSyncBlockTargetBlinkColor = 0;
    if ((o->oBehParams >> 24) <= 1) { // if our first behavior parameter is 1 or less, the block is supposed to be pink and activated
        o->oSyncBlockState = 1;
        o->oSyncBlockColor = 1;
    } else { // else it's supposed to be blue and deactivated
        o->oSyncBlockState = 0;
        o->oSyncBlockColor = 0;
    }
}

// this code runs over and over forever
void sync_block_color_loop(void) {
    f32 max_cycles = 7; // a cycle lasts 1 second, this is after how many seconds we swap the blocks !
    if (o->oSyncBlockState == 1) { // If the block is visible, make it so Mario can stand on it !
        load_object_collision_model();
        //cur_obj_unhide();
        
    } else { 
       // cur_obj_hide();
    }

    //set models
    if (o->oSyncBlockColor == 0) { 
        cur_obj_set_model(SYNC_BLOCK_M1);
    } else  { 
        cur_obj_set_model(SYNC_BLOCK_2_M1);
    } 


    if (o->oSyncBlockTimer >= 30) { // If 1 seconds has last
        o->oSyncBlockTimer = 0; // reset the timer to be able to count again
        if (o->oSyncBlockCycle > max_cycles - 5) { // If we are just a few cycle away from swapping, do the following:
            if (o->oDistanceToMario < 3500) { // Mario needs to be close for the sounds to play (we could use cur_obj_play_sound_2 but it's a bit buggy four our purpose)
                if (o->oSyncBlockCycle >= max_cycles - 1) { // If its the last cycle, do the following:
                    play_sound(SOUND_OBJ_MIPS_RABBIT, gGlobalSoundSource); // Play swap sound !
                } else {
                    play_sound(SOUND_MENU_REVERSE_PAUSE, gGlobalSoundSource); // else, play the cycle ding sound !

                    //REasignmodels
                    if (o->oSyncBlockColor == 0) { 
                        cur_obj_set_model(SYNC_BLOCK_M2);
                    } else  { 
                        cur_obj_set_model(SYNC_BLOCK_2_M2);
                    } 


                }
            }
        }
        o->oSyncBlockCycle += 1; // increase the cycle count
    }

    if (o->oSyncBlockCycle >= max_cycles) { // If we reach the last cycle, do the following:
        o->oSyncBlockCycle = 0; // reset the number of cycles to be ready for next swap
        if (o->oSyncBlockState == 1) { // Swap the block !
            o->oSyncBlockState = 0; // If it's Pink, make it Cyan
        } else {
            o->oSyncBlockState = 1; // Else if it's Cyan, make it Pink
        }
        o->oSyncBlockTargetBlinkColor = 0; // We want the block's blink transparency value to be fully opaque (so 0, not 255 in our case because we substract this value to the real transparency value)
    }
    
    o->oSyncBlockTimer += 1; // Increase timer that make cycles happen
    o->oSyncBlockCurrentBlinkColor = approach_s32(o->oSyncBlockCurrentBlinkColor, o->oSyncBlockTargetBlinkColor, 10, 10); // Interpolate transparency for the block blinking

    if (o->oSyncBlockCycle > max_cycles - 4) { // If we are just a few cycle away from swapping, do the following:
        if (o->oSyncBlockCurrentBlinkColor <= 0) { // If we are opaque, make our goal to be semi transparent
            o->oSyncBlockTargetBlinkColor = 100;
        }

        if (o->oSyncBlockCurrentBlinkColor >= 100) { // If we are semi transparent, make our goal to be opaque
            o->oSyncBlockTargetBlinkColor = 0;
        }
    }

    if (o->oSyncBlockState == 1) { // If the block is visible, make it so Mario can stand on it !
        load_object_collision_model();
        //cur_obj_unhide();
        
    } else { 
       // cur_obj_hide();
       cur_obj_set_model(SYNC_BLOCK_FRAME);
    }


}