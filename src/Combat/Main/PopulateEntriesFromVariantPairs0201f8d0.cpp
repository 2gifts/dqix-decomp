#include <globaldefs.h>

#if defined(jpn)
#define func_0201f8d0 func_0201f65c
#define AllocateNameBuffer02026b0c func_02026470
#define SetEntry02026b3c func_020264a0
enum { ObjectSlotOffset = 0xc };
#else
enum { ObjectSlotOffset = 0x10 };
#endif

struct Variant02030b0c { int tag; int u; };
struct Struct02030b7c { int field0; void* field4; };
struct Entry0201f8d0 { struct Variant02030b0c key; struct Struct02030b7c value; };
struct Obj02026b0c;
struct Obj02026b3c;
#if defined(jpn)
extern "C" void func_02026470(struct Obj02026b0c* p, int n);
extern "C" void func_020264a0(struct Obj02026b3c* obj, unsigned int index, short id, const char* name);
#endif

extern int data_020fdc4c;
void ClearRecords02026644(char* obj);
void AllocateNameBuffer02026b0c(struct Obj02026b0c* p, int n);
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);
extern "C" void* _ZNK6Script9Parameter8ToStringEv(struct Struct02030b7c* s);
void SetEntry02026b3c(struct Obj02026b3c* obj, unsigned int index, short id, const char* name);
typedef void (*SetEntry02026b3c_U)(struct Obj02026b3c*, unsigned int, unsigned short, const char*);

// USA: func_0201f8d0  (semantic: PopulateEntriesFromVariantPairs0201f8d0)
extern "C" ARM int func_0201f8d0(struct Entry0201f8d0* list, int n) {
    int count = n / 2;
    void* obj = *(void**)((char*)&data_020fdc4c + ObjectSlotOffset);
    ClearRecords02026644((char*)obj);
    obj = *(void**)((char*)&data_020fdc4c + ObjectSlotOffset);
    AllocateNameBuffer02026b0c((struct Obj02026b0c*)obj, count & 0xff);
    struct Entry0201f8d0* p = list;
    for (int i = 0; i < count; i++) {
        int id = _ZNK6Script9Parameter5ToIntEv(&p->key);
        struct Struct02030b7c* val = &p->value;
        p++;
        void* name = _ZNK6Script9Parameter8ToStringEv(val);
        obj = *(void**)((char*)&data_020fdc4c + ObjectSlotOffset);
        ((SetEntry02026b3c_U)SetEntry02026b3c)((struct Obj02026b3c*)obj, (unsigned char)i, id, (const char*)name);
    }
    return 1;
}
