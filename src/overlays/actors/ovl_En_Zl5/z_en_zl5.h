#ifndef Z_ZL5_H
#define Z_ZL5_H

#include "ultra64.h"
#include "global.h"

struct EnZl4;

typedef void (*EnZl5ActionFunc)(struct EnZl5*, PlayState*);

typedef struct EnZl5 {
    Actor actor;
    SkelAnime skelAnime;
    /* 0x0190 */ EnZl5ActionFunc actionFunc;
    /* 0x0194 */ ColliderCylinder collider;
    /* 0x020A */ u8 leftEyeState;
    /* 0x020B */ u8 rightEyeState;
    /* 0x020C */ u8 mouthState;
    /* 0x020D */ u8 eyeExpression;
    /* 0x020E */ u8 mouthExpression;
    /* 0x01E0 */ struct_80034A14_arg1 unk_1E0;
    /* 0x0210 */ s16 blinkTimer;
    /* 0x0218 */ Vec3s jointTable[18];
    /* 0x0284 */ Vec3s morphTable[18];
} EnZl5;

#endif
