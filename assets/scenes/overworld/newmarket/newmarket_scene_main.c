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
	SCENE_CMD_ROOM_LIST(3, newmarket_scene_roomList),
	SCENE_CMD_TRANSITION_ACTOR_LIST(16, newmarket_scene_header00_transitionActors),
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
	{ ACTOR_PLAYER, 16, -408, 191, 0, 0, 0, 0x0FFF },
};

TransitionActorEntry newmarket_scene_header00_transitionActors[16] = {
	{ 2, 0x00, 1, 0x00, ACTOR_EN_DOOR, -368, -412, 2430, 32768, 0x01BF },
	{ 2, 0x00, 1, 0x00, ACTOR_EN_HOLL, 637, -408, 2365, 49152, 0x013F },
	{ 2, 0x00, 1, 0x00, ACTOR_EN_DOOR, 302, -411, 1452, 0, 0x028D },
	{ 1, 0x00, 1, 0x00, ACTOR_EN_DOOR, 302, -411, 1452, 0, 0x028D },
	{ 1, 0x00, 1, 0x00, ACTOR_EN_DOOR, 227, -412, 2430, 32768, 0x01BF },
	{ 0, 0x00, 0, 0x00, ACTOR_EN_DOOR, -116, -410, 223, 16384, 0x01BF },
	{ 1, 0x00, 1, 0x00, ACTOR_EN_DOOR, -544, -412, 1591, 16384, 0x01BF },
	{ 1, 0x00, 1, 0x00, ACTOR_EN_DOOR, 396, -412, 1899, 49152, 0x01BF },
	{ 2, 0x00, 1, 0x00, ACTOR_EN_DOOR, 227, -412, 2430, 32768, 0x01BF },
	{ 1, 0x00, 1, 0x00, ACTOR_EN_DOOR, -368, -412, 2430, 32768, 0x01BF },
	{ 1, 0x00, 1, 0x00, ACTOR_EN_DOOR, -544, -412, 1983, 16384, 0x01BF },
	{ 2, 0x00, 1, 0x00, ACTOR_EN_DOOR, 396, -412, 1899, 49152, 0x01BF },
	{ 0, 0x00, 1, 0x00, ACTOR_EN_HOLL, 41, -408, 869, 0, 0x013F },
	{ 2, 0x00, 1, 0x00, ACTOR_EN_DOOR, -544, -412, 1591, 16384, 0x01BF },
	{ 2, 0x00, 1, 0x00, ACTOR_EN_HOLL, 637, -408, 1522, 49152, 0x013F },
	{ 2, 0x00, 1, 0x00, ACTOR_EN_DOOR, -544, -412, 1983, 16384, 0x01BF },
};

extern u8 _newmarket_room_0SegmentRomStart[];
extern u8 _newmarket_room_0SegmentRomEnd[];
extern u8 _newmarket_room_1SegmentRomStart[];
extern u8 _newmarket_room_1SegmentRomEnd[];
extern u8 _newmarket_room_2SegmentRomStart[];
extern u8 _newmarket_room_2SegmentRomEnd[];

RomFile newmarket_scene_roomList[] = {
	{ (u32)_newmarket_room_0SegmentRomStart, (u32)_newmarket_room_0SegmentRomEnd },
	{ (u32)_newmarket_room_1SegmentRomStart, (u32)_newmarket_room_1SegmentRomEnd },
	{ (u32)_newmarket_room_2SegmentRomStart, (u32)_newmarket_room_2SegmentRomEnd },
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
	{ -300, -408, 1665 },
	{ -157, -408, 1633 },
	{ 33, -408, 1613 },
	{ 198, -408, 1762 },
	{ 234, -417, 2009 },
	{ 267, -387, 2183 },
	{ 258, -384, 2304 },
	{ 128, -412, 2361 },
	{ 64, -419, 2326 },
	{ 56, -408, 2236 },
	{ -7, -408, 2180 },
	{ -87, -408, 2126 },
	{ -181, -408, 2026 },
	{ -257, -408, 1901 },
	{ -307, -408, 1801 },
	{ -330, -408, 1716 },
	{ -300, -408, 1665 },
};

Vec3s newmarket_pathwayList_1[] = {
	{ 318, -408, 1895 },
	{ 314, -408, 1989 },
	{ 303, -408, 2090 },
	{ 295, -408, 2265 },
	{ 328, -408, 2347 },
	{ 541, -408, 2364 },
	{ 775, -408, 2351 },
	{ 1039, -408, 2324 },
	{ 1162, -408, 2273 },
	{ 1162, -408, 2143 },
	{ 1165, -408, 1740 },
	{ 1128, -408, 1590 },
	{ 1086, -408, 1534 },
	{ 1012, -408, 1527 },
	{ 667, -408, 1518 },
	{ 356, -408, 1525 },
	{ 295, -408, 1639 },
	{ 298, -408, 1849 },
	{ 318, -408, 1895 },
};

Vec3s newmarket_pathwayList_2[] = {
	{ -138, -408, 2336 },
	{ -170, -408, 2273 },
	{ -229, -408, 2243 },
	{ -225, -408, 2146 },
	{ -217, -408, 2078 },
	{ -247, -408, 2028 },
	{ -330, -408, 2067 },
	{ -386, -408, 1974 },
	{ -358, -408, 1896 },
	{ -349, -408, 1808 },
	{ -425, -408, 1814 },
	{ -477, -408, 1752 },
	{ -431, -408, 1679 },
	{ -375, -408, 1712 },
	{ -369, -408, 1787 },
	{ -420, -408, 1862 },
	{ -345, -408, 1947 },
	{ -256, -408, 1968 },
	{ -284, -408, 2036 },
	{ -319, -408, 2126 },
	{ -403, -408, 2121 },
	{ -377, -408, 2043 },
	{ -410, -408, 1997 },
	{ -479, -408, 2009 },
	{ -474, -408, 2060 },
	{ -448, -408, 2117 },
	{ -412, -408, 2210 },
	{ -528, -408, 2225 },
	{ -613, -408, 2177 },
	{ -656, -408, 2256 },
	{ -641, -408, 2354 },
	{ -553, -408, 2389 },
	{ -464, -408, 2353 },
	{ -426, -408, 2300 },
	{ -336, -408, 2317 },
	{ -285, -408, 2285 },
	{ -346, -408, 2253 },
	{ -423, -408, 2256 },
	{ -473, -408, 2293 },
	{ -404, -408, 2350 },
	{ -303, -408, 2386 },
	{ -250, -408, 2350 },
	{ -185, -408, 2336 },
	{ -138, -408, 2336 },
};

Vec3s newmarket_pathwayList_3[] = {
	{ -285, -408, 2012 },
	{ -277, -408, 2031 },
	{ -216, -408, 2036 },
	{ -159, -408, 2068 },
	{ -156, -408, 2183 },
	{ -180, -408, 2220 },
	{ -301, -408, 2232 },
	{ -342, -408, 2215 },
	{ -381, -408, 2111 },
	{ -362, -408, 2081 },
	{ -275, -408, 2033 },
	{ -172, -408, 2091 },
	{ -99, -408, 2124 },
	{ -42, -408, 2136 },
	{ 29, -408, 2138 },
	{ 66, -408, 2158 },
	{ 78, -408, 2197 },
	{ 76, -408, 2235 },
	{ 77, -408, 2309 },
	{ 122, -408, 2354 },
	{ 191, -408, 2317 },
	{ 225, -408, 2296 },
	{ 270, -408, 2217 },
	{ 237, -408, 2189 },
	{ 204, -408, 2179 },
	{ 179, -408, 2178 },
	{ 163, -408, 2179 },
	{ 150, -408, 2147 },
	{ 150, -408, 2122 },
	{ 152, -408, 2082 },
	{ 194, -408, 2041 },
	{ 210, -408, 1994 },
	{ 204, -408, 1953 },
	{ 181, -408, 1886 },
	{ 127, -408, 1842 },
	{ 113, -408, 1790 },
	{ 51, -408, 1753 },
	{ -9, -408, 1737 },
	{ -45, -408, 1761 },
	{ -130, -408, 1820 },
	{ -184, -408, 1889 },
	{ -235, -408, 1981 },
	{ -284, -408, 2002 },
	{ -285, -408, 2012 },
};

Path newmarket_scene_pathway[4] = {
	{ 17, newmarket_pathwayList_0 },
	{ 19, newmarket_pathwayList_1 },
	{ 44, newmarket_pathwayList_2 },
	{ 44, newmarket_pathwayList_3 },
};

