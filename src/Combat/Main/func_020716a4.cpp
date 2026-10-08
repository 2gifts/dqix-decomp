#include <globaldefs.h>
#include "GameState/GameState.h"

struct Variant02030b0c {
    int tag;
    union { int i; float f; } u;
};
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

extern "C" void* func_0205ec34(void);
extern "C" void func_0206dfe8(void* p, int a, int b);

extern "C" void _Z20ClearRegions0206e080Pci(void* obj, int slot);
#define _Z20ClearRegions0206e080Pci _Z20ClearRegions0206e080Pci
extern "C" void _Z31ClearIndexedEntryFields0206e0d0Pci(void* obj, int slot);
#define _Z31ClearIndexedEntryFields0206e0d0Pci _Z31ClearIndexedEntryFields0206e0d0Pci
extern "C" void _Z20SetOrClearBitInArrayPvPhii(void* obj, unsigned char* arr, int idx, int flag);
#define SetOrClearBitInArray _Z20SetOrClearBitInArrayPvPhii

extern "C" void _Z26SetField5cb0AndRecordByte0Pci(char* obj, int v);
#define SetField5cb0AndRecordByte0 _Z26SetField5cb0AndRecordByte0Pci
extern "C" void _Z26SetField5cb4AndRecordByte1Pci(char* obj, int v);
#define SetField5cb4AndRecordByte1 _Z26SetField5cb4AndRecordByte1Pci
extern "C" void _Z19SetSlotByte020107dcPci(char* base, int val);
#define _Z19SetSlotByte020107dcPci _Z19SetSlotByte020107dcPci

struct MsgQueueState02108d70 {
    unsigned char forceFlag;
    char pad1[7];
    void* entries;
    char pad2[4];
    int limit;
    int field14;
    char pad18[8];
    int targetValue;
    char pad20[4];
    int count;
};
extern struct MsgQueueState02108d70 data_02108d70;

// USA: func_020716a4
extern "C" ARM int func_020716a4(struct Variant02030b0c* args, int count) {
    int v0;
    int a;
    int b;
    int c;
    int v;
    void* entry;
    int i;
    GameState* bs;

    v0 = _ZNK6Script9Parameter5ToIntEv(args);
    if (data_02108d70.field14 != v0) {
        return 1;
    }

    a = _ZNK6Script9Parameter5ToIntEv(args + 1);
    b = _ZNK6Script9Parameter5ToIntEv(args + 2);
    {
        struct Variant02030b0c* last = args + 3;
        args = args + 4;
        c = _ZNK6Script9Parameter5ToIntEv(last);
    }

    bs = GameState::GetInstance();
    SetField5cb0AndRecordByte0((char*)bs, a);
    SetField5cb4AndRecordByte1((char*)bs, b);
    _Z19SetSlotByte020107dcPci((char*)bs, c);

    entry = func_0205ec34();
    _Z20ClearRegions0206e080Pci(entry, *(unsigned char*)((char*)entry + 0x332));
    _Z31ClearIndexedEntryFields0206e0d0Pci(entry, *(unsigned char*)((char*)entry + 0x332));
    func_0206dfe8(entry, 0, 0x200);
    func_0206dfe8(entry, 0x38e, 0x3e8);

    for (i = 0; i < count - 4; i++) {
        v = _ZNK6Script9Parameter5ToIntEv(args);
        args = args + 1;
        switch (v >> 16) {
        case 2:
            SetOrClearBitInArray(entry, (unsigned char*)entry + *(unsigned char*)((char*)entry + 0x332) * 0x1c + 3, (unsigned short)v, 1);
            break;
        case 1:
            SetOrClearBitInArray(entry, (unsigned char*)entry + *(unsigned char*)((char*)entry + 0x332) * 0x1c + 0x10, (unsigned short)v, 1);
            break;
        case 0:
            SetOrClearBitInArray(entry, (unsigned char*)entry + 0x8c, (unsigned short)v, 1);
            break;
        }
    }

    return 1;
}
