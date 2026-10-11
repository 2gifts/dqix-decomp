#include <globaldefs.h>
#include "GameState/GameState.h"

int GetField0x3b0Value(GameState* battleStruct);
int GetWord0x0(int* obj);
void* GetActiveCombatWork(void);
extern "C" void func_ov000_0216d370(int a, int b, int c, int d);

extern unsigned int data_ov025_021ef9a4;
extern unsigned int data_ov025_021ef9c0;

struct In021e9a94 {
    char pad[0x1c0];
    int field1c0;
};

// USA: func_ov025_021e9a94
ARM void UpdateCombatFlags_021e9a94(struct In021e9a94* obj) {
    GameState* bs = GameState::GetInstance();
    int val = GetField0x3b0Value(bs);
    GetWord0x0((int*)bs);
    GetActiveCombatWork();
    if (data_ov025_021ef9a4 & 1) {
        data_ov025_021ef9a4 = (data_ov025_021ef9a4 | 8) & ~1;
    }
    if (!(data_ov025_021ef9a4 & 2)) {
        return;
    }
    if (obj->field1c0 == 0) {
        func_ov000_0216d370(val, 1, 1, 1);
    }
    data_ov025_021ef9c0 += 1;
    data_ov025_021ef9a4 &= ~2;
}
