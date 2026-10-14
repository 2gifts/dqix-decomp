#include <globaldefs.h>
#include "Combat/CombatantRecovery.h"
#include "GameState/GameState.h"

struct SearchStruct0202c1a4;
struct Foo02033b58;


extern "C" void* func_0202ae18(void);
int CheckField0NonZero(int* obj);
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
int TryClearFlags0x130(unsigned char* obj, unsigned short flag);
void SetByteSavingPrevious(struct Foo02033b58* p, unsigned char v);
extern "C" void func_ov017_021c9d2c(int slot, unsigned short a1, unsigned short a2, unsigned short a3, int a4, unsigned int a5, unsigned char a6, int flagA, int flagB);
extern "C" void func_ov017_02191108(void* unused, int c, int d, int e, int flag);

static inline unsigned short GetMaximumMP(const BaseCombatStats* stats) {
    return stats->primaryStats.maxMP;
}
static inline unsigned short GetMaximumHP(const BaseCombatStats* stats) {
    return stats->primaryStats.maxHP;
}

// USA: func_ov017_021bd5d0
extern "C" ARM void func_ov017_021bd5d0(void) {
    GameState* battle = GameState::GetInstance();
    void* g = func_0202ae18();
    GameObject* combatant = battle->GetGameObjectByIndex(0);
    void* other = func_ov017_0218b5b0();
    struct CombatantStatus* p = combatant->combatFields_.savedState_130_;

    if (p->GetFlags() & 1) {
        if (CheckField0NonZero((int*)g) && GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)g) == 0) {
            ClearFieldBit02053fe4(combatant, 1, 0);
            TryClearFlags0x130((unsigned char*)combatant, 1);

            p = combatant->combatFields_.savedState_130_;
            struct BaseCombatStats* q = combatant->baseStats_;
            unsigned char byte8 = p->GetStatus();
            unsigned int word0 = p->GetFlags();
            unsigned short maxMP = GetMaximumMP(q);
            unsigned short maxHP = GetMaximumHP(q);
            unsigned short half6 = p->GetMP();
            func_ov017_021c9d2c(combatant->obj3D_.unknown_4_, 1, maxHP, half6, maxMP, word0, byte8, 1, 0);

            SetByteSavingPrevious((struct Foo02033b58*)combatant, 0);
            combatant->combatFields_.unknown_b2_ = 0;
        } else if (CheckField0NonZero((int*)g) == 0) {
            ClearFieldBit02053fe4(combatant, 1, 0);
            TryClearFlags0x130((unsigned char*)combatant, 1);
            SetByteSavingPrevious((struct Foo02033b58*)combatant, 0);
            combatant->combatFields_.unknown_b2_ = 0;
        }
        func_ov017_02191108(other, 1, 1, 1, 0);
    }
}
