#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj02088e80;
struct S_a0608;
struct S_a0294;

struct BattleBlkSub_0215a004 {
    char data[0x48];
};

struct BattleBlk_0215a004 {
    char data[0x68];
    struct BattleBlkSub_0215a004 sub;
};

extern "C" void func_ov000_021554f4(void* self, int id, void* arg, int a3, unsigned char a4, int a5);
extern "C" void func_ov000_02155184(void* self, int id, int a2);
extern "C" void _Z15InitObj02088e80P11Obj02088e80(struct ModifiableCombatStats* stats, int id);
extern "C" int _Z18GetField0x3acValueP9GameState(GameState* gs);
extern "C" void _Z23LoadBattleBlock020ac4c0Pv(struct BattleBlk_0215a004* b);
extern "C" void _Z24AddClamped16BitLowAt0x24P7S_a0608j(struct BattleBlk_0215a004* b, unsigned int v);
extern "C" void _Z29AddClamped16BitFieldMidAt0x1cP7S_a0294j(struct BattleBlkSub_0215a004* b, unsigned int v);
extern "C" void _Z23CopyInBattleField0x7540Pv(struct BattleBlk_0215a004* b);

// USA: func_ov000_0215a004
extern "C" ARM short func_ov000_0215a004(void* self, void* arg, int id, int damage, unsigned long long* result,
                                          int a5, unsigned char a6, int a7) {
    int hp;
    GameObject* c = GameState::GetInstance()->GetCombatantByIndex(id);
    if (c == 0) {
        return 0;
    }
    hp = c->currentStats_->primaryStats.currHP - damage;
    if (hp <= 0) {
        hp = 0;
        *result = 0;
        *result |= 4;
        func_ov000_021554f4(self, id, arg, a5, a6, a7);
        _Z15InitObj02088e80P11Obj02088e80(c->currentStats_, (signed char)c->obj3D_.unknown_4_);
        func_ov000_02155184(self, id, a7);
        if (id == _Z18GetField0x3acValueP9GameState(GameState::GetInstance())) {
            struct BattleBlk_0215a004 blk;
            _Z23LoadBattleBlock020ac4c0Pv(&blk);
            _Z24AddClamped16BitLowAt0x24P7S_a0608j(&blk, 1);
            _Z29AddClamped16BitFieldMidAt0x1cP7S_a0294j(&blk.sub, 1);
            _Z23CopyInBattleField0x7540Pv(&blk);
        }
    }
    if (damage > 0) {
        *result |= 2;
    }
    c->currentStats_->primaryStats.currHP = hp;
    return (short)hp;
}
