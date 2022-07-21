/*
 * File: z_en_md.c
 * Overlay: ovl_En_Md
 * Description: Mido
 */

#include "z_en_md.h"
#include "assets/objects/object_md/object_md.h"
#include "assets/objects/gameplay_keep/gameplay_keep.h"
#include "overlays/actors/ovl_En_Elf/z_en_elf.h"

#define FLAGS (ACTOR_FLAG_0 | ACTOR_FLAG_3 | ACTOR_FLAG_4 | ACTOR_FLAG_25)

#define TELEPORT_WAIT 30
#define STAB_WAIT 20

void EnMd_Init(Actor* thisx, PlayState* play);
void EnMd_Destroy(Actor* thisx, PlayState* play);
void EnMd_Update(Actor* thisx, PlayState* play);
void EnMd_Draw(Actor* thisx, PlayState* play);

void func_80AAB874(EnMd* this, PlayState* play);
void func_80AAB8F8(EnMd* this, PlayState* play);
void func_80AAB948(EnMd* this, PlayState* play);
void func_80AABC10(EnMd* this, PlayState* play);
void func_80AABD0C(EnMd* this, PlayState* play);

static Vec3f sZeroVec = { 0.0f, 0.0f, 0.0f };

const ActorInit En_Md_InitVars = {
    ACTOR_EN_MD,
    ACTORCAT_NPC,
    FLAGS,
    OBJECT_MD,
    sizeof(EnMd),
    (ActorFunc)EnMd_Init,
    (ActorFunc)EnMd_Destroy,
    (ActorFunc)EnMd_Update,
    (ActorFunc)EnMd_Draw,
};

// NPC Collider
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
    { 26, 44, 0, { 0, 0, 0 } },
};

// Sword Collider
static ColliderCylinderInit sKokiriSwordColliderInit = {
    {
        COLTYPE_NONE,
        AT_ON | AT_TYPE_PLAYER,
        AC_NONE,
        OC1_NONE,
        OC2_TYPE_PLAYER,
        COLSHAPE_CYLINDER,
    },
    {
        ELEMTYPE_UNK2,
        { 0x00000100, 0x00, 0x01 },
        { 0xFFCFFFFF, 0x00, 0x00 },
        TOUCH_ON | TOUCH_SFX_NORMAL,
        BUMP_NONE,
        OCELEM_NONE,
    },
    { 30, 40, 0, { 0, 0, 0 } },
};

static CollisionCheckInfoInit2 sColChkInfoInit = { 0, 0, 0, 0, MASS_IMMOVABLE };
static CollisionCheckInfoInit2 sColChkInfoInit_Follower = { 0, 0, 0, 0, MASS_HEAVY };

typedef enum {
    /*  0 */ ENMD_ANIM_0,
    /*  1 */ ENMD_ANIM_1,
    /*  2 */ ENMD_ANIM_2,
    /*  3 */ ENMD_ANIM_3,
    /*  4 */ ENMD_ANIM_4,
    /*  5 */ ENMD_ANIM_5,
    /*  6 */ ENMD_ANIM_6,
    /*  7 */ ENMD_ANIM_7,
    /*  8 */ ENMD_ANIM_WALK,
    /*  9 */ ENMD_ANIM_9,
    /* 10 */ ENMD_ANIM_10,
    /* 11 */ ENMD_ANIM_11,
    /* 12 */ ENMD_ANIM_12,
    /* 13 */ ENMD_ANIM_13,
    /* 14 */ ENMD_ANIM_WALKFAST,
    /* 15 */ ENMD_ANIM_STAB
} EnMdAnimation;

typedef enum {
    ENMD_LIMB_ROOT = 1,
    ENMD_LIMB_WAIST,
    ENMD_LIMB_LEFT_THIGH,
    ENMD_LIMB_LEFT_LEG,
    ENMD_LIMB_LEFT_FOOT,
    ENMD_LIMB_RIGHT_THIGH,
    ENMD_LIMB_RIGHT_LEG,
    ENMD_LIMB_RIGHT_FOOT,
    ENMD_LIMB_TORSO,
    ENMD_LIMB_LEFT_UPPER_ARM,
    ENMD_LIMB_LEFT_FOREARM,
    ENMD_LIMB_LEFT_HAND,
    ENMD_LIMB_RIGHT_UPPER_ARM,
    ENMD_LIMB_RIGHT_FOREARM,
    ENMD_LIMB_RIGHT_HAND,
    ENMD_LIMB_HEAD,
    ENMD_LIMB_SWORD
} EnMdLimbs;

static AnimationInfo sAnimationInfo[] = {
    { &gMidoHandsOnHipsIdleAnim, 0.0f, 0.0f, -1.0f, ANIMMODE_LOOP, 0.0f },
    { &gMidoHandsOnHipsIdleAnim, 0.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -10.0f },
    { &gMidoRaiseHand1Anim, 1.0f, 0.0f, -1.0f, ANIMMODE_ONCE, -1.0f },
    { &gMidoHaltAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -1.0f },
    { &gMidoPutHandDownAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_ONCE, -1.0f },
    { &gMidoAnnoyedPointedHeadIdle1Anim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -1.0f },
    { &gMidoAnnoyedPointedHeadIdle2Anim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -1.0f },
    { &gMidoAnim_92B0, 1.0f, 0.0f, -1.0f, ANIMMODE_ONCE, -1.0f },
    { &gMidoWalkingAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -1.0f },
    { &gMidoHandsOnHipsTransitionAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_ONCE, -1.0f },
    { &gMidoHandsOnHipsIdleAnim, 0.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -8.0f },
    { &gMidoSlamAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -1.0f },
    { &gMidoRaiseHand2Anim, 1.0f, 0.0f, -1.0f, ANIMMODE_ONCE, -1.0f },
    { &gMidoAngryHeadTurnAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -1.0f },
    { &gMidoWalkingAnim, 3.0f, 0.0f, -1.0f, ANIMMODE_LOOP, -1.0f },
    { &gMidoSkelStabAnim, 1.0f, 0.0f, -1.0f, ANIMMODE_ONCE, -1.0f }
};

bool EnMd_IsFollower(EnMd* this) {
    return (this->actor.params & IS_FOLLOWER_MASK) != 0;
}

void func_80AAA250(EnMd* this) {
    f32 startFrame;

    startFrame = this->skelAnime.startFrame;
    this->skelAnime.startFrame = this->skelAnime.endFrame;
    this->skelAnime.curFrame = this->skelAnime.endFrame;
    this->skelAnime.endFrame = startFrame;
    this->skelAnime.playSpeed = -1.0f;
}

void func_80AAA274(EnMd* this) {
    switch (this->unk_20A) {
        case 0:
            Animation_ChangeByInfo(&this->skelAnime, sAnimationInfo, ENMD_ANIM_2);
            this->unk_20A++;
            FALLTHROUGH;
        case 1:
            if (Animation_OnFrame(&this->skelAnime, this->skelAnime.endFrame)) {
                Animation_ChangeByInfo(&this->skelAnime, sAnimationInfo, ENMD_ANIM_3);
                this->unk_20A++;
            }
            break;
    }
}

void func_80AAA308(EnMd* this) {
    switch (this->unk_20A) {
        case 0:
            Animation_ChangeByInfo(&this->skelAnime, sAnimationInfo, ENMD_ANIM_4);
            this->unk_20A++;
            FALLTHROUGH;
        case 1:
            if (Animation_OnFrame(&this->skelAnime, this->skelAnime.endFrame)) {
                Animation_ChangeByInfo(&this->skelAnime, sAnimationInfo, ENMD_ANIM_5);
                this->unk_20A++;
            }
            break;
    }
}

void func_80AAA39C(EnMd* this) {
    switch (this->unk_20A) {
        case 0:
            Animation_ChangeByInfo(&this->skelAnime, sAnimationInfo, ENMD_ANIM_2);
            func_80AAA250(this);
            this->unk_20A++;
            FALLTHROUGH;
        case 1:
            if (Animation_OnFrame(&this->skelAnime, this->skelAnime.endFrame)) {
                Animation_ChangeByInfo(&this->skelAnime, sAnimationInfo, ENMD_ANIM_7);
                this->unk_20A++;
            } else {
                break;
            }
            FALLTHROUGH;
        case 2:
            if (Animation_OnFrame(&this->skelAnime, this->skelAnime.endFrame)) {
                Animation_ChangeByInfo(&this->skelAnime, sAnimationInfo, ENMD_ANIM_WALK);
                this->unk_20A++;
            }
            break;
    }
}

void func_80AAA474(EnMd* this) {
    switch (this->unk_20A) {
        case 0:
            Animation_ChangeByInfo(&this->skelAnime, sAnimationInfo, ENMD_ANIM_7);
            this->unk_20A++;
            FALLTHROUGH;
        case 1:
            if (Animation_OnFrame(&this->skelAnime, this->skelAnime.endFrame)) {
                Animation_ChangeByInfo(&this->skelAnime, sAnimationInfo, ENMD_ANIM_10);
                this->unk_20A++;
            }
            break;
    }
}

void func_80AAA508(EnMd* this) {
    switch (this->unk_20A) {
        case 0:
            Animation_ChangeByInfo(&this->skelAnime, sAnimationInfo, ENMD_ANIM_2);
            func_80AAA250(this);
            this->unk_20A++;
            FALLTHROUGH;
        case 1:
            if (Animation_OnFrame(&this->skelAnime, this->skelAnime.endFrame)) {
                Animation_ChangeByInfo(&this->skelAnime, sAnimationInfo, ENMD_ANIM_10);
                this->unk_20A++;
            }
            break;
    }
}

void func_80AAA5A4(EnMd* this) {
    switch (this->unk_20A) {
        case 0:
            Animation_ChangeByInfo(&this->skelAnime, sAnimationInfo, ENMD_ANIM_9);
            this->unk_20A++;
            FALLTHROUGH;
        case 1:
            if (Animation_OnFrame(&this->skelAnime, this->skelAnime.endFrame)) {
                Animation_ChangeByInfo(&this->skelAnime, sAnimationInfo, ENMD_ANIM_6);
                this->unk_20A++;
            }
            break;
    }
}

void func_80AAA638(EnMd* this) {
    switch (this->unk_20A) {
        case 0:
            Animation_ChangeByInfo(&this->skelAnime, sAnimationInfo, ENMD_ANIM_9);
            func_80AAA250(this);
            this->unk_20A++;
            FALLTHROUGH;
        case 1:
            if (Animation_OnFrame(&this->skelAnime, this->skelAnime.endFrame)) {
                Animation_ChangeByInfo(&this->skelAnime, sAnimationInfo, ENMD_ANIM_10);
                this->unk_20A++;
            }
            break;
    }
}

void func_80AAA6D4(EnMd* this) {
    switch (this->unk_20A) {
        case 0:
            Animation_ChangeByInfo(&this->skelAnime, sAnimationInfo, ENMD_ANIM_11);
            this->unk_20A++;
            FALLTHROUGH;
        case 1:
            if (Animation_OnFrame(&this->skelAnime, this->skelAnime.endFrame)) {
                Animation_ChangeByInfo(&this->skelAnime, sAnimationInfo, ENMD_ANIM_6);
                this->unk_20A++;
            }
            break;
    }
}

void func_80AAA768(EnMd* this) {
    switch (this->unk_20A) {
        case 0:
            Animation_ChangeByInfo(&this->skelAnime, sAnimationInfo, ENMD_ANIM_12);
            this->unk_20A++;
            FALLTHROUGH;
        case 1:
            if (Animation_OnFrame(&this->skelAnime, this->skelAnime.endFrame)) {
                Animation_ChangeByInfo(&this->skelAnime, sAnimationInfo, ENMD_ANIM_3);
                this->unk_20A++;
            }
            break;
    }
}

void func_80AAA7FC(EnMd* this) {
    switch (this->unk_20A) {
        case 0:
            Animation_ChangeByInfo(&this->skelAnime, sAnimationInfo, ENMD_ANIM_13);
            this->unk_20A++;
            FALLTHROUGH;
        case 1:
            if (Animation_OnFrame(&this->skelAnime, this->skelAnime.endFrame)) {
                Animation_ChangeByInfo(&this->skelAnime, sAnimationInfo, ENMD_ANIM_6);
                this->unk_20A++;
            }
            break;
    }
}

void func_80AAA890(EnMd* this) {
    switch (this->unk_20A) {
        case 0:
            Animation_ChangeByInfo(&this->skelAnime, sAnimationInfo, ENMD_ANIM_7);
            func_80AAA250(this);
            this->unk_20A++;
            FALLTHROUGH;
        case 1:
            if (Animation_OnFrame(&this->skelAnime, this->skelAnime.endFrame)) {
                Animation_ChangeByInfo(&this->skelAnime, sAnimationInfo, ENMD_ANIM_10);
                this->unk_20A++;
            }
            break;
    }
}

void func_80AAA92C(EnMd* this, u8 arg1) {
    this->unk_20B = arg1;
    this->unk_20A = 0;
}

void func_80AAA93C(EnMd* this) {
    if (this->isFollowing && this->actor.speedXZ != 0.0f) {
        return;
    }

    switch (this->unk_20B) {
        case 1:
            func_80AAA274(this);
            break;
        case 2:
            func_80AAA308(this);
            break;
        case 3:
            func_80AAA39C(this);
            break;
        case 4:
            func_80AAA474(this);
            break;
        case 5:
            func_80AAA508(this);
            break;
        case 6:
            func_80AAA5A4(this);
            break;
        case 7:
            func_80AAA638(this);
            break;
        case 8:
            func_80AAA6D4(this);
            break;
        case 9:
            func_80AAA768(this);
            break;
        case 10:
            func_80AAA7FC(this);
            break;
        case 11:
            func_80AAA890(this);
    }
}

void func_80AAAA24(EnMd* this) {
    if (this->unk_1E0.unk_00 != 0) {
        switch (this->actor.textId) {
            case 0x102F:
                if ((this->unk_208 == 0) && (this->unk_20B != 1)) {
                    func_80AAA92C(this, 1);
                }
                if ((this->unk_208 == 2) && (this->unk_20B != 2)) {
                    func_80AAA92C(this, 2);
                }
                if ((this->unk_208 == 5) && (this->unk_20B != 8)) {
                    func_80AAA92C(this, 8);
                }
                if ((this->unk_208 == 11) && (this->unk_20B != 9)) {
                    func_80AAA92C(this, 9);
                }
                break;
            case 0x1033:
                if ((this->unk_208 == 0) && (this->unk_20B != 1)) {
                    func_80AAA92C(this, 1);
                }
                if ((this->unk_208 == 1) && (this->unk_20B != 2)) {
                    func_80AAA92C(this, 2);
                }
                if ((this->unk_208 == 5) && (this->unk_20B != 10)) {
                    func_80AAA92C(this, 10);
                }
                if ((this->unk_208 == 7) && (this->unk_20B != 9)) {
                    func_80AAA92C(this, 9);
                }
                break;
            case 0x1030:
            case 0x1034:
            case 0x1045:
                if ((this->unk_208 == 0) && (this->unk_20B != 1)) {
                    func_80AAA92C(this, 1);
                }
                break;
            case 0x1046:
                if ((this->unk_208 == 0) && (this->unk_20B != 6)) {
                    func_80AAA92C(this, 6);
                }
                break;
        }
    } else if (this->skelAnime.animation != &gMidoHandsOnHipsIdleAnim && !EnMd_IsFollower(this)) {
        Animation_ChangeByInfo(&this->skelAnime, sAnimationInfo, ENMD_ANIM_10);
        func_80AAA92C(this, 0);
    }

    func_80AAA93C(this);
}

s16 func_80AAAC78(EnMd* this, PlayState* play) {
    s16 dialogState = Message_GetState(&play->msgCtx);

    if ((this->unk_209 == TEXT_STATE_AWAITING_NEXT) || (this->unk_209 == TEXT_STATE_EVENT) ||
        (this->unk_209 == TEXT_STATE_CLOSING) || (this->unk_209 == TEXT_STATE_DONE_HAS_NEXT)) {
        if (this->unk_209 != dialogState) {
            this->unk_208++;
        }
    }

    this->unk_209 = dialogState;
    return dialogState;
}

u16 EnMd_GetTextKokiriForest(PlayState* play, EnMd* this) {
    u16 reactionText = Text_GetFaceReaction(play, 0x11);

    if (reactionText != 0) {
        return reactionText;
    }

    this->unk_208 = 0;
    this->unk_209 = TEXT_STATE_NONE;

    if (CHECK_QUEST_ITEM(QUEST_KOKIRI_EMERALD)) {
        return 0x1045;
    }

    if (GET_EVENTCHKINF(EVENTCHKINF_04)) {
        return 0x1034;
    }

    if (INV_CONTENT(SLOT_SLINGSHOT) == ITEM_SLINGSHOT) {
        return 0x1033;
    }

    if (GET_INFTABLE(INFTABLE_0C)) {
        return 0x1030;
    }

    return 0x102F;
}

u16 EnMd_GetTextKokiriHome(PlayState* play, EnMd* this) {
    this->unk_208 = 0;
    this->unk_209 = TEXT_STATE_NONE;

    if (GET_EVENTCHKINF(EVENTCHKINF_40)) {
        return 0x1028;
    }

    return 0x1046;
}

u16 EnMd_GetTextLostWoods(PlayState* play, EnMd* this) {
    this->unk_208 = 0;
    this->unk_209 = TEXT_STATE_NONE;

    if (GET_EVENTCHKINF(EVENTCHKINF_48)) {
        if (GET_INFTABLE(INFTABLE_19)) {
            return 0x1071;
        }
        return 0x1070;
    }

    if (GET_EVENTCHKINF(EVENTCHKINF_0A)) {
        return 0x1068;
    }

    if (GET_INFTABLE(INFTABLE_15)) {
        return 0x1061;
    }

    return 0x1060;
}

u16 EnMd_GetText(PlayState* play, Actor* thisx) {
    EnMd* this = (EnMd*)thisx;

    if (EnMd_IsFollower(this)) {
        if(AMMO(ITEM_SLINGSHOT) <= 0) {
            return 0x71BF;
        }
        return 0x71B5;
    }

    switch (play->sceneNum) {
        case SCENE_SPOT04:
            return EnMd_GetTextKokiriForest(play, this);
        case SCENE_KOKIRI_HOME4:
            return EnMd_GetTextKokiriHome(play, this);
        case SCENE_SPOT10:
            return EnMd_GetTextLostWoods(play, this);
        default:
            return 0x71B5;
    }
}

s16 func_80AAAF04(PlayState* play, Actor* thisx) {
    EnMd* this = (EnMd*)thisx;
    switch (func_80AAAC78(this, play)) {
        case TEXT_STATE_NONE:
        case TEXT_STATE_DONE_HAS_NEXT:
        case TEXT_STATE_DONE_FADING:
        case TEXT_STATE_CHOICE:
        case TEXT_STATE_DONE:
        case TEXT_STATE_SONG_DEMO_DONE:
        case TEXT_STATE_8:
        case TEXT_STATE_9:
            return 1;
        case TEXT_STATE_CLOSING:
            switch (this->actor.textId) {
                case 0x1028:
                    SET_EVENTCHKINF(EVENTCHKINF_0F);
                    break;
                case 0x102F:
                    SET_EVENTCHKINF(EVENTCHKINF_02);
                    SET_INFTABLE(INFTABLE_0C);
                    break;
                case 0x1060:
                    SET_INFTABLE(INFTABLE_15);
                    break;
                case 0x1070:
                    SET_INFTABLE(INFTABLE_19);
                    break;
                case 0x1033:
                case 0x1067:
                    return 2;
                case 0x71BF:
                    Inventory_ChangeAmmo(ITEM_SLINGSHOT, 10);
                    break;
            }
            return 0;
        case TEXT_STATE_EVENT:
            if(!this->spawnedKokiriSword) {
                this->spawnedKokiriSword = true;
                Actor_Spawn(&play->actorCtx, play, ACTOR_ITEM_SHIELD, this->actor.home.pos.x,
                                   this->actor.home.pos.y, this->actor.home.pos.z, 0, 0, 0, 6);
            }
            if (Message_ShouldAdvance(play)) {
                return 2;
            }
            FALLTHROUGH;
        default:
            return 1;
    }
}

u8 EnMd_ShouldSpawn(EnMd* this, PlayState* play) {
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

    if (play->sceneNum == SCENE_SPOT10 || play->sceneNum == SCENE_LEARNING01 || play->sceneNum == SCENE_YDAN_BOSS ) {
        return 1;
    }

    if (play->sceneNum == SCENE_YDAN &&
        (play->roomCtx.curRoom.num == 0 || GET_PLAYER(play)->hasFollowingMido || this->actor.params == 1)) {
        return 1;
    }

    return 0;
}

void EnMd_UpdateEyes(EnMd* this) {
    if (DECR(this->blinkTimer) == 0) {
        this->eyeIdx++;
        if (this->eyeIdx > 2) {
            this->blinkTimer = Rand_S16Offset(30, 30);
            this->eyeIdx = 0;
        }
    }
}

void func_80AAB158(EnMd* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    s16 absYawDiff;
    s16 temp;
    s16 temp2;
    s16 yawDiff;

    if (this->actor.xzDistToPlayer < 170.0f) {
        yawDiff = (f32)this->actor.yawTowardsPlayer - this->actor.shape.rot.y;
        absYawDiff = ABS(yawDiff);

        temp = (absYawDiff <= func_800347E8(2)) ? 2 : 1;
        temp2 = 1;
    } else {
        temp = 1;
        temp2 = 0;
    }

    if (this->unk_1E0.unk_00 != 0) {
        temp = 4;
    }

    if (this->actionFunc == func_80AABD0C) {
        temp = 1;
        temp2 = 0;
    }
    if (this->actionFunc == func_80AAB8F8) {
        temp = 4;
        temp2 = 1;
    }

    if ((play->csCtx.state != CS_STATE_IDLE) || gDbgCamEnabled) {
        this->unk_1E0.unk_18 = play->view.eye;
        this->unk_1E0.unk_14 = 40.0f;
        temp = 2;
    } else {
        this->unk_1E0.unk_18 = player->actor.world.pos;
        this->unk_1E0.unk_14 = (gSaveContext.linkAge > 0) ? 0.0f : -18.0f;
    }

    func_80034A14(&this->actor, &this->unk_1E0, 2, temp);
    if (this->actionFunc != func_80AABC10 && temp2) {
        if (EnMd_IsFollower(this) && Message_GetState(&play->msgCtx) == TEXT_STATE_CHOICE &&
            Message_ShouldAdvance(play)) {
            switch (play->msgCtx.choiceIndex) {
                case 0: // Yes
                    this->isFollowing = true;
                    player->hasFollowingMido = true;
                    break;
                case 1: // No
                    this->isFollowing = false;
                    player->hasFollowingMido = false;
                    Message_CloseTextbox(play);
                    break;
            }
        } else {
            func_800343CC(play, &this->actor, &this->unk_1E0.unk_00, this->collider.dim.radius + 30.0f, EnMd_GetText,
                          func_80AAAF04);
        }
    }
}

u8 EnMd_FollowPath(EnMd* this, PlayState* play) {
    Path* path;
    Vec3s* pointPos;
    f32 pathDiffX;
    f32 pathDiffZ;

    if ((this->actor.params & 0xFF00) == 0xFF00 || EnMd_IsFollower(this)) {
        return 0;
    }

    path = &play->setupPathList[(this->actor.params & 0xFF00) >> 8];
    pointPos = SEGMENTED_TO_VIRTUAL(path->points);
    pointPos += this->waypoint;

    pathDiffX = pointPos->x - this->actor.world.pos.x;
    pathDiffZ = pointPos->z - this->actor.world.pos.z;
    Math_SmoothStepToS(&this->actor.world.rot.y, Math_FAtan2F(pathDiffX, pathDiffZ) * (65536.0f / (2 * M_PI)), 4, 4000,
                       1);

    if ((SQ(pathDiffX) + SQ(pathDiffZ)) < 100.0f) {
        this->waypoint++;
        if (this->waypoint >= path->count) {
            this->waypoint = 0;
        }
        return 1;
    }
    return 0;
}

u8 EnMd_SetMovedPos(EnMd* this, PlayState* play) {
    Path* path;
    Vec3s* lastPointPos;

    if ((this->actor.params & 0xFF00) == 0xFF00 || EnMd_IsFollower(this)) {
        return 0;
    }

    path = &play->setupPathList[(this->actor.params & 0xFF00) >> 8];
    lastPointPos = SEGMENTED_TO_VIRTUAL(path->points);
    lastPointPos += path->count - 1;

    this->actor.world.pos.x = lastPointPos->x;
    this->actor.world.pos.y = lastPointPos->y;
    this->actor.world.pos.z = lastPointPos->z;

    return 1;
}

void func_80AAB5A4(EnMd* this, PlayState* play) {
    f32 temp;

    if (play->sceneNum != SCENE_KOKIRI_HOME4) {
        temp = (CHECK_QUEST_ITEM(QUEST_KOKIRI_EMERALD) && !GET_EVENTCHKINF(EVENTCHKINF_1C) &&
                (play->sceneNum == SCENE_SPOT04))
                   ? 100.0f
                   : 400.0f;
        this->alpha = func_80034DD4(&this->actor, play, this->alpha, temp);
        this->actor.shape.shadowAlpha = this->alpha;
    } else {
        this->alpha = 255;
        this->actor.shape.shadowAlpha = this->alpha;
    }
}

void EnMd_Init(Actor* thisx, PlayState* play) {
    EnMd* this = (EnMd*)thisx;
    Player* player = GET_PLAYER(play);
    s32 pad;

    ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawCircle, 24.0f);
    SkelAnime_InitFlex(play, &this->skelAnime, &gMidoSkel, NULL, this->jointTable, this->morphTable, 17);

    // NPC cylinder
    Collider_InitCylinder(play, &this->collider);
    Collider_SetCylinder(play, &this->collider, &this->actor, &sCylinderInit);

    this->actor.targetMode = 6;

    if(EnMd_IsFollower(this)) {
        this->actor.targetMode = 10;
        this->actor.flags &= ~ACTOR_FLAG_0;
        this->collider.dim.radius /= 2;
        CollisionCheck_SetInfo2(&this->actor.colChkInfo, NULL, &sColChkInfoInit_Follower);
    } else {
        CollisionCheck_SetInfo2(&this->actor.colChkInfo, NULL, &sColChkInfoInit);
    }

    // Kokiri sword quad
    Collider_InitCylinder(play, &this->kokiriSwordCylinder);
    Collider_SetCylinder(play, &this->kokiriSwordCylinder, &this->actor, &sKokiriSwordColliderInit);

    if (!EnMd_ShouldSpawn(this, play)) {
        Actor_Kill(&this->actor);
        return;
    }

    if(GET_PLAYER(play)->hasFollowingMido) {
        this->actor.params = 2;
    }

    this->isFollowing = this->actor.params == 2;
    this->teleportTimer = -1;
    this->stabTimer = 0;

    if(this->isFollowing) {
        GET_PLAYER(play)->hasFollowingMido = true;
    }

    Animation_ChangeByInfo(&this->skelAnime, sAnimationInfo, ENMD_ANIM_0);
    Actor_SetScale(&this->actor, 0.01f);
    this->alpha = 255;
    Actor_SpawnAsChild(&play->actorCtx, &this->actor, play, ACTOR_EN_ELF, this->actor.world.pos.x,
                       this->actor.world.pos.y, this->actor.world.pos.z, 0, 0, 0, FAIRY_KOKIRI);

    if (play->sceneNum == SCENE_YDAN) {
        /*
        // Spawn directly in front of Link
        Actor_SetPosRotY(thisx, player->actor.world.pos.x + Math_SinS(player->actor.shape.rot.y) * 200.0f,
                                player->actor.world.pos.y,
                                player->actor.world.pos.z + Math_CosS(player->actor.shape.rot.y) * 200.0f, 0);
        */
        switch(play->roomCtx.curRoom.num) {
            case 0: // Main room
                if(this->isFollowing) {
                    switch(play->roomCtx.prevRoom.num) {
                        case 1: // Middle room
                            Actor_SetPosRotY(thisx, -301, 400, 352, -10022);
                            break;
                        case 3: // Below room
                            Actor_SetPosRotY(thisx, 132, 0, -39, -12317);
                            break;
                        case 10: // Top room
                            Actor_SetPosRotY(thisx, -423, 800, 65, -23125);
                            break;
                    }
                }
                break;
            case 1: // Between main and compass
                switch(play->roomCtx.prevRoom.num) {
                    case 0: // Main room
                        Actor_SetPosRotY(thisx, -613, 400, 458, 15637);
                        break;
                    case 2: // Compass room
                        Actor_SetPosRotY(thisx, -847, 400, 892, -12068);
                        break;
                }
                break;
            case 3: // Below room
                switch(play->roomCtx.prevRoom.num) {
                    case 0: // Main room
                        Actor_SetPosRotY(thisx, 29, -880, 119, -3257);
                        break;
                    case 7: // Grave room
                        Actor_SetPosRotY(thisx, -828, -820, 68, -24174);
                        break;
                    case 4: // Corner room with minigoma and deku scrub
                        Actor_SetPosRotY(thisx, -24, -880, 380, -5928);
                        break;
                    case 9: // Pre-gohma room
                        Actor_SetPosRotY(thisx, -714, -820, 163, 29278);
                        break;
                }
                break;
            case 4: // Corner room with minigoma and deku scrub
                switch(play->roomCtx.prevRoom.num) {
                    case 3: // Below room
                        Actor_SetPosRotY(thisx, -35, -880, 751, -29421);
                        break;
                    case 5: // Spike roller room
                        Actor_SetPosRotY(thisx, -179, -880, 917, -14158);
                        break;
                    // next case
                }
                break;
            case 5: // Spike roller room
                switch(play->roomCtx.prevRoom.num) {
                    case 4: // Corner room with minigoma and deku scrub
                        Actor_SetPosRotY(thisx, -477, -880, 1020, 20736);
                        break;
                    case 6: // Minigoma, deku scrub, keese
                        Actor_SetPosRotY(thisx, -1425, -760, 1130, -26724);
                        break;
                }
                break;
            case 6: // Minigoma, deku scrub, keese
                switch(play->roomCtx.prevRoom.num) {
                    case 5:
                        Actor_SetPosRotY(thisx, -1668, -760, 1135, 20629);
                        break;
                    case 7:
                        Actor_SetPosRotY(thisx, -1793, -760, 906, -27546);
                        break;
                }
                break;
            case 7: // Grave room
                switch(play->roomCtx.prevRoom.num) {
                    case 3: // Below room
                        Actor_SetPosRotY(thisx, -1328, -820, -50, 10139);
                        break;
                    case 6: // Minigoma, deku scrub, keese
                        Actor_SetPosRotY(thisx, -1828, -760, 586, -3586);
                        break;
                    case 8: // Skulltula room with big dekubaba and minigoma
                        Actor_SetPosRotY(thisx, -2284, -760, -379, -20580);
                        break;
                }
                break;
            case 9: // Pre-gohma room
                switch(play->roomCtx.prevRoom.num) {
                    case 3: // Below room
                        Actor_SetPosRotY(thisx, -755, -1880, -454, 1266);
                        break;
                }
            case 2: // Compass room
            case 8: // Skulltula room with big dekubaba and minigoma
            case 10: // Switch platforms room
            default:
                break;
        }
    }

    if (((play->sceneNum == SCENE_SPOT04) && !GET_EVENTCHKINF(EVENTCHKINF_04)) ||
            ((play->sceneNum == SCENE_SPOT04) && GET_EVENTCHKINF(EVENTCHKINF_04) &&
            CHECK_QUEST_ITEM(QUEST_KOKIRI_EMERALD)) ||
            ((play->sceneNum == SCENE_SPOT10) && !GET_EVENTCHKINF(EVENTCHKINF_0A)) || EnMd_IsFollower(this)) {
        this->actor.home.pos = this->actor.world.pos;
        this->actionFunc = func_80AAB948;
        return;
    }

    if (play->sceneNum != SCENE_KOKIRI_HOME4) {
        EnMd_SetMovedPos(this, play);
    }

    this->actionFunc = func_80AAB874;
}

void EnMd_Destroy(Actor* thisx, PlayState* play) {
    EnMd* this = (EnMd*)thisx;
    Collider_DestroyCylinder(play, &this->collider);
    Collider_DestroyCylinder(play, &this->kokiriSwordCylinder);
}

void func_80AAB874(EnMd* this, PlayState* play) {
    if (this->skelAnime.animation == &gMidoHandsOnHipsIdleAnim) {
        func_80034F54(play, this->unk_214, this->unk_236, 17);
    } else if ((this->unk_1E0.unk_00 == 0) && (this->unk_20B != 7)) {
        func_80AAA92C(this, 7);
    }

    func_80AAAA24(this);
}

void func_80AAB8F8(EnMd* this, PlayState* play) {
    if (this->skelAnime.animation == &gMidoHandsOnHipsIdleAnim) {
        func_80034F54(play, this->unk_214, this->unk_236, 17);
    }
    func_80AAA93C(this);
}

void EnMd_SetupHurtbox(EnMd* this, PlayState* play) {
    Vec3s passInPosition;

    /*
    passInPosition.x = (s16)(this->actor.world.pos.x + Math_SinS(this->actor.shape.rot.y) * 60.0f);
    passInPosition.y = (s16)this->actor.world.pos.y + this->collider.dim.height / 2;
    passInPosition.z = (s16)(this->actor.world.pos.z + Math_CosS(this->actor.shape.rot.y) * 60.0f);
    */

    passInPosition.x = (s16)this->targetActor->focus.pos.x;
    passInPosition.y = (s16)this->targetActor->focus.pos.y;
    passInPosition.z = (s16)this->targetActor->focus.pos.z;

    this->kokiriSwordCylinder.base.colType = COLTYPE_METAL;
    this->kokiriSwordCylinder.info.toucher.dmgFlags = DMG_SLASH_KOKIRI;

    Collider_SetCylinderPosition(&this->kokiriSwordCylinder, &passInPosition);

    CollisionCheck_SetAT(play, &play->colChkCtx, &this->kokiriSwordCylinder.base);
}

void func_80AAB948(EnMd* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    f32 temp;
    Actor* actorToBlock = &GET_PLAYER(play)->actor;
    s16 yaw;

    EnMdAnimation targetAnim = ENMD_ANIM_WALK;
    bool isRunning = false;

    func_80AAAA24(this);

    // Follow Link/Targeted
    if (EnMd_IsFollower(this) && this->isFollowing) {

        if (player->targetActor != NULL && player->targetActor->id != this->actor.id &&
            fabsf(player->targetActor->focus.pos.y - (this->actor.world.pos.y + this->collider.dim.height / 2)) < 80) {
            this->targetActor = player->targetActor;
            this->targetingEnemy = true;
        } else {
            this->targetActor = &(player->actor);
            this->targetingEnemy = false;
            this->stabTimer = 0;
        }

        this->actor.gravity = -2.0f;

        this->actor.world.rot.y = Actor_WorldYawTowardActor(&(this->actor), this->targetActor);
        this->actor.shape.rot.y = this->actor.world.rot.y;

        // If y dist is big and player isn't climbing
        if (fabsf(this->actor.yDistToPlayer) > 100 && !(player->stateFlags1 & PLAYER_STATE1_21)) {
            if (this->teleportTimer == -1) {
                this->teleportTimer = TELEPORT_WAIT;
            } else if (this->teleportTimer == 1) {
                Actor_SetPosRotY(&this->actor, player->actor.world.pos.x - Math_SinS(player->actor.shape.rot.y) * 60.0f,
                                              player->actor.world.pos.y,
                                              player->actor.world.pos.z - Math_CosS(player->actor.shape.rot.y) * 60.0f, 0);
                //this->actor.world.pos = player->actor.world.pos;
                this->teleportTimer = -1;
            } else {
                this->teleportTimer--;
            }
        }

        if (Math_Vec3f_DistXZ(&this->actor.world.pos, &this->targetActor->focus.pos) > 1000 && this->targetActor == &player->actor) {
            Animation_ChangeByInfo(&this->skelAnime, sAnimationInfo, ENMD_ANIM_10);

            this->actor.world.pos.x = (player->actor.world.pos.x + this->actor.world.pos.x) / 2;
            this->actor.world.pos.z = (player->actor.world.pos.z + this->actor.world.pos.z) / 2;
        } else {
            this->actor.speedXZ = 0.0f;
            temp = Math_Vec3f_DistXZ(&this->actor.world.pos, &this->targetActor->focus.pos);
            if (temp > 100) {
                this->actor.speedXZ = 5.0f;
                targetAnim = ENMD_ANIM_WALKFAST;
                isRunning = true;
            } else if (temp > (this->targetActor == &player->actor ? 60 : 80)) {
                this->actor.speedXZ = 2.0f;
            }

            // If moving, play the normal or fast walk animations depending on distance
            if (this->actor.speedXZ > 0.0f &&
                (this->skelAnime.animation != &gMidoWalkingAnim || isRunning != this->isRunning)) {
                Animation_ChangeByInfo(&this->skelAnime, sAnimationInfo, targetAnim);
            } else if (this->actor.speedXZ == 0.0f) {
                // If not moving and targeting player, just idle
                if (this->targetActor == &(player->actor) && this->skelAnime.animation != &gMidoHandsOnHipsIdleAnim) {
                    Animation_ChangeByInfo(&this->skelAnime, sAnimationInfo, ENMD_ANIM_10);
                    // If not moving and targeting another actor, stab
                } else if (this->targetActor != &(player->actor) && (this->skelAnime.animation != &gMidoSkelStabAnim ||
                    (this->skelAnime.animation == &gMidoSkelStabAnim && this->skelAnime.curFrame == this->skelAnime.endFrame))) {
                    if(this->stabTimer == -1) {
                        Animation_ChangeByInfo(&this->skelAnime, sAnimationInfo, ENMD_ANIM_10);
                        this->stabTimer = STAB_WAIT;
                    } else if(this->stabTimer == 0) {
                        Animation_ChangeByInfo(&this->skelAnime, sAnimationInfo, ENMD_ANIM_STAB);
                        this->stabTimer = -1;
                    } else {
                        this->stabTimer--;
                    }
                }
            }

            this->isRunning = isRunning;
        }
    } else if (!EnMd_IsFollower(this)) {
        if (this->unk_1E0.unk_00 == 0) {
            this->actor.world.rot.y = this->actor.yawTowardsPlayer;
            this->actor.shape.rot.y = this->actor.yawTowardsPlayer;

            yaw = Math_Vec3f_Yaw(&this->actor.home.pos, &actorToBlock->world.pos);

            this->actor.world.pos.x = this->actor.home.pos.x;
            this->actor.world.pos.x += 60.0f * Math_SinS(yaw);

            this->actor.world.pos.z = this->actor.home.pos.z;
            this->actor.world.pos.z += 60.0f * Math_CosS(yaw);

            temp = fabsf((f32)this->actor.yawTowardsPlayer - yaw) * 0.001f * 3.0f;
            this->skelAnime.playSpeed = CLAMP(temp, 1.0f, 3.0f);
        }

        if (this->unk_1E0.unk_00 == 2) {
            if (CHECK_QUEST_ITEM(QUEST_KOKIRI_EMERALD) && !GET_EVENTCHKINF(EVENTCHKINF_1C) &&
                (play->sceneNum == SCENE_SPOT04)) {
                play->msgCtx.msgMode = MSGMODE_PAUSED;
            }

            if (play->sceneNum == SCENE_SPOT04) {
                SET_EVENTCHKINF(EVENTCHKINF_04);
            }
            if (play->sceneNum == SCENE_SPOT10) {
                SET_EVENTCHKINF(EVENTCHKINF_0A);
            }

            func_80AAA92C(this, 3);
            func_80AAA93C(this);
            this->waypoint = 1;
            this->unk_1E0.unk_00 = 0;
            this->actionFunc = func_80AABD0C;
            this->actor.speedXZ = 1.5f;
            return;
        }
    }

    if (this->skelAnime.animation == &gMidoHandsOnHipsIdleAnim) {
        func_80034F54(play, this->unk_214, this->unk_236, 17);
    }

    if ((this->unk_1E0.unk_00 == 0) && (play->sceneNum == SCENE_SPOT10)) {
        if (player->stateFlags2 & PLAYER_STATE2_24) {
            player->stateFlags2 |= PLAYER_STATE2_25;
            player->unk_6A8 = &this->actor;
            func_8010BD58(play, OCARINA_ACTION_CHECK_SARIA);
            this->actionFunc = func_80AABC10;
            return;
        }

        if (this->actor.xzDistToPlayer < (30.0f + this->collider.dim.radius)) {
            player->stateFlags2 |= PLAYER_STATE2_23;
        }
    }
}

void func_80AABC10(EnMd* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    if (play->msgCtx.ocarinaMode >= OCARINA_MODE_04) {
        this->actionFunc = func_80AAB948;
        play->msgCtx.ocarinaMode = OCARINA_MODE_04;
    } else if (play->msgCtx.ocarinaMode == OCARINA_MODE_03) {
        Audio_PlaySoundGeneral(NA_SE_SY_CORRECT_CHIME, &gSfxDefaultPos, 4, &gSfxDefaultFreqAndVolScale,
                               &gSfxDefaultFreqAndVolScale, &gSfxDefaultReverb);
        this->actor.textId = 0x1067;
        func_8002F2CC(&this->actor, play, this->collider.dim.radius + 30.0f);

        this->actionFunc = func_80AAB948;
        play->msgCtx.ocarinaMode = OCARINA_MODE_04;
    } else {
        player->stateFlags2 |= PLAYER_STATE2_23;
    }
}

void func_80AABD0C(EnMd* this, PlayState* play) {
    func_80034F54(play, this->unk_214, this->unk_236, 17);
    func_80AAA93C(this);

    if (!(EnMd_FollowPath(this, play)) || (this->waypoint != 0)) {
        this->actor.shape.rot = this->actor.world.rot;
        return;
    }

    if (CHECK_QUEST_ITEM(QUEST_KOKIRI_EMERALD) && !GET_EVENTCHKINF(EVENTCHKINF_1C) &&
        (play->sceneNum == SCENE_SPOT04)) {
        Message_CloseTextbox(play);
        SET_EVENTCHKINF(EVENTCHKINF_1C);
        Actor_Kill(&this->actor);
        return;
    }

    func_80AAA92C(this, 11);

    this->skelAnime.playSpeed = 0.0f;
    this->actor.speedXZ = 0.0f;
    this->actor.home.pos = this->actor.world.pos;
    this->actionFunc = func_80AAB8F8;
}

void EnMd_Update(Actor* thisx, PlayState* play) {
    EnMd* this = (EnMd*)thisx;
    s32 pad;

    Collider_UpdateCylinder(&this->actor, &this->collider);
    CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);

    SkelAnime_Update(&this->skelAnime);
    EnMd_UpdateEyes(this);
    func_80AAB5A4(this, play);

    if (!EnMd_IsFollower(this) || this->skelAnime.animation == &gMidoWalkingAnim) {
        Actor_MoveForward(&this->actor);
    }

    func_80AAB158(this, play);

    Actor_UpdateBgCheckInfo(play, &this->actor, 0.0f, 0.0f, 0.0f, UPDBGCHECKINFO_FLAG_2);

    this->actionFunc(this, play);

    Collider_ResetCylinderAT(play, &this->kokiriSwordCylinder.base);
}

s32 EnMd_OverrideLimbDraw(PlayState* play, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot, void* thisx, Gfx** gfx) {
    EnMd* this = (EnMd*)thisx;
    Vec3s vec;

    if (limbIndex == ENMD_LIMB_HEAD && !this->targetingEnemy) {
        Matrix_Translate(1200.0f, 0.0f, 0.0f, MTXMODE_APPLY);
        vec = this->unk_1E0.unk_08;
        Matrix_RotateX(BINANG_TO_RAD_ALT(vec.y), MTXMODE_APPLY);
        Matrix_RotateZ(BINANG_TO_RAD_ALT(vec.x), MTXMODE_APPLY);
        Matrix_Translate(-1200.0f, 0.0f, 0.0f, MTXMODE_APPLY);
    } else if (limbIndex == ENMD_LIMB_TORSO) {
        vec = this->unk_1E0.unk_0E;
        Matrix_RotateX(BINANG_TO_RAD_ALT(vec.x), MTXMODE_APPLY);
        Matrix_RotateY(BINANG_TO_RAD_ALT(vec.y), MTXMODE_APPLY);
    } else if (((limbIndex == ENMD_LIMB_TORSO) || (limbIndex == ENMD_LIMB_LEFT_UPPER_ARM)) ||
               (limbIndex == ENMD_LIMB_RIGHT_UPPER_ARM)) {
        rot->y += Math_SinS(this->unk_214[limbIndex]) * 200.0f;
        rot->z += Math_CosS(this->unk_236[limbIndex]) * 200.0f;
    } else if (limbIndex == ENMD_LIMB_RIGHT_HAND && EnMd_IsFollower(this)) {
        *dList = gMidoRightHandKokiriSwordDL;
    }

    return false;
}

void EnMd_PostLimbDraw(PlayState* play, s32 limbIndex, Gfx** dList, Vec3s* rot, void* thisx, Gfx** gfx) {
    EnMd* this = (EnMd*)thisx;
    Vec3f vec = { 400.0f, 0.0f, 0.0f };

    if (this->skelAnime.animation == &gMidoSkelStabAnim && 3 <= this->skelAnime.curFrame &&
               this->skelAnime.curFrame <= 7) {
        EnMd_SetupHurtbox(this, play);
    }

    if (limbIndex == ENMD_LIMB_HEAD) {
        Matrix_MultVec3f(&vec, &this->actor.focus.pos);
    }
}

void EnMd_Draw(Actor* thisx, PlayState* play) {
    static void* sEyeTextures[] = {
        gMidoEyeOpenTex,
        gMidoEyeHalfTex,
        gMidoEyeClosedTex,
    };
    EnMd* this = (EnMd*)thisx;

    OPEN_DISPS(play->state.gfxCtx, "../z_en_md.c", 1280);

    if (this->alpha == 255) {
        gSPSegment(POLY_OPA_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sEyeTextures[this->eyeIdx]));
        func_80034BA0(play, &this->skelAnime, EnMd_OverrideLimbDraw, EnMd_PostLimbDraw, &this->actor, this->alpha);
    } else if (this->alpha != 0) {
        gSPSegment(POLY_XLU_DISP++, 0x08, SEGMENTED_TO_VIRTUAL(sEyeTextures[this->eyeIdx]));
        func_80034CC4(play, &this->skelAnime, EnMd_OverrideLimbDraw, EnMd_PostLimbDraw, &this->actor, this->alpha);
    }

    CLOSE_DISPS(play->state.gfxCtx, "../z_en_md.c", 1317);
}
