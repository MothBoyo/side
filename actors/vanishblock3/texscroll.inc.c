void scroll_gfx_mat_vanishblock3_PATTERN3() {
	Gfx *mat = segmented_to_virtual(mat_vanishblock3_PATTERN3);

	shift_s(mat, 9, PACK_TILESIZE(0, 1));

};

void scroll_actor_geo_vanishblock3() {
	scroll_gfx_mat_vanishblock3_PATTERN3();
};
