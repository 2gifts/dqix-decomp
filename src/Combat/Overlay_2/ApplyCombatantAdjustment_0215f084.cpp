#include <globaldefs.h>
#include "GameState/GameState.h"

int AdjustValueByFieldFlag(void *obj, unsigned int flag);
void *GetGlobalField0x1c020421a0();
extern "C" void func_02046380();
extern "C" void _Z17StoreInArray0x8b0P11StoreStructii(void *g, int idx, int val);
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(void *c, int key);
extern "C" void func_02046608(void *g, int a, int b, int c, int d, int e, int f);

struct Struct020fdcb0 { int f0; int f4; char pad[0x18]; };
extern Struct020fdcb0 data_020fdcb0[];

// USA: func_ov002_0215f084  (semantic: ApplyCombatantAdjustment_0215f084)
extern "C" ARM void func_ov002_0215f084(void *objPtr, int param2) {
    if (param2 == 0) {
        return;
    }
    char *base = (char*)objPtr;
    void *bs = GameState::GetInstance();
    signed char byteFlag = *(signed char*)(base + 0x1c20);
    void *combatant = ((GameState*)bs)->GetPartyMemberByIndex(byteFlag);
    if (combatant == 0) {
        return;
    }
    short idx = *(short*)(base + 0x1bfa);
    void *entry = 0;
    if (idx >= 0) {
        if (idx < 0x20) {
            entry = *(void**)(base + 0x2000 + idx * 4 + 0x4a0);
        }
    }
    if (entry == 0) {
        return;
    }
    struct FlagsField8 { unsigned int byte0 : 8; unsigned int rest : 24; };
    unsigned int flagByte = ((FlagsField8*)((char*)entry + 8))->byte0;
    int adjResult = AdjustValueByFieldFlag(combatant, flagByte);
    short s = *(short*)((char*)combatant + 4);
    Struct020fdcb0 *e = &data_020fdcb0[s];
    void *g = GetGlobalField0x1c020421a0();
    func_02046380();
    _Z17StoreInArray0x8b0P11StoreStructii(g, 0, adjResult);
    _Z17StoreInArray0x8b0P11StoreStructii(g, 1, e->f4);
    int fieldResult = _Z21GetFieldByKey020e0434P17Container020e0310i(base + 0x20, 0xbb8);
    func_02046608(g, 0xa, fieldResult, param2, 0x100, 0, 0);
}
