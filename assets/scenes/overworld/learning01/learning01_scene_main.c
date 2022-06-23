#include "ultra64.h"
#include "z64.h"
#include "macros.h"
#include "learning01_scene.h"

#include "segment_symbols.h"
#include "command_macros_base.h"
#include "z64cutscene_commands.h"
#include "variables.h"

SCmdBase learning01_scene_header00[] = {
	SCENE_CMD_SOUND_SETTINGS(0x00, 0x00, 0x50),
	SCENE_CMD_ROOM_LIST(2, learning01_scene_roomList),
	SCENE_CMD_TRANSITION_ACTOR_LIST(2, learning01_scene_header00_transitionActors),
	SCENE_CMD_MISC_SETTINGS(0x00, 0x00),
	SCENE_CMD_COL_HEADER(&learning01_collisionHeader),
	SCENE_CMD_ENTRANCE_LIST(learning01_scene_header00_entranceList),
	SCENE_CMD_SPECIAL_FILES(0x00, 0x0002),
	SCENE_CMD_SPAWN_LIST(1, learning01_scene_header00_startPositionList),
	SCENE_CMD_SKYBOX_SETTINGS(0x01, 0x01, 0x01),
	SCENE_CMD_EXIT_LIST(learning01_scene_header00_exitList),
	SCENE_CMD_ENV_LIGHT_SETTINGS(1, learning01_scene_header00_lightSettings),
	SCENE_CMD_END(),
};

ActorEntry learning01_scene_header00_startPositionList[] = {
	{ ACTOR_PLAYER, 0, -190, 0, 0, 32768, 0, 0x0FFF },
};

TransitionActorEntry learning01_scene_header00_transitionActors[2] = {
	{ 0, 0x00, 1, 0x00, ACTOR_DOOR_SHUTTER, -501, -242, 810, 0, 0x0000 },
	{ 1, 0x00, 0, 0x00, ACTOR_DOOR_SHUTTER, -501, -243, 830, 0, 0x0000 },
};

extern u8 _learning01_room_0SegmentRomStart[];
extern u8 _learning01_room_0SegmentRomEnd[];
extern u8 _learning01_room_1SegmentRomStart[];
extern u8 _learning01_room_1SegmentRomEnd[];

RomFile learning01_scene_roomList[] = {
	{ (u32)_learning01_room_0SegmentRomStart, (u32)_learning01_room_0SegmentRomEnd },
	{ (u32)_learning01_room_1SegmentRomStart, (u32)_learning01_room_1SegmentRomEnd },
};

EntranceEntry learning01_scene_header00_entranceList[] = {
	{ 0, 0 },
};

u16 learning01_scene_header00_exitList[1] = {
	0x171,
};

LightSettings learning01_scene_header00_lightSettings[1] = {
	{ 0x8F, 0x6E, 0x82, 0x49, 0x49, 0x49, 0xDB, 0xCC, 0xC2, 0xB7, 0xB7, 0xB7, 0x4F, 0x4F, 0x85, 0xC4, 0xB6, 0xAF, 0x07E1, 0x3200 },
};

