#include <globaldefs.h>
#if defined(jpn)
enum{regionTable=0x10,regionNode=0x964,regionFlag=0x868};
#else
enum{regionTable=0x190,regionNode=0xb84,regionFlag=0x998};
#endif
#if defined(jpn)
#define func_ov023_021f6524 func_ov004_02168f08
#define func_ov004_02168b08 func_ov004_02169040
#define func_ov023_021f65d4 func_ov004_02168eac
#endif

#include "std_library_functions.h"

extern "C" void* func_ov023_021f6524(void* ctx, int value);
extern "C" int func_ov004_02168b08(void* a, int key);
int GetGlobalField0x1c020421a0(void);
extern "C" int func_ov023_021f9bc8(char* obj);
extern "C" void func_ov004_0216950c(void* obj);
extern "C" int func_ov017_0218b5b0(void);
extern "C" void func_ov004_0216920c(void* obj);
extern "C" void __clear(void* buf, int n);
void* FindEntryByKey(struct TableA68* table, int key);
extern "C" void func_02046380(void* global);
extern "C" void func_02042764(void* a, void* b, int flag);
void SetIndexedName02046574(struct Obj02046574* obj, int index, char* str);
#if defined(jpn)
extern "C" void func_02045d88(void*, void*, int);
#else
extern "C" void func_0204500c(void* field, void* buf, int p2, int p3);
#endif
extern "C" void func_ov023_021f65d4(void* obj, int id, int mask);
struct Fields021849e0;
void SetFieldConditional_021849e0(struct Fields021849e0* obj, unsigned short val);
extern "C" void func_ov011_021848a0(void* obj, int val);

struct TableA68 { struct EntryA68* entries; short count; };
extern void* data_ov004_02171030;

struct Entry0216a464 { unsigned short lowBits : 14; unsigned short used : 1; unsigned short highBit : 1; };

// USA: func_ov004_0216a464  (semantic: AddSaveDataEntryAndDispatch_0216a464)  (semantic: AddSaveDataEntryAndDispatch_0216a464)
extern "C" ARM int func_ov004_0216a464(void* a) {
    if (!*(void**)((char*)data_ov004_02171030 + regionTable)) return 0;

    void* node = func_ov023_021f6524(a, 0x64);
    int table3 = func_ov004_02168b08(a, 3);
    int g = GetGlobalField0x1c020421a0();
    func_ov023_021f9bc8((char*)node);
    func_ov004_0216950c(a);

    int base = func_ov017_0218b5b0();
    node = *(void**)(base + 0x3000 + regionNode);
    void* val190b = *(void**)((char*)data_ov004_02171030 + regionTable);

    unsigned char* entry = (unsigned char*)val190b + 4;
    int idx;
    for (idx = 0; idx < 0x10; entry += 0x2c, idx++) {
        struct Entry0216a464* e12 = (struct Entry0216a464*)(entry + 0x12);
        if (!e12->used) {
            memcpy(entry, (char*)node + 0x28, 0x2c);
            void* val190Fresh = *(void**)((char*)data_ov004_02171030 + regionTable);
            (*(unsigned char*)val190Fresh)++;
            break;
        }
    }

    func_ov004_0216920c(a);

#if !defined(jpn)
    char buf[0x30];
    __clear(buf, 0x30);
#endif

    void* entryD = FindEntryByKey((struct TableA68*)table3, 0xd);
    func_02046380((void*)g);
#if defined(jpn)
    SetIndexedName02046574((struct Obj02046574*)g, 0, (char*)node+0x2e);
    func_02045d88((void*)g, entryD, 0);
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
