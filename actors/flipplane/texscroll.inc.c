void scroll_gfx_mat_flipplane_f3dlite_material_002_layer1() {
	Gfx *mat = segmented_to_virtual(mat_flipplane_f3dlite_material_002_layer1);

	shift_t(mat, 16, PACK_TILESIZE(0, 3));

};

void scroll_actor_geo_flipplane() {
	scroll_gfx_mat_flipplane_f3dlite_material_002_layer1();
};
