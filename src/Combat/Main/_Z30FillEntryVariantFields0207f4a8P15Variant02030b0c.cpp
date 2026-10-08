#include <globaldefs.h>

struct Variant02030b0c;

extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);
void* GetElementStride0x30(unsigned char* obj, short index);

struct Data02108ee0 { void* field0; void* field4; };
extern struct Data02108ee0 data_02108ee0;

struct EntryArray0207f594 {
    void* entries;
    short count;
};

struct Entry0207f4a8 {
    char pad[0x18];
    short f18;
    char gap18[2];
    short f1c;
    char gap1c[2];
    short f20;
    char gap20[2];
    short f24;
};

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_0207f4a8
extern "C" ARM int _Z30FillEntryVariantFields0207f4a8P15Variant02030b0c(struct Variant02030b0c* p) {
    struct EntryArray0207f594* list = (struct EntryArray0207f594*)data_02108ee0.field4;
    struct Entry0207f4a8* e = (struct Entry0207f4a8*)GetElementStride0x30((unsigned char*)list, (short)(list->count - 1));
    if (e != NULL) {
        e->f18 = _ZNK6Script9Parameter5ToIntEv(p);
        e->f1c = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)((char*)p + 8));
        e->f20 = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)((char*)p + 0x10));
        e->f24 = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)((char*)p + 0x18));
    }
    return 1;
}