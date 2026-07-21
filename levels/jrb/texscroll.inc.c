void scroll_jrb_dl_VISUAL_001_mesh_layer_1_vtx_8() {
	int i = 0;
	int count = 9;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(jrb_dl_VISUAL_001_mesh_layer_1_vtx_8);

	deltaY = (int)(1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_jrb_dl_VISUAL_002_mesh_layer_1_vtx_9() {
	int i = 0;
	int count = 9;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(jrb_dl_VISUAL_002_mesh_layer_1_vtx_9);

	deltaY = (int)(1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_jrb_dl_VISUAL_004_mesh_layer_1_vtx_3() {
	int i = 0;
	int count = 32;
	int height = 256 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(jrb_dl_VISUAL_004_mesh_layer_1_vtx_3);

	deltaY = (int)(0.5 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_gfx_mat_jrb_dl_ACID_layer1() {
	Gfx *mat = segmented_to_virtual(mat_jrb_dl_ACID_layer1);


	shift_s(mat, 12, PACK_TILESIZE(0, 1));
	shift_t(mat, 17, PACK_TILESIZE(0, 1));

};

void scroll_jrb() {
	scroll_jrb_dl_VISUAL_001_mesh_layer_1_vtx_8();
	scroll_jrb_dl_VISUAL_002_mesh_layer_1_vtx_9();
	scroll_jrb_dl_VISUAL_004_mesh_layer_1_vtx_3();
	scroll_gfx_mat_jrb_dl_ACID_layer1();
};
