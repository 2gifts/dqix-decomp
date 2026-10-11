#include <globaldefs.h>
#if defined(jpn)
enum { kListOffset = 0x14 };
#else
enum { kListOffset = 0x18 };
#endif


struct Entry_02028bd0;
struct Entry_02028bd0* GetEntryTableBase(void);

struct U16Field0x6_020375f8;
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(struct U16Field0x6_020375f8* obj);

struct Entry_02028bd0* FindInlineEntryById(struct Entry_02028bd0* base, int key);

extern "C" int func_02028638(void* a, void* b);

struct List_020283fc;
int FindListIndexById(struct List_020283fc* list, int id);

struct Obj02079040 {
    char pad0[0x44];
    char pad44[0xb8 - 0x44];
    unsigned short field0xb8;
};

// USA: func_02079040
ARM unsigned short FindAndCacheListIndex(struct Obj02079040* obj, unsigned char* outFlag) {
    struct Entry_02028bd0* base;
    struct Entry_02028bd0* entry;
    unsigned short key;
    int id;
    int idx;
    *outFlag = 0;
    base = GetEntryTableBase();
    key = _ZNK8Object3D10GetField06Ev((struct U16Field0x6_020375f8*)obj);
    entry = FindInlineEntryById(base, key);
    if (entry == NULL) {
        return 0;
    }
    id = func_02028638((char*)entry + kListOffset, (char*)obj + 0x44);
    idx = FindListIndexById((struct List_020283fc*)((char*)entry + kListOffset), id);
    if (idx != -1) {
        obj->field0xb8 = idx;
    }
    return (unsigned short)id;
}
