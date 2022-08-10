#ifndef Z_NEWACTOR_H
#define Z_NEWACTOR_H

#include "ultra64.h"
#include "global.h"

typedef struct NewActor {
    Actor actor;
    SkelAnime skelAnime;
    Vec3s jointTable[18];
    Vec3s morphTable[18];
} NewActor;

#endif
