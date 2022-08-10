#include "z_en_greeble.h"
#include "assets/objects/object_greeble/object_greeble.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

void EnGreeble_Init(Actor* thisx, PlayState* play);
void EnGreeble_Destroy(Actor* thisx, PlayState* play);
void EnGreeble_Update(Actor* thisx, PlayState* play);
void EnGreeble_Draw(Actor* thisx, PlayState* play);

const ActorInit En_Greeble_InitVars = {
    ACTOR_EN_GREEBLE,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_GREEBLE,
    sizeof(EnGreeble),
    (ActorFunc)EnGreeble_Init,
    (ActorFunc)EnGreeble_Destroy,
    (ActorFunc)EnGreeble_Update,
    (ActorFunc)EnGreeble_Draw,
};

typedef enum {
    ENGREEBLEWORM_LIMB_NONE,
    ENGREEBLEWORM_LIMB_HEAD,
    ENGREEBLEWORM_LIMB_MIDDLE,
    ENGREEBLEWORM_LIMB_TAIL,
    ENGREEBLEWORM_LIMB_MAX
} EnGreebleWormLimbs;

typedef enum { ENGREEBLEWORM_ROTATE_ANIM } EnGreebleAnimation;

static AnimationInfo sAnimationInfo[] = {
    { &gGreebleWormSkelRotateAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, 0.0f },
};

void EnGreeble_Init(Actor* thisx, PlayState* play) {
    EnGreeble* this = (EnGreeble*)thisx;

    SkelAnime_Init(play, &this->skelAnime, &gGreebleWormSkel, NULL, this->jointTable, this->morphTable,
                   ENGREEBLEWORM_LIMB_MAX);
    Animation_ChangeByInfo(&this->skelAnime, sAnimationInfo, ENGREEBLEWORM_ROTATE_ANIM);

    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawCircle, 18.0f);

    // Actor_SetScale(&this->actor, 0.01f);

    this->alpha = 255;

    this->actor.gravity = 0;
}

void EnGreeble_Destroy(Actor* thisx, PlayState* play) {
    EnGreeble* this = (EnGreeble*)thisx;
}

void EnGreeble_Update(Actor* thisx, PlayState* play) {
    EnGreeble* this = (EnGreeble*)thisx;

    SkelAnime_Update(&this->skelAnime);
}

s32 EnGreeble_OverrideLimbDraw(PlayState* play, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx,
                               Gfx** gfx) {
    return false;
}

void EnGreeble_PostLimbDraw(PlayState* play2, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx, Gfx** gfx) {
    return;
}

void EnGreeble_Draw(Actor* thisx, PlayState* play) {
    EnGreeble* this = (EnGreeble*)thisx;

    OPEN_DISPS(play->state.gfxCtx, __FILE__, __LINE__);

    Gfx_SetupDL_25Opa(play->state.gfxCtx);
    SkelAnime_DrawOpa(play, this->skelAnime.skeleton, this->skelAnime.jointTable, NULL, NULL, NULL);

    CLOSE_DISPS(play->state.gfxCtx, __FILE__, __LINE__);
}
