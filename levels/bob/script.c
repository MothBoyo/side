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
#include "levels/bob/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_bob_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _bob_segment_7SegmentRomStart, _bob_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _generic_yay0SegmentRomStart, _generic_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group11_yay0SegmentRomStart, _group11_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group11_geoSegmentRomStart, _group11_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group13_yay0SegmentRomStart, _group13_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_12), 
	JUMP_LINK(script_func_global_14), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_CHAIN_CHOMP_GATE, bob_geo_000440), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_SEESAW_PLATFORM, bob_geo_000458), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BARS_GRILLS, bob_geo_000470), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bob_area_1),
		WARP_NODE(1, LEVEL_BOB, 0x02, 2, WARP_NO_CHECKPOINT),
		WARP_NODE(2, LEVEL_BOB, 0x01, 1, WARP_NO_CHECKPOINT),
		WARP_NODE(0x00, LEVEL_BOB, 0x08, 8, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_HEART, -2879, 931, -8318, 0, -90, 0, (1 << 16), bhvDoorWarp),
		OBJECT(MODEL_NONE, 5400, 500, -5609, 0, 0, 0, 0x00000000, bhvFlipswap),
		OBJECT(MODEL_NONE, 5338, 2623, 2238, 0, 0, 0, 0x00000000, bhvFlipswap),
		OBJECT(MODEL_NONE, 5038, 3023, 2238, 0, -90, 0, 0x00000000, bhvFlipswap),
		OBJECT(MODEL_NONE, 5438, 3523, 2738, 0, -90, 0, 0x00000000, bhvFlipswap),
		OBJECT(MODEL_NONE, 7855, 1212, -1835, 0, -90, 0, 0x00000000, bhvFlipswap),
		OBJECT(MODEL_NONE, 7855, 1318, 277, 0, -90, 0, 0x00000000, bhvFlipswap),
		OBJECT(MODEL_NONE, 5138, 4023, 2338, 0, -90, 0, 0x00000000, bhvFlipswap),
		OBJECT(MODEL_NONE, 7058, 2600, -9131, 0, -17, 0, 0x00000000, bhvFlipswap),
		OBJECT(MODEL_NONE, 5581, 3100, -8550, 0, -45, 0, 0x00000000, bhvFlipswap),
		OBJECT(MODEL_NONE, 5909, 3600, -7622, 0, -90, 0, 0x00000000, bhvFlipswap),
		OBJECT(MODEL_NONE, 2129, 2060, 2305, 0, 90, 0, 0x00000000, bhvFlipswap),
		OBJECT(MODEL_NONE, 7855, 1257, -823, 0, 90, 0, 0x00000000, bhvFlipswap),
		OBJECT(MODEL_EXCLAMATION_BOX, -5915, -31, -8377, 0, 0, 0, (3 << 16), bhvExclamationBox),
		OBJECT(MODEL_EXCLAMATION_BOX, 494, -323, 1951, 0, 0, 0, (3 << 16), bhvExclamationBox),
		MARIO_POS(0x01, 0, 1500, 200, -7300),
		OBJECT(MODEL_NONE, -4303, 750, -1585, 0, 0, 0, (1 << 16), bhvOnOffBlock),
		OBJECT(MODEL_NONE, -4603, 750, -1585, 0, 0, 0, (1 << 16), bhvOnOffBlock),
		OBJECT(MODEL_NONE, -4303, 750, -1885, 0, 0, 0, (1 << 16), bhvOnOffBlock),
		OBJECT(MODEL_NONE, -4603, 750, -1885, 0, 0, 0, (1 << 16), bhvOnOffBlock),
		OBJECT(MODEL_ONOFF_SWITCH, -2665, 4000, 1370, 0, 0, 0, (1 << 16), bhvOnOffButton),
		OBJECT(MODEL_RED_COIN, -8063, 577, 2291, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, -2211, -50, -6423, 0, 0, 0, (3 << 24), bhvHiddenRedCoinStar),
		OBJECT(MODEL_RED_COIN, -8076, 77, -5502, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 4007, -23, -2049, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 10229, 88, 563, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 2768, -35, 6116, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -3022, 377, 5981, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 2292, -523, 1628, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -9417, -523, -1645, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_STAR, 6930, 4250, -7622, 0, 0, 0, 0x00000000, bhvStar),
		OBJECT(MODEL_STAR, 5043, 6323, 701, 0, 0, 0, (1 << 24), bhvStar),
		OBJECT(MODEL_STAR, -5803, 1800, -2283, 0, 0, 0, (2 << 24), bhvStar),
		OBJECT(MODEL_STAR, -3764, 4831, -9098, 0, 0, 0, (5 << 24), bhvStar),
		OBJECT(MODEL_EXCLAMATION_BOX, 7950, 2150, -10416, 0, 0, 0, 0x00000000, bhvExclamationBox),
		OBJECT(MODEL_NONE, 1500, 200, -7300, 0, 180, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(bob_area_1_collision),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(2, bob_area_2),
		WARP_NODE(1, LEVEL_BOB, 0x02, 2, WARP_NO_CHECKPOINT),
		WARP_NODE(2, LEVEL_BOB, 0x01, 1, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 0, 0, 0, 0, 0, 0, (1 << 16), bhv2dMode),
		OBJECT(MODEL_HEART, 1500, 0, 0, 0, -90, 0, (2 << 16), bhvDoorWarp),
		OBJECT(MODEL_NONE, 100, 1150, -300, 0, 0, 0, 0x00000000, bhvFlipswap),
		OBJECT(MODEL_NONE, -200, 2650, 300, 0, 0, 0, 0x00000000, bhvFlipswap),
		OBJECT(MODEL_NONE, 275, 4250, -300, 0, 0, 0, 0x00000000, bhvFlipswap),
		OBJECT(MODEL_STAR, 1188, 4700, 0, 0, 0, 0, (4 << 24), bhvStar),
		TERRAIN(bob_area_2_collision),
		MACRO_OBJECTS(bob_area_2_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(8, bob_area_8),
		WARP_NODE(0x00, LEVEL_BOB, 0x08, 8, WARP_NO_CHECKPOINT),
		WARP_NODE(8, LEVEL_BOB, 0x08, 8, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_SKEETER, 860, 800, -887, 0, 0, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_SKEETER, 824, 400, 326, 0, -54, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_SKEETER, -824, 400, -815, 0, 19, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_SKEETER, 299, 400, 923, 0, -154, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_NONE, -600, 1000, 600, 0, 0, 0, (8 << 16), bhvSpinAirborneWarp),
		TERRAIN(bob_area_8_collision),
		MACRO_OBJECTS(bob_area_8_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 1500, 200, -7300),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};