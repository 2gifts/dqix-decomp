#include <globaldefs.h>
#include "Resource/Script.h"
#include "Memory/SafeAllocator.h"

struct Elem0201f0f0 {
    signed short f0;
    unsigned char f2;
    unsigned char f3;
    char* f4;
    int f8;
};

struct List0201f0f0 {
    struct Elem0201f0f0* base;
    int count;
    int capacity;
};

struct Entry_1f170 {
    signed short id;
    char unk[0xa];
};

struct EntryList_1f170 {
    struct Entry_1f170* entries;
    int count;
};

extern "C" void _Z27AppendElementCapped0201f0f0P12List0201f0f0P12Elem0201f0f0(struct List0201f0f0*, struct Elem0201f0f0*);
extern "C" struct Entry_1f170* _Z19FindEntryBySignedIdP15EntryList_1f170i(struct EntryList_1f170*, int);

struct Container0201ec00 {
    struct Entry_1f170* f0;
    SafeAllocator* alloc;
    struct List0201f0f0* list;
    char pad[16];
};
extern struct Container0201ec00 data_020fdc40;

// USA: func_0201ec00
extern "C" ARM int func_0201ec00(Script::Parameter* params, int count) {
    struct Elem0201f0f0 e;
    e.f0 = params->ToInt();
    params++;
    const char* text = (params++)->ToString();
    if (text == NULL) {
        return 0;
    }
    e.f4 = (char*)data_020fdc40.alloc->Allocate(strlen(text) + 1);
    strcpy(e.f4, text);
    e.f2 = 0;
    if (count >= 3) {
        e.f2 = params->ToInt();
        e.f2 &= 0x3f;
        params++;
    }
    e.f3 = 0;
    if (count >= 4) {
        e.f3 = params->ToInt();
    }
    e.f8 = 0;
    _Z27AppendElementCapped0201f0f0P12List0201f0f0P12Elem0201f0f0(data_020fdc40.list, &e);
    data_020fdc40.f0 = _Z19FindEntryBySignedIdP15EntryList_1f170i((struct EntryList_1f170*)data_020fdc40.list, e.f0);
    return 1;
}
