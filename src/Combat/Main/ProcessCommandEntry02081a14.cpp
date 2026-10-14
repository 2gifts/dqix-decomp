#include <globaldefs.h>
#include "std_library_functions.h"

struct TableA68;
struct StoreStruct;

extern int GetGlobalField0x1c020421a0();
void* FindEntryByKey_02072a68(struct TableA68* table, int key);
void StoreInArray0x8b0_020465c0(struct StoreStruct* base, int index, int value);

extern "C" void func_02046380(int g);
extern "C" void func_02046608(int g, int nibble, void* found, void* buf, int a5, int a6, int a7);
extern "C" int func_020420e8(void* value, int flag);
extern "C" void func_0204f41c(void* b, short diff, int field8, void* field18, int nibble, int initial4, short* fieldAaddr, short* fieldCaddr, int zero);

struct AObj02081a14 {
    struct TableA68* field0;
    char pad4[0x18 - 0x4];
    void* field18;
};

struct BObj02081a14 {
    char pad[0xb4];
    unsigned short fieldB4;
    unsigned short fieldB6;
};

struct Entry02081a14 {
    int field0;
    char pad1[0x6 - 0x4];
    short field6;
    short field8;
    short fieldA;
    short fieldC;
    short fieldE;
    short field10;
    char pad2[0x13 - 0x12];
    unsigned char field13nibble : 4;
    unsigned char field13rest : 4;
    unsigned char field14 : 2;
    char pad3[0x28 - 0x15];
    short field28;
    unsigned char field2a;
};

// USA: func_02081a14
ARM void ProcessCommandEntry02081a14(struct AObj02081a14* a, struct BObj02081a14* b, struct Entry02081a14* e) {
    int initial4 = e->field13rest;
    if (e->field2a & 0x4) {
        initial4 = 5;
    }

    int g = GetGlobalField0x1c020421a0();
    memset(a->field18, 0, 0x960);
    func_02046380(g);
    StoreInArray0x8b0_020465c0((struct StoreStruct*)g, e->field10, e->field0);

    void* found = FindEntryByKey_02072a68(a->field0, e->fieldE);
    func_02046608(g, e->field13nibble, found, a->field18, 0x100, 0, 0);

    int y = 0;
    if (e->field14 != 0) {
        y = func_020420e8(a->field18, 0);
    }

    int nibble = e->field13nibble;
    b->fieldB4 = nibble;
    b->fieldB6 = nibble + 1;

    func_0204f41c(b, (short)(e->field6 + e->field28 - y), e->field8, a->field18,
                  e->field13nibble, initial4, &e->fieldA, &e->fieldC, 0);
}
