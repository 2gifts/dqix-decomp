#include <globaldefs.h>

#if defined(jpn)
#define func_ov013_02186cac func_ov013_02187fc0
#endif

struct Struct_0205d81c;
struct Elem_0205d81c {
    unsigned char pad0[0xac];
    short fac;
    short fae;
    unsigned char padb0[0xc];
    short fbc;
    short fbe;
};
Elem_0205d81c* FindElementForFieldB0_0205d8c4(Struct_0205d81c*);
int CheckField0x9cSetWhenField0xd4Present_0204c7e0(unsigned char*);

struct Container0205a3d0;
void SetEntryFlag2ByKey0205a370(Container0205a3d0*, int);
unsigned char* FindEntryByHalfword0205a3d0(Container0205a3d0*, int);

struct Container0205a330;
void IterateEntries0205a330(Container0205a330*, int);

extern "C" void func_0205ae8c(void*);

struct ListHeader02186cac {
    char pad0[0x3c];
    void* container;
};

// USA: func_ov013_02186cac
extern "C" ARM void func_ov013_02186cac(void* obj) {
    unsigned char* o = (unsigned char*)obj;
    Elem_0205d81c* elem;
    short x, y;
    unsigned char mode;
    ListHeader02186cac* list;
    Container0205a3d0* container;
    unsigned char* entry;

    if (*(void**)(o + 0x18) == 0) return;
    if (!(o[0x6bc] & 1)) return;

    elem = FindElementForFieldB0_0205d8c4((Struct_0205d81c*)(o + 0x38));
    if (elem == 0) return;
    if (!CheckField0x9cSetWhenField0xd4Present_0204c7e0((unsigned char*)elem)) return;

    x = elem->fac * 8;
    y = elem->fae * 8;
    x += elem->fbc;
    y += elem->fbe;
    mode = o[0x63c];

    if (mode != 3 && mode != 4) {
        x = x - 8;
        y = y - 2;
    } else {
        x = x - 8;
    }

    list = *(ListHeader02186cac**)(o + 0x18);
    container = (Container0205a3d0*)list->container;
    if (container == 0) return;

    SetEntryFlag2ByKey0205a370(container, *(unsigned short*)(o + 0x1c));
    entry = FindEntryByHalfword0205a3d0(container, *(unsigned short*)(o + 0x1c));
    if (entry != 0) entry[0x15] |= 8;

    IterateEntries0205a330((Container0205a330*)container, *(int*)(o + 0x14));

    entry = FindEntryByHalfword0205a3d0(container, *(unsigned short*)(o + 0x1c));
    if (entry != 0) {
        *(short*)(entry + 4) = x;
        *(short*)(entry + 6) = y;
    }

    func_0205ae8c(*(void**)(o + 0x18));
}
