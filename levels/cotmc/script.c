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
#include "levels/cotmc/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_cotmc_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _cotmc_segment_7SegmentRomStart, _cotmc_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _cave_yay0SegmentRomStart, _cave_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group9_yay0SegmentRomStart, _group9_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group9_geoSegmentRomStart, _group9_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group13_yay0SegmentRomStart, _group13_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_10), 
	JUMP_LINK(script_func_global_14), 
	LOAD_MODEL_FROM_GEO(MODEL_CASTLE_GROUNDS_WARP_PIPE, warp_pipe_geo), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, cotmc_area_1),
		WARP_NODE(3, LEVEL_COTMC, 0x02, 4, WARP_NO_CHECKPOINT),
		WARP_NODE(4, LEVEL_COTMC, 0x01, 3, WARP_NO_CHECKPOINT),
		WARP_NODE(241, LEVEL_CASTLE, 0x01, 2, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -5803, 2200, -5426, 20, -155, 0, 0x00000000, bhv2dCamera),
		OBJECT(MODEL_NONE, -964, 150, 0, 0, 0, 0, 0x00000000, bhvFlipswap),
		OBJECT(MODEL_NONE, -3914, 450, 0, 0, 180, 0, 0x00000000, bhvFlipswap),
		MARIO_POS(0x01, 0, 500, 1500, 0),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, -6107, 900, 0, 0, 0, 0, (3 << 16), bhvWarpPipe),
		OBJECT(MODEL_NONE, 500, 1500, 0, 0, -90, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(cotmc_area_1_collision),
		MACRO_OBJECTS(cotmc_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_UNDERGROUND),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(2, cotmc_area_2),
		WARP_NODE(3, LEVEL_COTMC, 0x02, 4, WARP_NO_CHECKPOINT),
		WARP_NODE(4, LEVEL_COTMC, 0x01, 3, WARP_NO_CHECKPOINT),
		WARP_NODE(5, LEVEL_COTMC, 0x03, 6, WARP_NO_CHECKPOINT),
		WARP_NODE(6, LEVEL_COTMC, 0x02, 5, WARP_NO_CHECKPOINT),
		WARP_NODE(241, LEVEL_COTMC, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 4250, 2350, 4250, 20, 45, 0, 0x00000000, bhv2dCamera),
		OBJECT(MODEL_FADING_PLATFORM, 1867, 200, -200, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 1667, 200, -200, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 1867, 200, 0, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 1667, 200, 0, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 1867, 200, 200, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 1667, 200, 200, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_NONE, -150, 300, 1800, 0, 0, 0, (1 << 16), bhvOnOffBlock),
		OBJECT(MODEL_NONE, 150, 300, 1800, 0, 0, 0, (1 << 16), bhvOnOffBlock),
		OBJECT(MODEL_ONOFF_SWITCH, -400, 1200, -400, 0, 0, 0, (1 << 16), bhvOnOffButton),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, 3050, 0, 0, 0, -90, 0, (4 << 16), bhvWarpPipe),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, 100, 800, 3027, 0, -90, 0, (5 << 16), bhvWarpPipe),
		TERRAIN(cotmc_area_2_collision),
		MACRO_OBJECTS(cotmc_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_UNDERGROUND),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(3, cotmc_area_3),
		WARP_NODE(5, LEVEL_COTMC, 0x03, 6, WARP_NO_CHECKPOINT),
		WARP_NODE(6, LEVEL_COTMC, 0x02, 5, WARP_NO_CHECKPOINT),
		WARP_NODE(7, LEVEL_COTMC, 0x04, 8, WARP_NO_CHECKPOINT),
		WARP_NODE(241, LEVEL_COTMC, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -2150, 2350, 2150, 20, -45, 0, 0x00000000, bhv2dCamera),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, 2674, -1200, 0, 0, -90, 0, (6 << 16), bhvWarpPipe),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, 0, 1200, -2680, 0, -90, 0, (7 << 16), bhvWarpPipe),
		TERRAIN(cotmc_area_3_collision),
		MACRO_OBJECTS(cotmc_area_3_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_UNDERGROUND),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(4, cotmc_area_4),
		WARP_NODE(7, LEVEL_COTMC, 0x04, 8, WARP_NO_CHECKPOINT),
		WARP_NODE(8, LEVEL_CASTLE, 0x01, 2, WARP_NO_CHECKPOINT),
		WARP_NODE(241, LEVEL_COTMC, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 2700, 1500, 2700, 20, 45, 0, 0x00000000, bhv2dCamera),
		OBJECT(MODEL_SILVER_STAR, 1450, 100, 1450, 0, 0, 0, 0x00000000, bhvSilverStar),
		OBJECT(MODEL_SILVER_STAR_PODIUM, -50, -50, 350, 0, 0, 0, 0x00000000, bhvSilverStarPodium),
		OBJECT(MODEL_SILVER_STAR, -1200, 800, 1200, 0, 0, 0, 0x00000000, bhvSilverStar),
		OBJECT(MODEL_SILVER_STAR, 1500, 600, -1500, 0, 0, 0, 0x00000000, bhvSilverStar),
		OBJECT(MODEL_SILVER_STAR, -1450, 1000, -1450, 0, 0, 0, 0x00000000, bhvSilverStar),
		OBJECT(MODEL_SILVER_STAR, -200, -200, -1450, 0, 0, 0, 0x00000000, bhvSilverStar),
		OBJECT(MODEL_CASTLE_GROUNDS_WARP_PIPE, -350, -400, 350, 0, 90, 0, (8 << 16), bhvWarpPipe),
		TERRAIN(cotmc_area_4_collision),
		MACRO_OBJECTS(cotmc_area_4_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_UNDERGROUND),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 500, 1500, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};