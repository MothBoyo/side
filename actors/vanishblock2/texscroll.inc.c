void scroll_gfx_mat_vanishblock2_PATTERN_2() {
	Gfx *mat = segmented_to_virtual(mat_vanishblock2_PATTERN_2);

	shift_s(mat, 9, PACK_TILESIZE(0, 1));

};

void scroll_actor_geo_vanishblock2() {
	scroll_gfx_mat_vanishblock2_PATTERN_2();
};
