
// our mesh switch bone in our tablet actor in blender
Gfx *interactive_tablet_state(s32 callContext, struct GraphNode *node){
    struct GraphNodeSwitchCase *switchCase = (struct GraphNodeSwitchCase *) node; // our switch bone's state
    struct Object *curObj;
    curObj = (struct Object *) gCurGraphNodeObject; // our o object, important to do curObj-> instead of o-> here !
    

    if (callContext == GEO_CONTEXT_RENDER) { // called every frame when the object is on screen !
        switchCase->selectedCase = curObj->oInteractiveTabletState; // If the tablet actor should be Yellow, switch to the Yellow mesh, else the Blue one
    }
    return NULL;
}

// initiate the tablet and set default values
void interactive_tablet_init(void){
    o->oInteractiveTabletState = 0;
    o->oInteractiveTabletIsPodium = FALSE;
    o->oInteractiveTabletCanInteract = TRUE;
    o->oInteractiveTabletInteractTimer = 0;

    o->oInteractiveTabletAssignedPodium = NULL; // failsafe to prevent the game from crashing, we set it to NULL and later check if it isn't NULL, otherwise do nothing

    // Here we are finding every single podium actors
    uintptr_t *behaviorAddr = segmented_to_virtual(bhvInteractiveTabletPodium);
    struct ObjectNode *listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    struct ObjectNode *obj = listHead->next;

    while (listHead != obj) {
        if (((struct Object *) obj)->behavior == behaviorAddr) {
            // We look to see if they have the same first parameter as the tablet
            if ((((struct Object *) obj)->oBehParams >> 24) == (o->oBehParams >> 24)) {
                // If it does, assign this podium to this tablet and stop the loop ! Else continue to iterate through the podiums until you find one that has the same first parameter as the tablet
                o->oInteractiveTabletAssignedPodium = (struct Object *) obj;
                break;
            }
        }
        obj = obj->next;
    }

    // If we didn't find any podium actor to assign, o->oInteractiveTabletAssignedPodium remains NULL

}

// this code runs over and over forever
void interactive_tablet_loop(void){
    if (o->oInteractiveTabletAssignedPodium != NULL) { // if we have a podium assigned (in other words, if o->oInteractiveTabletAssignedPodium  isn't NULL), do the following:
        
        // If Mario is standing on the tablet and the cooldown timer as well as a boolean allows it, swap the state of the tablet and play a sound !
        if ((gMarioObject->platform == o) && (o->oInteractiveTabletInteractTimer <= 0) && (o->oInteractiveTabletCanInteract == TRUE)) {
            if (o->oInteractiveTabletState == 0) {
                o->oInteractiveTabletState = 1;
                cur_obj_play_sound_2(SOUND_OBJ_CANNON_BARREL_PITCH);
            } else if (o->oInteractiveTabletState == 1) {
                o->oInteractiveTabletState = 0;
                cur_obj_play_sound_2(SOUND_OBJ_CANNON_BARREL_PITCH);
            }
            o->oInteractiveTabletInteractTimer = 30; // Sets cooldown timer
            o->oInteractiveTabletCanInteract = FALSE; // Set the boolean to not be able to interact with the same platform again just yet
        }
        o->oInteractiveTabletInteractTimer -= 1; // Decrease cooldown timer
        if ((o->oInteractiveTabletCanInteract == FALSE) && (gMarioObject->platform != o)) { // If Mario ain't on the platform and we cannot currently interact with the platform, do the following:
            o->oInteractiveTabletCanInteract = TRUE; // Set the boolean to be able to interact with the same platform again
        }
        
    }
}


// initiate the podium and set default values
void interactive_tablet_podium_init(void){
    o->oInteractiveTabletPodiumSpawnStar = FALSE;
}

// this code runs over and over forever
void interactive_tablet_podium_loop(void){
    uintptr_t *behaviorAddr = segmented_to_virtual(bhvInteractiveTablet);
    struct ObjectNode *listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    struct ObjectNode *obj = listHead->next;

    if (o->oInteractiveTabletPodiumSpawnStar == FALSE) { // If we haven't spawned a star for completing the puzzle yet, do the following:
        while (listHead != obj) {
            // Here we are finding every single tablet actors
            if (((struct Object *) obj)->behavior == behaviorAddr) {
                // We look to see if they have the same first behavior parameter as the podium
                if ((((struct Object *) obj)->oBehParams >> 24) == (o->oBehParams >> 24)) {
                    o->oInteractiveTabletAssignedTablet = (struct Object *) obj;
                    o->oInteractiveTabletSetFinal = TRUE; // Sets the platform to the final Green state temporarily
                    
                    // If one of the tablets with the same first behavior parameter isn't Yellow, do the following:
                    if (o->oInteractiveTabletAssignedTablet->oInteractiveTabletState != 1) {
                        o->oInteractiveTabletSetFinal = FALSE; // Sets the platform to NOT be the final Green state and stop the loop because it means not all tablets are Yellow
                        break;
                    } // Else that means all the platforms are Yellow ! :D

                }
            }
            obj = obj->next; // iterate through the next object
        }

        struct ObjectNode *obj = listHead->next;
        if (o->oInteractiveTabletSetFinal == TRUE) { // If all platforms are Yellow, do the following:
            while (listHead != obj) {
            // Here we are finding every single tablet actors again
            if (((struct Object *) obj)->behavior == behaviorAddr) {
                if ((((struct Object *) obj)->oBehParams >> 24) == (o->oBehParams >> 24)) { // If they have the same first behavior parameter, do the following:
                    o->oInteractiveTabletAssignedTablet = (struct Object *) obj;
                    o->oInteractiveTabletAssignedTablet->oInteractiveTabletState = 2; // set this tablet to be Green !
                    o->oInteractiveTabletPodiumSpawnStar = TRUE; // Allow the podium to spawn a star !

                }
            }
            obj = obj->next;
            }
            // This will be called once (for one frame)
            struct Object *starObj = NULL;
            play_puzzle_jingle();
            starObj = spawn_object_abs_with_rot(o, 0, MODEL_STAR, bhvStar, o->oPosX, o->oPosY + 350, o->oPosZ, 0, 0, 0); // spawn a star !
            starObj->oBehParams = o->oBehParams2ndByte << 24; // set the star's ID to be the podium's second behavior parameter !
        }
    }

}