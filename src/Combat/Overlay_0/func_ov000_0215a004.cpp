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
void InitObj02088e80(Obj02088e80*, int);
int GetField0x3acValue_020100a8(GameState* gs);
void LoadBattleBlock020ac4c0(void*);
void AddClamped16BitLowAt0x24_020a0608(S_a0608*, unsigned int);
void AddClamped16BitFieldMidAt0x1c_020a0294(S_a0294*, unsigned int);
void CopyInBattleField0x7540_020ac494(void*);

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
        InitObj02088e80((Obj02088e80*)c->currentStats_, (signed char)c->obj3D_.unknown_4_);
        func_ov000_02155184(self, id, a7);
        if (id == GetField0x3acValue_020100a8(GameState::GetInstance())) {
            struct BattleBlk_0215a004 blk;
            LoadBattleBlock020ac4c0(&blk);
            AddClamped16BitLowAt0x24_020a0608((S_a0608*)&blk, 1);
            AddClamped16BitFieldMidAt0x1c_020a0294((S_a0294*)&blk.sub, 1);
            CopyInBattleField0x7540_020ac494(&blk);
        }
    }
    if (damage > 0) {
        *result |= 2;
    }
    c->currentStats_->primaryStats.currHP = hp;
    return (short)hp;
}
