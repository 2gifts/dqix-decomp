#include <globaldefs.h>

struct Outer020e28dc;
int GetInnerFlagBit0020e28dc(struct Outer020e28dc *o);

struct Struct_0205d81c;
struct Elem_0205d81c {
    unsigned char pad0[0xac];
    short fac;
    short fae;
    unsigned char padb0[0xc];
    short fbc;
    short fbe;
};
struct Elem_0205d81c *FindElementForFieldB0_0205d8c4(struct Struct_0205d81c *s);
int CheckField0x9cSetWhenField0xd4Present_0204c7e0(unsigned char *p);

struct Container0205a3d0;
struct Elem0205a3d0 {
    unsigned char pad0[0x15];
    unsigned char flags;
};
struct Elem0205a3d0 *FindEntryByHalfword0205a3d0(struct Container0205a3d0 *c, int key);
void SetEntryFlag2ByKey0205a370(struct Container0205a3d0 *c, int key);
void SetEntryPosition_020e27ec(struct Container0205a3d0 *c, int key, short a, short b);

struct Container0205a330;
void IterateEntries0205a330(struct Container0205a330 *c, int arg);

extern "C" void func_0205ae8c(void *obj);

// USA: func_ov002_0215afb8  (semantic: UpdateCursorEntry_0215afb8)
extern "C" ARM void func_ov002_0215afb8(char *obj) {
    struct Elem0205a3d0 *e;

    if (!(*(int *) (obj + 0x2000 + 0x47c) & 4)) return;

    struct Elem_0205d81c *elem = FindElementForFieldB0_0205d8c4((struct Struct_0205d81c *) (obj + 0x2c8 + 0xc00));
    if (elem == NULL) return;
    if (!CheckField0x9cSetWhenField0xd4Present_0204c7e0((unsigned char *) elem)) return;
    struct Outer020e28dc *choice = *(struct Outer020e28dc **) (obj + 4);
    if (choice == NULL) return;
    if (GetInnerFlagBit0020e28dc(choice)) return;

    short x = (short) (elem->fac * 8);
    short y = (short) (elem->fae * 8);
    x += elem->fbc;
    y += elem->fbe;
    struct Container0205a3d0 *cont = *(struct Container0205a3d0 **) (obj + 0x1000 + 0xa6c);
    SetEntryFlag2ByKey0205a370(cont, 0);
    e = FindEntryByHalfword0205a3d0(cont, 0);
    if (e != NULL) {
        e->flags |= 8;
    }
    IterateEntries0205a330((struct Container0205a330 *) cont, *(int *) (obj + 0x1000 + 0xba0));
    SetEntryPosition_020e27ec(cont, 0, x - 8, y - 2);
    func_0205ae8c(*(void **) (obj + 0x1000 + 0xa68));
}
