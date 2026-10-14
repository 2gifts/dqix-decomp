#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" void func_02052d7c(void* combatant, int arg1, int arg2);
extern "C" void func_02072afc(int id, void* out1, void* out2);
int GetFieldAt0x150_02053c6c(unsigned char* obj);
extern char data_020f0cf4[];

struct EffectSlot02072c9c {
    void* ptr;
    char pad[0x14];
    short flag;
};

// USA: func_02072c9c
ARM void FormatEffectStats02072c9c(int combatantId, char* buf) {
    GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(GameState::GetInstance(), combatantId);
    if (combatant == NULL) {
        return;
    }
    int fieldVal = GetFieldAt0x150_02053c6c((unsigned char*)combatant);
    if (fieldVal == 0) {
        return;
    }
    char* table = (char*)fieldVal;

    char local1[0x2c];
    char local2[0x18];
    func_02072afc(combatantId, local1, local2);

    struct EffectSlot02072c9c* subB = (struct EffectSlot02072c9c*)(table + 0x294);
    struct EffectSlot02072c9c* subA = (struct EffectSlot02072c9c*)(table + 0x194);
    if (subA == NULL) {
        func_02052d7c(combatant, 0, -1);
        func_02072afc(combatantId, local1, local2);
        subA = (struct EffectSlot02072c9c*)(table + 0x194);
    }

    unsigned int* innerA = *(unsigned int**)subA;
    unsigned int val1 = (innerA[1] << 12) >> 24;
    unsigned int val2 = 0;
    if (subB->flag >= 0) {
        if (subB != NULL) {
            unsigned int* innerB = *(unsigned int**)subB;
            val2 = (innerB[1] << 12) >> 24;
        }
    }
    sprintf(buf, data_020f0cf4, val1, val2);
}
