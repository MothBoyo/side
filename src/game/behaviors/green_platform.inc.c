// Math to move the current platform across a circular path on YZ axis
void green_platform_circular_vertical(void) {

    s16 angle = gGlobalTimer * (0x10 * o->oGreenPlatformSpeed) + ((0x8000 / (o->oGreenPlatformAmount)) * (o->oGreenPlatformID + o->oGreenPlatformID));
    o->oPosX = o->oHomeX + sins(o->oFaceAngleYaw) * sins(angle) * o->oGreenPlatformRadius;
    o->oPosZ = o->oHomeZ + coss(o->oFaceAngleYaw) * sins(angle) * o->oGreenPlatformRadius;
    o->oPosY = o->oHomeY + coss(angle) * o->oGreenPlatformRadius;

}

// Math to move the current platform across a circular path on XZ axis
void green_platform_circular_horizontal(void) {

    s16 angle = gGlobalTimer * (0x10 * o->oGreenPlatformSpeed) + ((0x8000 / (o->oGreenPlatformAmount)) * (o->oGreenPlatformID + o->oGreenPlatformID));
    o->oPosY = o->oHomeY + sins(o->oFaceAngleYaw) * sins(angle) * o->oGreenPlatformRadius;
    o->oPosZ = o->oHomeZ + coss(o->oFaceAngleYaw) * sins(angle) * o->oGreenPlatformRadius;
    o->oPosX = o->oHomeX + coss(angle) * o->oGreenPlatformRadius;

}

// Executed once, this spawns the platforms and their behavior !
void green_platform_manager_init(void) {

	if (o->oTimer == 0) {
	int i;
	struct Object *curPlatform;

	cur_obj_scale((o->oBehParams >> 8 & 0xFF)); // Scale track visual actor based on radius

	o->oAction = o->oBehParams >> 24;
	switch (o->oAction) {
		case GREEN_PLATFORM_CIRCULAR_HORIZONTAL: // 0x00
			o->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_GREEN_PLATFORM_TRACK]; // Set track model
			for (i = 0; i < o->oBehParams2ndByte; i++) { // spawns all the platforms
				curPlatform = spawn_object(o, MODEL_GREEN_PLATFORM, bhvGreenPlatformCircular); // spawns a platform
				curPlatform->oBehParams = o->oBehParams; // assign parameters to the platform
				curPlatform->oGreenPlatformAmount = CLAMP(o->oBehParams2ndByte, i+1, 255); // assigning ID and ammount to determine where to place them in the circular path
				curPlatform->oGreenPlatformID = i+1; // assigning ID and ammount to determine where to place them in the circular path

				curPlatform->respawnInfo = NULL; //fix
				curPlatform->respawnInfoType = RESPAWN_INFO_TYPE_NULL;
			}
			o->oFaceAngleRoll = 0x4000; // Rotate track 90° on Z axis to make it rest flat
		break;

		case GREEN_PLATFORM_CIRCULAR_VERTICAL: // 0x01
			o->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_GREEN_PLATFORM_TRACK]; // Set track model
			for (i = 0; i < o->oBehParams2ndByte; i++) { // spawns all the platforms
				curPlatform = spawn_object(o, MODEL_GREEN_PLATFORM, bhvGreenPlatformCircular); // spawns a platform
				curPlatform->oBehParams = o->oBehParams; // assign parameters to the platform
				curPlatform->oGreenPlatformAmount = CLAMP(o->oBehParams2ndByte, i+1, 255); // assigning ID and ammount to determine where to place them in the circular path
				curPlatform->oGreenPlatformID = i+1; // assigning ID and ammount to determine where to place them in the circular path

				curPlatform->respawnInfo = NULL; //fix
				curPlatform->respawnInfoType = RESPAWN_INFO_TYPE_NULL;
			}
		break;
		
	}
	}
}

// Executed once per indivudual platform !
void green_platform_init(void) {
	o->oAction = o->oBehParams >> 24; // set mode (horizontal or vertical)
	o->oGreenPlatformRadius = (o->parentObj->oBehParams >> 8 & 0xFF) * 100; // Sets radius
	o->oGreenPlatformSpeed = o->parentObj->oBehParams & 0xFF; // Set speed
}

// Loop forever per indivudual platform !
void green_platform_loop(void) {
	switch (o->oAction) {// execute code based on the mode
		case GREEN_PLATFORM_CIRCULAR_HORIZONTAL: // horizontal (0x00)
			green_platform_circular_horizontal();
		break;

		case GREEN_PLATFORM_CIRCULAR_VERTICAL: // vertical (0x01)
			green_platform_circular_vertical();
		break;
		
	}
}