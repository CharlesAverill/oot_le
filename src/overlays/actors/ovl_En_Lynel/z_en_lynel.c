#include "z_en_lynel.h"
#include "assets/objects/object_lynel/object_lynel.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

void EnLynel_Init(Actor* thisx, PlayState* play);
void EnLynel_Destroy(Actor* thisx, PlayState* play);
void EnLynel_Update(Actor* thisx, PlayState* play);
void EnLynel_Draw(Actor* thisx, PlayState* play);

const ActorInit En_Lynel_InitVars = {
    ACTOR_EN_LYNEL,
    ACTORCAT_ENEMY,
    FLAGS,
    OBJECT_LYNEL,
    sizeof(EnLynel),
    (ActorFunc)EnLynel_Init,
    (ActorFunc)EnLynel_Destroy,
    (ActorFunc)EnLynel_Update,
    (ActorFunc)EnLynel_Draw,
};

typedef enum { ENLYNEL_IDLE_ANIM } EnLynelAnimation;

static AnimationInfo sAnimationInfo[] = {
    { &gLynelTailSkelTailidleAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, 0.0f },
};

void EnLynel_Init(Actor* thisx, PlayState* play) {
    EnLynel* this = (EnLynel*)thisx;

    SkelAnime_InitFlex(play, &this->skelAnime, &gLynelTailSkel, NULL, this->jointTable, this->morphTable, 4);
    Animation_ChangeByInfo(&this->skelAnime, sAnimationInfo, ENLYNEL_IDLE_ANIM);

    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawCircle, 18.0f);

    // Actor_SetScale(&this->actor, 0.01f);

    this->alpha = 255;
}

void EnLynel_Destroy(Actor* thisx, PlayState* play) {
    EnLynel* this = (EnLynel*)thisx;
}

void EnLynel_Update(Actor* thisx, PlayState* play) {
    EnLynel* this = (EnLynel*)thisx;

    SkelAnime_Update(&this->skelAnime);
}

s32 EnLynel_OverrideLimbDraw(PlayState* play, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx) {
    return false;
}

void EnLynel_PostLimbDraw(PlayState* play2, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx, Gfx** gfx) {
    return;
}

void EnLynel_Draw(Actor* thisx, PlayState* play) {
    EnLynel* this = (EnLynel*)thisx;

    OPEN_DISPS(play->state.gfxCtx, __FILE__, __LINE__);

    Gfx_SetupDL_37Opa(play->state.gfxCtx);
    SkelAnime_DrawFlexOpa(play, this->skelAnime.skeleton, this->skelAnime.jointTable, this->skelAnime.dListCount, NULL,
                          NULL, this);

    // func_80034BA0(play, &this->skelAnime, EnLynel_OverrideLimbDraw, EnLynel_PostLimbDraw, &this->actor, this->alpha);

    /*
    Gfx_SetupDL_25Opa(play->state.gfxCtx);
    gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(play->state.gfxCtx, __FILE__, __LINE__),
              G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(POLY_OPA_DISP++, gLynelBodyDL);
    */

    CLOSE_DISPS(play->state.gfxCtx, __FILE__, __LINE__);
}
