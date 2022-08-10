#include "z_en_zl5.h"
#include "assets/objects/object_zl4/object_zl4.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

void EnZl5_Init(Actor* thisx, PlayState* play);
void EnZl5_Destroy(Actor* thisx, PlayState* play);
void EnZl5_Update(Actor* thisx, PlayState* play);
void EnZl5_Draw(Actor* thisx, PlayState* play);

const ActorInit En_EnZl5_InitVars = {
    ACTOR_EN_ZL5,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_ZL4,
    sizeof(EnZl5),
    (ActorFunc)EnZl5_Init,
    (ActorFunc)EnZl5_Destroy,
    (ActorFunc)EnZl5_Update,
    (ActorFunc)EnZl5_Draw,
};

typedef enum {
    /* 0 */ ZL5_EYES_NEUTRAL,
    /* 1 */ ZL5_EYES_SHUT,
    /* 2 */ ZL5_EYES_LOOK_LEFT,
    /* 3 */ ZL5_EYES_LOOK_RIGHT,
    /* 4 */ ZL5_EYES_WIDE,
    /* 5 */ ZL5_EYES_SQUINT,
    /* 6 */ ZL5_EYES_OPEN
} EnZl5EyeExpression;

typedef enum {
    /* 0 */ ZL5_MOUTH_NEUTRAL,
    /* 1 */ ZL5_MOUTH_HAPPY,
    /* 2 */ ZL5_MOUTH_WORRIED,
    /* 3 */ ZL5_MOUTH_SURPRISED
} EnZl5MouthExpression;

typedef enum {
    /* 0 */ ZL5_EYE_OPEN,
    /* 1 */ ZL5_EYE_BLINK,
    /* 2 */ ZL5_EYE_SHUT,
    /* 3 */ ZL5_EYE_WIDE,
    /* 4 */ ZL5_EYE_SQUINT,
    /* 5 */ ZL5_EYE_LOOK_OUT,
    /* 6 */ ZL5_EYE_LOOK_IN
} EnZl5EyeState;

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
    { 10, 44, 0, { 0, 0, 0 } },
};

static CollisionCheckInfoInit2 sColChkInfoInit = { 0, 0, 0, 0, MASS_IMMOVABLE };

static AnimationInfo sAnimationInfo[] = {
    { &gChildZeldaCivSkelStandAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, 0.0f },
    { &gChildZeldaCivSkelWalkAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, 0.0f }
}

typedef enum {
    ZL5_ANIM_IDLE,
    ZL5_ANIM_WALK
} EnZl5Animation;

s16 func_80B5B9B0(PlayState* play, Actor* thisx) {
    if (Message_GetState(&play->msgCtx) == TEXT_STATE_CLOSING) {
        return false;
    }
    return true;
}

void EnZl5_GetText(EnZl5* this, PlayState* play) {
    return
}

void EnZl5_Idle(EnZl5* this, PlayState* play) {
    func_800343CC(play, &this->actor, &this->unk_1E0.unk_00, this->collider.dim.radius + 60.0f, EnZl5_GetText,
                  func_80B5B9B0);
}

void EnZl5_Init(Actor* thisx, PlayState* play) {
    EnZl5* this = (EnZl5*)thisx;

    SkelAnime_InitFlex(play, &this->skelAnime, &gChildZeldaCivSkel, NULL, this->jointTable, this->morphTable, 18);
    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawCircle, 18.0f);
    Animation_ChangeByInfo(&this->skelAnime, sAnimationInfo, ZL5_ANIM_IDLE);
    Collider_InitCylinder(play, &this->collider);
    Collider_SetCylinder(play, &this->collider, &this->actor, &sCylinderInit);
    CollisionCheck_SetInfo2(&this->actor.colChkInfo, NULL, &sColChkInfoInit);
    Actor_SetScale(&this->actor, 0.01f);
    this->actor.targetMode = 6;
    this->actionFunc = EnZl5_Idle;
    this->eyeExpression = this->mouthExpression = ZL5_MOUTH_NEUTRAL;
}

void EnZl5_Destroy(Actor* thisx, PlayState* play) {
    EnZl5* this = (EnZl5*)thisx;
}

void EnZl5_Update(Actor* thisx, PlayState* play) {
    EnZl5* this = (EnZl5*)thisx;

    SkelAnime_Update(&this->skelAnime);

    EnZl5_UpdateFace(this);
}

void EnZl5_UpdateFace(EnZl5* this) {
    if (this->blinkTimer > 0) {
        this->blinkTimer--;
    } else {
        this->blinkTimer = 0;
    }
    if (this->blinkTimer <= 2) {
        this->leftEyeState = this->rightEyeState = this->blinkTimer;
    }
    switch (this->eyeExpression) {
        case ZL5_EYES_NEUTRAL:
            if (this->blinkTimer == 0) {
                this->blinkTimer = Rand_S16Offset(30, 30);
            }
            break;
        case ZL5_EYES_SHUT:
            if (this->blinkTimer == 0) {
                this->leftEyeState = this->rightEyeState = ZL5_EYE_SHUT;
            }
            break;
        case ZL5_EYES_LOOK_LEFT:
            if (this->blinkTimer == 0) {
                this->leftEyeState = ZL5_EYE_LOOK_OUT;
                this->rightEyeState = ZL5_EYE_LOOK_IN;
            }
            break;
        case ZL5_EYES_LOOK_RIGHT:
            if (this->blinkTimer == 0) {
                this->leftEyeState = ZL5_EYE_LOOK_IN;
                this->rightEyeState = ZL5_EYE_LOOK_OUT;
            }
            break;
        case ZL5_EYES_WIDE:
            if (this->blinkTimer == 0) {
                this->leftEyeState = this->rightEyeState = ZL5_EYE_WIDE;
            }
            break;
        case ZL5_EYES_SQUINT:
            if (this->blinkTimer == 0) {
                this->leftEyeState = this->rightEyeState = ZL5_EYE_SQUINT;
            }
            break;
        case ZL5_EYES_OPEN:
            if (this->blinkTimer >= 3) {
                this->blinkTimer = ZL5_EYE_OPEN;
            }
            break;
    }
    switch (this->mouthExpression) {
        case ZL5_MOUTH_HAPPY:
            this->mouthState = 1;
            break;
        case ZL5_MOUTH_WORRIED:
            this->mouthState = 2;
            break;
        case ZL5_MOUTH_SURPRISED:
            this->mouthState = 3;
            break;
        default:
            this->mouthState = 0;
            break;
    }
}

s32 EnZl5_OverrideLimbDraw(PlayState* play, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    EnZl5* this = (EnZl5*)thisx;
    Vec3s sp1C;

    if (limbIndex == 17) {
        sp1C = this->unk_1E0.unk_08;
        Matrix_Translate(900.0f, 0.0f, 0.0f, MTXMODE_APPLY);
        Matrix_RotateX(BINANG_TO_RAD_ALT(sp1C.y), MTXMODE_APPLY);
        Matrix_RotateZ(BINANG_TO_RAD_ALT(sp1C.x), MTXMODE_APPLY);
        Matrix_Translate(-900.0f, 0.0f, 0.0f, MTXMODE_APPLY);
    }
    if (limbIndex == 10) {
        sp1C = this->unk_1E0.unk_0E;
        Matrix_RotateY(BINANG_TO_RAD_ALT(sp1C.y), MTXMODE_APPLY);
        Matrix_RotateX(BINANG_TO_RAD_ALT(sp1C.x), MTXMODE_APPLY);
    }
    if ((limbIndex >= 3) && (limbIndex < 7)) {
        *dList = NULL;
    }
    return false;
}

void EnZl5_PostLimbDraw(PlayState* play, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx) {
    Vec3f zeroVec = { 0.0f, 0.0f, 0.0f };
    EnZl5* this = (EnZl5*)thisx;

    if (limbIndex == 17) {
        Matrix_MultVec3f(&zeroVec, &this->actor.focus.pos);
    }
}

void EnZl5_Draw(Actor* thisx, PlayState* play) {
    EnZl5* this = (EnZl5*)thisx;
    void* mouthTex[] = { gChildZeldaMouthNeutralTex, gChildZeldaMouthHappyTex, gChildZeldaMouthWorriedTex,
                         gChildZeldaMouthSurprisedTex };
    void* eyeTex[] = {
        gChildZeldaEyeOpenTex,   gChildZeldaEyeBlinkTex, gChildZeldaEyeShutTex, gChildZeldaEyeWideTex,
        gChildZeldaEyeSquintTex, gChildZeldaEyeOutTex,   gChildZeldaEyeInTex,
    };

    OPEN_DISPS(play->state.gfxCtx, __FILE__, __LINE__);
    gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(eyeTex[this->rightEyeState]));
    gSPSegment(POLY_OPA_DISP++, 0x09, SEGMENTED_TO_VIRTUAL(eyeTex[this->leftEyeState]));
    gSPSegment(POLY_OPA_DISP++, 0x0A, SEGMENTED_TO_VIRTUAL(mouthTex[this->mouthState]));
    Gfx_SetupDL_25Opa(play->state.gfxCtx);
    SkelAnime_DrawFlexOpa(play, this->skelAnime.skeleton, this->skelAnime.jointTable, this->skelAnime.dListCount,
                          EnZl5_OverrideLimbDraw, EnZl5_PostLimbDraw, this);
    CLOSE_DISPS(play->state.gfxCtx, __FILE__, __LINE__);
}
