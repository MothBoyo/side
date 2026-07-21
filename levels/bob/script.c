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
	LOAD_YAY0(0x06, _group14_yay0SegmentRomStart, _group14_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group14_geoSegmentRomStart, _group14_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_12), 
	JUMP_LINK(script_func_global_15), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BUBBLY_TREE, bubbly_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_CHAIN_CHOMP_GATE, bob_geo_000440), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_SEESAW_PLATFORM, bob_geo_000458), 
	LOAD_MODEL_FROM_GEO(MODEL_BOB_BARS_GRILLS, bob_geo_000470), 
	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, bob_area_1),
		INSTANT_WARP(0x00, 0x02, 8619, -2560, 596),
		INSTANT_WARP(0x01, 0x01, -8619, 2560, -596),
		OBJECT(MODEL_FADING_PLATFORM, -7242, 3210, 157, 0, -45, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, -8591, 3710, -538, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, -9810, 4210, 237, 0, -135, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, -9810, 4705, 237, 0, -135, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, -8591, 5196, -338, 0, -90, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_NONE, 4812, 2678, 7709, 0, 37, 0, 0x00000000, bhvFlipswap),
		OBJECT(MODEL_NONE, 6859, 2978, 5458, 0, -96, 0, 0x00000000, bhvFlipswap),
		OBJECT(MODEL_KOOPA_FLAG, 3337, 2657, -4770, 0, 0, 0, 0x00000000, bhvKoopaFlag),
		OBJECT(MODEL_KOOPA_FLAG, 2566, 2528, 9273, 0, 0, 0, 0x00000000, bhvKoopaFlag),
		OBJECT(MODEL_SILVER_STAR, -4271, 550, 7658, 0, 0, 0, 0x00000000, bhvSilverStar),
		OBJECT(MODEL_SILVER_STAR_PODIUM, -9733, 4060, 4380, 0, 0, 0, 0x00000000, bhvSilverStarPodium),
		OBJECT(MODEL_SILVER_STAR, -3258, 950, 5766, 0, 0, 0, 0x00000000, bhvSilverStar),
		OBJECT(MODEL_SILVER_STAR, -6341, 1230, 7312, 0, 0, 0, 0x00000000, bhvSilverStar),
		OBJECT(MODEL_SILVER_STAR, -6111, 1910, 5515, 0, 0, 0, 0x00000000, bhvSilverStar),
		OBJECT(MODEL_SILVER_STAR, -4811, 1350, 295, 0, 0, 0, 0x00000000, bhvSilverStar),
		TERRAIN(bob_area_1_collision),
		MACRO_OBJECTS(bob_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(2, bob_area_2),
		INSTANT_WARP(0x00, 0x02, 8619, -2560, 596),
		INSTANT_WARP(0x01, 0x01, -8619, 2560, -596),
		OBJECT(MODEL_FADING_PLATFORM, -1647, 1450, -1146, 0, -30, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 1647, 1450, -1146, 0, 30, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, -1668, 1950, 1143, 0, 30, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 1668, 1950, 1143, 0, -30, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, -1668, 3250, 1143, 0, 30, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 1668, 3250, 1143, 0, -30, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_NONE, 0, 900, -1688, 0, 90, 0, 0x00000000, bhvFlipswap),
		OBJECT(MODEL_NONE, 1247, 3750, -1224, 0, 60, 0, 0x00000000, bhvFlipswap),
		OBJECT(MODEL_NONE, -1247, 3750, -1224, 0, 120, 0, 0x00000000, bhvFlipswap),
		OBJECT(MODEL_KOOPA_FLAG, 0, 600, 0, 0, 0, 0, 0x00000000, bhvKoopaFlag),
		OBJECT(MODEL_NOTEBLOCK, 0, 2200, 2025, 0, 0, 0, 0x00000000, bhvNoteblock),
		TERRAIN(bob_area_2_collision),
		MACRO_OBJECTS(bob_area_2_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	FREE_LEVEL_POOL(),
	MARIO_POS(1, 0, 0, 0, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};