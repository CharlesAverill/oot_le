#include "ultra64.h"
#include "z64.h"
#include "macros.h"
#include "newmarket_scene.h"

#include "segment_symbols.h"
#include "command_macros_base.h"
#include "z64cutscene_commands.h"
#include "variables.h"

SCmdBase newmarket_room_2_header00[] = {
	SCENE_CMD_ECHO_SETTINGS(0x00),
	SCENE_CMD_ROOM_BEHAVIOR(0x00, 0x00, false, false),
	SCENE_CMD_SKYBOX_DISABLES(false, false),
	SCENE_CMD_TIME_SETTINGS(0xFF, 0xFF, 0),
	SCENE_CMD_MESH(&newmarket_room_2_meshHeader),
	SCENE_CMD_OBJECT_LIST(13, newmarket_room_2_header00_objectList),
	SCENE_CMD_ACTOR_LIST(31, newmarket_room_2_header00_actorList),
	SCENE_CMD_END(),
};

s16 newmarket_room_2_header00_objectList[13] = {
	OBJECT_WOOD02,
	OBJECT_OS_ANIME,
	OBJECT_AOB,
	OBJECT_AHG,
	OBJECT_CNE,
	OBJECT_BJI,
	OBJECT_BOJ,
	OBJECT_BBA,
	OBJECT_NIW,
	OBJECT_MA1,
	OBJECT_DOG,
	OBJECT_KIBAKO2,
	OBJECT_SD,
};

ActorEntry newmarket_room_2_header00_actorList[31] = {
	{ ACTOR_EN_HY, 1016, -408, 2431, 0, 49152, 0, 0x178D },
	{ ACTOR_EN_HY, 360, -311, 1695, 0, 53225, 0, 0x078C },
	{ ACTOR_EN_WOOD02, -632, -408, 1829, 0, 56787, 0, 0xFF20 },
	{ ACTOR_EN_KUSA, -45, -386, 2367, 0, 1, 0, 0xFF30 },
	{ ACTOR_EN_HY, 175, -408, 1681, 0, 38303, 0, 0x178A },
	{ ACTOR_EN_RIVER_SOUND, 1192, -408, 2041, 0, 49152, 0, 0x000B },
	{ ACTOR_EN_KUSA, -429, -408, 2405, 0, 16384, 0, 0xFF40 },
	{ ACTOR_EN_WOOD02, 1251, -408, 2328, 0, 49152, 0, 0xFF52 },
	{ ACTOR_EN_KUSA, -469, -408, 2405, 0, 16384, 0, 0xFF50 },
	{ ACTOR_EN_WOOD02, 1220, -408, 1693, 0, 49152, 0, 0xFF02 },
	{ ACTOR_EN_KUSA, -508, -408, 2405, 0, 16384, 0, 0xFF60 },
	{ ACTOR_EN_WOOD02, -632, -408, 1760, 0, 56787, 0, 0xFF71 },
	{ ACTOR_EN_HY, 156, -408, 2272, 0, 24158, 0, 0x1784 },
	{ ACTOR_EN_WOOD02, 707, -408, 2446, 0, 49152, 0, 0xFF42 },
	{ ACTOR_OBJ_KIBAKO2, -498, -408, 1797, 0x0012, 0, 0, 0x0000 },
	{ ACTOR_OBJ_KIBAKO2, -223, -407, 2400, 0x0012, 0, 0, 0x0001 },
	{ ACTOR_EN_KUSA, -45, -386, 2230, 0, 1, 0, 0xFF10 },
	{ ACTOR_OBJ_KIBAKO2, 121, -407, 2400, 0x0012, 0, 0, 0x0002 },
	{ ACTOR_EN_KUSA, -45, -386, 2299, 0, 1, 0, 0xFF20 },
	{ ACTOR_EN_HY, 1271, -408, 2055, 0, 49152, 0, 0x078E },
	{ ACTOR_OBJ_MURE, -90, -378, 2250, 0, 0, 0, 0x3324 },
	{ ACTOR_EN_HY, 777, -408, 1568, 0, 32768, 0, 0x178F },
	{ ACTOR_EN_HEISHI4, 1095, -408, 2200, 0, 16384, 0, 0xFF07 },
	{ ACTOR_EN_KUSA, 182, -408, 1622, 0, 0, 0, 0xFF70 },
	{ ACTOR_EN_KUSA, 209, -408, 1668, 0, 0, 0, 0xFF80 },
	{ ACTOR_EN_WOOD02, 185, -408, 1645, 0, 56787, 0, 0xFF32 },
	{ ACTOR_EN_HY, 150, -408, 1638, 0, 4087, 0, 0x1789 },
	{ ACTOR_EN_WOOD02, 359, -408, 1635, 0, 56787, 0, 0xFF62 },
	{ ACTOR_EN_HY, 183, -408, 2243, 0, 59564, 0, 0x178B },
	{ ACTOR_EN_WOOD02, -613, -408, 1795, 0, 56787, 0, 0xFF10 },
	{ ACTOR_EN_HY, -507, -408, 1683, 0, 11057, 0, 0x1782 },
};

