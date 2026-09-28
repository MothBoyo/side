void scroll_bitfs_dl_VISUAL_mesh_layer_1_vtx_10() {
	int i = 0;
	int count = 48;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(bitfs_dl_VISUAL_mesh_layer_1_vtx_10);

	deltaX = (int)(0.25 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_bitfs_dl_VISUAL_002_mesh_layer_1_vtx_11() {
	int i = 0;
	int count = 52;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(bitfs_dl_VISUAL_002_mesh_layer_1_vtx_11);

	deltaX = (int)(0.25 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

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
	scroll_bitfs_dl_VISUAL_mesh_layer_1_vtx_10();
	scroll_bitfs_dl_VISUAL_002_mesh_layer_1_vtx_11();
	scroll_gfx_mat_bitfs_dl_WALL__MARBLE_BRICK_layer1();
	scroll_gfx_mat_bitfs_dl_WALL_MARBLE_BRICK__FADE_OUT__layer5();
	scroll_gfx_mat_bitfs_dl_BURNING_layer1();
};
