#include "ultra64.h"
#include "z64.h"
#include "macros.h"
#include "newmarket_scene.h"

#include "segment_symbols.h"
#include "command_macros_base.h"
#include "z64cutscene_commands.h"
#include "variables.h"

SCmdBase newmarket_scene_header00[] = {
	SCENE_CMD_SOUND_SETTINGS(0x00, 0x00, 0x1D),
	SCENE_CMD_ROOM_LIST(2, newmarket_scene_roomList),
	SCENE_CMD_TRANSITION_ACTOR_LIST(8, newmarket_scene_header00_transitionActors),
	SCENE_CMD_MISC_SETTINGS(0x00, 0x0E),
	SCENE_CMD_COL_HEADER(&newmarket_collisionHeader),
	SCENE_CMD_ENTRANCE_LIST(newmarket_scene_header00_entranceList),
	SCENE_CMD_SPECIAL_FILES(0x00, 0x0002),
	SCENE_CMD_PATH_LIST(newmarket_scene_pathway),
	SCENE_CMD_SPAWN_LIST(1, newmarket_scene_header00_startPositionList),
	SCENE_CMD_SKYBOX_SETTINGS(0x01, 0x00, 0x00),
	SCENE_CMD_EXIT_LIST(newmarket_scene_header00_exitList),
	SCENE_CMD_ENV_LIGHT_SETTINGS(4, newmarket_scene_header00_lightSettings),
	SCENE_CMD_END(),
};

ActorEntry newmarket_scene_header00_startPositionList[] = {
	{ ACTOR_PLAYER, 16, -409, 192, 0, 0, 0, 0x0FFF },
};

TransitionActorEntry newmarket_scene_header00_transitionActors[8] = {
	{ 1, 0x00, 1, 0x00, ACTOR_EN_DOOR, 303, -413, 1456, 0, 0x028D },
	{ 1, 0x00, 1, 0x00, ACTOR_EN_DOOR, 228, -413, 2438, 32768, 0x01BF },
	{ 1, 0x00, 1, 0x00, ACTOR_EN_DOOR, -546, -413, 1596, 16384, 0x01BF },
	{ 0, 0x00, 0, 0x00, ACTOR_EN_DOOR, -116, -411, 223, 16384, 0x01BF },
	{ 1, 0x00, 1, 0x00, ACTOR_EN_DOOR, 397, -413, 1905, 49152, 0x01BF },
	{ 1, 0x00, 1, 0x00, ACTOR_EN_DOOR, -370, -413, 2437, 32768, 0x01BF },
	{ 0, 0x00, 1, 0x00, ACTOR_EN_HOLL, 41, -409, 871, 0, 0x013F },
	{ 1, 0x00, 1, 0x00, ACTOR_EN_DOOR, -546, -413, 1989, 16384, 0x01BF },
};

extern u8 _newmarket_room_0SegmentRomStart[];
extern u8 _newmarket_room_0SegmentRomEnd[];
extern u8 _newmarket_room_1SegmentRomStart[];
extern u8 _newmarket_room_1SegmentRomEnd[];

RomFile newmarket_scene_roomList[] = {
	{ (u32)_newmarket_room_0SegmentRomStart, (u32)_newmarket_room_0SegmentRomEnd },
	{ (u32)_newmarket_room_1SegmentRomStart, (u32)_newmarket_room_1SegmentRomEnd },
};

EntranceEntry newmarket_scene_header00_entranceList[] = {
	{ 0, 0 },
};

u16 newmarket_scene_header00_exitList[9] = {
	0x0B7,
	0x07E,
	0x388,
	0x530,
	0x03B,
	0x507,
	0x0CD,
	0x138,
	0x063,
};

LightSettings newmarket_scene_header00_lightSettings[4] = {
	{ 0x46, 0x2D, 0x39, 0x49, 0x49, 0x49, 0xB4, 0x9A, 0x8A, 0xB7, 0xB7, 0xB7, 0x14, 0x14, 0x3C, 0x8C, 0x78, 0x64, 0x07E1, 0x3200 },
	{ 0x69, 0x5A, 0x5A, 0x49, 0x49, 0x49, 0xFF, 0xFF, 0xF0, 0xB7, 0xB7, 0xB7, 0x32, 0x32, 0x5A, 0x64, 0x64, 0x78, 0x07E4, 0x3200 },
	{ 0x78, 0x5A, 0x00, 0x49, 0x49, 0x49, 0xFA, 0x87, 0x32, 0xB7, 0xB7, 0xB7, 0x1E, 0x1E, 0x3C, 0x78, 0x46, 0x32, 0x07E3, 0x3200 },
	{ 0x28, 0x46, 0x64, 0x49, 0x49, 0x49, 0x14, 0x14, 0x23, 0xB7, 0xB7, 0xB7, 0x32, 0x32, 0x64, 0x00, 0x00, 0x1E, 0x07E0, 0x3200 },
};

Vec3s newmarket_pathwayList_0[] = {
	{ -301, -409, 1670 },
	{ -157, -409, 1638 },
	{ 33, -409, 1618 },
	{ 199, -409, 1767 },
	{ 235, -419, 2015 },
	{ 267, -388, 2189 },
	{ 259, -385, 2311 },
	{ 129, -414, 2368 },
	{ 64, -420, 2333 },
	{ 57, -409, 2243 },
	{ -7, -409, 2186 },
	{ -87, -409, 2132 },
	{ -182, -409, 2032 },
	{ -258, -409, 1907 },
	{ -308, -409, 1806 },
	{ -331, -409, 1721 },
	{ -301, -409, 1670 },
};

Vec3s newmarket_pathwayList_1[] = {
	{ 319, -409, 1901 },
	{ 315, -409, 1995 },
	{ 304, -409, 2096 },
	{ 296, -409, 2271 },
	{ 329, -409, 2354 },
	{ 543, -409, 2371 },
	{ 778, -409, 2358 },
	{ 1042, -409, 2331 },
	{ 1165, -409, 2280 },
	{ 1165, -409, 2150 },
	{ 1168, -409, 1745 },
	{ 1131, -409, 1594 },
	{ 1089, -409, 1539 },
	{ 1015, -409, 1531 },
	{ 669, -409, 1523 },
	{ 357, -409, 1529 },
	{ 296, -409, 1644 },
	{ 299, -409, 1855 },
	{ 319, -409, 1901 },
};

Vec3s newmarket_pathwayList_2[] = {
	{ -138, -409, 2343 },
	{ -170, -409, 2280 },
	{ -230, -409, 2250 },
	{ -226, -409, 2153 },
	{ -218, -409, 2084 },
	{ -247, -409, 2034 },
	{ -331, -409, 2073 },
	{ -387, -409, 1980 },
	{ -359, -409, 1901 },
	{ -351, -409, 1814 },
	{ -426, -409, 1820 },
	{ -479, -409, 1757 },
	{ -432, -409, 1684 },
	{ -376, -409, 1717 },
	{ -371, -409, 1792 },
	{ -421, -409, 1868 },
	{ -346, -409, 1953 },
	{ -257, -409, 1974 },
	{ -285, -409, 2042 },
	{ -320, -409, 2133 },
	{ -404, -409, 2128 },
	{ -378, -409, 2049 },
	{ -411, -409, 2003 },
	{ -481, -409, 2015 },
	{ -475, -409, 2066 },
	{ -449, -409, 2123 },
	{ -414, -409, 2217 },
	{ -530, -409, 2232 },
	{ -614, -409, 2183 },
	{ -657, -409, 2263 },
	{ -643, -409, 2361 },
	{ -554, -409, 2396 },
	{ -465, -409, 2360 },
	{ -427, -409, 2307 },
	{ -337, -409, 2324 },
	{ -286, -409, 2292 },
	{ -348, -409, 2260 },
	{ -424, -409, 2263 },
	{ -474, -409, 2300 },
	{ -405, -409, 2357 },
	{ -304, -409, 2393 },
	{ -250, -409, 2357 },
	{ -185, -409, 2343 },
	{ -138, -409, 2343 },
};

Vec3s newmarket_pathwayList_3[] = {
	{ -314, -409, 2021 },
	{ -294, -409, 2054 },
	{ -267, -409, 2082 },
	{ -228, -409, 2115 },
	{ -204, -409, 2156 },
	{ -228, -409, 2193 },
	{ -281, -409, 2201 },
	{ -322, -409, 2184 },
	{ -343, -409, 2140 },
	{ -324, -409, 2109 },
	{ -271, -409, 2087 },
	{ -173, -409, 2097 },
	{ -99, -409, 2131 },
	{ -42, -409, 2143 },
	{ 29, -409, 2144 },
	{ 76, -409, 2143 },
	{ 95, -409, 2191 },
	{ 92, -409, 2245 },
	{ 78, -409, 2316 },
	{ 122, -409, 2361 },
	{ 191, -409, 2324 },
	{ 225, -409, 2303 },
	{ 271, -409, 2224 },
	{ 238, -409, 2195 },
	{ 205, -409, 2185 },
	{ 180, -409, 2184 },
	{ 164, -409, 2185 },
	{ 150, -409, 2153 },
	{ 150, -409, 2128 },
	{ 153, -409, 2088 },
	{ 194, -409, 2047 },
	{ 211, -409, 2000 },
	{ 205, -409, 1959 },
	{ 182, -409, 1892 },
	{ 127, -409, 1848 },
	{ 113, -409, 1796 },
	{ 51, -409, 1759 },
	{ -9, -409, 1742 },
	{ -45, -409, 1766 },
	{ -130, -409, 1825 },
	{ -185, -409, 1895 },
	{ -236, -409, 1987 },
	{ -285, -409, 2008 },
	{ -314, -409, 2021 },
};

Path newmarket_scene_pathway[4] = {
	{ 17, newmarket_pathwayList_0 },
	{ 19, newmarket_pathwayList_1 },
	{ 44, newmarket_pathwayList_2 },
	{ 44, newmarket_pathwayList_3 },
};

