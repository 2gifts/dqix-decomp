#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_0202ae18(void);
extern "C" int func_0202c508(void);
extern "C" void func_ov017_021a23b0(void* self, int val);

GameObject* FindCombatantByField0x16a_0200ffe0(GameState* battleStruct, int id);
void SetField0x17eBitAndHigh_02079710(unsigned char* obj, int bit, int cond);
int CheckAndSetAllCombatantFlags0207973c(unsigned char* obj);
int IsField0x17eAllSet_020797bc(unsigned char* obj);
void EnqueueEventTag140_021d0aa8(unsigned short a, unsigned char b);
void ClearField0x17e_020797d0(unsigned char* obj);

// USA: func_ov017_02192654  (semantic: NotifyCombatantFlagBit_02192654)
extern "C" ARM void func_ov017_02192654(int bit, int id, unsigned char cond) {
    void* base = func_ov017_0218b5b0();
    GameState* battleStruct = GameState::GetInstance();
    func_0202ae18();
    if (func_0202c508()) {
        GameObject* combatant = FindCombatantByField0x16a_0200ffe0(battleStruct, id);
        if (combatant != 0) {
            SetField0x17eBitAndHigh_02079710((unsigned char*)combatant, bit, cond);
            if (CheckAndSetAllCombatantFlags0207973c((unsigned char*)combatant)) {
                if (IsField0x17eAllSet_020797bc((unsigned char*)combatant)) {
                    EnqueueEventTag140_021d0aa8((unsigned short)id, 1);
                    func_ov017_021a23b0(base, id);
                }
                ClearField0x17e_020797d0((unsigned char*)combatant);
            }
        }
    } else {
        EnqueueEventTag140_021d0aa8((unsigned short)id, cond);
    }
}
