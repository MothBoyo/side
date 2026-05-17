
// Create a Hitbox !
static struct ObjectHitbox sSilverStarHitbox = {
    /* interactType:      */ INTERACT_NONE,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 0,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 80,
    /* height:            */ 80,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

// This scales the silver star based on o->oSilverStarScale (We do a lil scale animation when we pick a silver star !)
Gfx *silver_star_size_func(s32 callContext, struct GraphNode *node) {
    struct Object *curObj;

    if (callContext == GEO_CONTEXT_RENDER) { // called every frame when the object is on screen !
        curObj = (struct Object *) gCurGraphNodeObject; // our o object, important to do curObj-> instead of o-> here !
        
        ((struct GraphNodeScale *) node->next)->scale = curObj->oSilverStarScale; // sets scale
    }
    return NULL;
}

// initiate the silver star and set default values
void silver_star_init(void) {
    o->oSilverStarScale = 1.0;
    o->oSilverStarTargetScale = 1.0;
    o->oSilverStarAssignedPodium = NULL; // failsafe to prevent the game from crashing, we set it to NULL and later check if it isn't NULL, otherwise do nothing
    o->oSilverStarNum = -1;
    o->oSilverStarAccel = random_float() / 8 + 0.05; // Makes the silver stars more organic by giving them a slightly random speed when following Mario !
    o->oSilverStarCollected = FALSE;
    obj_set_hitbox(o, &sSilverStarHitbox); // Assign the hitbox we created to this silver star !

    // Here we are finding every single podium actors
    uintptr_t *behaviorAddr = segmented_to_virtual(bhvSilverStarPodium);
    struct ObjectNode *listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];

    struct ObjectNode *obj = listHead->next;
    while (listHead != obj) {
        if (((struct Object *) obj)->behavior == behaviorAddr) {
            // We look to see if they have the same first parameter as the silver star
            if ((((struct Object *) obj)->oBehParams >> 24) == (o->oBehParams >> 24)) {
                // If it does, assign this podium to this silver star and stop the loop ! Else continue to iterate through the podiums until you find one that has the same first parameter as the silver star
                o->oSilverStarAssignedPodium = (struct Object *) obj;
                break;
            }
        }
        obj = obj->next; // then check next podium
    }

    // Here we are finding every single silver star actors, we will assign each of them an ID !
    uintptr_t *behaviorAddr_star = segmented_to_virtual(bhvSilverStar);
    struct ObjectNode *listHead_star = &gObjectLists[get_object_list_from_behavior(behaviorAddr_star)];
    struct ObjectNode *obj_star = listHead_star->next;
    f32 star_num = 0; // first silver star ID
    while (listHead_star != obj_star) {
        if (((struct Object *) obj_star)->behavior == behaviorAddr_star) {
            if ((((struct Object *) obj_star)->oBehParams >> 24) == (o->oBehParams >> 24)) {
            // We look to see if they have the same first parameter as themself
                ((struct Object *) obj_star)->oSilverStarNum = star_num; // assign this silver star an ID
                star_num += 1; // Make it so the next silver star's ID will be different than this silver star's
            }
        }
        obj_star = obj_star->next; // look through the next silver star !
    }


}

// Monitoring the silver star to check if Mario touches it !
void silver_star_check_interact(void) {
    // If Mario touches the star, do the following:
    if (obj_check_if_collided_with_object(o, gMarioObject)) {
        o->oSilverStarTargetScale = 1.5; // Start our little scale animation
        play_sound(SOUND_MENU_MESSAGE_APPEAR, gGlobalSoundSource); // Play a sound !
        o->oSilverStarCollected = TRUE; // Mark this star as collected !
        o->oAction = 1; // switch to the 'follow Mario' state !
    }
}

// Making the silver star follow Mario !
void silver_star_follow_mario(void) {
    o->oSilverStarScale = approach_f32(o->oSilverStarScale, o->oSilverStarTargetScale, 0.1, 0.07); // process our little scale animation by interpolating the silver star's scale ! :)
    if (o->oSilverStarScale >= 1.4) { // If the silver star reaches a big size, reduce it's size
        o->oSilverStarTargetScale = 0.8; // end our scale animation
    }

    Vec3f obj_pos = { o->oPosX , o->oPosY , o->oPosZ }; // Create a Vector3 for the object's position
    f32 offset = ((o->oSilverStarNum + 1) * 150); //how far from mario we want each silver star to be
    s16 angle = gMarioState->faceAngle[1] + 0x8000; // mario angle + 180 degrees so they align behind Mario

    Vec3f targetPos; // target pos = where the star wants to go
    targetPos[0] = sins(angle) * offset + gMarioState->prevPos[0]; // Math stuff to determine the final silver star location
    targetPos[1] = 60 + gMarioState->prevPos[1]; // Math stuff to determine the final star location
    targetPos[2] = coss(angle) * offset + gMarioState->prevPos[2]; // Math stuff to determine the final silver star location

    f32 accel = (o->oDistanceToMario / 1500000) * (400 / (o->oSilverStarNum + 1)); // Silver star's acceleration bazsed on Mario's distance 
    
    if (o->oSilverStarAssignedPodium->oSilverStarSpawnStar == FALSE) { // If our podium hasn't spawned a yellow star yet, do the following:
        approach_vec3f_asymptotic(obj_pos, targetPos, accel / 1.5, accel / 2, accel / 1.5); // interpolate the silver star's position to where it wants to be based on the acceleration
    } else { // else if we spawned a yellow star, do the following:
        Vec3f targetPodiumPos = { o->oSilverStarAssignedPodium->oPosX , o->oSilverStarAssignedPodium->oPosY , o->oSilverStarAssignedPodium->oPosZ }; // Make it so the silver stars wants to go toward the yellow star
        approach_vec3f_asymptotic(obj_pos, targetPodiumPos, accel * 0.7, accel * 0.7, accel * 0.7); // Makes the silver stars actually move toward the location they want to go to !
        
        // Math to see if we are close enough to the star. If we are, delete the silver star
        vec3f_diff(targetPodiumPos, targetPodiumPos, obj_pos);
        if (absf(vec3_mag(targetPodiumPos)) < 30){
            obj_mark_for_deletion(o);
        }
        
    }

    // assign our position Vector3 to our silver star's real position
    o->oPosX = obj_pos[0];
    o->oPosY = obj_pos[1];
    o->oPosZ = obj_pos[2];
    
}

// this code runs over and over forever
void silver_star_loop(void) {
    if (o->oSilverStarAssignedPodium != NULL) { // if we have a podium assigned (in other words, if o->oSilverStarAssignedPodium  isn't NULL), do the following:
        // Select which code to execute, starting with case 0: !
        switch (o->oAction) {
            case 0: // idle
                silver_star_check_interact();
            break;
    
            case 1: // follow mario
                silver_star_follow_mario();
            break;
        }
    }
}

// initiate the podium and set default values
void silver_star_podium_init(void) {
    o->oSilverStarSpawnStar = FALSE;
}

// this code runs over and over forever
void silver_star_podium_loop(void) {
    // Here we are finding every single silver star actors
    uintptr_t *behaviorAddr = segmented_to_virtual(bhvSilverStar);
    struct ObjectNode *listHead = &gObjectLists[get_object_list_from_behavior(behaviorAddr)];
    struct ObjectNode *obj = listHead->next;

    if (o->oSilverStarSpawnStar == FALSE) {
        while (listHead != obj) {
            if (((struct Object *) obj)->behavior == behaviorAddr) {
                // We look to see if they have the same first parameter as the podium
                if ((((struct Object *) obj)->oBehParams >> 24) == (o->oBehParams >> 24)) {
                    // If it does, assign this silver star to this podium !
                    o->oSilverStarPodiumAssignedSilverStar = (struct Object *) obj;
                    o->oSilverStarSpawnStar = TRUE; // Sets the yellow star to be allowed to be spawned temporarily
                    
                    // If the silver stars isn't collected, do the following:
                    if (o->oSilverStarPodiumAssignedSilverStar->oSilverStarCollected == FALSE) {
                        o->oSilverStarSpawnStar = FALSE; // Forbid the yellow star to spawn next frame
                        break; // Stop the loop, we still have some uncollected silver stars !
                    }

                }
            }
            obj = obj->next; // check next silver star
        }

        // else o->oSilverStarSpawnStar is still true, meaning all silver stars were collected !

        // If we are allowed to spawn the yellow star, do the following:
        if (o->oSilverStarSpawnStar == TRUE) {
            // This will be called once (for one frame)
            struct Object *starObj = NULL;
            play_puzzle_jingle();
            starObj = spawn_object_abs_with_rot(o, 0, MODEL_STAR, bhvStar, o->oPosX, o->oPosY, o->oPosZ, 0, 0, 0); // spawn a star !
            starObj->oBehParams = o->oBehParams2ndByte << 24; // set the star's ID to be the podium's second behavior parameter !
        }
    }
}
