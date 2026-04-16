Vtx bob_dl_Plane_mesh_layer_1_vtx_cull[8] = {
	{{ {-2500, 0, 2500}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-2500, 0, 2500}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-2500, 0, -2500}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-2500, 0, -2500}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {2500, 0, 2500}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {2500, 0, 2500}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {2500, 0, -2500}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {2500, 0, -2500}, 0, {0, 0}, {0, 0, 0, 0} }},
};

Vtx bob_dl_Plane_mesh_layer_1_vtx_0[4] = {
	{{ {-2500, 0, 2500}, 0, {-16, 1008}, {0, 127, 0, 255} }},
	{{ {2500, 0, 2500}, 0, {1008, 1008}, {0, 127, 0, 255} }},
	{{ {2500, 0, -2500}, 0, {1008, -16}, {0, 127, 0, 255} }},
	{{ {-2500, 0, -2500}, 0, {-16, -16}, {0, 127, 0, 255} }},
};

Gfx bob_dl_Plane_mesh_layer_1_tri_0[] = {
	gsSPVertex(bob_dl_Plane_mesh_layer_1_vtx_0 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Gfx mat_bob_dl_f3dlite_material[] = {
	gsSPLightColor(LIGHT_1, 0xFFFFFFFF),
	gsSPLightColor(LIGHT_2, 0x7F7F7FFF),
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_bob_dl_f3dlite_material[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx bob_dl_Plane_mesh_layer_1[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(bob_dl_Plane_mesh_layer_1_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_bob_dl_f3dlite_material),
	gsSPDisplayList(bob_dl_Plane_mesh_layer_1_tri_0),
	gsSPDisplayList(mat_revert_bob_dl_f3dlite_material),
	gsSPEndDisplayList(),
};

Gfx bob_dl_final_revert_mesh_layer_1[] = {
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsDPSetEnvColor(255, 255, 255, 255),
	gsDPSetAlphaCompare(G_AC_NONE),
	gsSPEndDisplayList(),
};

