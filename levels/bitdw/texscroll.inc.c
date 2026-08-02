void scroll_bitdw_dl_Sphere_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 253;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bitdw_dl_Sphere_mesh_layer_1_vtx_0);

	deltaY = (int)(0.5 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bitdw_dl_Sphere_mesh_layer_4_vtx_1() {
	int i = 0;
	int count = 14;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bitdw_dl_Sphere_mesh_layer_4_vtx_1);

	deltaY = (int)(1.0 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bitdw_dl_VISUAL_mesh_layer_1_vtx_9() {
	int i = 0;
	int count = 28;
	int width = 32 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(bitdw_dl_VISUAL_mesh_layer_1_vtx_9);

	deltaX = (int)(3.0 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_bitdw_dl_VISUAL_mesh_layer_5_vtx_0() {
	int i = 0;
	int count = 64;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bitdw_dl_VISUAL_mesh_layer_5_vtx_0);

	deltaY = (int)(0.5 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bitdw() {
	scroll_bitdw_dl_Sphere_mesh_layer_1_vtx_0();
	scroll_bitdw_dl_Sphere_mesh_layer_4_vtx_1();
	scroll_bitdw_dl_VISUAL_mesh_layer_1_vtx_9();
	scroll_bitdw_dl_VISUAL_mesh_layer_5_vtx_0();
};
