void scroll_bob_dl_VISUAL_mesh_layer_5_vtx_1() {
	int i = 0;
	int count = 433;
	int height = 256 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bob_dl_VISUAL_mesh_layer_5_vtx_1);

	deltaY = (int)(3.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_gfx_mat_bob_dl_SAND_layer1() {
	Gfx *mat = segmented_to_virtual(mat_bob_dl_SAND_layer1);


	shift_s(mat, 11, PACK_TILESIZE(0, 1));
	shift_t(mat, 16, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_bob_dl_SAND__FADE_OUT__layer5() {
	Gfx *mat = segmented_to_virtual(mat_bob_dl_SAND__FADE_OUT__layer5);


	shift_s(mat, 11, PACK_TILESIZE(0, 1));
	shift_t(mat, 16, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_bob_dl_LAVA_layer1() {
	Gfx *mat = segmented_to_virtual(mat_bob_dl_LAVA_layer1);


	shift_s(mat, 12, PACK_TILESIZE(0, 1));
	shift_t(mat, 17, PACK_TILESIZE(0, 1));

};

void scroll_bob() {
	scroll_bob_dl_VISUAL_mesh_layer_5_vtx_1();
	scroll_gfx_mat_bob_dl_SAND_layer1();
	scroll_gfx_mat_bob_dl_SAND__FADE_OUT__layer5();
	scroll_gfx_mat_bob_dl_LAVA_layer1();
};
