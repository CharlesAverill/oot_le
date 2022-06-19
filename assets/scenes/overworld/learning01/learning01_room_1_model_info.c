#include "ultra64.h"
#include "z64.h"
#include "macros.h"
#include "learning01_scene.h"

#include "segment_symbols.h"
#include "command_macros_base.h"
#include "z64cutscene_commands.h"
#include "variables.h"

MeshHeader0 learning01_room_1_meshHeader= {
    0,
    1,
    learning01_room_1_meshDListEntry,
    learning01_room_1_meshDListEntry + ARRAY_COUNT(learning01_room_1_meshDListEntry)
};

MeshHeader01Entry learning01_room_1_meshDListEntry[1] = {
	{ learning01_room_1_entry_0_opaque, NULL },
};

