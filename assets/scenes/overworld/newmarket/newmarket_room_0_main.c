#include "ultra64.h"
#include "z64.h"
#include "macros.h"
#include "newmarket_scene.h"

#include "segment_symbols.h"
#include "command_macros_base.h"
#include "z64cutscene_commands.h"
#include "variables.h"

SCmdBase newmarket_room_0_header00[] = {
	SCENE_CMD_ECHO_SETTINGS(0x00),
	SCENE_CMD_ROOM_BEHAVIOR(0x00, 0x00, false, false),
	SCENE_CMD_SKYBOX_DISABLES(false, false),
	SCENE_CMD_TIME_SETTINGS(0xFF, 0xFF, 0),
	SCENE_CMD_MESH(&newmarket_room_0_meshHeader),
	SCENE_CMD_OBJECT_LIST(2, newmarket_room_0_header00_objectList),
	SCENE_CMD_ACTOR_LIST(2, newmarket_room_0_header00_actorList),
	SCENE_CMD_END(),
};

s16 newmarket_room_0_header00_objectList[2] = {
	OBJECT_SD,
	OBJECT_DOG,
};

ActorEntry newmarket_room_0_header00_actorList[2] = {
	{ ACTOR_EN_HEISHI4, -84, -408, 173, 0, 9390, 0, 0xFF08 },
	{ ACTOR_EN_RIVER_SOUND, -2, -408, 402, 0, 0, 0, 0x000B },
};

