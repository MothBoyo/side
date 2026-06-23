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
	LOAD_YAY0(0x05, _group2_yay0SegmentRomStart, _group2_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group2_geoSegmentRomStart, _group2_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group17_yay0SegmentRomStart, _group17_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group17_geoSegmentRomStart, _group17_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_3), 
	JUMP_LINK(script_func_global_18), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_CHAIN_CHOMP_GATE, bob_geo_000440), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_SEESAW_PLATFORM, bob_geo_000458), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BARS_GRILLS, bob_geo_000470), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bob_area_1),
		WARP_NODE(1, LEVEL_BOB, 0x02, 2, WARP_NO_CHECKPOINT),
		WARP_NODE(2, LEVEL_BOB, 0x01, 1, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_BOB, 0x03, 4, WARP_NO_CHECKPOINT),
		WARP_NODE(4, LEVEL_BOB, 0x01, 3, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BREAKABLE_BOX, -3777, 3220, -4938, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -3777, 3120, -4738, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -3777, 3320, -5138, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -3777, 3320, -5338, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_BREAKABLE_BOX, -3777, 3120, -4538, 0, 0, 0, 0x00000000, bhvHiddenObject),
		OBJECT(MODEL_PURPLE_SWITCH, -4718, 5720, -1231, 0, 0, 0, 0x00000000, bhvFloorSwitchHiddenObjects),
		OBJECT(MODEL_NONE, 80, 1386, 2979, 0, 0, 0, 0x00000000, bhvFlipswap),
		MARIO_POS(0x01, 0, 0, 200, 0),
		OBJECT(MODEL_NONE, -6956, 1850, 5854, 0, 0, 0, 0x00000000, bhvOnOffBlock),
		OBJECT(MODEL_NONE, -8456, 2950, 4854, 0, 0, 0, (1 << 16), bhvOnOffBlock),
		OBJECT(MODEL_NONE, -6456, 750, 7854, 0, 0, 0, (1 << 16), bhvOnOffBlock),
		OBJECT(MODEL_ONOFF_SWITCH, -7956, 900, 7354, 0, 0, 0, 0x00000000, bhvOnOffButton),
		OBJECT(MODEL_ONOFF_SWITCH, -6456, 4100, 4354, 0, 0, 0, (1 << 16), bhvOnOffButton),
		OBJECT(MODEL_ONOFF_SWITCH, -5956, -600, 7854, 0, 0, 0, (1 << 16), bhvOnOffButton),
		OBJECT(MODEL_EXCLAMATION_BOX, 2069, 1100, 1643, 0, 0, 0, (3 << 16), bhvExclamationBox),
		OBJECT(MODEL_SILVER_STAR, -1757, 748, 8626, 0, 0, 0, 0x00000000, bhvSilverStar),
		OBJECT(MODEL_SILVER_STAR_PODIUM, -3554, -300, 5236, 0, 0, 0, 0x00000000, bhvSilverStarPodium),
		OBJECT(MODEL_SILVER_STAR, 11378, -625, 6790, 0, 0, 0, 0x00000000, bhvSilverStar),
		OBJECT(MODEL_SILVER_STAR, 1972, 400, 953, 0, 0, 0, 0x00000000, bhvSilverStar),
		OBJECT(MODEL_SILVER_STAR, -8522, -800, 5794, 0, 0, 0, 0x00000000, bhvSilverStar),
		OBJECT(MODEL_SILVER_STAR, -1734, -625, 8612, 0, 0, 0, 0x00000000, bhvSilverStar),
		OBJECT(MODEL_NONE, 4356, 3813, -4292, 0, 0, 0, (3 << 16), bhvWarp),
		OBJECT(MODEL_NONE, 5335, 2361, 1137, 0, 0, 0, (1 << 16), bhvWarpPipe),
		OBJECT(MODEL_NONE, 4490, 615, 12214, 0, -90, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(bob_area_1_collision),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(2, bob_area_2),
		WARP_NODE(2, LEVEL_BOB, 0x01, 1, WARP_NO_CHECKPOINT),
		WARP_NODE(1, LEVEL_BOB, 0x02, 2, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_AMP, 3612, 2618, -3559, 0, 0, 0, (1 << 16), bhvCirclingAmp),
		OBJECT(MODEL_AMP, -1736, 875, -100, 0, 0, 0, (3 << 16), bhvCirclingAmp),
		OBJECT(MODEL_AMP, -153, -1374, 1417, 0, 0, 0, (3 << 16), bhvCirclingAmp),
		OBJECT(MODEL_AMP, 2778, 2358, -1333, 0, 0, 0, (3 << 16), bhvCirclingAmp),
		OBJECT(MODEL_BOWLING_BALL, -2388, -1818, 4440, 0, 0, 0, 0x00000000, bhvFireSpitter),
		OBJECT(MODEL_BOWLING_BALL, 2471, 3319, 1793, 0, 0, 0, 0x00000000, bhvFireSpitter),
		OBJECT(MODEL_RED_COIN, -4321, -406, -1851, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, 2442, 400, -153, 0, 0, 0, (3 << 24), bhvHiddenRedCoinStar),
		OBJECT(MODEL_RED_COIN, -2878, -618, 4930, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3371, 4119, 2693, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3612, 2918, -3559, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -2760, 1393, 2510, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 0, 1796, -2634, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -5722, -1174, 1753, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 6414, 1153, -1042, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, 2442, 0, 247, 0, -180, 0, (2 << 16), bhvWarpPipe),
		TERRAIN(bob_area_2_collision),
		MACRO_OBJECTS(bob_area_2_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(3, bob_area_3),
		WARP_NODE(3, LEVEL_BOB, 0x03, 4, WARP_NO_CHECKPOINT),
		WARP_NODE(4, LEVEL_BOB, 0x01, 3, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BULLY, -3194, 1000, -511, 0, 0, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_BULLY, -804, 61, -2895, 0, 0, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_BULLY, 1903, 1494, -1520, 0, 0, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_BULLY, 1202, 1094, -2453, 0, 0, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_BULLY, 3079, 400, -2632, 0, 0, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_BULLY, 2114, -200, -3479, 0, 0, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_BULLY, -481, -200, 3327, 0, 0, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_BULLY, -1804, 1200, 3109, 0, 0, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_BULLY, 3028, -200, 1645, 0, 0, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_BULLY, -3883, -200, 811, 0, 0, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_BULLY, -3358, -200, -2364, 0, 0, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_BULLY, 4560, -200, -978, 0, 0, 0, 0x00000000, bhvSmallBully),
		OBJECT(MODEL_NONE, -3877, -200, -1744, 0, -23, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, 4241, -200, 390, 0, -18, 0, 0x00000000, bhvCoinFormation),
		OBJECT(MODEL_NONE, -804, 61, -2895, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 1202, 1094, -2453, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -3194, 1000, -511, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, -2480, 1000, 2739, 0, 0, 0, (2 << 16), bhvCoinFormation),
		OBJECT(MODEL_NONE, 0, 0, 0, 0, 0, 0, (2 << 24) | (0 << 16) | (10 << 8), bhvTriggerByEnemiesKilled),
		OBJECT(MODEL_NONE, 0, 0, 0, 0, 0, 0, (4 << 16), bhvWarpPipe),
		TERRAIN(bob_area_3_collision),
		MACRO_OBJECTS(bob_area_3_macro_objs),
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