/*
 * File: z_obj_kokirisword.c
 * Overlay: ovl_Obj_KokiriSword
 * Description: Sword model to be held by Following Mido
 */

#include "z_obj_kokirisword.h"
#include "src/overlays/actors/ovl_En_Md/z_en_md.h"
#include "assets/objects/object_md/object_md.h"

#define FLAGS ACTOR_FLAG_22

void ObjKokiriSword_Init(Actor* thisx, PlayState* play);
void ObjKokiriSword_Destroy(Actor* thisx, PlayState* play);
void ObjKokiriSword_Update(Actor* thisx, PlayState* play);
void ObjKokiriSword_Draw(Actor* thisx, PlayState* play);

const ActorInit Obj_KokiriSword_InitVars = {
    ACTOR_OBJ_KOKIRISWORD,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_MD,
    sizeof(ObjKokiriSword),
    (ActorFunc)ObjKokiriSword_Init,
    (ActorFunc)ObjKokiriSword_Destroy,
    (ActorFunc)ObjKokiriSword_Update,
    (ActorFunc)ObjKokiriSword_Draw,
};

void ObjKokiriSword_Init(Actor* thisx, PlayState* play) {
    ((ObjKokiriSword*)thisx)->isVisible = true;
}

void ObjKokiriSword_Destroy(Actor* thisx, PlayState* play) {

}

void ObjKokiriSword_Update(Actor* thisx, PlayState* play) {

}

void ObjKokiriSword_Draw(Actor* thisx, PlayState* play) {
    if (((ObjKokiriSword*)thisx)->isVisible) {
        OPEN_DISPS(play->state.gfxCtx, "../z_obj_kokirisword.c", __LINE__);

        Gfx_SetupDL_25Opa(play->state.gfxCtx);
        gSPMatrix(POLY_OPA_DISP++, Matrix_NewMtx(play->state.gfxCtx, "../z_obj_kokirisword.c", __LINE__),
                  G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_OPA_DISP++, gKokiriSwordModelDL);

        CLOSE_DISPS(play->state.gfxCtx, "../z_obj_kokirisword.c", __LINE__);
    }
}
