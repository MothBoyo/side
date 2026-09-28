void scroll_gfx_mat_cotmc_dl_ACID_layer1() {
	Gfx *mat = segmented_to_virtual(mat_cotmc_dl_ACID_layer1);


	shift_s(mat, 12, PACK_TILESIZE(0, 1));
	shift_t(mat, 17, PACK_TILESIZE(0, 1));

};

void scroll_cotmc() {
	scroll_gfx_mat_cotmc_dl_ACID_layer1();
};
