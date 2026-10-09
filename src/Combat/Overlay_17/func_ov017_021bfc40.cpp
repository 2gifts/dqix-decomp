#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" int _Z44HasNonZeroByteAtOfField498_0218d75c_0218d75cPv(void* obj);
int GetByteField0x252(void* obj);
void SetByteField0x253(void* obj);
int GetFieldIfFlag4(char* obj);
void SetField0x23cTrue(void* obj);
void ClearBitsInField4(unsigned int* obj, unsigned int mask);
extern "C" int _Z26GetGlobalField0x1c020421a0v(void);

struct Vec3copy0202ec84 { unsigned int v[3]; };
extern "C" int _Z27ComputeTwoFromVec3_0202ec84PvP16Vec3copy0202ec84PiS2_(void* obj, struct Vec3copy0202ec84* src, int* out1, int* out2);

struct StructAt020473c8;
void RenderFlaggedIndexedEntry(struct StructAt020473c8* obj, int param1);

int GetField0x3b0Value(GameState* battleStruct);
extern "C" short _Z8fix32sini(int x);

struct Obj021bfc40 {
    char pad0[0x8];
    unsigned short timer;
    char pad1[0x10 - 0xa];
    unsigned char* sprite;
    char pad2[0x16 - 0x14];
    short countdown;
    short angle;
    char pad3[0x28 - 0x1a];
    struct Vec3copy0202ec84 pos;
    char pad4[0x48 - 0x34];
    unsigned char skip;
};

// USA: func_ov017_021bfc40
extern "C" ARM int func_ov017_021bfc40(struct Obj021bfc40* self) {
    GameState* battle = GameState::GetInstance();
    int ticks = battle->GetTickCount();
    GameResources* res = func_ov017_0218b5b0();

    if (self->skip != 0) {
        GameResources* res2 = func_ov017_0218b5b0();
        if (_Z44HasNonZeroByteAtOfField498_0218d75c_0218d75cPv(res2) != 0) {
            return 4;
        }
        GameObject* combatant = battle->GetUnknownGameObject();
        if (combatant != NULL && GetByteField0x252(combatant) == 0) {
            SetByteField0x253(combatant);
        }
        int flag = GetFieldIfFlag4((char*)battle);
        if (flag != 0) {
            SetField0x23cTrue((void*)flag);
        }
        if (res2 != NULL) {
            ClearBitsInField4((unsigned int*)res2, 0x80);
        }
        self->countdown = 0;
        self->timer = 0;
        return 6;
    }

    GameState* state = GameState::GetInstance();
    void* ptr3b0 = (void*)GetField0x3b0Value(state);
    struct Vec3copy0202ec84 vecBuf = self->pos;

    if (self->angle < 0x191e) {
        self->angle += state->GetTickCount() * 0x199;
    }

    vecBuf.v[1] += _Z8fix32sini(self->angle);

    int screenY;
    int screenX;
    if (ptr3b0 != NULL) {
        _Z27ComputeTwoFromVec3_0202ec84PvP16Vec3copy0202ec84PiS2_(ptr3b0, &vecBuf, &screenX, &screenY);
    }

    int x = (screenX - 0xc) << 0xc;
    int y = (screenY - 0x28) << 0xc;
    unsigned char* sprite = self->sprite;
    *(int*)(sprite + 0x1c) = x;
    *(int*)(sprite + 0x20) = y;
    *(int*)(sprite + 0x24) = 0;
    RenderFlaggedIndexedEntry((struct StructAt020473c8*)sprite, 1);

    short level = self->countdown;
    if (level > 0x1f) {
        level = 0x1f;
    }
    *(short*)(sprite + 0x82) = level;

    unsigned int dt = battle->GetEffectiveDeltaTime();
    if (dt < self->timer) {
        self->timer = self->timer - dt;
    } else {
        self->timer = 0;
    }

    if (self->timer == 0) {
        GameObject* combatant = battle->GetUnknownGameObject();
        if (combatant != NULL && GetByteField0x252(combatant) == 0) {
            SetByteField0x253(combatant);
        }
        int flag = GetFieldIfFlag4((char*)battle);
        if (flag != 0) {
            SetField0x23cTrue((void*)flag);
        }
        if (res != NULL) {
            ClearBitsInField4((unsigned int*)res, 0x80);
        }
    }

    _Z26GetGlobalField0x1c020421a0v();
    if (ticks < self->countdown) {
        self->countdown -= ticks;
    } else {
        self->countdown = 0;
        self->timer = 0x12c;
        return 6;
    }
    return 4;
}
