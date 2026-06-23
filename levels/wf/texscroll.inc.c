void scroll_wf_dl_VIS_mesh_layer_1_vtx_3() {
	int i = 0;
	int count = 88;
	int width = 256 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(wf_dl_VIS_mesh_layer_1_vtx_3);

	deltaX = (int)(1.0 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_wf_dl_VIS_mesh_layer_1_vtx_8() {
	int i = 0;
	int count = 125;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wf_dl_VIS_mesh_layer_1_vtx_8);

	deltaX = (int)(0.5 * 0x20) % width;
	deltaY = (int)(-0.5 * 0x20) % height;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	currentY += deltaY;
}

void scroll_wf_dl_VIS_2_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 42;
	int width = 32 * 0x20;
	int height = 64 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wf_dl_VIS_2_mesh_layer_1_vtx_0);

	deltaX = (int)(0.5 * 0x20) % width;
	deltaY = (int)(-0.5 * 0x20) % height;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	currentY += deltaY;
}

void scroll_wf_dl_VIS_2_mesh_layer_1_vtx_5() {
	int i = 0;
	int count = 27;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 1.0;
	float frequencyY = 0.5;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(wf_dl_VIS_2_mesh_layer_1_vtx_5);

	deltaX = (int)(0.5 * 0x20) % width;
	deltaY = (int)(amplitudeY * frequencyY * coss((frequencyY * timeY + offsetY) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	currentY += deltaY;	timeY += 1;
}

void scroll_wf_dl_VIS_2_mesh_layer_1_vtx_7() {
	int i = 0;
	int count = 44;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(wf_dl_VIS_2_mesh_layer_1_vtx_7);

	deltaX = (int)(0.5 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_wf_dl_VIS_2_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 48;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 1.0;
	float frequencyY = 0.5;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(wf_dl_VIS_2_mesh_layer_5_vtx_0);

	deltaX = (int)(0.5 * 0x20) % width;
	deltaY = (int)(amplitudeY * frequencyY * coss((frequencyY * timeY + offsetY) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	currentY += deltaY;	timeY += 1;
}

void scroll_wf_dl_VIS_1_mesh_layer_1_vtx_4() {
	int i = 0;
	int count = 27;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 1.0;
	float frequencyY = 0.5;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(wf_dl_VIS_1_mesh_layer_1_vtx_4);

	deltaX = (int)(0.5 * 0x20) % width;
	deltaY = (int)(amplitudeY * frequencyY * coss((frequencyY * timeY + offsetY) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	currentY += deltaY;	timeY += 1;
}

void scroll_wf_dl_VIS_1_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 48;
	int width = 32 * 0x20;
	int height = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	static int currentY = 0;
	int deltaY;
	static int timeY;
	float amplitudeY = 1.0;
	float frequencyY = 0.5;
	float offsetY = 0.0;
	Vtx *vertices = segmented_to_virtual(wf_dl_VIS_1_mesh_layer_5_vtx_0);

	deltaX = (int)(0.5 * 0x20) % width;
	deltaY = (int)(amplitudeY * frequencyY * coss((frequencyY * timeY + offsetY) * (1024 * 16 - 1) / 6.28318530718) * 0x20);

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}
	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
		vertices[i].n.tc[1] += deltaY;
	}
	currentX += deltaX;	currentY += deltaY;	timeY += 1;
}

void scroll_gfx_mat_wf_dl_METAL_FLOOR_2_layer1() {
	Gfx *mat = segmented_to_virtual(mat_wf_dl_METAL_FLOOR_2_layer1);

	shift_s(mat, 15, PACK_TILESIZE(0, 2));
	shift_t(mat, 15, PACK_TILESIZE(0, 2));

};

void scroll_gfx_mat_wf_dl_MAGIC_PLATFORM_layer1() {
	Gfx *mat = segmented_to_virtual(mat_wf_dl_MAGIC_PLATFORM_layer1);


	shift_s(mat, 11, PACK_TILESIZE(0, 1));
	shift_t(mat, 16, PACK_TILESIZE(0, 1));

};

void scroll_gfx_mat_wf_dl_ACID_layer1() {
	Gfx *mat = segmented_to_virtual(mat_wf_dl_ACID_layer1);


	shift_s(mat, 12, PACK_TILESIZE(0, 1));
	shift_t(mat, 17, PACK_TILESIZE(0, 1));

};

void scroll_wf() {
	scroll_wf_dl_VIS_mesh_layer_1_vtx_3();
	scroll_wf_dl_VIS_mesh_layer_1_vtx_8();
	scroll_wf_dl_VIS_2_mesh_layer_1_vtx_0();
	scroll_wf_dl_VIS_2_mesh_layer_1_vtx_5();
	scroll_wf_dl_VIS_2_mesh_layer_1_vtx_7();
	scroll_wf_dl_VIS_2_mesh_layer_5_vtx_0();
	scroll_wf_dl_VIS_1_mesh_layer_1_vtx_4();
	scroll_wf_dl_VIS_1_mesh_layer_5_vtx_0();
	scroll_gfx_mat_wf_dl_METAL_FLOOR_2_layer1();
	scroll_gfx_mat_wf_dl_MAGIC_PLATFORM_layer1();
	scroll_gfx_mat_wf_dl_ACID_layer1();
};
