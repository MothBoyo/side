struct ObjectHitbox sCustomExclamationBoxHitbox = { // hitbox ! without it, no breaking the boxy boxy ! <3
    .interactType      = INTERACT_BREAKABLE,
    .downOffset        = 5,
    .damageOrCoinValue = 0,
    .health            = 1,
    .numLootCoins      = 0,
    .radius            = 40,
    .height            = 30,
    .hurtboxRadius     = 40,
    .hurtboxHeight     = 30,
};

struct CustomExclamationBoxContents { // struct we'll use to define our object models, behaviors and behaviorr params
    ModelID32 model;
    const BehaviorScript *behavior;
    u8 behParam;
};

enum CustomExclamationBoxContentsList { // Enum list, names dont matter but must be unique ! <3
    CUSTOM_ITEM_0,
    CUSTOM_ITEM_1,
    CUSTOM_ITEM_2,
    CUSTOM_ITEM_3,
    CUSTOM_ITEM_4,
    CUSTOM_ITEM_5,
    CUSTOM_ITEM_6,
    CUSTOM_ITEM_7,
    CUSTOM_ITEM_8,
    CUSTOM_ITEM_9,
    CUSTOM_ITEM_10,
};

struct CustomExclamationBoxContents sCustomExclamationBoxContents[] = { // the good stuff ! the content :D
 // [ENUM_FROM_ABOVE      ] = { MODEL_OF_OBJECT, bhvBehaviorOfObject, behavior_param_applied_to_the_second_byte_of_the_actor_params }
    [CUSTOM_ITEM_0        ] = { MODEL_GOOMBA,  bhvGoomba,               0 },
    [CUSTOM_ITEM_1        ] = { MODEL_CHUCKYA, bhvChuckya,              0 },
    [CUSTOM_ITEM_2        ] = { MODEL_AMP,     bhvCirclingAmp,          1 },
    [CUSTOM_ITEM_3        ] = { MODEL_AMP,     bhvHomingAmp,            0 },
    [CUSTOM_ITEM_4        ] = { MODEL_BLACK_BOBOMB,     bhvBobomb,      0 },
    [CUSTOM_ITEM_5        ] = { MODEL_SCUTTLEBUG,     bhvScuttlebug,    0 },
    [CUSTOM_ITEM_6        ] = { MODEL_HEAVE_HO,     bhvHeaveHo,         0 },
};

void custom_exclamation_box_spawn_contents(struct CustomExclamationBoxContents *contentsList, u8 lootIndex) {
    struct Object *contentsObj = NULL;

    if (lootIndex < ARRAY_COUNT(sCustomExclamationBoxContents)) { // if the behavior param we set in blender exist, spawn the stuff assigned to it !
        struct CustomExclamationBoxContents *contents = &contentsList[lootIndex];

        contentsObj = spawn_object_relative(0, 0, 0, 0, o, contents->model, contents->behavior); // spawn actor
        contentsObj->oBehParams2ndByte = contents->behParam; // assign the 2nd beh param to the actor
        contentsObj->oVelY = random_u16() & 30;
        contentsObj->oForwardVel = random_u16() & 10;
        contentsObj->oMoveAngleYaw = random_u16();
        
    }
}

void custom_exclamation_box_act_explode(void) { // break box
    custom_exclamation_box_spawn_contents(sCustomExclamationBoxContents, o->oBehParams2ndByte); // spawn logic
    spawn_mist_particles_variable(0, 0, 46.0f);
    spawn_triangle_break_particles(20, MODEL_CARTOON_STAR, 0.3f, o->oAnimState);
    create_sound_spawner(SOUND_GENERAL_BREAK_BOX);
    obj_mark_for_deletion(o);
}

void custom_exclamation_box_act_scaling(void) { // anim of breaking
    cur_obj_move_using_fvel_and_gravity();
    if (o->oVelY < 0.0f) {
        o->oVelY = 0.0f;
        o->oGravity = 0.0f;
    }
    o->oGraphYOffset                  = ((-sins(o->oExclamationBoxScaleAngle) + 1.0f) * 26.0f);
    o->oExclamationBoxHorizontalScale = ((-sins(o->oExclamationBoxScaleAngle) + 1.0f) *  0.5f) + 1.0f;
    o->oExclamationBoxVerticalScale   = (( sins(o->oExclamationBoxScaleAngle) + 1.0f) *  0.3f) + 0.0f;
    o->oExclamationBoxScaleAngle += 0x1000;
    obj_scale_xyz(o,
        (o->oExclamationBoxHorizontalScale * 2.0f),
        (o->oExclamationBoxVerticalScale   * 2.0f),
        (o->oExclamationBoxHorizontalScale * 2.0f)
    );
    if (o->oTimer == 7) {
        o->oAction = 2;
    }
}

void custom_exclamation_box_act_active(void) { // idle state of the boxy box !
    obj_set_hitbox(o, &sCustomExclamationBoxHitbox);
    if (o->oTimer == 0) {
        cur_obj_unhide();
        cur_obj_become_tangible();
        o->oInteractStatus = INT_STATUS_NONE;
        o->oPosY = o->oHomeY;
        o->oGraphYOffset = 0.0f;
    }
    if (cur_obj_was_attacked_or_ground_pounded()) {
        cur_obj_become_intangible();
        o->oExclamationBoxScaleAngle = 0x4000;
        o->oVelY = 30.0f;
        o->oGravity = -8.0f;
        o->oFloorHeight = o->oPosY;
        o->oAction = 1;
    }
    load_object_collision_model();
}

void bhv_custom_exclamation_box_loop(void) { // core logic, looping forever
    cur_obj_scale(2.0f);
    o->oAnimState = EXCLAMATION_BOX_ANIM_STATE_YELLOW; // Make it yellow ! 

    switch (o->oAction) {
        case 0:
            custom_exclamation_box_act_active();
        break;

        case 1:
            custom_exclamation_box_act_scaling();
        break;

        case 2:
            custom_exclamation_box_act_explode();
        break;
    }
}