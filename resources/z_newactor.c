#include "newactor.h"
#include "assets/objects/object_newactor/object_newactor.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

void NewActor_Init(Actor* thisx, PlayState* play);
void NewActor_Destroy(Actor* thisx, PlayState* play);
void NewActor_Update(Actor* thisx, PlayState* play);
void NewActor_Draw(Actor* thisx, PlayState* play);

const ActorInit En_NewActor_InitVars = {
    ACTOR_NEWACTOR,
    ACTORCAT_MISC,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(NewActor),
    (ActorFunc)NewActor_Init,
    (ActorFunc)NewActor_Destroy,
    (ActorFunc)NewActor_Update,
    (ActorFunc)NewActor_Draw,
};

void NewActor_Init(Actor* thisx, PlayState* play) {

}

void NewActor_Destroy(Actor* thisx, PlayState* play) {

}

void NewActor_Update(Actor* thisx, PlayState* play) {
    // SkelAnime_Update(&this->skelAnime);
}

s32 NewActor_OverrideLimbDraw(PlayState* play, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx,
                              Gfx** gfx) {
    return false;
}

void NewActor_PostLimbDraw(PlayState* play2, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx, Gfx** gfx) {
    return;
}

void NewActor_Draw(Actor* thisx, PlayState* play) {
    GfxPrint printer;
    Gfx* gfx;

    OPEN_DISPS(play->state.gfxCtx, __FILE__, __LINE__);

    gfx = POLY_OPA_DISP + 1;
    gSPDisplayList(OVERLAY_DISP++, gfx);

    GfxPrint_Init(&printer);
    GfxPrint_Open(&printer, gfx);

    GfxPrint_SetColor(&printer, 255, 0, 255, 255);
    GfxPrint_SetPos(&printer, 10, 10);
    GfxPrint_Printf(&printer, "Hello from NewActor_Draw");

    gfx = GfxPrint_Close(&printer);
    GfxPrint_Destroy(&printer);

    gSPEndDisplayList(gfx++);
    gSPBranchList(POLY_OPA_DISP, gfx);
    POLY_OPA_DISP = gfx;

    CLOSE_DISPS(play->state.gfxCtx, __FILE__, __LINE__);

    /*
     *
     OPEN_DISPS(play->state.gfxCtx, __FILE__, __LINE__);

     Gfx_SetupDL_25Opa(play->state.gfxCtx);
     gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(play->state.gfxCtx, __FILE__, __LINE__),
               G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
     gSPDisplayList(POLY_OPA_DISP++, gNewActorDL);

     CLOSE_DISPS(play->state.gfxCtx, __FILE__, __LINE__);
     */

    /*
     func_80034BA0(play, &this->skelAnime, NewActor_OverrideLimbDraw, NewActor_PostLimbDraw, &this->actor, this->alpha);
     */
}
