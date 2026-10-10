#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct;

struct CombatantFlagsC2 {
    unsigned char low : 5;
    unsigned char flag : 1;
    unsigned char high : 2;
};

extern "C" void* func_0202ae18(void);
int CheckField0NonZero(int* obj);
int GetField0x3acValue(GameState* gameState);
int IsEntryFlagBit11Set(struct SearchStruct* search, int id);
int IsEntryFlagBit13Set(struct SearchStruct* search, int id);
int IsEntryFlagBit14Set(struct SearchStruct* search, int id);
char* GetCombatantWithFlag0x1000(GameState* gameState, int index);
int GetSignedByte0x2d0(void* obj);

// USA: func_020dc920
extern "C" ARM int func_020dc920(int a, int b, int c, int d) {
    GameState* battle = GameState::GetInstance();
    GameObject* protagonist = battle->GetProtagonist();
    struct SearchStruct* search = (struct SearchStruct*)func_0202ae18();
    if (protagonist != NULL) {
        GameObject* party = battle->GetPartyMemberByIndex(a);
        if (party != NULL) {
            if (CheckField0NonZero((int*)search) && d) {
                int id = a;
                if (party->obj3D_.unknown_0_ & 0x1000)
                    id = 0;
                if (id != GetField0x3acValue(battle)) {
                    if (!IsEntryFlagBit13Set(search, id))
                        return 0;
                }
            }
            if (b != 0 && a != GetField0x3acValue(battle)) {
                if (IsEntryFlagBit11Set(search, a))
                    return 0;
                char* combatant = GetCombatantWithFlag0x1000(battle, a);
                if (combatant != NULL) {
                    int id = GetSignedByte0x2d0(combatant);
                    if (IsEntryFlagBit11Set(search, id)) {
                        if (id != GetField0x3acValue(battle))
                            return 0;
                    }
                }
                if (IsEntryFlagBit14Set(search, a))
                    return 0;
                combatant = GetCombatantWithFlag0x1000(battle, a);
                if (combatant != NULL) {
                    int id = GetSignedByte0x2d0(combatant);
                    if (IsEntryFlagBit14Set(search, id)) {
                        if (id != GetField0x3acValue(battle))
                            return 0;
                    }
                }
            }
            int flag = 0;
            if (protagonist->obj3D_.GetField06() == party->obj3D_.GetField06()) {
                flag = 1;
            } else if (c != 0 && ((protagonist->obj3D_.GetField06() == 10000 && party->obj3D_.GetField06() == 5900) ||
                                  (protagonist->obj3D_.GetField06() == 5900 && party->obj3D_.GetField06() == 10000))) {
                flag = 1;
            } else if (c != 0 && ((protagonist->obj3D_.GetField06() == 10100 && party->obj3D_.GetField06() == 6401) ||
                                  (protagonist->obj3D_.GetField06() == 6401 && party->obj3D_.GetField06() == 10100))) {
                flag = 1;
            }
            if (flag != 0) {
                if (((struct CombatantFlagsC2*)((unsigned char*)protagonist + 0xc2))->flag)
                    return ((struct CombatantFlagsC2*)((unsigned char*)party + 0xc2))->flag != 0;
                return ((struct CombatantFlagsC2*)((unsigned char*)party + 0xc2))->flag == 0;
            }
        }
    }
    return 0;
}
