void scroll_gfx_mat_bitfs_dl_BACKGROUND_layer1() {
	Gfx *mat = segmented_to_virtual(mat_bitfs_dl_BACKGROUND_layer1);


	shift_s(mat, 14, PACK_TILESIZE(0, 1));
	shift_t(mat, 19, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_bitfs_dl_WALL__MARBLE_BRICK_layer1() {
	Gfx *mat = segmented_to_virtual(mat_bitfs_dl_WALL__MARBLE_BRICK_layer1);

	shift_t_down(mat, 20, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_bitfs_dl_WALL_MARBLE_BRICK__FADE_OUT__layer5() {
	Gfx *mat = segmented_to_virtual(mat_bitfs_dl_WALL_MARBLE_BRICK__FADE_OUT__layer5);

	shift_t_down(mat, 20, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_bitfs_dl_BURNING_layer1() {
	Gfx *mat = segmented_to_virtual(mat_bitfs_dl_BURNING_layer1);


	shift_s(mat, 12, PACK_TILESIZE(0, 1));
	shift_t(mat, 17, PACK_TILESIZE(0, 1));

};

void scroll_bitfs() {
	scroll_gfx_mat_bitfs_dl_BACKGROUND_layer1();
	scroll_gfx_mat_bitfs_dl_WALL__MARBLE_BRICK_layer1();
	scroll_gfx_mat_bitfs_dl_WALL_MARBLE_BRICK__FADE_OUT__layer5();
	scroll_gfx_mat_bitfs_dl_BURNING_layer1();
};
