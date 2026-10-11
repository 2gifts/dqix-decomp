#include <globaldefs.h>
#include "Combat/Main/MessageSlotTable.h"


extern "C" unsigned char func_ov004_02157128(void* obj);
extern "C" void* func_ov004_02156fd4(void* obj, int key);
struct Container020dedd0;
struct Element020de650;
Element020de650* FindElementByKey020dedd0(Container020dedd0* c, int key);
extern "C" void func_020dd7ac(void* buf);
extern "C" int func_020dd4c4(void*, void*);
void Setup020ddaf4(int a, int b, int c, int d, int e, int f);
extern "C" void* func_ov004_02156f04(void* a, int key);
extern "C" void* func_ov004_02156f38(void* obj, int key);
extern "C" void* func_ov004_02156f6c(void* obj, int key);
extern "C" void func_ov023_021f809c(void* obj, void* param2);
extern "C" void func_ov023_021f65d4(void* obj, int id, int mask);
void ClearNodeMaskById_021f6600(void* obj, int id, int mask);
extern "C" void* func_ov011_021849c8(void* a);
extern "C" void* func_ov023_021f6880(void* obj, int key);
extern "C" void* func_ov004_02157054(void* a, int key);
struct Obj021fbdf4;
void SetFieldThenTailCallOffset20_021fbdf4(struct Obj021fbdf4* obj, unsigned char v);

struct Struct021707d8_02159ce0 { char pad[8]; unsigned char* ptr; };
extern Struct021707d8_02159ce0 data_ov004_021707d8;

typedef void (*FuncPtrE0_02159ce0)(void*, int);
struct HandlerE0_02159ce0 { char pad[0xe0]; FuncPtrE0_02159ce0 func; };
struct NodeE0_02159ce0 { HandlerE0_02159ce0* handler; };

typedef void (*FuncPtrD8_02159ce0)(void*, int);
struct HandlerD8_02159ce0 { char pad[0xd8]; FuncPtrD8_02159ce0 func; };
struct NodeD8_02159ce0 { HandlerD8_02159ce0* handler; };

struct NodeInt20_02159ce0 { char pad[0x20]; int field20; };
struct NodeShort38_02159ce0 { char pad[0x38]; short field38; };

struct ElemNibble_02159ce0 { unsigned int nibble : 4; unsigned int rest : 28; };

// USA: func_ov004_02159ce0
// JPN: func_ov004_0215acd8
extern "C" ARM int func_ov004_02159ce0(void* a) {
    unsigned char idxVal = func_ov004_02157128(a);
    Container020dedd0* node = (Container020dedd0*)func_ov004_02156fd4(a, 5);
    if (!node) return 0;

    short key = *(short*)(data_ov004_021707d8.ptr + 0xe);
    Element020de650* elem = FindElementByKey020dedd0(node, key);
    if (!elem) return 0;

    MessageSlotTable_020dd7ac bufC;
    func_020dd7ac(&bufC);
    int typeCode = 1;
    unsigned int nibble = ((ElemNibble_02159ce0*)((char*)elem + 8))->nibble;

    unsigned short valA, valB;
    if (nibble == 0) {
        Setup020ddaf4((int)&bufC, idxVal, (int)elem, 0, (int)&valA, (int)&valB);
    } else {
        Setup020ddaf4((int)&bufC, idxVal, (int)elem, typeCode, (int)&valA, (int)&valB);
        typeCode = 3;
    }

    NodeInt20_02159ce0* n3e8 = (NodeInt20_02159ce0*)func_ov004_02156f04(a, 0x3e8);
    if (n3e8) n3e8->field20 = *(int*)((char*)elem + 4);

    NodeShort38_02159ce0* n3ea = (NodeShort38_02159ce0*)func_ov004_02156f04(a, 0x3ea);
    if (n3ea) n3ea->field38 = (short)(typeCode + 0xb);

    if (func_020dd4c4((void*)idxVal, elem) != 0) {
        func_ov023_021f65d4(a, 0x3eb, 8);
        func_ov023_021f65d4(a, 0x3ec, 8);
        func_ov023_021f65d4(a, 0x3ed, 8);
        ClearNodeMaskById_021f6600(a, 0x3ee, 8);
    } else {
        NodeE0_02159ce0* h3eb = (NodeE0_02159ce0*)func_ov004_02156f38(a, 0x3eb);
        if (h3eb) h3eb->handler->func(h3eb, valA);

        NodeE0_02159ce0* h3ed = (NodeE0_02159ce0*)func_ov004_02156f38(a, 0x3ed);
        if (h3ed) h3ed->handler->func(h3ed, valB);

        NodeD8_02159ce0* d3eb = (NodeD8_02159ce0*)func_ov023_021f6880(func_ov011_021849c8(a), 0x3eb);
        if (d3eb) d3eb->handler->func(d3eb, 0xf);

        if (valA == valB) {
            NodeD8_02159ce0* d3ed = (NodeD8_02159ce0*)func_ov023_021f6880(func_ov011_021849c8(a), 0x3ed);
            if (d3ed) d3ed->handler->func(d3ed, 0xf);
        } else if (valA < valB) {
            NodeD8_02159ce0* d3ed = (NodeD8_02159ce0*)func_ov023_021f6880(func_ov011_021849c8(a), 0x3ed);
            if (d3ed) d3ed->handler->func(d3ed, 0x5);
        } else {
            NodeD8_02159ce0* d3ed = (NodeD8_02159ce0*)func_ov023_021f6880(func_ov011_021849c8(a), 0x3ed);
            if (d3ed) d3ed->handler->func(d3ed, 0x9);
        }

        ClearNodeMaskById_021f6600(a, 0x3eb, 8);
        ClearNodeMaskById_021f6600(a, 0x3ec, 8);
        ClearNodeMaskById_021f6600(a, 0x3ed, 8);
        func_ov023_021f65d4(a, 0x3ee, 8);
    }

    NodeE0_02159ce0* n17 = (NodeE0_02159ce0*)func_ov004_02156f6c(a, 0x17);
    if (n17) func_ov023_021f809c(n17, a);

    void* n7 = func_ov004_02157054(a, 7);
    if (n7) {
        SetFieldThenTailCallOffset20_021fbdf4((Obj021fbdf4*)n7, idxVal);
#if defined(jpn)
        data_ov004_021707d8.ptr[0xa8] = 0;
#else
        data_ov004_021707d8.ptr[0x9c] = 0;
#endif
    }

    return 0;
}
