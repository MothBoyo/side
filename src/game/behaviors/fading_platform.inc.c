
// This scales down the platform based on o->oFadingPlatformScale
Gfx *fading_platform_scale(s32 callContext, struct GraphNode *node){
    struct Object *curObj;

    if (callContext == GEO_CONTEXT_RENDER) { // called every frame when the object is on screen
        curObj = (struct Object *) gCurGraphNodeObject; // our o object, important to do curObj-> instead of o-> here !
        
        ((struct GraphNodeScale *) node->next)->scale = curObj->oFadingPlatformScale; // sets scale
    }
    return NULL;
}

// initiate the platform and set defualt values
void fading_platform_init(void){
    o->oFadingPlatformScale = 1.0;
    o->oFadingPlatformTimerIdle = 0;
    o->oFadingPlatformTargetScale = 1;
}

// this code runs over and over forever
void fading_platform_loop(void){

    // Mario is on the platform and we're not already shrinking down the platform, do the following:
    if ((gMarioObject->platform == o) && (!o->oFadingPlatformVanishing)) {
        o->oFadingPlatformVanishing = TRUE; // Set the platform as shrinking
        play_sound(SOUND_MENU_PINCH_MARIO_FACE, gGlobalSoundSource); // Play a sound !
    }

    // Used for scale interpolation
    if (o->oFadingPlatformVanishing) {
        o->oFadingPlatformTargetScale = 0; // sets the target scale to 0
    }

    if (o->oFadingPlatformScale <= 0) { // if the platform is gone, do the following:
        o->oFadingPlatformScale = 0; // set scale at exactly 0
        o->oFadingPlatformTimerIdle += 1; // increase the timer that will respawn the platform
        if (o->oFadingPlatformTimerIdle >= 150) { // if the timer is over 20 seconds, do the following:
            o->oFadingPlatformTargetScale = 1; // We set the target scale to 1 to get our platform back :)
            o->oFadingPlatformTimerIdle = 0; // We reset our timer for next use
            o->oFadingPlatformVanishing = FALSE; // We say the platform is no longer shrinking and basically ready to be shrunk again !
        }
        
    }
    
    // interpolate the scale so we shrink/go bigger smooooothly !
    o->oFadingPlatformScale = approach_f32(o->oFadingPlatformScale, o->oFadingPlatformTargetScale, 0.1, 0.01);
    
    // If we are above 0.1 in scale, load the collisions, so if the platform is too small we dont want Mario to be able to stand on it anymore.
    if (o->oFadingPlatformScale > 0.1) {
        load_object_collision_model();
    }
    

}
