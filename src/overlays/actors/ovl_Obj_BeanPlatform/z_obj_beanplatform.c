#include "z_obj_beanplatform.h"
#include "assets/objects/object_mamenoki/object_mamenoki.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

#define ROTATE_SPEED 100

void ObjBeanPlatform_Init(Actor* thisx, PlayState* play);
void ObjBeanPlatform_Destroy(Actor* thisx, PlayState* play);
void ObjBeanPlatform_Update(Actor* thisx, PlayState* play);
void ObjBeanPlatform_Draw(Actor* thisx, PlayState* play);

const ActorInit Obj_BeanPlatform_InitVars = {
    ACTOR_OBJ_BEANPLATFORM,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_MAMENOKI,
    sizeof(ObjBeanPlatform),
    (ActorFunc)ObjBeanPlatform_Init,
    (ActorFunc)ObjBeanPlatform_Destroy,
    (ActorFunc)ObjBeanPlatform_Update,
    (ActorFunc)ObjBeanPlatform_Draw,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_NONE,
        OC1_ON | OC1_TYPE_PLAYER,
        OC2_TYPE_2,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK0,
        { 0x00000000, 0x00, 0x00 },
        { 0x00000000, 0x00, 0x00 },
        TOUCH_NONE,
        BUMP_NONE,
        OCELEM_ON,
    },
    { 64, 30, -31, { 0, 0, 0 } },
};

void ObjBeanPlatform_Init(Actor* thisx, PlayState* play) {
    ObjBeanPlatform* this = (ObjBeanPlatform*)thisx;
    CollisionHeader* colHeader = NULL;

    DynaPolyActor_Init(&this->dyna, DPM_UNK3);
    CollisionHeader_GetVirtual(&gMagicBeanPlatformCol, &colHeader);

    this->dyna.bgId = DynaPoly_SetBgActor(play, &play->colCtx.dyna, &this->dyna.actor, colHeader);
    if (this->dyna.bgId == BG_ACTOR_MAX) {
        osSyncPrintf("Warning : move BG 登録失敗(%s %d)(name %d)(arg_data 0x%04x)\n", __FILE__, __LINE__,
                     this->dyna.actor.id, this->dyna.actor.params);
    }

    Collider_InitCylinder(play, &this->collider);
    Collider_SetCylinder(play, &this->collider, &this->dyna.actor, &sCylinderInit);
    Collider_UpdateCylinder(&this->dyna.actor, &this->collider);

    ActorShape_Init(&this->dyna.actor.shape, 0.0f, ActorShadow_DrawCircle, 8.8f);

    this->dyna.actor.world.rot.z = this->dyna.actor.home.rot.z = this->dyna.actor.shape.rot.z = 0;

    this->dyna.actor.home.pos = this->dyna.actor.world.pos;

    Actor_SetScale(&this->dyna.actor, 0.1f);

    this->type = this->dyna.actor.params & 0xF;
    this->movementSpeed = this->velocity = (this->dyna.actor.params >> 4) & 0xF;

    if((this->dyna.actor.params >> 8) & 0x1) {
        this->velocity *= -1;
    }

    if((this->dyna.actor.params >> 8) & 0x1 == 1) {
        this->movementSpeed *= -1;
    }

    this->maxDistance = ((this->dyna.actor.params >> 9) & 0xF) * 50;
}

void ObjBeanPlatform_Destroy(Actor* thisx, PlayState* play) {
    ObjBeanPlatform* this = (ObjBeanPlatform*)thisx;

    DynaPoly_DeleteBgActor(play, &play->colCtx.dyna, this->dyna.bgId);
    Collider_DestroyCylinder(play, &this->collider);
}

void ObjBeanPlatform_Update(Actor* thisx, PlayState* play) {
    ObjBeanPlatform* this = (ObjBeanPlatform*)thisx;

    switch(this->type) {
        case BEANPLATFORM_YMOVE:
            this->dyna.actor.world.pos.y += this->velocity;
            break;
        case BEANPLATFORM_XMOVE:
            this->dyna.actor.world.pos.x += this->velocity;
            break;
        case BEANPLATFORM_ZMOVE:
            this->dyna.actor.world.pos.z += this->velocity;
            break;
        case BEANPLATFORM_YXMOVE:
            this->dyna.actor.world.pos.y += this->velocity;
            this->dyna.actor.world.pos.x += this->velocity;
            break;
        case BEANPLATFORM_YZMOVE:
            this->dyna.actor.world.pos.y += this->velocity;
            this->dyna.actor.world.pos.z += this->velocity;
            break;
        case BEANPLATFORM_XZMOVE:
            this->dyna.actor.world.pos.x += this->velocity;
            this->dyna.actor.world.pos.z += this->velocity;
            break;
        case BEANPLATFORM_CWCIRCLE_XZ:
            this->dyna.actor.world.pos.x = this->dyna.actor.home.pos.x + Math_SinS(this->dyna.actor.shape.rot.y * this->velocity) * this->maxDistance;
            this->dyna.actor.world.pos.z = this->dyna.actor.home.pos.z - Math_CosS(this->dyna.actor.shape.rot.y * this->velocity) * this->maxDistance;
            break;
        case BEANPLATFORM_CCWCIRCLE_XZ:
            this->dyna.actor.world.pos.x = this->dyna.actor.home.pos.x + Math_SinS(this->dyna.actor.shape.rot.y * this->velocity) * this->maxDistance;
            this->dyna.actor.world.pos.z = this->dyna.actor.home.pos.z + Math_CosS(this->dyna.actor.shape.rot.y * this->velocity) * this->maxDistance;
            break;
        case BEANPLATFORM_CWCIRCLE_XY:
            this->dyna.actor.world.pos.x = this->dyna.actor.home.pos.x + Math_SinS(this->dyna.actor.shape.rot.y * this->velocity) * this->maxDistance;
            this->dyna.actor.world.pos.y = this->dyna.actor.home.pos.y - Math_CosS(this->dyna.actor.shape.rot.y * this->velocity) * this->maxDistance;
            break;
        case BEANPLATFORM_CCWCIRCLE_XY:
            this->dyna.actor.world.pos.x = this->dyna.actor.home.pos.x + Math_SinS(this->dyna.actor.shape.rot.y * this->velocity) * this->maxDistance;
            this->dyna.actor.world.pos.y = this->dyna.actor.home.pos.y + Math_CosS(this->dyna.actor.shape.rot.y * this->velocity) * this->maxDistance;
            break;
        case BEANPLATFORM_CWCIRCLE_YZ:
            this->dyna.actor.world.pos.y = this->dyna.actor.home.pos.y + Math_SinS(this->dyna.actor.shape.rot.y * this->velocity) * this->maxDistance;
            this->dyna.actor.world.pos.z = this->dyna.actor.home.pos.z - Math_CosS(this->dyna.actor.shape.rot.y * this->velocity) * this->maxDistance;
            break;
        case BEANPLATFORM_CCWCIRCLE_YZ:
            this->dyna.actor.world.pos.y = this->dyna.actor.home.pos.y + Math_SinS(this->dyna.actor.shape.rot.y * this->velocity) * this->maxDistance;
            this->dyna.actor.world.pos.z = this->dyna.actor.home.pos.z + Math_CosS(this->dyna.actor.shape.rot.y * this->velocity) * this->maxDistance;
            break;
        case BEANPLATFORM_STATIC:
        default:
            break;
    }

    if(Math_Vec3f_DistXYZ(&this->dyna.actor.home.pos, &this->dyna.actor.world.pos) > this->maxDistance) {
        this->velocity *= -1;
    }

    this->dyna.actor.world.rot.y += ROTATE_SPEED;
    this->dyna.actor.shape.rot.y = this->dyna.actor.world.rot.y;

    if (this->dyna.actor.xzDistToPlayer < 150.0f) {
        this->collider.dim.radius = this->dyna.actor.scale.x * 640.0f + 0.5f;
        Collider_UpdateCylinder(&this->dyna.actor, &this->collider);
        CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
    }

    this->dyna.actor.shape.shadowDraw = ActorShadow_DrawCircle;
    this->dyna.actor.shape.shadowScale = this->dyna.actor.scale.x * 88.0f;

    Actor_SetFocus(&this->dyna.actor, 6.0f);
}

void ObjBeanPlatform_Draw(Actor* thisx, PlayState* play) {
    ObjBeanPlatform* this = (ObjBeanPlatform*)thisx;
    Gfx* gfx;

    OPEN_DISPS(play->state.gfxCtx, __FILE__, __LINE__);

    Matrix_Translate(this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y, this->dyna.actor.world.pos.z,
                     MTXMODE_NEW);
    Matrix_RotateY(BINANG_TO_RAD(this->dyna.actor.shape.rot.y), MTXMODE_APPLY);
    Matrix_Scale(0.1f, 0.1f, 0.1f, MTXMODE_APPLY);
    Gfx_DrawDListOpa(play, gMagicBeanPlatformDL);

    CLOSE_DISPS(play->state.gfxCtx, __FILE__, __LINE__);
}
