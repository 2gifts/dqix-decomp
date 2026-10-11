#include <globaldefs.h>

struct Struct_0205d81c;
struct Elem_0205d81c {
    unsigned char pad0[0xac];
    short x_;
    short y_;
    unsigned char padb0[0xbc - 0xb0];
    short offsetX_;
    short offsetY_;
    unsigned char padc0[0xc4 - 0xc0];
    unsigned char type_;
};
Elem_0205d81c* FindElementForFieldB0(Struct_0205d81c*);
int CheckField0x9cSetWhenField0xd4Present(unsigned char*);

struct Elem0205a3d0 {
    char pad0[4];
    short x_;
    short y_;
    unsigned short key_;
    char padA[0x15 - 0xa];
    unsigned char flags_;
    char pad16[0x18 - 0x16];
};

struct Container0205a3d0;
extern "C" void _Z26SetEntryFlag2ByKey0205a370P17Container0205a3d0i(Container0205a3d0*, int);
extern "C" Elem0205a3d0* _Z27FindEntryByHalfword0205a3d0P17Container0205a3d0i(Container0205a3d0*, int);
extern "C" void _Z27SetEntryByte14ByKey0205a42cP17Container0205a3d0ii(Container0205a3d0*, int, int);

struct Container0205a330;
extern "C" void _Z22IterateEntries0205a330P17Container0205a330i(Container0205a330*, int);

extern "C" void func_0205ae8c(void*);

// USA: func_ov000_02175544
extern "C" ARM void func_ov000_02175544(unsigned char* obj) {
#if defined(jpn)
    enum { flagOffset = 0x1faa, byte14 = 0x4c };
#else
    enum { flagOffset = 0x1d72, byte14 = 0x50 };
#endif
    if (!(*(unsigned short*)(obj + flagOffset) & 0x100)) return;

    Elem_0205d81c* elem = FindElementForFieldB0((Struct_0205d81c*)(obj + 0x188));
    if (elem == NULL) return;
    if (elem->type_ >= 0x1a) return;
    if (!CheckField0x9cSetWhenField0xd4Present((unsigned char*)elem)) return;

    short x = elem->x_ * 8;
    short y = elem->y_ * 8;
    x += elem->offsetX_;
    y += elem->offsetY_;

    Container0205a3d0* container = *(Container0205a3d0**)(obj + 0x174);
    _Z26SetEntryFlag2ByKey0205a370P17Container0205a3d0i(container, 0);
    Elem0205a3d0* entry = _Z27FindEntryByHalfword0205a3d0P17Container0205a3d0i(container, 0);
    if (entry != NULL) entry->flags_ |= 8;

    _Z22IterateEntries0205a330P17Container0205a330i((Container0205a330*)container, *(int*)(obj + 0x94c));

    entry = _Z27FindEntryByHalfword0205a3d0P17Container0205a3d0i(container, 0);
    if (entry != NULL) {
        entry->x_ = x - 8;
        entry->y_ = y - 2;
    }

    _Z27SetEntryByte14ByKey0205a42cP17Container0205a3d0ii(container, 0, byte14);
    func_0205ae8c(obj + 0x11c);
}
