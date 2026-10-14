#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Script.h"

struct Variant02030b0c {
    int tag;
    union { int i; float f; } u;
};

extern "C" void* func_0205ec34(void);
extern "C" void func_0206dfe8(void* p, int a, int b);

void ClearRegions0206e080(char* obj, int slot);
void ClearIndexedEntryFields0206e0d0(char* obj, int slot);
void SetOrClearBitInArray_0206df6c(void* obj, unsigned char* arr, int idx, int flag);

void SetField5cb0AndRecordByte0_02010774(char* obj, int v);
void SetField5cb4AndRecordByte1_020107a8(char* obj, int v);
void SetSlotByte020107dc(char* base, int val);

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

    v0 = ((Script::Parameter*)args)->ToInt();
    if (data_02108d70.field14 != v0) {
        return 1;
    }

    a = ((Script::Parameter*)(args + 1))->ToInt();
    b = ((Script::Parameter*)(args + 2))->ToInt();
    {
        struct Variant02030b0c* last = args + 3;
        args = args + 4;
        c = ((Script::Parameter*)last)->ToInt();
    }

    bs = GameState::GetInstance();
    SetField5cb0AndRecordByte0_02010774((char*)bs, a);
    SetField5cb4AndRecordByte1_020107a8((char*)bs, b);
    SetSlotByte020107dc((char*)bs, c);

    entry = func_0205ec34();
    ClearRegions0206e080((char*)entry, *(unsigned char*)((char*)entry + 0x332));
    ClearIndexedEntryFields0206e0d0((char*)entry, *(unsigned char*)((char*)entry + 0x332));
    func_0206dfe8(entry, 0, 0x200);
    func_0206dfe8(entry, 0x38e, 0x3e8);

    for (i = 0; i < count - 4; i++) {
        v = ((Script::Parameter*)args)->ToInt();
        args = args + 1;
        switch (v >> 16) {
        case 2:
            SetOrClearBitInArray_0206df6c(entry, (unsigned char*)entry + *(unsigned char*)((char*)entry + 0x332) * 0x1c + 3, (unsigned short)v, 1);
            break;
        case 1:
            SetOrClearBitInArray_0206df6c(entry, (unsigned char*)entry + *(unsigned char*)((char*)entry + 0x332) * 0x1c + 0x10, (unsigned short)v, 1);
            break;
        case 0:
            SetOrClearBitInArray_0206df6c(entry, (unsigned char*)entry + 0x8c, (unsigned short)v, 1);
            break;
        }
    }

    return 1;
}
