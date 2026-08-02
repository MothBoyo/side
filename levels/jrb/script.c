#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"
#include "make_const_nonconst.h"
#include "levels/jrb/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_jrb_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _jrb_segment_7SegmentRomStart, _jrb_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _water_yay0SegmentRomStart, _water_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group9_yay0SegmentRomStart, _group9_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group9_geoSegmentRomStart, _group9_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_10), 
	JUMP_LINK(script_func_global_18), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SHIP_LEFT_HALF_PART, jrb_geo_000978), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SHIP_BACK_LEFT_PART, jrb_geo_0009B0), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SHIP_RIGHT_HALF_PART, jrb_geo_0009E8), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SHIP_BACK_RIGHT_PART, jrb_geo_000A00), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SUNKEN_SHIP, jrb_geo_000990), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SUNKEN_SHIP_BACK, jrb_geo_0009C8), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_ROCK, jrb_geo_000930), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SLIDING_BOX, jrb_geo_000960), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_FALLING_PILLAR, jrb_geo_000900), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_FALLING_PILLAR_BASE, jrb_geo_000918), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_FLOATING_PLATFORM, jrb_geo_000948), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, jrb_area_1),
		WARP_NODE(1, LEVEL_JRB, 0x04, 2, WARP_NO_CHECKPOINT),
		WARP_NODE(2, LEVEL_JRB, 0x01, 1, WARP_NO_CHECKPOINT),
		WARP_NODE(5, LEVEL_JRB, 0x03, 6, WARP_NO_CHECKPOINT),
		WARP_NODE(6, LEVEL_JRB, 0x01, 5, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_JRB, 0x01, 4, WARP_NO_CHECKPOINT),
		WARP_NODE(4, LEVEL_JRB, 0x01, 1, WARP_NO_CHECKPOINT),
		WARP_NODE(0x00, LEVEL_JRB, 0x08, 8, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 900, 2825, -11078, 0, 0, 0, (5 << 16), bhvDoorWarp),
		OBJECT(MODEL_NONE, 900, 2000, -7610, 0, -90, 0, 0x00000000, bhvFlipswap),
		OBJECT(MODEL_NONE, 1650, 2600, -8360, 0, 0, 0, 0x00000000, bhvFlipswap),
		MARIO_POS(0x01, 0, 0, 0, -3000),
		OBJECT(MODEL_NOTEBLOCK, 900, 4600, -11212, 0, 0, 0, 0x00000000, bhvNoteblock),
		OBJECT(MODEL_NONE, 900, 4300, -11212, 0, 0, 0, 0x00000000, bhvOnOffBlock),
		OBJECT(MODEL_ONOFF_SWITCH, -3000, 800, -9398, 0, 0, 0, (1 << 16), bhvOnOffButton),
		OBJECT(MODEL_NONE, 1650, 975, -7610, 0, 0, 0, 0x00000000, bhvInteractiveTabletPodium),
		OBJECT(MODEL_INTERACTIVE_TABLET, 2400, 1625, -7860, 0, 0, 0, 0x00000000, bhvInteractiveTablet),
		OBJECT(MODEL_INTERACTIVE_TABLET, 2900, 425, -8360, 0, 0, 0, 0x00000000, bhvInteractiveTablet),
		OBJECT(MODEL_INTERACTIVE_TABLET, 3400, 1725, -8360, 0, 0, 0, 0x00000000, bhvInteractiveTablet),
		OBJECT(MODEL_INTERACTIVE_TABLET, 900, 1225, -8860, 0, 0, 0, 0x00000000, bhvInteractiveTablet),
		OBJECT(MODEL_INTERACTIVE_TABLET, 2650, 2925, -8110, 0, 0, 0, 0x00000000, bhvInteractiveTablet),
		OBJECT(MODEL_HEART, -2250, 2450, -5510, 0, 0, 0, (1 << 16), bhvWarpPipe),
		OBJECT(MODEL_HEART, -2805, 1150, -5423, 0, 90, 0, (4 << 16), bhvWarpPipe),
		OBJECT(MODEL_EXCLAMATION_BOX, 3650, 2750, -5110, 0, 0, 0, 0x00000000, bhvExclamationBox),
		OBJECT(MODEL_NONE, 0, 0, -3000, 0, -90, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(jrb_area_1_collision),
		MACRO_OBJECTS(jrb_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(2, jrb_area_2),
		INSTANT_WARP(0x01, 0x03, 0, 0, 0),
		TERRAIN(jrb_area_2_collision),
		MACRO_OBJECTS(jrb_area_2_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(3, jrb_area_3),
		INSTANT_WARP(0x00, 0x02, 0, 0, 0),
		WARP_NODE(5, LEVEL_JRB, 0x01, 6, WARP_NO_CHECKPOINT),
		WARP_NODE(6, LEVEL_JRB, 0x01, 5, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_HEART, 470, 0, 2, 0, -90, 0, (6 << 16), bhvDoorWarp),
		TERRAIN(jrb_area_3_collision),
		MACRO_OBJECTS(jrb_area_3_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(4, jrb_area_4),
		WARP_NODE(1, LEVEL_JRB, 0x04, 2, WARP_NO_CHECKPOINT),
		WARP_NODE(2, LEVEL_JRB, 0x01, 1, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_JRB, 0x01, 4, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -150, 0, 0, 0, -90, 0, (1 << 16), bhv2dMode),
		OBJECT(MODEL_FADING_PLATFORM, 1991, 1000, 0, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 1991, 1000, -700, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 2191, 1000, 0, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 2191, 1000, -700, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 2391, 1000, 0, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 2391, 1000, -700, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 3291, 800, -700, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 3491, 800, -700, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 3691, 800, -700, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_NONE, 3291, 800, 0, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_NONE, 3491, 800, 0, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_NONE, 3691, 800, 0, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 3891, 800, -700, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_NONE, 3891, 800, 0, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 4091, 800, -700, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_NONE, 4091, 800, 0, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_NONE, 5225, 481, 0, 0, -90, 0, 0x00000000, bhvNoteblock),
		OBJECT(MODEL_NOTEBLOCK, 5225, 481, -700, 0, -90, 0, 0x00000000, bhvNoteblock),
		OBJECT(MODEL_HEART, -10729, 0, 0, 0, 90, 0, (2 << 16), bhvWarpPipe),
		OBJECT(MODEL_HEART, 9275, 1700, 0, 0, -90, 0, (3 << 16), bhvWarpPipe),
		OBJECT(MODEL_HEART, 9275, 1700, -700, 0, -90, 0, (3 << 16), bhvWarpPipe),
		TERRAIN(jrb_area_4_collision),
		MACRO_OBJECTS(jrb_area_4_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(8, jrb_area_8),
		WARP_NODE(0x00, LEVEL_BOB, 0x08, 8, WARP_NO_CHECKPOINT),
		WARP_NODE(8, LEVEL_BOB, 0x08, 8, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 250, 1000, -2650, 0, 0, 0, (0x1  << 24) | (0x3 << 16) | (0xA << 8) | (0xD), bhvGreenPlatformCircularManager),
		OBJECT(MODEL_NONE, -2050, 2500, -50, 0, 0, 0, (0x1  << 24) | (0x3 << 16) | (0xA << 8) | (0xD), bhvGreenPlatformCircularManager),
		OBJECT(MODEL_NONE, 150, 4000, 2650, 0, 0, 0, (0x1  << 24) | (0x3 << 16) | (0xA << 8) | (0xD), bhvGreenPlatformCircularManager),
		OBJECT(MODEL_NONE, 2000, 1000, 0, 0, 0, 0, (8 << 16), bhvSpinAirborneWarp),
		OBJECT(MODEL_STAR, 2350, 5400, 2650, 0, 0, 0, (6 << 24), bhvStar),
		OBJECT(MODEL_NONE, 2000, 0, 0, 0, 0, 0, (40 << 16), bhvCountdownTimer),
		TERRAIN(jrb_area_8_collision),
		MACRO_OBJECTS(jrb_area_8_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 0, -3000),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};