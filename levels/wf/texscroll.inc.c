void scroll_wf_dl_VISUAL_001_mesh_layer_4_vtx_0() {
	int i = 0;
	int count = 44;
	int height = 32 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(wf_dl_VISUAL_001_mesh_layer_4_vtx_0);

	deltaY = (int)(0.5 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_gfx_mat_wf_dl_PLANETOID_layer1() {
	Gfx *mat = segmented_to_virtual(mat_wf_dl_PLANETOID_layer1);


	shift_t_down(mat, 12, PACK_TILESIZE(0, 1));
	shift_t_down(mat, 17, PACK_TILESIZE(0, 2));

};

void scroll_wf() {
	scroll_wf_dl_VISUAL_001_mesh_layer_4_vtx_0();
	scroll_gfx_mat_wf_dl_PLANETOID_layer1();
};
