#ifndef Z_EN_TIDO_H
#define Z_EN_TIDO_H

#include "ultra64.h"
#include "global.h"

struct EnTido;

typedef void (*EnTidoActionFunc)(struct EnTido*, PlayState*);

typedef struct EnTido {
    Actor actor;
    SkelAnime skelAnime;
    EnTidoActionFunc actionFunc;
    ColliderCylinder collider;
    struct_80034A14_arg1 unk_1E0;
    Vec3s jointTable[17];
    Vec3s morphTable[17];
    f32 appearDist;
    f32 alpha;
} EnTido;

#endif
