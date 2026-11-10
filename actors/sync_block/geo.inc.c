#include "src/game/envfx_snow.h"

const GeoLayout sync_block_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sync_block_sync_block_frame_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, sync_block_final_revert_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
