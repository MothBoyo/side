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
	LOAD_YAY0(0x06, _group13_yay0SegmentRomStart, _group13_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_10), 
	JUMP_LINK(script_func_global_14), 
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
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(3, LEVEL_BOB, 0x02, 4, WARP_NO_CHECKPOINT),
		MARIO_POS(0x01, 0, 0, 0, 0),
		OBJECT(MODEL_NONE, 0, 0, 0, 0, -90, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(jrb_area_1_collision),
		MACRO_OBJECTS(jrb_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(2, jrb_area_2),
		WARP_NODE(4, LEVEL_JRB, 0x03, 5, WARP_NO_CHECKPOINT),
		WARP_NODE(5, LEVEL_JRB, 0x02, 4, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -6003, 2200, -5426, 20, -155, 0, 0x00000000, bhv2dCamera),
		OBJECT(MODEL_NONE, -964, 150, 0, 0, 0, 0, 0x00000000, bhvFlipswap),
		OBJECT(MODEL_NONE, -3914, 450, 0, 0, 180, 0, 0x00000000, bhvFlipswap),
		OBJECT(MODEL_NONE, -6107, 900, 0, 0, 0, 0, (4 << 16), bhvWarpPipe),
		TERRAIN(jrb_area_2_collision),
		MACRO_OBJECTS(jrb_area_2_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(3, jrb_area_3),
		WARP_NODE(5, LEVEL_JRB, 0x02, 4, WARP_NO_CHECKPOINT),
		WARP_NODE(4, LEVEL_JRB, 0x03, 5, WARP_NO_CHECKPOINT),
		WARP_NODE(6, LEVEL_JRB, 0x03, 7, WARP_NO_CHECKPOINT),
		WARP_NODE(8, LEVEL_JRB, 0x02, 9, WARP_NO_CHECKPOINT),
		WARP_NODE(15, LEVEL_JRB, 0x04, 16, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BREAKABLE_BOX, -525, 1200, -625, 0, 0, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_NONE, 4250, 2350, 4250, 20, 45, 0, 0x00000000, bhv2dCamera),
		OBJECT(MODEL_FADING_PLATFORM, 1867, 200, -200, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 1667, 200, -200, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 1867, 200, 0, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 1667, 200, 0, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 200, 600, 1716, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 200, 600, 1916, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 0, 600, 1716, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 0, 600, 1916, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 1867, 200, 200, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, 1667, 200, 200, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, -200, 600, 1716, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_FADING_PLATFORM, -200, 600, 1916, 0, 0, 0, 0x00000000, bhvFadingPlatform),
		OBJECT(MODEL_NONE, -525, 1225, -625, 0, -90, 0, (6 << 16), bhvFadingWarp),
		OBJECT(MODEL_NONE, -225, 1625, -325, 0, -90, 0, (9 << 16), bhvFadingWarp),
		OBJECT(MODEL_NONE, 100, 800, 3027, 0, -90, 0, (15 << 16), bhvWarpPipe),
		OBJECT(MODEL_NONE, 3050, 0, 0, 0, -90, 0, (5 << 16), bhvWarpPipe),
		TERRAIN(jrb_area_3_collision),
		MACRO_OBJECTS(jrb_area_3_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(4, jrb_area_4),
		WARP_NODE(6, LEVEL_JRB, 0x04, 7, WARP_NO_CHECKPOINT),
		WARP_NODE(8, LEVEL_JRB, 0x03, 9, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 2700, 1400, 2700, 20, 45, 0, 0x00000000, bhv2dCamera),
		OBJECT(MODEL_SILVER_STAR, 1450, 100, 1450, 0, 0, 0, 0x00000000, bhvSilverStar),
		OBJECT(MODEL_SILVER_STAR_PODIUM, -50, -50, 350, 0, 0, 0, 0x00000000, bhvSilverStarPodium),
		OBJECT(MODEL_SILVER_STAR, -1200, 800, 1200, 0, 0, 0, 0x00000000, bhvSilverStar),
		OBJECT(MODEL_SILVER_STAR, 1500, 600, -1500, 0, 0, 0, 0x00000000, bhvSilverStar),
		OBJECT(MODEL_SILVER_STAR, -1450, 1000, -1450, 0, 0, 0, 0x00000000, bhvSilverStar),
		OBJECT(MODEL_SILVER_STAR, -200, -200, -1450, 0, 0, 0, 0x00000000, bhvSilverStar),
		OBJECT(MODEL_NONE, -50, 0, 350, 0, 90, 0, (7 << 16), bhvFadingWarp),
		OBJECT(MODEL_NONE, -350, -375, 350, 0, -90, 0, (8 << 16), bhvFadingWarp),
		TERRAIN(jrb_area_4_collision),
		MACRO_OBJECTS(jrb_area_4_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(5, jrb_area_5),
		WARP_NODE(15, LEVEL_JRB, 0x05, 16, WARP_NO_CHECKPOINT),
		WARP_NODE(16, LEVEL_JRB, 0x03, 15, WARP_NO_CHECKPOINT),
		WARP_NODE(17, LEVEL_JRB, 0x06, 18, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -2150, 3000, 2150, 20, -45, 0, 0x00000000, bhv2dCamera),
		OBJECT(MODEL_NONE, 2674, -1200, 0, 0, -90, 0, (16 << 16), bhvWarpPipe),
		OBJECT(MODEL_NONE, 0, 1200, -2680, 0, -90, 0, (17 << 16), bhvWarpPipe),
		TERRAIN(jrb_area_5_collision),
		MACRO_OBJECTS(jrb_area_5_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_STONE),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),
	AREA(6, jrb_area_6),
		WARP_NODE(15, LEVEL_JRB, 0x05, 16, WARP_NO_CHECKPOINT),
		WARP_NODE(16, LEVEL_JRB, 0x03, 15, WARP_NO_CHECKPOINT),
		WARP_NODE(17, LEVEL_JRB, 0x06, 18, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_BOO, 0, 300, -100, 0, -90, 0, (1), bhvBalconyBigBoo),
		OBJECT(MODEL_NONE, 0, 1500, 2000, 20, 0, 0, 0x00000000, bhv2dCamera),
		OBJECT(MODEL_NONE, 0, 259, -1008, 0, 0, 0, (0 << 16) | (7 << 8) | (1), bhvTriggerByEnemiesKilled),
		OBJECT(MODEL_NONE, 0, 1500, 500, 0, -90, 0, (18 << 16), bhvSpinAirborneWarp),
		TERRAIN(jrb_area_6_collision),
		MACRO_OBJECTS(jrb_area_6_macro_objs),
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