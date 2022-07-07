#ifndef Z_OBJ_KOKIRISWORD
#define Z_OBJ_KOKIRISWORD

#include "ultra64.h"
#include "global.h"

struct ObjKokiriSword;

typedef void (*ObjKokiriSwordActionFunc)(struct ObjKokiriSword*, PlayState*);
typedef void (*ObjKokiriSwordTransformFunc)(struct ObjKokiriSword*);

typedef struct ObjKokiriSword {
    Actor actor;
    bool isVisible;
} ObjKokiriSword;

#endif
