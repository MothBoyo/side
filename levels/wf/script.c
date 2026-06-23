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
#include "levels/wf/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_wf_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _wf_segment_7SegmentRomStart, _wf_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _grass_yay0SegmentRomStart, _grass_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group8_yay0SegmentRomStart, _group8_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group8_geoSegmentRomStart, _group8_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_9), 
	JUMP_LINK(script_func_global_18), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, wf_geo_0007E0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_04, wf_geo_000820), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_05, wf_geo_000860), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_06, wf_geo_000878), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_07, wf_geo_000890), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_08, wf_geo_0008A8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_09, wf_geo_0008E8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0A, wf_geo_000900), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0C, wf_geo_000940), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_GIANT_POLE, wf_geo_000AE0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0E, wf_geo_000958), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_0F, wf_geo_0009A0), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_ROTATING_PLATFORM, wf_geo_0009B8), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_11, wf_geo_0009D0), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_12, wf_geo_0009E8), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_SMALL_BOMP, wf_geo_000A00), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_LARGE_BOMP, wf_geo_000A40), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_ROTATING_WOODEN_PLATFORM, wf_geo_000A58), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_SLIDING_PLATFORM, wf_geo_000A98), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TUMBLING_BRIDGE_PART, wf_geo_000AB0), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TUMBLING_BRIDGE, wf_geo_000AC8), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_TRAPEZOID_PLATORM, wf_geo_000AF8), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_SQUARE_PLATORM, wf_geo_000B10), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_SQUARE_PLATORM_UNUSED, wf_geo_000B38), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_SQUARE_PLATORM_ELEVATOR, wf_geo_000B60), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_BREAKABLE_WALL_RIGHT, wf_geo_000B78), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_BREAKABLE_WALL_LEFT, wf_geo_000B90), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_KICKABLE_BOARD, wf_geo_000BA8), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_TOWER_DOOR, wf_geo_000BE0), 
	LOAD_MODEL_FROM_GEO(MODEL_WF_KICKABLE_BOARD_FELLED, wf_geo_000BC8), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, wf_area_1),
		WARP_NODE(1, LEVEL_WF, 0x04, 2, WARP_NO_CHECKPOINT),
		WARP_NODE(2, LEVEL_WF, 0x01, 1, WARP_NO_CHECKPOINT),
		WARP_NODE(5, LEVEL_WF, 0x03, 6, WARP_NO_CHECKPOINT),
		WARP_NODE(6, LEVEL_WF, 0x01, 5, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_WF, 0x01, 4, WARP_NO_CHECKPOINT),
		WARP_NODE(4, LEVEL_WF, 0x01, 1, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_CAP_SWITCH, 2850, 2900, -5310, 0, -45, 0, 0x00000000, bhvCapSwitch),
		OBJECT(MODEL_NONE, 900, 2825, -8078, 0, 0, 0, (5 << 16), bhvDoorWarp),
		OBJECT(MODEL_NONE, 900, 2000, -4610, 0, -90, 0, 0x00000000, bhvFlipswap),
		OBJECT(MODEL_NONE, 1650, 2600, -5360, 0, 0, 0, 0x00000000, bhvFlipswap),
		MARIO_POS(0x01, 0, 0, 0, 0),
		OBJECT(MODEL_NOTEBLOCK, 3650, 2650, -2110, 0, 0, 0, 0x00000000, bhvNoteblock),
		OBJECT(MODEL_NONE, 3650, 2350, -2110, 0, 0, 0, 0x00000000, bhvOnOffBlock),
		OBJECT(MODEL_ONOFF_SWITCH, -3000, 800, -6398, 0, 0, 0, (1 << 16), bhvOnOffButton),
		OBJECT(MODEL_NONE, 1650, 1000, -4610, 0, 0, 0, 0x00000000, bhvInteractiveTabletPodium),
		OBJECT(MODEL_INTERACTIVE_TABLET, 2400, 1650, -4860, 0, 0, 0, 0x00000000, bhvInteractiveTablet),
		OBJECT(MODEL_INTERACTIVE_TABLET, 2900, 450, -5360, 0, 0, 0, 0x00000000, bhvInteractiveTablet),
		OBJECT(MODEL_INTERACTIVE_TABLET, 3400, 1750, -5360, 0, 0, 0, 0x00000000, bhvInteractiveTablet),
		OBJECT(MODEL_INTERACTIVE_TABLET, 900, 1250, -5860, 0, 0, 0, 0x00000000, bhvInteractiveTablet),
		OBJECT(MODEL_INTERACTIVE_TABLET, 2483, 2950, -4944, 0, 0, 0, 0x00000000, bhvInteractiveTablet),
		OBJECT(MODEL_NONE, -2250, 2450, -2510, 0, 0, 0, (1 << 16), bhvWarpPipe),
		OBJECT(MODEL_NONE, -2805, 1150, -2423, 0, 90, 0, (4 << 16), bhvWarpPipe),
		OBJECT(MODEL_NONE, 0, 0, 0, 0, -90, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(wf_area_1_collision),
		MACRO_OBJECTS(wf_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(2, wf_area_2),
		INSTANT_WARP(0x01, 0x03, 0, 0, 0),
		TERRAIN(wf_area_2_collision),
		MACRO_OBJECTS(wf_area_2_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(3, wf_area_3),
		INSTANT_WARP(0x00, 0x02, 0, 0, 0),
		WARP_NODE(5, LEVEL_WF, 0x01, 6, WARP_NO_CHECKPOINT),
		WARP_NODE(6, LEVEL_WF, 0x01, 5, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 470, 0, 2, 0, -90, 0, (6 << 16), bhvDoorWarp),
		TERRAIN(wf_area_3_collision),
		MACRO_OBJECTS(wf_area_3_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(4, wf_area_4),
		WARP_NODE(1, LEVEL_WF, 0x04, 2, WARP_NO_CHECKPOINT),
		WARP_NODE(2, LEVEL_WF, 0x01, 1, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_WF, 0x01, 4, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_FADING_PLATFORM, 4700, 1000, -1641, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 4000, 1000, -1641, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 4700, 1000, -1841, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 4000, 1000, -1841, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 4700, 1000, -2041, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 4000, 1000, -2041, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 4000, 800, -2941, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 4000, 800, -3141, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 4000, 800, -3341, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_NONE, 4700, 800, -2941, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_NONE, 4700, 800, -3141, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_NONE, 4700, 800, -3341, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 4000, 800, -3541, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_NONE, 4700, 800, -3541, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 4000, 800, -3741, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_NONE, 4700, 800, -3741, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_NONE, 4700, 481, -4875, 0, 0, 0, 0x00000000, bhvNoteblock),
		OBJECT(MODEL_NOTEBLOCK, 4000, 481, -4875, 0, 0, 0, 0x00000000, bhvNoteblock),
		OBJECT(MODEL_NONE, 4700, 0, 10991, 0, 180, 0, (2 << 16), bhvWarpPipe),
		OBJECT(MODEL_NONE, 4700, 1700, -8925, 0, 0, 0, (3 << 16), bhvWarpPipe),
		TERRAIN(wf_area_4_collision),
		MACRO_OBJECTS(wf_area_4_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 0, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};