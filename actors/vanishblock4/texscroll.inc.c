void scroll_gfx_mat_vanishblock4_PATTERN4() {
	Gfx *mat = segmented_to_virtual(mat_vanishblock4_PATTERN4);

	shift_s(mat, 9, PACK_TILESIZE(0, 1));

};

void scroll_actor_geo_vanishblock4() {
	scroll_gfx_mat_vanishblock4_PATTERN4();
};
