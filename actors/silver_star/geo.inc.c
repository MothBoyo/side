#include "src/game/envfx_snow.h"

const GeoLayout silver_star_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SHADOW(1, 77, 100),
		GEO_OPEN_NODE(),
			GEO_ASM(0, silver_star_size_func),
			GEO_SCALE(LAYER_OPAQUE, 65536),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, silver_star_000_body_mesh_layer_1_with_revert),
			GEO_CLOSE_NODE(),
			GEO_BILLBOARD_WITH_PARAMS_AND_DL(LAYER_TRANSPARENT, 0, 0, 0, silver_star_billboard_mesh_layer_5_with_revert),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
