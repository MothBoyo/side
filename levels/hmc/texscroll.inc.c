void scroll_hmc_dl_VISUAL_001_mesh_layer_1_vtx_13() {
	int i = 0;
	int count = 201;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(hmc_dl_VISUAL_001_mesh_layer_1_vtx_13);

	deltaY = (int)(-0.25 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_hmc_dl_VISUAL_001_mesh_layer_4_vtx_0() {
	int i = 0;
	int count = 38;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(hmc_dl_VISUAL_001_mesh_layer_4_vtx_0);

	deltaY = (int)(0.5 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_gfx_mat_hmc_dl_ACID_layer1() {
	Gfx *mat = segmented_to_virtual(mat_hmc_dl_ACID_layer1);


	shift_s(mat, 12, PACK_TILESIZE(0, 1));
	shift_t(mat, 17, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_hmc_dl__7th_STAR_ABSTRACT_layer1() {
	Gfx *mat = segmented_to_virtual(mat_hmc_dl__7th_STAR_ABSTRACT_layer1);


	shift_s(mat, 12, PACK_TILESIZE(0, 1));
	shift_t(mat, 17, PACK_TILESIZE(0, 1));

};

void scroll_hmc() {
	scroll_hmc_dl_VISUAL_001_mesh_layer_1_vtx_13();
	scroll_hmc_dl_VISUAL_001_mesh_layer_4_vtx_0();
	scroll_gfx_mat_hmc_dl_ACID_layer1();
	scroll_gfx_mat_hmc_dl__7th_STAR_ABSTRACT_layer1();
};
