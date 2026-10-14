#include <globaldefs.h>
#if defined(jpn)
#define data_ov004_0216fffa data_ov004_02170752
#define data_ov004_0216fff8 data_ov004_02170750
struct JPDispatchNode;
struct JPDispatchVtable { char pad[0xe0]; void (*setValue)(JPDispatchNode*, int); };
struct JPDispatchNode { JPDispatchVtable* vtable; };
#endif
#include "GameState/GameState.h"

struct Obj02086aec;
short SumCombatantKeyMatches02086aec(struct Obj02086aec* obj, int key);
extern "C" void func_ov023_021f64a8(void* obj, int id, int argE0, int argD8);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
#if defined(jpn)
extern "C" int func_ov023_021f6f10(void* self);
#define ScaleStatsIfType12_021f6f10 func_ov023_021f6f10
#else
int ScaleStatsIfType12_021f6f10(void* self);
#endif
extern "C" int func_ov004_02167908(void* a, int key);
struct Container020dedd0;
struct Element020de650 { char pad[4]; int field4; };
struct Element020de650* FindElementByKey020dedd0(struct Container020dedd0* c, int key);
extern "C" void func_ov023_021f809c(void* obj, void* param2);

extern short data_ov004_0216fffa;
extern short data_ov004_0216fff8;

// USA: func_ov004_021680cc
extern "C" ARM int func_ov004_021680cc(void* a) {
    short matches = SumCombatantKeyMatches02086aec((struct Obj02086aec*)GetPtrField0x2a04_02010828(GameState::GetInstance()), 0x5617);
#if defined(jpn)
    {
        JPDispatchNode* entry = (JPDispatchNode*)func_ov023_021f6880(func_ov011_021849c8(a), 0x2b);
        if (entry) entry->vtable->setValue(entry, matches);
    }
#else
    func_ov023_021f64a8(a, 0x2b, matches, 0xf);
#endif

    unsigned char* node11;
    void* sub;
    unsigned char* node6;
    sub = func_ov011_021849c8(a);
    node11 = (unsigned char*)func_ov023_021f6880(sub, 0xc);
    if (!node11) return 0;
    if (ScaleStatsIfType12_021f6f10(node11) != 6) return 0;

    node6 = (unsigned char*)func_ov023_021f6880(sub, 0xd);
    if (!node6) return 0;
    if (ScaleStatsIfType12_021f6f10(node6) != 6) return 0;

    for (int i = 0; i < 6; i++) {
        unsigned char* node4 = (unsigned char*)func_ov023_021f6880(sub, i + 0x15);
        if (!node4) continue;
        if (ScaleStatsIfType12_021f6f10(node4) != 8) continue;

        short valA = *(short*)((char*)&data_ov004_0216fffa + i * 4);
        short valB = *(short*)((char*)&data_ov004_0216fff8 + i * 4);

        void* container = (void*)func_ov004_02167908(a, 5);
        if (!container) continue;

        *(int*)(node4 + 0x20) = 0;
        node4[0xc] |= 8;

        struct Element020de650* elem = FindElementByKey020dedd0((struct Container020dedd0*)container, valA);
        if (!elem) continue;

        *(int*)(node4 + 0x20) = elem->field4;
        node4[0xc] &= ~8;
#if defined(jpn)
        {
            JPDispatchNode* entry = (JPDispatchNode*)func_ov023_021f6880(func_ov011_021849c8(a), i + 0x21);
            if (entry) entry->vtable->setValue(entry, valB);
        }
#else
        func_ov023_021f64a8(a, i + 0x21, valB, 0xf);
#endif
    }

    *(short*)(node11 + 0x104) = 0;
    *(short*)(node11 + 0x106) = 0;
    func_ov023_021f809c(node11, a);

    *(short*)(node6 + 0x104) = 0;
    *(short*)(node6 + 0x106) = 0;
    func_ov023_021f809c(node6, a);

    return 0;
}
