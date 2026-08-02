void scroll_gfx_mat_vanishblock_PATTERN() {
	Gfx *mat = segmented_to_virtual(mat_vanishblock_PATTERN);

	shift_s(mat, 9, PACK_TILESIZE(0, 1));

};

void scroll_actor_geo_vanishblock() {
	scroll_gfx_mat_vanishblock_PATTERN();
};
