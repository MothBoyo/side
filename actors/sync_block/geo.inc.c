#include "src/game/envfx_snow.h"

const GeoLayout sync_block_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, NULL),
		GEO_OPEN_NODE(),
			GEO_ASM(0, sync_block_color),
			GEO_ANIMATED_PART(LAYER_OPAQUE, 0, 0, 0, sync_block_000_body_mesh_layer_1_with_revert),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_TRANSPARENT, sync_block_000_body_mesh_layer_5_with_revert),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
