#include "ultra64.h"
#include "z64.h"
#include "macros.h"
#include "newmarket_scene.h"

#include "segment_symbols.h"
#include "command_macros_base.h"
#include "z64cutscene_commands.h"
#include "variables.h"

MeshHeader0 newmarket_room_2_meshHeader= {
    0,
    1,
    newmarket_room_2_meshDListEntry,
    newmarket_room_2_meshDListEntry + ARRAY_COUNT(newmarket_room_2_meshDListEntry)
};

MeshHeader01Entry newmarket_room_2_meshDListEntry[1] = {
	{ newmarket_room_2_entry_0_opaque, newmarket_room_2_entry_0_transparent },
};

