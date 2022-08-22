import bpy
import re

context = bpy.context

namesraw = """
extern Gfx spot15_room_0DL_001160[];
extern Vtx spot15_room_0Vtx_0013D0[];
...
"""
names = re.findall("Gfx (.*)\[\];", namesraw)

for name in names:
    context.scene.ootDLImportName = name
    bpy.ops.object.oot_import_dl()