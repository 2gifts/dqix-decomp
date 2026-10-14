#include <globaldefs.h>
#include "Memory/AllocatorUnion.h"
#include "std_library_functions.h"

struct Struct02030b7c;
struct Variant02030b0c;
extern "C" void* _ZNK6Script9Parameter8ToStringEv(struct Struct02030b7c* s);
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);
int StringLength(const char* s);
void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);

struct Entry0218b9d4 {
    int a;
    int b;
    unsigned short c;
    unsigned char d;
    unsigned char e;
};
struct List0218b9d4 {
    Entry0218b9d4* arr;
    int pad4;
    int count;
};
void AppendEntry0218b9d4(struct List0218b9d4* list, struct Entry0218b9d4* src);

extern AllocatorUnion data_02114e20;
extern struct List0218b9d4* data_ov015_02194560;

// USA: func_ov015_0218b5c8  (semantic: BuildAndAppendNameEntry_0218b5c8)
extern "C" ARM int func_ov015_0218b5c8(char* obj) {
    char* n1 = (char*)_ZNK6Script9Parameter8ToStringEv((struct Struct02030b7c*)obj);
    char* n2 = (char*)_ZNK6Script9Parameter8ToStringEv((struct Struct02030b7c*)(obj + 8));
    int v1 = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)(obj + 0x10));
    int v2 = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)(obj + 0x18));
    int v3 = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)(obj + 0x20));

    struct Entry0218b9d4 entry;
    entry.a = 0;
    entry.b = 0;
    entry.c = 0;
    entry.d = 0;
    entry.e = 0;

    if (n1 != 0) {
        int len = StringLength(n1);
        char* buf = (char*)AllocateAligned4(&data_02114e20, len + 1);
        entry.a = (int)buf;
        if (buf != 0) {
            strcpy(buf, n1);
        }
    }
    if (n2 != 0) {
        int len = StringLength(n2);
        char* buf = (char*)AllocateAligned4(&data_02114e20, len + 1);
        entry.b = (int)buf;
        if (buf != 0) {
            strcpy(buf, n2);
        }
    }

    entry.c = (unsigned short)v1;
    entry.d = (unsigned char)v2;
    entry.e = (unsigned char)v3;
    AppendEntry0218b9d4(data_ov015_02194560, &entry);
    return 1;
}
