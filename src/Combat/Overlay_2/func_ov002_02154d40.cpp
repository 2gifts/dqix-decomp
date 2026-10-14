#include "Memory/SafeAllocator.h"
#include <globaldefs.h>

struct EntryManager020e2490;
struct PairAndByte020e1368;
struct Setter020e1374;

void InitEntryManager020e2490(EntryManager020e2490 *mgr, int a,
                                                                                          int b, void *p, SafeAllocator *alloc,
                                                                                          int c, unsigned char d);
void SetPairAndByte020e1368(PairAndByte020e1368 *p, unsigned int a, unsigned int b,
                                                                    unsigned char c);
void SetFields020e1374(Setter020e1374 *p, unsigned int a, unsigned int b, int c);

// USA: func_ov002_02154d40
extern "C" ARM void func_ov002_02154d40(char *self, SafeAllocator *alloc) {
    if (alloc == NULL) return;
    ((SafeAllocator *) (self + 0x810))->CreateTypeA(alloc->Allocate(0x3c00), 0x3c00);
    ((SafeAllocator *) (self + 0x83c))->CreateTypeA(alloc->Allocate(0x5400), 0x5400);
    ((SafeAllocator *) (self + 0x828))->CreateTypeA(alloc->Allocate(0xd400), 0xd400);
    ((SafeAllocator *) (self + 0x850))->CreateTypeA(alloc->Allocate(0x4c00), 0x4c00);
    ((SafeAllocator *) (self + 0x864))->CreateTypeA(alloc->Allocate(0x9400), 0x9400);
    ((SafeAllocator *) (self + 0x878))->CreateTypeA(alloc->Allocate(0x800), 0x800);
    ((SafeAllocator *) (self + 0x88c))->CreateTypeA(alloc->Allocate(0x580), 0x580);
    ((SafeAllocator *) (self + 0x8a0))->CreateTypeA(alloc->Allocate(0x533), 0x533);
    *(void **) (self + 0x1a64) = alloc->Allocate(0x6b8);
    *(void **) (self + 0x1a68) = alloc->Allocate(0x54);
    *(void **) (self + 0x1a6c) = alloc->Allocate(8);
    *(void **) (self + 0x1bd4) = alloc->Allocate(0x960);
    *(void **) (self + 0)      = alloc->Allocate(0x24);
    *(void **) (self + 4)      = alloc->Allocate(0x24);
    InitEntryManager020e2490(*(EntryManager020e2490 **) (self + 0), 0, 0, 0,
                                                                              alloc, 0xc, 0x40);
    InitEntryManager020e2490(*(EntryManager020e2490 **) (self + 4), 0, 1,
                                                                              *(void **) (self + 0x1a6c), alloc, 4, 0x60);
    char *e = *(char **) (*(char **) (self + 0) + 0xc);
    SetPairAndByte020e1368((PairAndByte020e1368 *) (e + 0xc), 0, 0x3000, 5);
    SetFields020e1374((Setter020e1374 *) (e + 0xc), 0x3800, 0x3000, 4);
}
