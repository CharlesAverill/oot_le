#include "ultra64.h"
#include "z64.h"
#include "macros.h"
#include "learning01_scene.h"

#include "segment_symbols.h"
#include "command_macros_base.h"
#include "z64cutscene_commands.h"
#include "variables.h"

SCmdBase learning01_room_1_header00[] = {
	SCENE_CMD_ECHO_SETTINGS(0x00),
	SCENE_CMD_ROOM_BEHAVIOR(0x00, 0x00, false, false),
	SCENE_CMD_SKYBOX_DISABLES(false, false),
	SCENE_CMD_TIME_SETTINGS(0xFF, 0xFF, 10),
	SCENE_CMD_MESH(&learning01_room_1_meshHeader),
	SCENE_CMD_OBJECT_LIST(2, learning01_room_1_header00_objectList),
	SCENE_CMD_ACTOR_LIST(1, learning01_room_1_header00_actorList),
	SCENE_CMD_END(),
};

s16 learning01_room_1_header00_objectList[2] = {
	OBJECT_LYNEL,
	OBJECT_GREEBLE,
};

ActorEntry learning01_room_1_header00_actorList[1] = {
	{ ACTOR_EN_LYNEL, -640, -241, 1257, 0, 0, 0, 0x0000 },
};

