void scroll_gfx_mat_bob_dl_WATER_SURFACE_layer5() {
	Gfx *mat = segmented_to_virtual(mat_bob_dl_WATER_SURFACE_layer5);


	shift_s(mat, 12, PACK_TILESIZE(0, 1));
	shift_t(mat, 17, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_bob_dl_ABSTRACT_layer1() {
	Gfx *mat = segmented_to_virtual(mat_bob_dl_ABSTRACT_layer1);


	shift_s(mat, 16, PACK_TILESIZE(0, 1));
	shift_t(mat, 21, PACK_TILESIZE(0, 1));

};

void scroll_bob() {
	scroll_gfx_mat_bob_dl_WATER_SURFACE_layer5();
	scroll_gfx_mat_bob_dl_ABSTRACT_layer1();
};
