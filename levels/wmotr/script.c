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
#include "levels/wmotr/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_wmotr_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _wmotr_segment_7SegmentRomStart, _wmotr_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _cloud_floor_skybox_yay0SegmentRomStart, _cloud_floor_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _sky_yay0SegmentRomStart, _sky_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group16_yay0SegmentRomStart, _group16_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group16_geoSegmentRomStart, _group16_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	JUMP_LINK(script_func_global_17), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE, warp_pipe_geo), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, wmotr_area_1),
		WARP_NODE(5, LEVEL_WMOTR, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_CASTLE, 0x01, 5, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 0, 0, 0, 0, 0, 0, (1 << 16), bhv2dMode),
		OBJECT(MODEL_BOWLING_BALL, 1550, 1400, -300, 0, 0, 0, 0x00000000, bhvFireSpitter),
		OBJECT(MODEL_BOWLING_BALL, 4250, 2000, -300, 0, 0, 0, 0x00000000, bhvFireSpitter),
		OBJECT(MODEL_BOWLING_BALL, -5750, 800, -300, 0, 0, 0, 0x00000000, bhvFireSpitter),
		MARIO_POS(0x01, 180, -10300, 1000, 0),
		OBJECT(MODEL_NOTEBLOCK, -4500, 800, 0, 0, 0, 0, 0x00000000, bhvNoteblock),
		OBJECT(MODEL_NOTEBLOCK, 9200, 3100, 0, 0, 0, 0, 0x00000000, bhvNoteblock),
		OBJECT(MODEL_SYNC_BLOCK, 300, 900, 0, 0, 0, 0, 0x00000000, bhvSyncBlock),
		OBJECT(MODEL_SYNC_BLOCK, 100, 900, 0, 0, 0, 0, 0x00000000, bhvSyncBlock),
		OBJECT(MODEL_SYNC_BLOCK, 5700, 2100, 0, 0, 0, 0, 0x00000000, bhvSyncBlock),
		OBJECT(MODEL_SYNC_BLOCK, 5500, 2100, 0, 0, 0, 0, 0x00000000, bhvSyncBlock),
		OBJECT(MODEL_SYNC_BLOCK, 3000, 1500, 0, 0, 0, 0, (2 << 24), bhvSyncBlock),
		OBJECT(MODEL_SYNC_BLOCK, 2800, 1500, 0, 0, 0, 0, (2 << 24), bhvSyncBlock),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, 11450, 4000, 0, 0, 0, 0, (3 << 16), bhvWarpPipe),
		OBJECT(MODEL_NONE, -10300, 1000, 0, 0, 90, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(wmotr_area_1_collision),
		MACRO_OBJECTS(wmotr_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 180, -10300, 1000, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};