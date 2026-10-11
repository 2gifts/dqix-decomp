#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValue324_20C = 0x20c };
enum { kRegionValue334_21C = 0x21c };
enum { kRegionValue328_210 = 0x210 };
enum { kRegionValue38C_274 = 0x274 };
enum { kRegionValue460_288 = 0x288 };
enum { kRegionValue394_27C = 0x27c };
enum { kRegionValue470_298 = 0x298 };
enum { kRegionValue464_28C = 0x28c };
enum { kRegionValue488_2B0 = 0x2b0 };
enum { kRegionValue474_29C = 0x29c };
#else
enum { kRegionValue324_20C = 0x324 };
enum { kRegionValue334_21C = 0x334 };
enum { kRegionValue328_210 = 0x328 };
enum { kRegionValue38C_274 = 0x38c };
enum { kRegionValue460_288 = 0x460 };
enum { kRegionValue394_27C = 0x394 };
enum { kRegionValue470_298 = 0x470 };
enum { kRegionValue464_28C = 0x464 };
enum { kRegionValue488_2B0 = 0x488 };
enum { kRegionValue474_29C = 0x474 };
#endif


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
    char pad0[kRegionValue324_20C];
    Obj2081* p324;
    char pad328[kRegionValue334_21C - kRegionValue328_210];
    char x334[kRegionValue38C_274 - kRegionValue334_21C];
    Container0205a3d0* p38c;
    Outer020e28dc* p390;
    char pad394[kRegionValue460_288 - kRegionValue394_27C];
    int field_460;
    char pad464[kRegionValue470_298 - kRegionValue464_28C];
    short* p470;
    char pad474[kRegionValue488_2B0 - kRegionValue474_29C];
    short h488;
};

// USA: func_ov003_0216039c
// JPN: func_ov003_02160554
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
