#include <globaldefs.h>

struct Obj2081;
struct Outer020e28dc;
struct Container0205a3d0;
struct Container0205a330;
struct Elem0205a3d0 {
    char pad0[0x15];
    unsigned char flags;
};

unsigned char* FindElementByByte0xc4(Obj2081* obj, int key);
extern "C" int _Z24GetInnerFlagBit0020e28dcP13Outer020e28dc(Outer020e28dc* o);
extern "C" void _Z27SetEntryByte14ByKey0205a42cP17Container0205a3d0ii(Container0205a3d0* c, int key, int val);
extern "C" void func_0205ae8c(void* obj);
int CheckField0x9cSetWhenField0xd4Present(unsigned char* obj);
extern "C" void _Z29GetLookAndTurnOffsets020809c4PviiPsS0_(void* obj, int id, int id2, short* out1, short* out2);
extern "C" void _Z26SetEntryFlag2ByKey0205a370P17Container0205a3d0i(Container0205a3d0* c, int key);
extern "C" Elem0205a3d0* _Z27FindEntryByHalfword0205a3d0P17Container0205a3d0i(Container0205a3d0* c, int key);
extern "C" void _Z22IterateEntries0205a330P17Container0205a330i(Container0205a330* c, int arg);
void SetEntryPosition(Container0205a3d0* c, int key, short a, short b);

struct Scene0216039c {
    char pad0[0x324];
    Obj2081* p324;
    char pad328[0x334 - 0x328];
    char x334[0x38c - 0x334];
    Container0205a3d0* p38c;
    Outer020e28dc* p390;
    char pad394[0x460 - 0x394];
    int field_460;
    char pad464[0x470 - 0x464];
    short* p470;
    char pad474[0x488 - 0x474];
    short h488;
};

// USA: func_ov003_0216039c
extern "C" ARM void func_ov003_0216039c(Scene0216039c* self) {
    if (self->p470 == NULL || self->h488 < 0 || self->p324 == NULL) {
        return;
    }
    unsigned char* elem = FindElementByByte0xc4(self->p324, self->h488);
    if (elem == NULL) {
        return;
    }
    if (self->p390 != NULL && _Z24GetInnerFlagBit0020e28dcP13Outer020e28dc(self->p390) != 0) {
        _Z27SetEntryByte14ByKey0205a42cP17Container0205a3d0ii(self->p38c, 0, 0);
        func_0205ae8c(self->x334);
        return;
    }
    if (CheckField0x9cSetWhenField0xd4Present(elem) == 0) {
        return;
    }
    short x;
    short y;
    _Z29GetLookAndTurnOffsets020809c4PviiPsS0_(self->p324, self->h488, *self->p470, &x, &y);
    x -= 0x10;
    y -= 3;
    _Z26SetEntryFlag2ByKey0205a370P17Container0205a3d0i(self->p38c, 0);
    Elem0205a3d0* e = _Z27FindEntryByHalfword0205a3d0P17Container0205a3d0i(self->p38c, 0);
    if (e != NULL) {
        e->flags |= 8;
    }
    e = _Z27FindEntryByHalfword0205a3d0P17Container0205a3d0i(self->p38c, 1);
    if (e != NULL) {
        e->flags &= ~8;
    }
    _Z22IterateEntries0205a330P17Container0205a330i((Container0205a330*)self->p38c, self->field_460);
    SetEntryPosition(self->p38c, 0, x, y);
    func_0205ae8c(self->x334);
}
