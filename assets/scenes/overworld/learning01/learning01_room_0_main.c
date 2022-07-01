#include "ultra64.h"
#include "z64.h"
#include "macros.h"
#include "learning01_scene.h"

#include "segment_symbols.h"
#include "command_macros_base.h"
#include "z64cutscene_commands.h"
#include "variables.h"

SCmdBase learning01_room_0_header00[] = {
	SCENE_CMD_ECHO_SETTINGS(0x00),
	SCENE_CMD_ROOM_BEHAVIOR(0x00, 0x00, false, false),
	SCENE_CMD_SKYBOX_DISABLES(false, false),
	SCENE_CMD_TIME_SETTINGS(0xFF, 0xFF, 10),
	SCENE_CMD_MESH(&learning01_room_0_meshHeader),
	SCENE_CMD_OBJECT_LIST(4, learning01_room_0_header00_objectList),
	SCENE_CMD_ACTOR_LIST(4, learning01_room_0_header00_actorList),
	SCENE_CMD_END(),
};

s16 learning01_room_0_header00_objectList[4] = {
	OBJECT_HORSE_GANON,
	OBJECT_ZO,
	OBJECT_MD,
	OBJECT_TIDO,
};

ActorEntry learning01_room_0_header00_actorList[4] = {
	{ ACTOR_EN_WOOD02, -232, -190, 250, 0, 0, 0, 0x0001 },
	{ ACTOR_EN_HORSE_GANON, 324, 56, -777, 0, 0, 0, 0x0000 },
	{ ACTOR_EN_TIDO, -105, -180, -345, 0, 0, 0, 0x0000 },
	{ ACTOR_EN_ZO, 61, -190, -345, 0, 0, 0, 0x0009 },
};

