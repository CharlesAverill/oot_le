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
	SCENE_CMD_SKYBOX_SETTINGS(0x01, 0x00, 0x00),
	SCENE_CMD_EXIT_LIST(learning01_scene_header00_exitList),
	SCENE_CMD_ENV_LIGHT_SETTINGS(4, learning01_scene_header00_lightSettings),
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

LightSettings learning01_scene_header00_lightSettings[4] = {
	{ 0x46, 0x2D, 0x39, 0x49, 0x49, 0x49, 0xB4, 0x9A, 0x8A, 0xB7, 0xB7, 0xB7, 0x14, 0x14, 0x3C, 0x8C, 0x78, 0x64, 0x07E1, 0x3200 },
	{ 0x69, 0x5A, 0x5A, 0x49, 0x49, 0x49, 0xFF, 0xFF, 0xF0, 0xB7, 0xB7, 0xB7, 0x32, 0x32, 0x5A, 0x64, 0x64, 0x78, 0x07E4, 0x3200 },
	{ 0x78, 0x5A, 0x00, 0x49, 0x49, 0x49, 0xFA, 0x87, 0x32, 0xB7, 0xB7, 0xB7, 0x1E, 0x1E, 0x3C, 0x78, 0x46, 0x32, 0x07E3, 0x3200 },
	{ 0x28, 0x46, 0x64, 0x49, 0x49, 0x49, 0x14, 0x14, 0x23, 0xB7, 0xB7, 0xB7, 0x32, 0x32, 0x64, 0x00, 0x00, 0x1E, 0x07E0, 0x3200 },
};

