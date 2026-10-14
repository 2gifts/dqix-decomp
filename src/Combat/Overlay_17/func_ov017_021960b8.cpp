#include <globaldefs.h>

#if defined(jpn)
enum { kGlobalStateOffset = 0x868, kGlobalFlagOffset = 0x17fc, kSceneFlagOffset = 0x3448, kNodeListOffset = 0x34ec, kPendingActionOffset = 0x4108, kAtmosphericOffset = 0x114 };
#else
enum { kGlobalStateOffset = 0x998, kGlobalFlagOffset = 0x19cb, kSceneFlagOffset = 0x3658, kNodeListOffset = 0x36fc, kPendingActionOffset = 0x4328, kAtmosphericOffset = 0xf4 };
#endif

#include "GameState/GameState.h"
#include "Graphics/AtmosphericEffect.h"
#include "Graphics/LightingManager.h"
#include "System/Matrix.h"

struct HeadNode02046b24;
struct Obj020444e0;

struct Timer020707c8 {
    unsigned char field0;
};

struct Global020421a0 {
    char pad0[kGlobalStateOffset];
    int field998;
    char pad1[kGlobalFlagOffset - (kGlobalStateOffset + 4)];
    unsigned char field19cb;
};

struct Field02114e54 {
    char pad0[0x24];
    unsigned short field24;
    char pad1[0x5f - 0x26];
    unsigned char field5f;
};

struct Battle021960b8 {
    unsigned int flags[2];
    char pad8[kSceneFlagOffset - 0x8];
    unsigned char field3658;
    char pad3659[kNodeListOffset - (kSceneFlagOffset + 1)];
    HeadNode02046b24** nodeList;
    char pad3700[kPendingActionOffset - (kNodeListOffset + 4)];
    unsigned char* pendingAction;
};

extern "C" void* func_020704fc(void);
extern "C" void __clear(void* ptr, int size);
void ResetGxEngineState020c52e8();
extern "C" void func_020c5414();
void SubmitGeometryJob_020c57d4(int, int, int, int, void*);
void ComputeAndLoadMatrix020c5770(int, int, int, int, int, int, int, int, void*);
void ForwardObjAndField0_021a3b30(int);
void UpdateInterpTimer020707c8(Timer020707c8*);
int GetHeadNodeIdOrMinusOne(HeadNode02046b24**);
unsigned int GetBitsInField4_0203b4fc(unsigned int*, unsigned int);
void ReleaseField0x38IfValid020444e0(Obj020444e0*);
extern "C" void func_ov017_0219ad84(Battle021960b8*);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState*, int);
extern "C" void func_0205337c(GameObject*);
unsigned char GetByteField0x252_02039820(void*);
int GetByte0x26c_02039d7c(char*);
void SelectCoordsByFlag0x24_02012a84(unsigned char*, int*, int*);
void MaybeDispatchPendingAction02096824(unsigned char*);
int* GetGlobal02109030_020936f8();
void UpdateChannelStateIfEligible02093f68(char*);
extern "C" void* func_02012fe4(void);
void MaybeUpdateOrDispatchEntry_021959ec(void*);
Global020421a0* GetGlobalField0x1c020421a0();

extern Vector3fix data_ov017_021d6408;
extern Vector3fix data_ov017_021d6414;
extern Field02114e54 data_02114e54;
extern int data_ov017_021d8340;
extern int data_ov017_021d8344;
extern int data_ov017_021d834c;
extern int data_ov017_021d8348;
extern int data_ov017_021d8350;

// USA: func_ov017_021960b8
extern "C" ARM void func_ov017_021960b8(Battle021960b8* self) {
    GameState* game = GameState::GetInstance();
    Global020421a0* global = GetGlobalField0x1c020421a0();
    Timer020707c8* timer = (Timer020707c8*)func_020704fc();
    GameObject* leader = game->GetUnknownGameObject();
    game->GetTickCount();

    Vector3fix target = data_ov017_021d6408;
    Vector3fix eye;
    __clear(&eye, sizeof(eye));
    Vector3fix up = data_ov017_021d6414;

    ResetGxEngineState020c52e8();
    func_020c5414();
    *(volatile unsigned int*)0x04000440 = 0;
    SubmitGeometryJob_020c57d4((int)&eye, (int)&up, (int)&target, 1, NULL);
    ComputeAndLoadMatrix020c5770(0, 0xc0000, 0, 0x100000, -0x400000, 0x400000, 0x400000, 1, NULL);
    *(volatile unsigned int*)0x04000440 = 2;
    ForwardObjAndField0_021a3b30((int)self->nodeList);

    if (timer->field0 != 0) {
        UpdateInterpTimer020707c8(timer);
    }

    if (GetHeadNodeIdOrMinusOne(self->nodeList) != 2 &&
        GetHeadNodeIdOrMinusOne(self->nodeList) != 3 &&
        GetHeadNodeIdOrMinusOne(self->nodeList) != 10) {
        if ((global->field998 != 0 || global->field19cb != 0) &&
            GetBitsInField4_0203b4fc(self->flags, 0x8000) == 0) {
            ReleaseField0x38IfValid020444e0((Obj020444e0*)global);
        }
        func_ov017_0219ad84(self);
        if (GetBitsInField4_0203b4fc(self->flags, 4) == 0) {
            for (int i = 0; i < 4; i++) {
                GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(game, i);
                if (combatant != NULL && combatant->obj3D_.GetFlag(1) == 0) {
                    func_0205337c(combatant);
                }
            }
        }
    }

    if (GetBitsInField4_0203b4fc(self->flags, 0x800) == 0) {
        LightingManager::GetInstance()->DrawBackgroundGradient();
    }

    if (GetBitsInField4_0203b4fc(self->flags, 0x80) == 0 && self->field3658 == 0 && leader != NULL &&
        (GetByteField0x252_02039820(leader) != 0 || GetByte0x26c_02039d7c((char*)leader) != 0)) {
        if (data_02114e54.field5f != 0 && data_02114e54.field24 != 0) {
            if (data_ov017_021d8340 == 0) {
                data_ov017_021d8340 = 1;
                SelectCoordsByFlag0x24_02012a84((unsigned char*)&data_02114e54, &data_ov017_021d8344,
                                       &data_ov017_021d834c);
            }
            SelectCoordsByFlag0x24_02012a84((unsigned char*)&data_02114e54, &data_ov017_021d8348,
                                   &data_ov017_021d8350);
        } else {
            data_ov017_021d8340 = 0;
        }
        MaybeDispatchPendingAction02096824(self->pendingAction);
    }

    UpdateChannelStateIfEligible02093f68((char*)GetGlobal02109030_020936f8());
    if (((AtmosphericEffectSet*)((char*)func_02012fe4() + kAtmosphericOffset))->Draw()) {
        MaybeUpdateOrDispatchEntry_021959ec(self);
    }
}
