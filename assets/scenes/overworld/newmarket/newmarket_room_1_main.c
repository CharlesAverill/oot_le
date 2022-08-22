#include "ultra64.h"
#include "z64.h"
#include "macros.h"
#include "newmarket_scene.h"

#include "segment_symbols.h"
#include "command_macros_base.h"
#include "z64cutscene_commands.h"
#include "variables.h"

SCmdBase newmarket_room_1_header00[] = {
	SCENE_CMD_ECHO_SETTINGS(0x00),
	SCENE_CMD_ROOM_BEHAVIOR(0x00, 0x00, false, false),
	SCENE_CMD_SKYBOX_DISABLES(false, false),
	SCENE_CMD_TIME_SETTINGS(0xFF, 0xFF, 0),
	SCENE_CMD_MESH(&newmarket_room_1_meshHeader),
	SCENE_CMD_OBJECT_LIST(15, newmarket_room_1_header00_objectList),
	SCENE_CMD_ACTOR_LIST(33, newmarket_room_1_header00_actorList),
	SCENE_CMD_END(),
};

s16 newmarket_room_1_header00_objectList[15] = {
	OBJECT_OS_ANIME,
	OBJECT_AOB,
	OBJECT_AHG,
	OBJECT_CNE,
	OBJECT_BBA,
	OBJECT_BJI,
	OBJECT_BOJ,
	OBJECT_NIW,
	OBJECT_WOOD02,
	OBJECT_MA1,
	OBJECT_DOG,
	OBJECT_KIBAKO2,
	OBJECT_GR,
	OBJECT_MU,
	OBJECT_COB,
};

ActorEntry newmarket_room_1_header00_actorList[33] = {
	{ ACTOR_EN_MA1, 36, -409, 1807, 0, 0, 0, 0xFFFF },
	{ ACTOR_EN_HY, 183, -409, 2249, 0, 59564, 0, 0x078B },
	{ ACTOR_OBJ_MURE, -90, -379, 2257, 0, 0, 0, 0x3324 },
	{ ACTOR_EN_HY, 361, -312, 1700, 0, 53225, 0, 0x078C },
	{ ACTOR_EN_DOG, -306, -409, 2015, 0, 22256, 0, 0x0030 },
	{ ACTOR_EN_HY, 319, -409, 1901, 0, 48658, 0, 0x0087 },
	{ ACTOR_EN_HY, 175, -409, 1686, 0, 38303, 0, 0x078A },
	{ ACTOR_EN_HY, 183, -409, 2119, 0, 40795, 0, 0x0786 },
	{ ACTOR_OBJ_KIBAKO2, -500, -409, 1918, 0x0012, 0, 0, 0x0000 },
	{ ACTOR_EN_NIW_GIRL, -138, -409, 2352, 0x0012, 0, 0, 0x0200 },
	{ ACTOR_EN_HY, 157, -409, 2279, 0, 24158, 0, 0x0784 },
	{ ACTOR_EN_KUSA, -510, -409, 2412, 0, 16384, 0, 0x0000 },
	{ ACTOR_EN_HY, 357, -408, 1860, 0, 56787, 0, 0x0788 },
	{ ACTOR_EN_WOOD02, 186, -409, 1650, 0, 56787, 0, 0xFF02 },
	{ ACTOR_EN_WOOD02, 360, -409, 1640, 0, 56787, 0, 0xFF02 },
	{ ACTOR_EN_WOOD02, -634, -409, 1834, 0, 56787, 0, 0xFF00 },
	{ ACTOR_EN_WOOD02, -634, -409, 1765, 0, 56787, 0, 0xFF01 },
	{ ACTOR_EN_KUSA, 183, -409, 1627, 0, 0, 0, 0x0000 },
	{ ACTOR_EN_TG, -152, -408, 1971, 0, 49152, 0, 0x0000 },
	{ ACTOR_EN_HY, -272, -409, 2128, 0, 22256, 0, 0x0780 },
	{ ACTOR_EN_KUSA, -45, -387, 2237, 0, 0, 0, 0x0000 },
	{ ACTOR_EN_HY, -429, -409, 2050, 0, 15723, 0, 0x0781 },
	{ ACTOR_EN_KUSA, -45, -387, 2306, 0, 0, 0, 0x0000 },
	{ ACTOR_EN_KUSA, -45, -387, 2374, 0, 0, 0, 0x0200 },
	{ ACTOR_EN_KUSA, -430, -409, 2412, 0, 16384, 0, 0x0200 },
	{ ACTOR_EN_HY, -508, -409, 1688, 0, 11057, 0, 0x0782 },
	{ ACTOR_OBJ_KIBAKO2, -224, -408, 2408, 0x0012, 0, 0, 0x0000 },
	{ ACTOR_EN_KUSA, -470, -409, 2412, 0, 16384, 0, 0x0000 },
	{ ACTOR_EN_HY, 373, -408, 2174, 0, 49152, 0, 0x0785 },
	{ ACTOR_EN_KUSA, 210, -409, 1673, 0, 0, 0, 0x0000 },
	{ ACTOR_EN_WOOD02, -615, -409, 1801, 0, 56787, 0, 0xFF00 },
	{ ACTOR_EN_HY, -300, -409, 1690, 0, 0X4000, 0, 0x0003 },
	{ ACTOR_EN_HY, 151, -409, 1643, 0, 4087, 0, 0x0789 },
};

