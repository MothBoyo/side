#include <ultra64.h>
#include "sm64.h"
#include "surface_terrains.h"
#include "geo_commands.h"

#include "make_const_nonconst.h"

// Note: This bin does not use bin IDs, unlike the other segmented bins.
#include "mario/model.inc.c"

#include "bubble/model.inc.c"

#include "walk_smoke/model.inc.c"

#include "burn_smoke/model.inc.c"

#include "small_water_splash/model.inc.c"

#include "water_wave/model.inc.c"

#include "sparkle/model.inc.c"

#include "water_splash/model.inc.c"

#include "white_particle_small/model.inc.c"

#include "sparkle_animation/model.inc.c"

#ifdef S2DEX_TEXT_ENGINE
#include "src/s2d_engine/s2d_config.h"
#include FONT_C_FILE
#endif

#include "flipplane/model.inc.c"
#include "flipplane/collision.inc.c"
#include "outlines/model.inc.c"
#include "outlines2/model.inc.c"
#include "flipplane2/model.inc.c"
#include "flipplane2/collision.inc.c"

#include "fading_platform/collision.inc.c"
#include "fading_platform/model.inc.c"

#include "sync_block/model.inc.c"
#include "sync_block/collision.inc.c"

#include "interactive_tablet/model.inc.c"
#include "interactive_tablet/collision.inc.c"
#include "interactive_tablet_podium/collision.inc.c"
#include "interactive_tablet_podium/model.inc.c"

#include "noteblock/collision.inc.c"
#include "noteblock/model.inc.c"

#include "onoffcol/collision.inc.c"
#include "onoffswitch/model.inc.c"
#include "onoffsolid/collision.inc.c"
#include "onoffsolid/model.inc.c"
#include "onoffhollow/model.inc.c"
#include "onoffexclamation/model.inc.c"

#include "silver_star_podium/model.inc.c"
#include "silver_star/model.inc.c"
#include "silver_star/anims/data.inc.c"
#include "silver_star/anims/table.inc.c"

#include "flipswap_edge/model.inc.c"
#include "flipswap_inside/model.inc.c"
#include "flipswap_inside/collision.inc.c"
