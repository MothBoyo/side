void scroll_gfx_mat_ccm_dl_ABSTRACT_layer1() {
	Gfx *mat = segmented_to_virtual(mat_ccm_dl_ABSTRACT_layer1);


	shift_s_down(mat, 15, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 20, PACK_TILESIZE(0, 1));

};

void scroll_ccm() {
	scroll_gfx_mat_ccm_dl_ABSTRACT_layer1();
};
