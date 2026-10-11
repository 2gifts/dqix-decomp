// JPN: func_ov017_021cc170
#if defined(jpn)
enum { RegionOffset718 = 0x508 };
#else
enum { RegionOffset718 = 0x718 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8468(void* obj);
void* GetField6b0_021b8470(void* obj);
void SetCombatWorkFlags0x55f4(void* work, int mask);
int GetField0x3acValue(GameState* battleStruct);
void SetByteFields0x77d3And0x77d4(void* obj, int a, int b);
extern "C" void __clear(void* buf, int len);
extern "C" void func_ov017_021b848c(void* h, void* buf, int a, int b, int c, int d, int e, int f);

struct EventHdr021cbcc0 {
    unsigned char pad0[8];
    unsigned short field8;
};

struct Evt021cbcc0 {
    unsigned char pad0[4];
    unsigned short field4;
    unsigned short field6;
    unsigned int field8;
    unsigned char field0xc;
    signed char field0xd;
    unsigned char field0xe;
    unsigned char field0xf;
    signed char field0x10;
    unsigned char pad1;
    signed short field0x12;
};

// USA: func_ov017_021cbcc0  (semantic: ApplyEventTagFlagsAndDispatch_021cbcc0)
extern "C" ARM void func_ov017_021cbcc0(int unused0, Evt021cbcc0* evt, GameState* battleStruct, unsigned char* base) {
    unsigned short f4;
    unsigned short hf8;
    unsigned int f8word;
    unsigned char fE;
    unsigned char fF;
    EventHdr021cbcc0* a;
    void* field6b0;
    void* field6ac;
    void* table = *(void**)(base + 0x3000 + RegionOffset718);
    a = (EventHdr021cbcc0*)func_ov017_021b8478(table);
    if (!a) return;
    field6b0 = GetField6b0_021b8470(table);
    if (!field6b0) return;
    field6ac = func_ov017_021b8468(table);
    if (!field6ac) return;

    f4 = evt->field4;
    hf8 = a->field8;
    f8word = evt->field8;
    fE = evt->field0xe;
    fF = evt->field0xf;
    if (f4 != hf8) return;

    SetCombatWorkFlags0x55f4(field6ac, 0x80000000);
    int idx = GetField0x3acValue(battleStruct);
    if (!(evt->field0xc & (1 << idx))) return;

    *(unsigned char*)((char*)field6b0 + 0x8e48) = (unsigned char)f8word;
    SetByteFields0x77d3And0x77d4(field6ac, fE, fF);

    unsigned char buf[4];
    __clear(buf, 4);
    for (int i = 0; i < 4; i++) {
        if (evt->field0xc & (1 << i)) buf[i] = 1;
        else buf[i] = 0;
    }
    func_ov017_021b848c(table, buf, evt->field0xd, 1, evt->field6, evt->field0x10, 1, evt->field0x12);
}
