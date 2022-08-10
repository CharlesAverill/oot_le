#ifndef Z_GREEBLE_H
#define Z_GREEBLE_H

#include "ultra64.h"
#include "global.h"

typedef struct EnGreeble {
    Actor actor;
    SkelAnime skelAnime;
    Vec3s jointTable[17];
    Vec3s morphTable[17];
    s16 alpha;
} EnGreeble;

#endif
