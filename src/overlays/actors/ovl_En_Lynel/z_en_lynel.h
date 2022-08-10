#ifndef Z_EN_LYNEL_H
#define Z_EN_LYNEL_H

#include "ultra64.h"
#include "global.h"

typedef struct EnLynel {
    Actor actor;
    SkelAnime skelAnime;
    Vec3s jointTable[17];
    Vec3s morphTable[17];
    s16 alpha;
} EnLynel;

typedef enum {
    ENLYNEL_LIMB_NONE,
    ENLYNEL_LIMB_UNK1,
    ENLYNEL_LIMB_UNK2,
    ENLYNEL_LIMB_UNK3,
    ENLYNEL_LIMB_UNK4,
    ENLYNEL_LIMB_UNK5,
    ENLYNEL_LIMB_UNK6,
    ENLYNEL_LIMB_UNK7,
    ENLYNEL_LIMB_UNK8,
    ENLYNEL_LIMB_UNK9,
    ENLYNEL_LIMB_UNK10,
    ENLYNEL_LIMB_UNK11,
    ENLYNEL_LIMB_UNK12,
    ENLYNEL_LIMB_UNK13,
    ENLYNEL_LIMB_UNK14,
    ENLYNEL_LIMB_UNK15,
    ENLYNEL_LIMB_UNK16,
    ENLYNEL_LIMB_UNK17,
    ENLYNEL_LIMB_UNK18,
    ENLYNEL_LIMB_UNK19,
    ENLYNEL_LIMB_UNK20,
    ENLYNEL_LIMB_UNK21,
    ENLYNEL_LIMB_UNK22,
    ENLYNEL_LIMB_UNK23,
    ENLYNEL_LIMB_UNK24,
    ENLYNEL_LIMB_UNK25,
    ENLYNEL_LIMB_UNK26,
    /*
    ENLYNEL_LIMB_UNK27,
    ENLYNEL_LIMB_UNK28,
    ENLYNEL_LIMB_UNK29,
    */
    ENLYNEL_LIMB_MAX
} EnMdLimbs;

#endif
