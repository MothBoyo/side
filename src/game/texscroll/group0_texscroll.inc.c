#include "actors/group0.h"
#include "actors/outlines/texscroll.inc.c"
#include "actors/flipplane2/texscroll.inc.c"
#include "actors/outlines2/texscroll.inc.c"
#include "actors/flipplane/texscroll.inc.c"
void scroll_textures_group0() {
	scroll_actor_geo_outlines();
	scroll_actor_geo_flipplane2();
	scroll_actor_geo_outlines2();
	scroll_actor_geo_flipplane();
}
