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
extern "C" void _Z26ResetGxEngineState020c52e8v();
extern "C" void func_020c5414();
void SubmitGeometryJob(int, int, int, int, void*);
extern "C" void _Z28ComputeAndLoadMatrix020c5770iiiiiiiiPv(int, int, int, int, int, int, int, int, void*);
extern "C" void _Z28ForwardObjAndField0_021a3b30i(int);
extern "C" void _Z25UpdateInterpTimer020707c8P13Timer020707c8(Timer020707c8*);
int GetHeadNodeIdOrMinusOne(HeadNode02046b24**);
unsigned int GetBitsInField4(unsigned int*, unsigned int);
extern "C" void _Z31ReleaseField0x38IfValid020444e0P11Obj020444e0(Obj020444e0*);
extern "C" void func_ov017_0219ad84(Battle021960b8*);
GameObject* GetCombatantWithFlag0x100(GameState*, int);
extern "C" void func_0205337c(GameObject*);
unsigned char GetByteField0x252(void*);
int GetByte0x26c(char*);
void SelectCoordsByFlag0x24(unsigned char*, int*, int*);
extern "C" void _Z34MaybeDispatchPendingAction02096824Ph(unsigned char*);
int* GetGlobal02109030();
extern "C" void _Z36UpdateChannelStateIfEligible02093f68Pc(char*);
extern "C" void* func_02012fe4(void);
extern "C" void _Z35MaybeUpdateOrDispatchEntry_021959ecv(Battle021960b8*);
extern "C" Global020421a0* _Z26GetGlobalField0x1c020421a0v();

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
    Global020421a0* global = _Z26GetGlobalField0x1c020421a0v();
    Timer020707c8* timer = (Timer020707c8*)func_020704fc();
    GameObject* leader = game->GetUnknownGameObject();
    game->GetTickCount();

    Vector3fix target = data_ov017_021d6408;
    Vector3fix eye;
    __clear(&eye, sizeof(eye));
    Vector3fix up = data_ov017_021d6414;

    _Z26ResetGxEngineState020c52e8v();
    func_020c5414();
    *(volatile unsigned int*)0x04000440 = 0;
    SubmitGeometryJob((int)&eye, (int)&up, (int)&target, 1, NULL);
    _Z28ComputeAndLoadMatrix020c5770iiiiiiiiPv(0, 0xc0000, 0, 0x100000, -0x400000, 0x400000, 0x400000, 1, NULL);
    *(volatile unsigned int*)0x04000440 = 2;
    _Z28ForwardObjAndField0_021a3b30i((int)self->nodeList);

    if (timer->field0 != 0) {
        _Z25UpdateInterpTimer020707c8P13Timer020707c8(timer);
    }

    if (GetHeadNodeIdOrMinusOne(self->nodeList) != 2 &&
        GetHeadNodeIdOrMinusOne(self->nodeList) != 3 &&
        GetHeadNodeIdOrMinusOne(self->nodeList) != 10) {
        if ((global->field998 != 0 || global->field19cb != 0) &&
            GetBitsInField4(self->flags, 0x8000) == 0) {
            _Z31ReleaseField0x38IfValid020444e0P11Obj020444e0((Obj020444e0*)global);
        }
        func_ov017_0219ad84(self);
        if (GetBitsInField4(self->flags, 4) == 0) {
            for (int i = 0; i < 4; i++) {
                GameObject* combatant = GetCombatantWithFlag0x100(game, i);
                if (combatant != NULL && combatant->obj3D_.GetFlag(1) == 0) {
                    func_0205337c(combatant);
                }
            }
        }
    }

    if (GetBitsInField4(self->flags, 0x800) == 0) {
        LightingManager::GetInstance()->DrawBackgroundGradient();
    }

    if (GetBitsInField4(self->flags, 0x80) == 0 && self->field3658 == 0 && leader != NULL &&
        (GetByteField0x252(leader) != 0 || GetByte0x26c((char*)leader) != 0)) {
        if (data_02114e54.field5f != 0 && data_02114e54.field24 != 0) {
            if (data_ov017_021d8340 == 0) {
                data_ov017_021d8340 = 1;
                SelectCoordsByFlag0x24((unsigned char*)&data_02114e54, &data_ov017_021d8344,
                                       &data_ov017_021d834c);
            }
            SelectCoordsByFlag0x24((unsigned char*)&data_02114e54, &data_ov017_021d8348,
                                   &data_ov017_021d8350);
        } else {
            data_ov017_021d8340 = 0;
        }
        _Z34MaybeDispatchPendingAction02096824Ph(self->pendingAction);
    }

    _Z36UpdateChannelStateIfEligible02093f68Pc((char*)GetGlobal02109030());
    if (((AtmosphericEffectSet*)((char*)func_02012fe4() + kAtmosphericOffset))->Draw()) {
        _Z35MaybeUpdateOrDispatchEntry_021959ecv(self);
    }
}
