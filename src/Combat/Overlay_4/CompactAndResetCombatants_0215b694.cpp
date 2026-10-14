#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetPtrField0x2a04_02010828(GameState* battleStruct);
int Compact0207c51c(unsigned char* base, int key);
void* ResetCombatantFields_0215a2f8(void* obj);
extern "C" void func_ov011_021848a0(void* obj, int val);
extern "C" void func_ov023_021f65d4(void* a, int key, int mask);

struct Struct021707d8_0215b694 { char pad[8]; unsigned char* ptr; };
extern Struct021707d8_0215b694 data_ov004_021707d8;

// USA: func_ov004_0215b694  (semantic: CompactAndResetCombatants_0215b694)
extern "C" ARM int func_ov004_0215b694(void* obj) {
    void* ptr = GetPtrField0x2a04_02010828(GameState::GetInstance());
    if (!ptr) {
        return 0;
    }
    for (int i = 0; i < 8; i++) {
        int key = *(data_ov004_021707d8.ptr + i + 0x7c);
        Compact0207c51c((unsigned char*)ptr + 0x1d4, key);
    }
    ResetCombatantFields_0215a2f8(data_ov004_021707d8.ptr);
    func_ov011_021848a0(obj, 0x3a0);
    func_ov023_021f65d4(obj, 2, 8);
    return 0;
}
