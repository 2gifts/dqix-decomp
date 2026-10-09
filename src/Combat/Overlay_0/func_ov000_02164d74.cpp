#include <globaldefs.h>
#include "GameState/GameState.h"

struct PtrBlock02164d74 {
    char pad0[0xf78];
    unsigned char ids[4];
    unsigned char count;
};

struct Info02164d74 {
    char pad0[0x2c];
    int field2c;
    int field30;
};

struct Stats02164d74 {
    char pad0[0x14];
    unsigned int flags14;
};

struct Combatant02164d74 {
    Object3D obj3D;
    char padac[0xc1 - sizeof(Object3D)];
    unsigned char visFlags : 2;
    unsigned char visRest : 6;
    char padc2[0x130 - 0xc2];
    char* field130;
    char* field134;
    struct Stats02164d74* stats;
    char pad13c[0x18c - 0x13c];
    unsigned int flags18c;
};

struct Battle02164d74 {
    char pad0[0x29c];
    int field29c;
    struct Info02164d74* info;
    char pad2a4[0xec8 - 0x2a4];
    unsigned short fieldEc8;
    char padEca[0x3760 - 0xeca];
    char sub3760[0x77d2 - 0x3760];
    unsigned char field77d2;
    char pad77d3;
    unsigned char field77d4;
};

struct Bytes02033b88;

extern "C" void _Z16GetField02163524Pv(struct Battle02164d74* battle);
extern "C" struct PtrBlock02164d74* _Z17GetPtrField0x2a04P9GameState(GameState* gs);
extern "C" void func_ov000_0217feb0(void* obj, unsigned char value, int id);
extern "C" int _Z13TestBitAt0x34Phj(struct Info02164d74* info, unsigned int index);
extern "C" void func_ov000_02174a50(void* obj, int combatantId);
extern "C" struct Combatant02164d74* _Z25GetCombatantWithFlag0x100P9GameStatei(GameState* gs, int id);
extern "C" struct Combatant02164d74* _Z25GetCombatantWithFlag0x400P9GameStatei(GameState* gs, int id);
extern "C" void _Z20SetByte0xbeShiftPrevP13Bytes02033b88i(struct Combatant02164d74* obj, int val);
extern "C" void _Z24InitPackedFields02089560PcS_S_(char* dst, char* buf, char* src);
extern "C" void _Z26CopyCombatantStats0208936cPcS_S_(char* dst, char* src1, char* src2);
void ApplyCombatantBuffs(int unused, int combatantId);
extern "C" void func_ov000_02174738(void* obj, int combatantId);
extern "C" void func_ov017_021917f0(int id, int flag);
extern "C" void func_ov000_021675a0(struct Battle02164d74* battle);
extern "C" void func_ov000_021676a8(struct Battle02164d74* battle);
extern "C" void _Z34SetupCombatantAllocations_021901acv(void* ov);
void ClearBitsInField4(unsigned int* obj, unsigned int mask);
void ClearSubstructByte0x56(unsigned char* obj);
extern "C" void func_ov000_021677fc(struct Battle02164d74* battle);
extern "C" void func_ov000_02167cd4(struct Battle02164d74* battle);
extern "C" void _Z38RunFlagPassAndSetMode02167dd8_02167dd8Ph(unsigned char* obj);
void SetCombatWorkFlags0x55f4(void* work, int mask);

#define REG_POWCNT1 (*(volatile unsigned short*)0x04000304)

// USA: func_ov000_02164d74
extern "C" ARM void func_ov000_02164d74(struct Battle02164d74* battle) {
    GameState* gs = GameState::GetInstance();
    GameResources* ov = func_ov017_0218b5b0();
    _Z16GetField02163524Pv(battle);
    struct PtrBlock02164d74* pb = _Z17GetPtrField0x2a04P9GameState(gs);
    int i;
    for (i = 0; i < pb->count; i++) {
        func_ov000_0217feb0(battle->sub3760, 1, pb->ids[i]);
    }
    REG_POWCNT1 |= 0x8000;
    for (i = 0; i < 4; i++) {
        if (!_Z13TestBitAt0x34Phj(battle->info, (unsigned char)i)) {
            func_ov000_02174a50(battle->sub3760, i);
            continue;
        }
        struct Combatant02164d74* c = _Z25GetCombatantWithFlag0x100P9GameStatei(gs, i);
        if (c == NULL) {
            continue;
        }
        c->obj3D.MakeVisible();
        c->visFlags |= 3;
        _Z20SetByte0xbeShiftPrevP13Bytes02033b88i(c, 0);
        c->obj3D.SetField06(battle->fieldEc8);
        if (battle->info->field30 != 0) {
            _Z24InitPackedFields02089560PcS_S_((char*)c->stats, c->field130, c->field134);
            ApplyCombatantBuffs(battle->field29c, (short)i);
        } else {
            _Z26CopyCombatantStats0208936cPcS_S_((char*)c->stats, c->field130, c->field134);
        }
        if (!(c->stats->flags14 & 1)) {
            c->flags18c &= ~1;
        } else {
            _Z20SetByte0xbeShiftPrevP13Bytes02033b88i(c, 4);
        }
        func_ov000_02174738(battle->sub3760, i);
        func_ov017_021917f0(i, 1);
    }
    battle->field77d2 = 1;
    func_ov000_021675a0(battle);
    func_ov000_021676a8(battle);
    _Z34SetupCombatantAllocations_021901acv(ov);
    ClearBitsInField4((unsigned int*)ov, 4);
    if (battle->info->field2c != 0) {
        unsigned char mask = battle->field77d4;
        for (i = 0; i < 8; i++) {
            struct Combatant02164d74* c = _Z25GetCombatantWithFlag0x400P9GameStatei(gs, i + 0xc0);
            if (c != NULL && !(mask & (1 << i))) {
                c->obj3D.MakeHidden();
                ClearSubstructByte0x56((unsigned char*)c);
            }
        }
    }
    func_ov000_021677fc(battle);
    func_ov000_02167cd4(battle);
    _Z38RunFlagPassAndSetMode02167dd8_02167dd8Ph((unsigned char*)battle);
    SetCombatWorkFlags0x55f4(battle, 0x200);
}
