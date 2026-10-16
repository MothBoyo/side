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
#include "levels/vcutm/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_vcutm_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0_TEXTURE(0x09, _outside_yay0SegmentRomStart, _outside_yay0SegmentRomEnd), 
	LOAD_YAY0(0x07, _vcutm_segment_7SegmentRomStart, _vcutm_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_18), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE, warp_pipe_geo), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, vcutm_area_1),
		WARP_NODE(3, LEVEL_VCUTM, 0x02, 4, WARP_NO_CHECKPOINT),
		WARP_NODE(241, LEVEL_CASTLE, 0x02, 103, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 0, 0, 4725, 0, -90, 0, (1 << 16), bhv2dMode),
		OBJECT(MODEL_FADING_PLATFORM, -4450, 1200, 4725, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_NONE, 50, 700, 4725, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_NONE, 250, 700, 4725, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_NONE, 450, 700, 4725, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_NONE, 650, 700, 4725, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, -4250, 1200, 4725, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, -4050, 1200, 4725, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, -1550, 900, 4725, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, -1350, 900, 4725, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, -1150, 900, 4725, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, -950, 900, 4725, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, -3850, 1200, 4725, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, -3850, 1200, 3925, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, -4450, 1200, 3925, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, -4250, 1200, 3925, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, -4050, 1200, 3925, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, -1550, 900, 3925, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, -1350, 900, 3925, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, -1150, 900, 3925, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, -950, 900, 3925, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 50, 700, 3925, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 250, 700, 3925, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 450, 700, 3925, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 650, 700, 3925, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		MARIO_POS(0x01, 0, -16000, 1500, 4725),
		OBJECT(MODEL_NONE, -2550, 700, 4725, 0, -90, 0, 0x00000000, bhvNoteblock),
		OBJECT(MODEL_NOTEBLOCK, -2550, 700, 3925, 0, -90, 0, 0x00000000, bhvNoteblock),
		OBJECT(MODEL_SYNC_BLOCK, 7250, 2400, 4725, 0, 0, 0, 0x00000000, bhvSyncBlock),
		OBJECT(MODEL_SYNC_BLOCK, 7450, 2400, 4725, 0, 0, 0, 0x00000000, bhvSyncBlock),
		OBJECT(MODEL_SYNC_BLOCK, 10450, 2000, 4725, 0, 0, 0, 0x00000000, bhvSyncBlock),
		OBJECT(MODEL_SYNC_BLOCK, 10650, 2000, 4725, 0, 0, 0, 0x00000000, bhvSyncBlock),
		OBJECT(MODEL_SYNC_BLOCK, 7250, 2400, 3925, 0, 0, 0, 0x00000000, bhvSyncBlock),
		OBJECT(MODEL_SYNC_BLOCK, 7450, 2400, 3925, 0, 0, 0, 0x00000000, bhvSyncBlock),
		OBJECT(MODEL_SYNC_BLOCK, 10450, 2000, 3925, 0, 0, 0, 0x00000000, bhvSyncBlock),
		OBJECT(MODEL_SYNC_BLOCK, 10650, 2000, 3925, 0, 0, 0, 0x00000000, bhvSyncBlock),
		OBJECT(MODEL_SYNC_BLOCK, 7650, 2400, 4725, 0, 0, 0, 0x00000000, bhvSyncBlock),
		OBJECT(MODEL_SYNC_BLOCK, 10850, 2000, 4725, 0, 0, 0, 0x00000000, bhvSyncBlock),
		OBJECT(MODEL_SYNC_BLOCK, 7650, 2400, 3925, 0, 0, 0, 0x00000000, bhvSyncBlock),
		OBJECT(MODEL_SYNC_BLOCK, 10850, 2000, 3925, 0, 0, 0, 0x00000000, bhvSyncBlock),
		OBJECT(MODEL_NONE, 8850, 2200, 4725, 0, 0, 0, (2 << 24), bhvSyncBlock),
		OBJECT(MODEL_NONE, 9050, 2200, 4725, 0, 0, 0, (2 << 24), bhvSyncBlock),
		OBJECT(MODEL_NONE, 9250, 2200, 4725, 0, 0, 0, (2 << 24), bhvSyncBlock),
		OBJECT(MODEL_SYNC_BLOCK, 9250, 2200, 3925, 0, 0, 0, (2 << 24), bhvSyncBlock),
		OBJECT(MODEL_SYNC_BLOCK, 8850, 2200, 3925, 0, 0, 0, (2 << 24), bhvSyncBlock),
		OBJECT(MODEL_SYNC_BLOCK, 9050, 2200, 3925, 0, 0, 0, (2 << 24), bhvSyncBlock),
		OBJECT(MODEL_THWOMP, 3250, 1100, 4725, 0, -90, 0, 0x00000000, bhvThwomp),
		OBJECT(MODEL_THWOMP, 13250, 2100, 4725, 0, -90, 0, 0x00000000, bhvThwomp),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, 15925, 2800, 4725, 0, 0, 0, (3 << 16), bhvWarpPipe),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, 15925, 2800, 3875, 0, 0, 0, (3 << 16), bhvWarpPipe),
		OBJECT(MODEL_NONE, -16000, 1500, 4725, 0, -90, 0, 0x000A0000, bhvSpinAirborneWarp),
		OBJECT(MODEL_NONE, 0, 0, 0, 0, 0, 0, 0x00000000, bhv2dCameraForce),
		TERRAIN(vcutm_area_1_collision),
		MACRO_OBJECTS(vcutm_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_EVENT_POWERUP),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(2, vcutm_area_2),
		WARP_NODE(3, LEVEL_VCUTM, 0x02, 4, WARP_NO_CHECKPOINT),
		WARP_NODE(241, LEVEL_CASTLE, 0x02, 103, WARP_NO_CHECKPOINT),
		WARP_NODE(5, LEVEL_CASTLE, 0x02, 7, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_EXCLAMATION_BOX, 600, 600, 600, 0, 0, 0, (3 << 16), bhvCustomExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, 0, 600, -600, 0, 0, 0, (2 << 16), bhvCustomExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, -600, 600, -600, 0, 0, 0, (4 << 16), bhvCustomExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, 0, 600, 0, 0, 0, 0, (1 << 16), bhvCustomExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, -600, 600, 0, 0, 0, 0, 0x00000000, bhvCustomExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, -600, 600, 600, 0, 0, 0, (6 << 16), bhvCustomExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, 0, 600, 600, 0, 0, 0, (5 << 16), bhvCustomExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, 600, 600, 0, 0, 0, 0, (5 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, 600, 600, -600, 0, 0, 0, (10 << 16), bhvExclamationBox),
		OBJECT(MODEL_NONE, 0, 2650, 2200, 0, 0, 0, (4 << 16), bhvSpinAirborneWarp),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, 0, -100, -1900, 0, 0, 0, (5 << 16), bhvWarpPipe),
		TERRAIN(vcutm_area_2_collision),
		MACRO_OBJECTS(vcutm_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_EVENT_POWERUP),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -16000, 1500, 4725),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};