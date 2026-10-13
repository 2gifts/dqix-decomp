#include <globaldefs.h>

#if defined(jpn)
enum { kModeOffset = 0x915, kFlagsOffset = 0x9cb, kBattleFlagsOffset = 0xa6c };
#else
enum { kModeOffset = 0x9c1, kFlagsOffset = 0xa97, kBattleFlagsOffset = 0xccc };
#endif

#include "GameState/GameState.h"

void* GetDataPtr02114e04_020d6c00(void);

struct FlagWord02046708;
int TestFlags02046708(struct FlagWord02046708* word, unsigned int mask);

void ApplyBitfieldsForTableEntries02026ebc(void* obj);
void ProcessCombatantElements02027100(unsigned char* obj);

extern "C" {
    void func_0202720c(void* obj);
    void func_02025f28(void* obj);
    void func_02024000(void* obj);
    void func_0202427c(void* obj);
    void func_02024518(void* obj);
    void func_02024e78(void* obj);
    void func_020251bc(void* obj);
    void func_0202555c(void* obj);
    void func_02025b0c(void* obj);
    void func_020276dc(void* obj);
    void func_020dc7e8(int a, int b);
}

struct BattleFlags5ccc020235c8 {
    char pad[kBattleFlagsOffset];
    unsigned int flagsBit0 : 1;
    signed int flagsBit1 : 1;
    unsigned int flagsRest : 30;
};

struct Obj020235c8 {
    char pad0[0x14];
    int field0x14;
    char pad1[kModeOffset - 0x18];
    unsigned char field0x9c1;
    char pad2[kFlagsOffset - (kModeOffset + 1)];
    unsigned char field0xa97;
};

// USA: func_020235c8
ARM void ProcessCombatantState020235c8(struct Obj020235c8* obj) {
    GameState* battle = GameState::GetInstance();

    if (TestFlags02046708((struct FlagWord02046708*)GetDataPtr02114e04_020d6c00(), 0x41)) {
        return;
    }

    unsigned char mode = obj->field0x9c1;
    switch (mode) {
    case 1:
        func_0202720c(obj);
        break;
    case 4:
        func_02025f28(obj);
        break;
    default:
        func_02024000(obj);
        func_0202427c(obj);
        ApplyBitfieldsForTableEntries02026ebc(obj);
        switch (obj->field0x14) {
        case 0:
            func_02024518(obj);
            break;
        case 1:
            func_02024e78(obj);
            break;
        case 2:
            func_020251bc(obj);
            break;
        case 3:
            func_0202555c(obj);
            break;
        case 4:
            func_02025b0c(obj);
            break;
        }
        break;
    }

    func_020276dc(obj);
    if (!(obj->field0xa97 & 1)) {
        ProcessCombatantElements02027100((unsigned char*)obj);
    }

    if (((struct BattleFlags5ccc020235c8*)((char*)battle + 0x5000))->flagsBit1) {
        func_020dc7e8(6, 6 - 7);
        func_020dc7e8(7, 7 - 8);
    }
}
