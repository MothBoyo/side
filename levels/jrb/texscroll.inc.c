void scroll_jrb_dl_Plane_003_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 119;
	int width = 256 * 0x20;

	static int currentX = 0;
	int deltaX;
	Vtx *vertices = segmented_to_virtual(jrb_dl_Plane_003_mesh_layer_1_vtx_0);

	deltaX = (int)(1.0 * 0x20) % width;

	if (absi(currentX) > width) {
		deltaX -= (int)(absi(currentX) / width) * width * signum_positive(deltaX);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[0] += deltaX;
	}
	currentX += deltaX;
}

void scroll_jrb() {
	scroll_jrb_dl_Plane_003_mesh_layer_1_vtx_0();
};
