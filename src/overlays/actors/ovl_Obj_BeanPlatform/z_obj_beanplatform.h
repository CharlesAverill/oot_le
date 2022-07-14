#ifndef Z_OBJ_BEANPLATFORM_H
#define Z_OBJ_BEANPLATFORM_H

#include "ultra64.h"
#include "global.h"

/*
 * PARAMS
 *
 *     0000000000001111
 *     Movement direction:
 *       0000 : No movement
 *       0001 : +Y/-Y
 *       0010 : +X/-X
 *       0011 : +Z/-Z
 *       0100 : +YX/-YX
 *       0101 : +YZ/-YZ
 *       0110 : CW circle around origin  (XZ)
 *       0111 : CCW circle around origin (XZ)
 *       1000 : CW circle around origin  (XY)
 *       1001 : CCW circle around origin (XY)
 *       1010 : CW circle around origin  (YZ)
 *       1011 : CCW circle around origin (YZ)
 *       1100 : +XZ/-XZ
 *
 *     0000000011110000
 *     Movement speed (unsigned)
 *
 *     0000000100000000
 *     Movement speed sign bit
 *       0 : Positive
 *       1 : Negative
 *
 *     0001111000000000
 *     Maximum distance / radius from origin (unsigned) * 50
 *       1000 represents (8 * 50) = 400
 */

typedef enum {
    BEANPLATFORM_STATIC,
    BEANPLATFORM_YMOVE,
    BEANPLATFORM_XMOVE,
    BEANPLATFORM_ZMOVE,
    BEANPLATFORM_YXMOVE,
    BEANPLATFORM_YZMOVE,
    BEANPLATFORM_CWCIRCLE_XZ,
    BEANPLATFORM_CCWCIRCLE_XZ,
    BEANPLATFORM_CWCIRCLE_XY,
    BEANPLATFORM_CCWCIRCLE_XY,
    BEANPLATFORM_CWCIRCLE_YZ,
    BEANPLATFORM_CCWCIRCLE_YZ,
    BEANPLATFORM_XZMOVE
} BeanPlatformTypes;

typedef struct ObjBeanPlatform {
    DynaPolyActor dyna;
    ColliderCylinder collider;
    u8 type;
    s8 movementSpeed;
    s8 velocity;
    u16 maxDistance;
    u8 frameCounter;
} ObjBeanPlatform;

#endif
