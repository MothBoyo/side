void scroll_gfx_mat_castle_inside_dl_ABSTRACT_layer1() {
	Gfx *mat = segmented_to_virtual(mat_castle_inside_dl_ABSTRACT_layer1);


	shift_s(mat, 16, PACK_TILESIZE(0, 1));
	shift_t(mat, 21, PACK_TILESIZE(0, 1));

};

void scroll_castle_inside() {
	scroll_gfx_mat_castle_inside_dl_ABSTRACT_layer1();
};
