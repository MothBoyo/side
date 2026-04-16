#include "src/game/envfx_snow.h"

const GeoLayout fading_platform_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, -10, 0, fading_platform_root_mesh_layer_1),
		GEO_OPEN_NODE(),
			GEO_ASM(0, fading_platform_scale),
			GEO_SCALE(LAYER_OPAQUE, 65536),
			GEO_OPEN_NODE(),
				GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 10, 0, fading_platform_body_mesh_layer_1_with_revert),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
