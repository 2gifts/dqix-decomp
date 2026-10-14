#include <globaldefs.h>

struct Struct020865b0;
struct FindEntryContainer02086e50;
struct Wrapper02168088;

extern "C" ARM void func_ov003_02167e28(void* self, void* stats, int flag, unsigned char index,
                                        int byteValue, int halfValue, int wordValue);
extern "C" ARM void func_ov003_02167fa4(void* self, int flag, unsigned char* table);
void SetEntryFieldsForRange_02168088(struct Wrapper02168088* obj, int* arr);
extern "C" int func_020813ec(void* list, int arg);
extern "C" void func_02042764(unsigned char* src, char* dst, int n);
extern "C" void memset(void* dst, int value, int n);
extern "C" void* _Z17GetPtrField0x2a04P9GameState(void* gameState);
extern "C" void* _ZN9GameState11GetInstanceEv();
void* FindEntryBySignedId02086e50(FindEntryContainer02086e50* p, int id);
int GetFieldAt0x50(Struct020865b0* p);

struct Entry02167ca8 {
    unsigned char pad0[2];
    unsigned char metaValues[13];
    unsigned char tableF[13];
    int wordValues[13];
    unsigned char pad50[0xf6 - 0x50];
    unsigned char tableF6[0x14c - 0xf6];
    struct { unsigned int v0 : 10; unsigned int v1 : 10; unsigned int v2 : 10; } g0;
    struct { unsigned int v3 : 10; unsigned int v4 : 10; unsigned int v5 : 10; } g1;
    struct { unsigned int v6 : 10; } g2;
    struct { unsigned int v7 : 10; unsigned int v8 : 10; unsigned int v9 : 10; } g3;
    struct { unsigned int v10 : 10; unsigned int v11 : 10; } g4;
    unsigned char pad160[0x174 - 0x160];
    unsigned char flag : 1;
};

struct Menu_02167ca8 {
    void* pad00[4];
    void* list;
    char pad14[0x2e - 0x14];
    char stats[0x30];
    char pad5e[0x76 - 0x5e];
    signed char combatantId;
};

// USA: func_ov003_02167ca8
extern "C" ARM void func_ov003_02167ca8(Menu_02167ca8* self) {
    Entry02167ca8* entry = (Entry02167ca8*)FindEntryBySignedId02086e50(
        (FindEntryContainer02086e50*)_Z17GetPtrField0x2a04P9GameState(_ZN9GameState11GetInstanceEv()),
        self->combatantId);
    if (entry == 0) {
        return;
    }
    int index = GetFieldAt0x50((Struct020865b0*)entry);
    memset(self->stats, 0, 0x30);
    func_02042764((unsigned char*)entry + 0x140, self->stats, 1);
    func_ov003_02167e28(self, self->stats, entry->flag, (unsigned char)index,
                        entry->tableF[index], entry->metaValues[index], entry->wordValues[index]);
    func_ov003_02167fa4(self, GetFieldAt0x50((Struct020865b0*)entry) & 0xff, entry->tableF6);
    int values[12];
    int a0 = entry->g0.v0;
    int b0 = a0;
    values[0] = b0;
    int a1 = entry->g0.v1;
    int b1 = a1;
    values[1] = b1;
    int a2 = entry->g0.v2;
    int b2 = a2;
    values[2] = b2;
    int a3 = entry->g1.v3;
    int b3 = a3;
    values[3] = b3;
    int a4 = entry->g1.v4;
    values[4] = a4;
    int a5 = entry->g1.v5;
    values[5] = a5;
    int a6 = entry->g2.v6;
    values[6] = a6;
    int a7 = entry->g3.v7;
    values[7] = a7;
    int a8 = entry->g3.v8;
    values[8] = a8;
    int a9 = entry->g3.v9;
    values[9] = a9;
    int a10 = entry->g4.v10;
    values[10] = a10;
    int a11 = entry->g4.v11;
    values[11] = a11;
    SetEntryFieldsForRange_02168088((Wrapper02168088*)self, values);
    func_020813ec(self->list, 0);
}
