#include "actors/group0.h"
#include "actors/outlines/texscroll.inc.c"
#include "actors/flipplane2/texscroll.inc.c"
#include "actors/outlines2/texscroll.inc.c"
#include "actors/flipplane/texscroll.inc.c"
#include "actors/vanishblock4/texscroll.inc.c"
#include "actors/vanishblock3/texscroll.inc.c"
#include "actors/vanishblock2/texscroll.inc.c"
#include "actors/vanishblock/texscroll.inc.c"
void scroll_textures_group0() {
	scroll_actor_geo_outlines();
	scroll_actor_geo_flipplane2();
	scroll_actor_geo_outlines2();
	scroll_actor_geo_flipplane();
	scroll_actor_geo_vanishblock4();
	scroll_actor_geo_vanishblock3();
	scroll_actor_geo_vanishblock2();
	scroll_actor_geo_vanishblock();
}
