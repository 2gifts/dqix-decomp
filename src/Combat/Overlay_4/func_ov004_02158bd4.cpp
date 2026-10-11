#include <globaldefs.h>
#include "System/Memory.h"


int DispatchNodeIfType7_02156e2c(void* a, int key);
void* GetEntryFor_021570a4(void* obj, int index);
extern "C" void* func_ov004_02156f6c(void*, int);
extern "C" void func_ov023_021f809c(void* obj, void* param2);
extern "C" void* func_ov004_02157054(void* a, int key);

struct Obj021fbdf4;
void SetFieldThenTailCallOffset20_021fbdf4(Obj021fbdf4*, unsigned char);
int TailCallOffset20_021fbdcc(void*, int, int, int);
typedef int (*TailCallOffset20Fn_02158bd4)(void*, int);
typedef void (*SetFieldFn_02158bd4)(Obj021fbdf4*, int);

extern "C" int func_ov004_02156fd4(void* a, int key);

struct Container020dedd0;
struct Element020de650 { unsigned int v[8]; };
Element020de650* FindElementByKey020dedd0(Container020dedd0*, int);

extern "C" void* func_ov011_021849c8(void*);
void CallFunc021f6788ForIndexUnder3_021f6eb8(void* obj, int idx);
extern "C" void func_ov004_0215d738(void*);
extern "C" void func_ov023_021f65d4(void* obj, int id, int mask);
void ClearNodeMaskById_021f6600(void*, int, int);
extern "C" void func_ov004_0215cec4(void*);
extern "C" int func_ov004_0215d384(void* a);
void CopyToSlot_021f6e90(char* obj, int idx, const void* src);

struct Struct021707d8_02158bd4 { char pad[8]; unsigned char* ptr; };
extern Struct021707d8_02158bd4 data_ov004_021707d8;

struct NibbleView_02158bd4 { char pad[8]; unsigned int nibble : 4; };

// USA: func_ov004_02158bd4
// JPN: func_ov004_02159c98
extern "C" ARM int func_ov004_02158bd4(void* obj) {
    int slotType = DispatchNodeIfType7_02156e2c(obj, 0x5b);
    if (slotType < 0) return 0;
    void* entry = GetEntryFor_021570a4(obj, (unsigned char)slotType);
    if (!entry) return 0;

    void* node2 = func_ov004_02156f6c(obj, 0x15);
    if (node2) {
        func_ov023_021f809c(node2, obj);
    }

    void* nodeX = func_ov004_02157054(obj, 7);
    if (nodeX) {
#if defined(jpn)
        if (data_ov004_021707d8.ptr[0xa8] == 0) {
#else
        if (data_ov004_021707d8.ptr[0x9c] == 0) {
#endif
            ((SetFieldFn_02158bd4)&SetFieldThenTailCallOffset20_021fbdf4)((Obj021fbdf4*)nodeX, -1);
#if defined(jpn)
            data_ov004_021707d8.ptr[0xa8] = 1;
#else
            data_ov004_021707d8.ptr[0x9c] = 1;
#endif
        }
        ((TailCallOffset20Fn_02158bd4)&TailCallOffset20_021fbdcc)(nodeX, *(short*)((char*)entry + 0));
    }

    void* container = (void*)func_ov004_02156fd4(obj, 5);
    if (!container) return 0;
    Element020de650* elem = FindElementByKey020dedd0((Container020dedd0*)container, *(short*)((char*)entry + 0));
    if (!elem) return 0;

    void* thing = func_ov011_021849c8(obj);
    CallFunc021f6788ForIndexUnder3_021f6eb8(thing, 0);

    char buf[0x16];
    VectorizedMemset(buf, 0, 0x16);
    *(short*)(buf + 0x14) = -1;
    *(short*)(buf + 0x12) = 0x384;

    int nibble = ((NibbleView_02158bd4*)elem)->nibble;
    switch (nibble) {
        case 8:
        case 9:
            func_ov004_0215d738(obj);
            func_ov023_021f65d4(obj, 0x17, 8);
            func_ov023_021f65d4(obj, 0x1b, 8);
            ClearNodeMaskById_021f6600(obj, 0x1c, 8);
            buf[0] = 3;
            *(short*)(buf + 2) = 0x15;
            *(short*)(buf + 4) = 0x1c;
            *(short*)(buf + 6) = 0x16;
            break;
        default:
            func_ov004_0215cec4(obj);
            func_ov004_0215d384(obj);
            ClearNodeMaskById_021f6600(obj, 0x17, 8);
            ClearNodeMaskById_021f6600(obj, 0x1b, 8);
            func_ov023_021f65d4(obj, 0x1c, 8);
            buf[0] = 4;
            *(short*)(buf + 2) = 0x15;
            *(short*)(buf + 4) = 0x17;
            *(short*)(buf + 6) = 0x1b;
            *(short*)(buf + 8) = 0x16;
            break;
    }

    CopyToSlot_021f6e90((char*)thing, 0, buf);
    return 0;
}
