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
	LOAD_YAY0(0x0A, _ccm_skybox_yay0SegmentRomStart, _ccm_skybox_yay0SegmentRomEnd), 
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
		OBJECT(MODEL_FADING_PLATFORM, -4917, 2907, 122, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, -4717, 2907, 122, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, -5117, 2907, 122, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, -5917, 3107, 122, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, -6117, 3107, 122, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, -6317, 3107, 122, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_NONE, -5917, 1907, 122, 0, 0, 0, 0x00000000, bhvFlipplane),
		OBJECT(MODEL_NONE, -6917, 1707, 122, 0, 0, 0, (1 << 16), bhvFlipplane),
		OBJECT(MODEL_NONE, -4917, 2107, 122, 0, 0, 0, (1 << 16), bhvFlipplane),
		MARIO_POS(0x01, 0, 0, 200, 0),
		OBJECT(MODEL_NOTEBLOCK, -5550, 3531, 122, 0, 0, 0, 0x00000000, bhvNoteblock),
		OBJECT(MODEL_SYNC_BLOCK, 2183, 2232, 0, 0, 0, 0, 0x00000000, bhvSyncBlock),
		OBJECT(MODEL_SYNC_BLOCK, 1983, 2232, 0, 0, 0, 0, 0x00000000, bhvSyncBlock),
		OBJECT(MODEL_SYNC_BLOCK, 1783, 2232, 0, 0, 0, 0, 0x00000000, bhvSyncBlock),
		OBJECT(MODEL_SYNC_BLOCK, 2183, 3689, 0, 0, 0, 0, 0x00000000, bhvSyncBlock),
		OBJECT(MODEL_SYNC_BLOCK, 1983, 3689, 0, 0, 0, 0, 0x00000000, bhvSyncBlock),
		OBJECT(MODEL_SYNC_BLOCK, 1783, 3689, 0, 0, 0, 0, 0x00000000, bhvSyncBlock),
		OBJECT(MODEL_SYNC_BLOCK, 1583, 2232, 0, 0, 0, 0, 0x00000000, bhvSyncBlock),
		OBJECT(MODEL_SYNC_BLOCK, 1583, 3689, 0, 0, 0, 0, 0x00000000, bhvSyncBlock),
		OBJECT(MODEL_SYNC_BLOCK, -1117, 2582, 0, 0, 0, 0, (2 << 24), bhvSyncBlock),
		OBJECT(MODEL_SYNC_BLOCK, -1317, 2582, 0, 0, 0, 0, (2 << 24), bhvSyncBlock),
		OBJECT(MODEL_SYNC_BLOCK, -1517, 2582, 0, 0, 0, 0, (2 << 24), bhvSyncBlock),
		OBJECT(MODEL_SYNC_BLOCK, -1117, 3582, 0, 0, 0, 0, (2 << 24), bhvSyncBlock),
		OBJECT(MODEL_SYNC_BLOCK, -1317, 3582, 0, 0, 0, 0, (2 << 24), bhvSyncBlock),
		OBJECT(MODEL_SYNC_BLOCK, -1517, 3582, 0, 0, 0, 0, (2 << 24), bhvSyncBlock),
		OBJECT(MODEL_SYNC_BLOCK, -1717, 2582, 0, 0, 0, 0, (2 << 24), bhvSyncBlock),
		OBJECT(MODEL_SYNC_BLOCK, -1717, 3582, 0, 0, 0, 0, (2 << 24), bhvSyncBlock),
		OBJECT(MODEL_NONE, 0, 200, 0, 0, -90, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(ccm_area_1_collision),
		MACRO_OBJECTS(ccm_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
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