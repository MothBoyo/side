#include "src/game/envfx_snow.h"

const GeoLayout green_platform_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SHADOW(11, 51, 600),
		GEO_OPEN_NODE(),
			GEO_SCALE(LAYER_OPAQUE, 65536),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, green_platform_body_mesh_layer_1_with_revert),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
