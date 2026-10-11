#include <globaldefs.h>

#if defined(jpn)
#define func_ov012_02185bf0 func_ov012_02186248
#endif
#include "std_library_functions.h"

struct Struct_0205d81c;
struct Elem_0205d81c;
extern struct Elem_0205d81c* FindElementByC40205d81c(struct Struct_0205d81c* s, int key);

struct StructA0205d5d0;
extern int TryApplyElemFields0205d5d0(struct StructA0205d5d0* a, int b, int c, int d, unsigned char e);

struct Entry02185bf0 { unsigned int fn; unsigned int locator; };
extern struct Entry02185bf0 data_020e6d5c;

struct Table02185bf0 { struct Entry02185bf0 e[16]; };
extern struct Table02185bf0 data_ov012_0218b088;

struct Local02185bf0 {
    unsigned int pairA;
    unsigned int pairB;
    struct Table02185bf0 table;
};

// USA: func_ov012_02185bf0  (semantic: DispatchElemHandlerAndApply_02185bf0)
extern "C" ARM void func_ov012_02185bf0(char* obj, int id, int flag) {
    struct Elem_0205d81c* e = FindElementByC40205d81c((struct Struct_0205d81c*)(obj + 0xac), id);
    if (e == 0) return;

    unsigned char* c5p = (unsigned char*)e + 0xc5;
    *c5p = flag ? (*c5p | 0x40) : (*c5p & ~0x40);
    unsigned char c5b = *(volatile unsigned char*)c5p;

    int useAlt = 0;
    if (c5b & 2) useAlt = 1;
    void* dest = *(void**)(obj + 0x1000 + 0x374);
    memset(dest, 0, 0x960);

    struct Local02185bf0 L;
    L.table = data_ov012_0218b088;

    unsigned int tmpA = data_020e6d5c.fn;
    unsigned int tmpB = data_020e6d5c.locator;
    *(volatile unsigned int*)&L.table.e[0].locator = tmpB;
    *(volatile unsigned int*)&L.table.e[0].fn = tmpA;
    *(volatile unsigned int*)&L.table.e[15].fn = tmpA;
    *(volatile unsigned int*)&L.table.e[15].locator = tmpB;

    unsigned int dispatchFn = L.table.e[id].fn;

    *(volatile unsigned int*)&L.pairA = tmpA;
    *(volatile unsigned int*)&L.pairB = tmpB;

    if (dispatchFn != 0) {
        struct Entry02185bf0* entry = &L.table.e[id];
        void* base = obj + ((int)entry->locator >> 1);
        void* callback;
        if (entry->locator & 1) {
            callback = *(void**)((char*)*(void**)base + entry->fn);
        } else {
            callback = (void*)entry->fn;
        }
        ((void(*)(void*, void*, int))callback)(base, *(void**)(obj + 0x1000 + 0x374), useAlt);
    }

    TryApplyElemFields0205d5d0((struct StructA0205d5d0*)(obj + 0xac), id, *(int*)(obj + 0x1000 + 0x374), 0, 0);
}
