#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct List0204af64 {
    char pad0[0xc];
    unsigned char b0c;
    unsigned char pad0d;
    unsigned short h0e;
    int w10;
    int w14;
    int w18;
    unsigned char b1c_lo : 4;
    unsigned char b1c_hi : 4;
    unsigned char b1d;
    unsigned char b1e;
    unsigned char b1f;
};
void ResetList0204af64(struct List0204af64* obj);
void SetWord0x18ClearByte0x1f(unsigned char* obj, int value);

extern "C" void func_0204b5b4(void*, int);

struct Obj0204b5e8 { char pad[0x1c]; unsigned char lo : 4; unsigned char hi : 4; };
int DispatchViaTable0204b5e8(struct Obj0204b5e8* obj, int a, int b);

extern "C" void func_0204c684(void*);

struct Obj0204fbf8 {
    char pad0[0x4];
    struct List0204af64* field4;
    void* field8;
    char pad1[0xa0 - 0xc];
    int fieldA0;
    int fieldA4;
    short fieldA8;
    short fieldAA;
    char pad2[0xb4 - 0xac];
    short fieldB4;
    short fieldB6;
    char pad3[0xc4 - 0xb8];
    unsigned char fieldC4;
    unsigned char fieldC5;
    char pad4[0xe0 - 0xc6];
};
void InvokeHandlerAfterCacheFlush0204fbf8(struct Obj0204fbf8* obj);

extern int data_0211e33c;

extern "C" int func_ov017_021d60f4(void*);

struct Entry_02153884 { int key; int val; };
struct Table_02153884 { struct Entry_02153884* pairs; int count; };
void* FindTableEntry_02153884(struct Table_02153884* t, int key);
extern struct Table_02153884 data_ov001_021658d8;

void SetField0xa0AndByte0xc4IfFlag0x1Clear(unsigned char* obj, int value, unsigned char b);

#if defined(jpn)
extern "C" void func_02050678(void* obj, short b, int c, void* field18, int nibble, int initial4, short* fieldAaddr, short* fieldCaddr);
#else
extern "C" void func_0204f41c(void* obj, short b, int c, void* field18, int nibble, int initial4, short* fieldAaddr, short* fieldCaddr, int zero);
#endif


// USA: func_ov001_0215e7c0  (semantic: RegisterTableEntryAndInvokeHandler_0215e7c0)
extern "C" ARM int func_ov001_0215e7c0(void* combatant) {
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();

    struct List0204af64 list;
    ResetList0204af64(&list);
    list.b1c_lo = 1;
    list.b1c_hi = 0;
    SetWord0x18ClearByte0x1f((unsigned char*)&list, 0);
    func_0204b5b4(&list, 0);
    DispatchViaTable0204b5e8((struct Obj0204b5e8*)&list, 0, 0);

    struct Obj0204fbf8 obj;
    func_0204c684(&obj);
    obj.field4 = &list;
    obj.field8 = &data_0211e33c;
    obj.fieldA8 = 0x20;
    obj.fieldAA = 0x18;
    obj.fieldA4 = 0x6000;
    obj.fieldB4 = 0xc;
    obj.fieldB6 = 0x10;
    unsigned char c5 = obj.fieldC5;
    obj.fieldA0 = 0x60;
    obj.fieldC5 = c5 | 0x10;

    int key = func_ov017_021d60f4(combatant);
    struct Entry_02153884* entry = (struct Entry_02153884*)FindTableEntry_02153884(&data_ov001_021658d8, key);
    if (entry == 0) {
        BackgroundLoader::RemoveLockGlobal();
        return 0;
    }

    SetField0xa0AndByte0xc4IfFlag0x1Clear((unsigned char*)&obj, 0x60, 0);

    short fieldA;
    short fieldC;
#if defined(jpn)
    func_02050678(&obj, 0, 0, (void*)entry->val, 0xc, 0xf, &fieldA, &fieldC);
#else
    func_0204f41c(&obj, 0, 0, (void*)entry->val, 0xc, 0xf, &fieldA, &fieldC, 0);
#endif

    InvokeHandlerAfterCacheFlush0204fbf8(&obj);
    BackgroundLoader::RemoveLockGlobal();
    return 1;
}
