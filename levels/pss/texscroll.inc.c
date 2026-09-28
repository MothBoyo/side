void scroll_gfx_mat_pss_dl_LAVA_layer1() {
	Gfx *mat = segmented_to_virtual(mat_pss_dl_LAVA_layer1);


	shift_s(mat, 12, PACK_TILESIZE(0, 1));
	shift_t(mat, 17, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_pss_dl_VANISHING_FLOOR_layer1() {
	Gfx *mat = segmented_to_virtual(mat_pss_dl_VANISHING_FLOOR_layer1);


	shift_s(mat, 11, PACK_TILESIZE(0, 1));
	shift_s(mat, 16, PACK_TILESIZE(0, 1));

};

void scroll_pss() {
	scroll_gfx_mat_pss_dl_LAVA_layer1();
	scroll_gfx_mat_pss_dl_VANISHING_FLOOR_layer1();
};
