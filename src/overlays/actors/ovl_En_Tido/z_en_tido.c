/*
 * File: z_en_tido.c
 * Overlay: ovl_En_Tido
 * Description: Tido
 */

#include "z_en_tido.h"
#include "assets/objects/object_tido/object_tido.h"
#include "overlays/actors/ovl_En_Elf/z_en_elf.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

void EnTido_Init(Actor* thisx, PlayState* play);
void EnTido_Destroy(Actor* thisx, PlayState* play);
void EnTido_Update(Actor* thisx, PlayState* play);
void EnTido_Draw(Actor* thisx, PlayState* play);

void EnTido_SetupGetItem(EnTido* this, PlayState* play);

const ActorInit En_Tido_InitVars = {
    ACTOR_EN_TIDO,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_TIDO,
    sizeof(EnTido),
    (ActorFunc)EnTido_Init,
    (ActorFunc)EnTido_Destroy,
    (ActorFunc)EnTido_Update,
    (ActorFunc)EnTido_Draw,
};

static ColliderCylinderInit sCylinderInit = {
    {
        COLTYPE_NONE,
        AT_NONE,
        AC_NONE,
        OC1_ON | OC1_TYPE_ALL,
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
    { 40, 46, 0, { 0, 0, 0 } },
};

static CollisionCheckInfoInit2 sColChkInfoInit = { 0, 0, 0, 0, MASS_IMMOVABLE };

typedef enum {
    /*  0 */ ENTIDO_HAMMERING_ANIM
} EnTidoAnimation;

static AnimationInfo sAnimationInfo[] = {
    { &gTidoSkelHammeringAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -1.0f },
};

u8 EnTido_ShouldSpawn(EnTido* this, PlayState* play) {
    if (play->sceneNum == SCENE_SPOT04) {
        if (!GET_EVENTCHKINF(EVENTCHKINF_1C) && !GET_EVENTCHKINF(EVENTCHKINF_40)) {
            return 1;
        }
    }

    if (play->sceneNum == SCENE_KOKIRI_HOME4) {
        if (GET_EVENTCHKINF(EVENTCHKINF_1C) || GET_EVENTCHKINF(EVENTCHKINF_40)) {
            if (!LINK_IS_ADULT) {
                return 1;
            }
        }
    }

    if (play->sceneNum == SCENE_SPOT10 || play->sceneNum == SCENE_LEARNING01) {
        return 1;
    }

    return 0;
}

void EnTido_Init(Actor* thisx, PlayState* play) {
    EnTido* this = (EnTido*)thisx;
    s32 pad;

    SkelAnime_InitFlex(play, &this->skelAnime, &gTidoSkel, NULL, this->jointTable, this->morphTable,
                       GTIDOSKEL_NUM_LIMBS);
    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawCircle, 18.0f);

    this->alpha = 255;
    this->appearDist = 400.0f;

    this->actor.gravity = 0.0f;

    Actor_SetFocus(thisx, 30.0f);

    Collider_InitCylinder(play, &this->collider);
    Collider_SetCylinder(play, &this->collider, &this->actor, &sCylinderInit);
    CollisionCheck_SetInfo2(&this->actor.colChkInfo, NULL, &sColChkInfoInit);
    if (!EnTido_ShouldSpawn(this, play)) {
        Actor_Kill(&this->actor);
        return;
    }

    Animation_ChangeByInfo(&this->skelAnime, sAnimationInfo, ENTIDO_HAMMERING_ANIM);
    Actor_SetScale(&this->actor, 0.01f);
    this->actor.targetMode = 6;
    Actor_SpawnAsChild(&play->actorCtx, &this->actor, play, ACTOR_EN_ELF, this->actor.world.pos.x,
                       this->actor.world.pos.y, this->actor.world.pos.z, 0, 0, 0, FAIRY_KOKIRI);

    this->actor.home.pos = this->actor.world.pos;

    this->unk_1E0.unk_14 = 40.0f;
}

void EnTido_Destroy(Actor* thisx, PlayState* play) {
    EnTido* this = (EnTido*)thisx;
    Collider_DestroyCylinder(play, &this->collider);
}

u16 EnTido_GetText(PlayState* play, Actor* thisx) {
    if (INV_CONTENT(SLOT_SLINGSHOT) != ITEM_SLINGSHOT) {
        if (!GET_INFTABLE(INFTABLE_0C)) {
            return 0x71BD;
        } else if (AMMO(ITEM_STICK) >= 2) {
            if (GET_INFTABLE(INFTABLE_TIDO_ASK_FOR_STICKS)) {
                return 0x71BC;
            } else {
                return 0x71B7;
            }
        } else {
            if (GET_INFTABLE(INFTABLE_TIDO_ASK_FOR_STICKS)) {
                return 0x71BB;
            } else {
                return 0x71B8;
            }
        }
    }

    if (CHECK_QUEST_ITEM(QUEST_KOKIRI_EMERALD)) {
        return 0x71B6;
    } else {
        return 0x71BD;
    }
}

s16 EnTido_UpdateFlags(PlayState* play, Actor* thisx) {
    EnTido* this = (EnTido*)thisx;
    switch (Message_GetState(&play->msgCtx)) {
        case TEXT_STATE_NONE:
        case TEXT_STATE_DONE_HAS_NEXT:
        case TEXT_STATE_DONE_FADING:
        case TEXT_STATE_SONG_DEMO_DONE:
        case TEXT_STATE_8:
        case TEXT_STATE_9:
            return 1;

        case TEXT_STATE_DONE:
            switch (this->actor.textId) {
                case 0x71B7:
                case 0x71BC:
                    this->actionFunc = EnTido_SetupGetItem;
                    break;
                case 0x71B8:
                case 0x71BB:
                    SET_INFTABLE(INFTABLE_TIDO_ASK_FOR_STICKS);
                    break;
            }
            return 1;

        case TEXT_STATE_CLOSING:
            return 0;

        case TEXT_STATE_CHOICE:
            return 1;

        case TEXT_STATE_EVENT:
            switch (Message_ShouldAdvance(play)) {
                case 0:
                    return 1;
                default:
                    return 2;
            }
    }

    return 1;
}

void EnTido_Dialog(EnTido* this, PlayState* play) {
    s16 temp;

    Player* player = GET_PLAYER(play);

    this->unk_1E0.unk_18 = player->actor.world.pos;
    this->unk_1E0.unk_14 = (gSaveContext.linkAge > 0) ? 0.0f : -18.0f;
    temp = 1;

    func_80034A14(&this->actor, &this->unk_1E0, 2, temp);
    func_800343CC(play, &this->actor, &this->unk_1E0.unk_00, this->collider.dim.radius + 30.0f, EnTido_GetText,
                  EnTido_UpdateFlags);
}

void EnTido_SetupGetItem(EnTido* this, PlayState* play) {
    f32 xzRange;
    f32 yRange;

    if (INV_CONTENT(SLOT_SLINGSHOT) != ITEM_SLINGSHOT) {
        Inventory_ChangeAmmo(ITEM_STICK, -2);
    }

    yRange = fabsf(this->actor.yDistToPlayer) * 2.0f;
    xzRange = this->actor.xzDistToPlayer * 2.0f;
    func_8002F434(&this->actor, play, GI_SLINGSHOT, xzRange, yRange);

    this->actionFunc = NULL;
}

void EnTido_UpdateAlpha(EnTido* this, PlayState* play) {
    f32 dist;

    if (play->csCtx.state != 0 || gDbgCamEnabled != 0) {
        dist = Math_Vec3f_DistXYZ(&this->actor.world.pos, &play->view.eye) * 0.25f;
    } else {
        dist = this->actor.xzDistToPlayer;
    }

    Math_SmoothStepToF(&this->alpha, (this->appearDist < dist) ? 0.0f : 255.0f, 0.3f, 40.0f, 1.0f);
    if (this->alpha < 10.0f) {
        this->actor.flags &= ~ACTOR_FLAG_0;
    } else {
        this->actor.flags |= ACTOR_FLAG_0;
    }
}

void EnTido_Update(Actor* thisx, PlayState* play) {
    ColliderCylinder* collider;
    EnTido* this = (EnTido*)thisx;
    s32 pad;

    SkelAnime_Update(&this->skelAnime);

    EnTido_UpdateAlpha(this, play);
    this->actor.shape.shadowAlpha = this->alpha;

    if (this->actionFunc != NULL) {
        this->actionFunc(this, play);
    }

    EnTido_Dialog(this, play);

    collider = &this->collider;
    Collider_UpdateCylinder(&this->actor, collider);
    CollisionCheck_SetOC(play, &play->colChkCtx, &collider->base);
}

s32 EnTido_OverrideLimbDraw(PlayState* play, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx,
                            Gfx** gfx) {
    return false;
}

void EnTido_PostLimbDraw(PlayState* play2, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx, Gfx** gfx) {
    return;
}

Gfx* EnTido_SetEnvColor(GraphicsContext* gfxCtx, u8 r, u8 g, u8 b, u8 a) {
    Gfx* dList = Graph_Alloc(gfxCtx, sizeof(Gfx) * 2);

    gDPSetEnvColor(dList, r, g, b, a);
    gSPEndDisplayList(dList + 1);
    return dList;
}

void EnTido_Draw(Actor* thisx, PlayState* play) {
    EnTido* this = (EnTido*)thisx;
    Color_RGBA8 tunicColor = { 247, 104, 6, 255 };
    Color_RGBA8 bootsColor = { 98, 74, 46, 255 };

    this->actor.shape.shadowAlpha = this->alpha;

    OPEN_DISPS(play->state.gfxCtx, "../z_en_tido.c", __LINE__);
    if (this->alpha == 255) {
        gSPSegment(POLY_OPA_DISP++, 0x08,
                   EnTido_SetEnvColor(play->state.gfxCtx, tunicColor.r, tunicColor.g, tunicColor.b, 255));
        gSPSegment(POLY_OPA_DISP++, 0x09,
                   EnTido_SetEnvColor(play->state.gfxCtx, bootsColor.r, bootsColor.g, bootsColor.b, 255));
        func_80034BA0(play, &this->skelAnime, EnTido_OverrideLimbDraw, EnTido_PostLimbDraw, &this->actor, this->alpha);
    } else if (this->alpha != 0) {
        tunicColor.a = this->alpha;
        bootsColor.a = this->alpha;
        gSPSegment(POLY_XLU_DISP++, 0x08,
                   EnTido_SetEnvColor(play->state.gfxCtx, tunicColor.r, tunicColor.g, tunicColor.b, tunicColor.a));
        gSPSegment(POLY_XLU_DISP++, 0x09,
                   EnTido_SetEnvColor(play->state.gfxCtx, bootsColor.r, bootsColor.g, bootsColor.b, bootsColor.a));
        func_80034CC4(play, &this->skelAnime, EnTido_OverrideLimbDraw, EnTido_PostLimbDraw, &this->actor, this->alpha);
    }
    CLOSE_DISPS(play->state.gfxCtx, "../z_en_tido.c", __LINE__);
}
