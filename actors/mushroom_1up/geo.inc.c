#include "src/game/envfx_snow.h"

const GeoLayout mushroom_1up_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_ALPHA, mushroom_1up_Plane_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_ALPHA, mushroom_1up_final_revert_mesh_layer_4),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
