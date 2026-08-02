void scroll_gfx_mat_sa_dl_BACKGROUND_layer1() {
	Gfx *mat = segmented_to_virtual(mat_sa_dl_BACKGROUND_layer1);


	shift_t(mat, 11, PACK_TILESIZE(0, 1));
	shift_t(mat, 16, PACK_TILESIZE(0, 1));

};

void scroll_sa() {
	scroll_gfx_mat_sa_dl_BACKGROUND_layer1();
};
