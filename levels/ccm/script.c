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
#include "levels/ccm/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ccm_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _ccm_segment_7SegmentRomStart, _ccm_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _snow_yay0SegmentRomStart, _snow_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group7_yay0SegmentRomStart, _group7_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group7_geoSegmentRomStart, _group7_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_8), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, ccm_geo_00042C), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_04, ccm_geo_00045C), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_05, ccm_geo_000494), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_06, ccm_geo_0004BC), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_07, ccm_geo_0004E4), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_CABIN_DOOR, cabin_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_SNOW_TREE, snow_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_ROPEWAY_LIFT, ccm_geo_0003D0), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_SNOWMAN_BASE, ccm_geo_0003F0), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_SNOWMAN_HEAD, ccm_geo_00040C), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ccm_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_BOB, 0x02, 4, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_EXCLAMATION_BOX, -1590, 250, 2879, 0, 0, 0, 0x00000000, bhvCustomExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, -2590, 250, 2879, 0, 0, 0, (1 << 16), bhvCustomExclamationBox),
		OBJECT(MODEL_FADING_PLATFORM, -1150, 250, -628, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_NONE, 350, 250, -628, 0, 0, 0, 0x00000000, bhvFlipplane),
		OBJECT(MODEL_NONE, 1375, 250, 122, 0, 0, 0, (1 << 16), bhvFlipplane),
		OBJECT(MODEL_NONE, 1020, 250, -2678, 0, 0, 0, 0x00000000, bhvFlipswap),
		OBJECT(MODEL_NONE, 2556, 1250, -1803, 0, 0, 0, (0x4 << 16) | (0xF << 8) | (0x4), bhvGreenPlatformCircularManager),
		OBJECT(MODEL_NONE, 2556, 1250, -3413, 0, 0, 0, (0x1  << 24) | (0x4 << 16) | (0xF << 8) | (0x4), bhvGreenPlatformCircularManager),
		MARIO_POS(0x01, 0, 0, 200, 0),
		OBJECT(MODEL_NOTEBLOCK, -1919, 250, -1591, 0, 0, 0, 0x00000000, bhvNoteblock),
		OBJECT(MODEL_NONE, -2966, 250, 1379, 0, 0, 0, 0x00000000, bhvOnOffBlock),
		OBJECT(MODEL_NONE, -2966, 250, -121, 0, 0, 0, (1 << 16), bhvOnOffBlock),
		OBJECT(MODEL_ONOFF_SWITCH, -1590, 250, 1379, 0, 0, 0, 0x00000000, bhvOnOffButton),
		OBJECT(MODEL_ONOFF_SWITCH, -1590, 250, -121, 0, 0, 0, (1 << 16), bhvOnOffButton),
		OBJECT(MODEL_INTERACTIVE_TABLET_PODIUM, 1375, 250, 2748, 0, 0, 0, 0x00000000, bhvInteractiveTabletPodium),
		OBJECT(MODEL_SILVER_STAR, -2588, 250, -3110, 0, 0, 0, 0x00000000, bhvSilverStar),
		OBJECT(MODEL_SILVER_STAR_PODIUM, -1988, 250, -2728, 0, 0, 0, 0x00000000, bhvSilverStarPodium),
		OBJECT(MODEL_SILVER_STAR, -2288, 250, -3110, 0, 0, 0, 0x00000000, bhvSilverStar),
		OBJECT(MODEL_SILVER_STAR, -1988, 250, -3110, 0, 0, 0, 0x00000000, bhvSilverStar),
		OBJECT(MODEL_SILVER_STAR, -1688, 250, -3110, 0, 0, 0, 0x00000000, bhvSilverStar),
		OBJECT(MODEL_SILVER_STAR, -1388, 250, -3110, 0, 0, 0, 0x00000000, bhvSilverStar),
		OBJECT(MODEL_SYNC_BLOCK, 350, 250, -2028, 0, 0, 0, 0x00000000, bhvSyncBlock),
		OBJECT(MODEL_SYNC_BLOCK, 1375, 250, -1278, 0, 0, 0, (2 << 24), bhvSyncBlock),
		OBJECT(MODEL_INTERACTIVE_TABLET, 350, 250, 1998, 0, 0, 0, 0x00000000, bhvInteractiveTablet),
		OBJECT(MODEL_INTERACTIVE_TABLET, 1229, 250, 1998, 0, 0, 0, 0x00000000, bhvInteractiveTablet),
		OBJECT(MODEL_INTERACTIVE_TABLET, 2213, 250, 1998, 0, 0, 0, 0x00000000, bhvInteractiveTablet),
		OBJECT(MODEL_INTERACTIVE_TABLET, 1669, 250, 1492, 0, 0, 0, 0x00000000, bhvInteractiveTablet),
		OBJECT(MODEL_INTERACTIVE_TABLET, 895, 250, 1530, 0, 0, 0, 0x00000000, bhvInteractiveTablet),
		OBJECT(MODEL_NONE, 0, 200, 0, 0, 180, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(ccm_area_1_collision),
		MACRO_OBJECTS(ccm_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 200, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};