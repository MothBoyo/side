
// our function bone in blender
Gfx *sync_block_color(s32 callContext, struct GraphNode *node) {
    struct Object *curObj;
    Gfx *dlStart, *dlHead;
    struct GraphNodeGenerated *currentGraphNode = (struct  GraphNodeGenerated *) node;
    

    if (callContext == GEO_CONTEXT_RENDER) { // called every frame when the object is on screen !
        curObj = (struct Object *) gCurGraphNodeObject; // our o object, important to do curObj-> instead of o-> here !
        dlStart = alloc_display_list(sizeof(Gfx) * 2);
        dlHead = dlStart;

        // create r, g and b values
        s32 r;
        s32 g;
        s32 b;

        if (curObj->oSyncBlockColor == 1) { // if we are supposed to be pink, set the rgb values to be pink !
            r = 255;
            g = 255 / 2;
            b = 255;
        } else { // else it means we are supposed to be cyan, set the rgb values to be cyan !
            r = 255 / 3;
            g = (255 / 3) * 2;
            b = 255;
        }
        
        // apply the colors rgb
        // apply the alpha by mutliplying curObj->oSyncBlockCurrentBlinkColor (0 or 1) by 255 minus a blinking transparency value
        gDPSetPrimColor(dlHead++, 0, 0, r, g, b, curObj->oSyncBlockState * (255 - curObj->oSyncBlockCurrentBlinkColor));
        gSPEndDisplayList(dlHead);

        currentGraphNode->fnNode.node.flags |= (LAYER_TRANSPARENT << 8); // Set draw layer to transparent
    }
    return dlStart;
}

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
    }

    if (o->oSyncBlockTimer >= 30) { // If 1 seconds has last
        o->oSyncBlockTimer = 0; // reset the timer to be able to count again
        if (o->oSyncBlockCycle > max_cycles - 5) { // If we are just a few cycle away from swapping, do the following:
            if (o->oDistanceToMario < 1000) { // Mario needs to be close for the sounds to play (we could use cur_obj_play_sound_2 but it's a bit buggy four our purpose)
                if (o->oSyncBlockCycle >= max_cycles - 1) { // If its the last cycle, do the following:
                    play_sound(SOUND_MENU_CAMERA_ZOOM_IN, gGlobalSoundSource); // Play swap sound !
                } else {
                    play_sound(SOUND_MENU_REVERSE_PAUSE, gGlobalSoundSource); // else, play the cycle ding sound !
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
}