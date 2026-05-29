#include "src/game/envfx_snow.h"

const GeoLayout flipswap_edge_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, flipswap_edge_edge_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, flipswap_edge_final_revert_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
