#include "npc.h"
#include "functions.h"

void (*const Cucco_Actions[])(Entity*);
const u16 Cucco_Sounds[];
const u16 Cucco_Messages[];

void sub_0806E4EC(Entity*);
void Cucco_ShowMessage(Entity*);
void sub_0806E65C(Entity* this);

void Cucco(Entity* this) {
    Cucco_Actions[this->action](this);
}

void Cucco_Init(Entity* this) {
    this->action += 1;
    this->field_0x68.HALF.LO = sub_0801E99C(this);
    sub_080787A8(this, this->field_0x68.HALF.LO);
    SetDefaultPriority(this, PRIO_MESSAGE);
    this->subAction = 0;
    sub_0806E4EC(this);
}

void sub_0806E4EC(Entity* this) {
    if (this->subAction == 0) {
        this->subAction += 1;
        this->actionDelay = (Random() & 0x1f) + 0x3c;
        InitAnimationForceUpdate(this, 0);
    }
    if (--this->actionDelay == 0) {
        if ((Random() & 1) != 0) {
            this->action = 3;
        } else {
            this->action = 2;
        }
        this->subAction = 0;
        if ((Random() & 1) != 0) {
            EnqueueSFX(Cucco_Sounds[Random() & 3]);
        }
    }
    sub_0806E65C(this);
    UpdateAnimationSingleFrame(this);
}

void Cucco_Fly(Entity* this) {
    if (this->subAction == 0) {
        this->subAction++;
        if (Random() & 1) {
            this->spriteSettings.flipX ^= 1;
        }

        this->actionDelay = (Random() & 1) + 1;
        this->zVelocity = 0x18000;
        InitAnimationForceUpdate(this, 1);
    }

    if (GravityUpdate(this, 0x2800) == 0) {
        if (--this->actionDelay == 0) {
            this->action = 1;
            this->subAction = 0;
        } else {
            this->zVelocity = 0x18000;
        }
    }

    sub_0806E65C(this);
    UpdateAnimationSingleFrame(this);
}

void Cucco_Idle(Entity* this) {
    if (this->subAction == 0) {
        this->subAction++;
        if (Random() & 1) {
            this->spriteSettings.flipX ^= 1;
        }

        InitAnimationForceUpdate(this, (Random() & 1) + 2);
    }

    if (this->frame & 0x80) {
        this->action = 1;
        this->subAction = 0;
    }

    sub_0806E65C(this);
    UpdateAnimationSingleFrame(this);
}

void sub_0806E648(Entity* this) {
    if (UpdateFuseInteraction(this) != 0) {
        this->action = 1;
    }
}

void sub_0806E65C(Entity* this) {
    if (this->interactType != 0) {
        if ((gPlayerState.flags & PL_MINISH) != 0) {
            if (this->interactType == 2) {
                this->action = 4;
                sub_0806F118(this);
            } else {
                Cucco_ShowMessage(this);
            }
        } else {
            ResetPlayerAnimationAndAction();
        }
        SoundReq(SFX_VO_CUCCO_CALL);
        this->interactType = 0;
    }
}

void Cucco_ShowMessage(Entity* this) {
    u32 val = 0;
    u32 index = sub_08002632(this);
    if (gSave.unk1C1[index] == 0xf3) {
        val = 1;
    }

    MessageNoOverlap(Cucco_Messages[val], this);
}

void Cucco_Fusion(Entity* this) {
    if (this->action == 0) {
        this->action += 1;
        this->spriteSettings.draw = 1;
        InitAnimationForceUpdate(this, 1);
    } else {
        UpdateAnimationSingleFrame(this);
    }
}

void (*const Cucco_Actions[])(Entity*) = {
    Cucco_Init, sub_0806E4EC, Cucco_Fly, Cucco_Idle, sub_0806E648,
};

const u16 Cucco_Sounds[] = { SFX_VO_CUCCO1, SFX_VO_CUCCO2, SFX_VO_CUCCO3, SFX_VO_CUCCO4 };
const u16 Cucco_Messages[] = { 0xdb4, 0xdb5 };
