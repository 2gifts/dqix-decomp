#include <globaldefs.h>
#if defined(jpn)
enum{regionTable=0x10,regionFlag=0x868};
#else
enum{regionTable=0x190,regionFlag=0x998};
#endif
#if defined(jpn)
#define func_ov023_021f6524 func_ov004_02168f08
#define func_ov004_02168b08 func_ov004_02169040
#define func_ov023_021f65d4 func_ov004_02168eac
#endif

#include "std_library_functions.h"
#include "Resource/GameResources.h"

extern "C" void* func_ov023_021f6524(void* ctx, int value);
struct TableA68;
extern "C" TableA68* func_ov004_02168b08(void* a, int key);
int GetGlobalField0x1c020421a0(void);
extern "C" int func_ov023_021f9bc8(char* obj);
extern "C" void func_ov004_0216950c(void* obj);
extern "C" void func_ov004_0216920c(void* obj);
extern "C" void __clear(void* buf, int n);
void* FindEntryByKey_02072a68(struct TableA68* table, int key);
extern "C" void func_02046380(void* global);
extern "C" void func_02042764(void* a, void* b, int flag);
void SetIndexedName02046574(struct Obj02046574* obj, int index, char* str);
#if defined(jpn)
extern "C" void func_0204500c(void*, void*, int);
#else
extern "C" void func_0204500c(void* field, void* buf, int p2, int p3);
#endif
extern "C" void func_ov023_021f65d4(void* obj, int id, int mask);
struct Fields021849e0;
void SetFieldConditional_021849e0(struct Fields021849e0* obj, unsigned short val);
extern "C" void func_ov011_021848a0(void* obj, int val);

struct TableA68 { struct EntryA68* entries; short count; };
extern void* data_ov004_02171030;

struct Entry0216a464 {
    unsigned char unknown00[6];
    char name[11];
    unsigned char field11;
    unsigned short lowBits : 14;
    unsigned short used : 1;
    unsigned short highBit : 1;
    unsigned char unknown14[0x18];
};
struct SavedEntryTable {
    unsigned char count;
    unsigned char unknown01[3];
    Entry0216a464 entries[16];
};

// USA: func_ov004_0216a464  (semantic: AddSaveDataEntryAndDispatch_0216a464)  (semantic: AddSaveDataEntryAndDispatch_0216a464)
extern "C" ARM int func_ov004_0216a464(void* a) {
    if (!*(void**)((char*)data_ov004_02171030 + regionTable)) return 0;

    void* node = func_ov023_021f6524(a, 0x64);
    TableA68* table3 = func_ov004_02168b08(a, 3);
    int g = GetGlobalField0x1c020421a0();
    func_ov023_021f9bc8((char*)node);
    func_ov004_0216950c(a);

    GameResources* resources = func_ov017_0218b5b0();
    node = resources->unknown_ptr_array_3afc[34];
    SavedEntryTable* table = *(SavedEntryTable**)((char*)data_ov004_02171030 + regionTable);

    Entry0216a464* entry = table->entries;
    int idx;
    for (idx = 0; idx < 16; entry++, idx++) {
        if (!entry->used) {
            memcpy(entry, (char*)node + 0x28, sizeof(*entry));
            SavedEntryTable* currentTable = *(SavedEntryTable**)((char*)data_ov004_02171030 + regionTable);
            ++currentTable->count;
            break;
        }
    }

    func_ov004_0216920c(a);

#if !defined(jpn)
    char buf[0x30];
    __clear(buf, 0x30);
#endif

    void* entryD = FindEntryByKey_02072a68(table3, 0xd);
    func_02046380((void*)g);
#if defined(jpn)
    SetIndexedName02046574((struct Obj02046574*)g, 0, (char*)node+0x2e);
    func_0204500c((void*)g, entryD, 0);
#else
    func_02042764((char*)node + 0x2e, buf, 1);
    SetIndexedName02046574((struct Obj02046574*)g, 0, buf);
    func_0204500c((void*)g, entryD, 0, 0xe3);
#endif
    *(int*)((char*)g + regionFlag) = 1;

    func_ov023_021f65d4(a, 0x1e, 8);
    func_ov023_021f65d4(a, 0x1f, 8);
    func_ov023_021f65d4(a, 2, 8);
    SetFieldConditional_021849e0((struct Fields021849e0*)a, 0x66);
    func_ov011_021848a0(a, 0x68);
    return 0;
}
