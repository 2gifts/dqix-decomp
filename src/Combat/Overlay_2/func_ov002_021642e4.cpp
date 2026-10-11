#include "Memory/SafeAllocator.h"
#include <globaldefs.h>

struct Struct0205de24;
struct Struct_0205c570;

extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(struct Struct_0205c570 *s);
extern "C" int _Z29CheckFlagOrThreshold_02161b48Pci(char *self, int flag);
extern "C" void *_Z27GetDataPtr02114e04_020d6c00v(void);
void OrBitsIntoField0(unsigned int *p, unsigned int mask);
extern "C" int GetInventoryItemByID(char *self, int idx, int member);
extern "C" void func_ov002_02161cf0(char *self);
extern "C" void func_ov002_0215d864(char *self);
extern "C" void func_ov002_02161b98(char *self);
extern "C" void func_ov002_02156e90(char *self);
extern "C" void func_ov023_021dc9e8(char *obj, SafeAllocator *alloc, int item, char *list, int n);
extern "C" void func_ov023_021dc134(char *obj, int item, int flag);
extern "C" void func_ov023_021dbfd0(char *obj, SafeAllocator *alloc);
extern "C" void func_ov023_021dcae0(char *obj, int item);
extern "C" void func_ov023_021dca88(char *obj);

// USA: func_ov002_021642e4
extern "C" ARM void func_ov002_021642e4(char *self) {
    int phase = *(int *) (self + 0x1bc0);
    if (phase == 0) {
        *(short *) (self + 0x1be8) = 0;
        _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((struct Struct0205de24 *) (self + 0xec8), 0, 2);
        func_ov002_02161cf0(self);
        func_ov002_0215d864(self);
        OrBitsIntoField0((unsigned int *) _Z27GetDataPtr02114e04_020d6c00v(), 1);
        if (*(int *) (self + 0x247c) & 1) {
            ((SafeAllocator *) (self + 0x864))->Reset();
            func_ov023_021dc9e8(self + 0x50, (SafeAllocator *) (self + 0x864),
                                GetInventoryItemByID(self, *(short *) (self + 0x1be8), *(signed char *) (self + 0x1c20)),
                                self + 0x7ec, 0x50);
        } else {
            ((SafeAllocator *) (self + 0x864))->Reset();
            func_ov023_021dc134(self + 0x50,
                                GetInventoryItemByID(self, *(short *) (self + 0x1be8), *(signed char *) (self + 0x1c20)), 0);
            struct F {
                char pad[0x774];
                unsigned short flags;
            };
            ((F *) (self + 0x50))->flags |= 0x50;
            func_ov023_021dbfd0(self + 0x50, (SafeAllocator *) (self + 0x864));
            *(char **) (self + 0x98) = self + 0x7ec;
            *(int *) (self + 0x247c) |= 1;
        }
        (*(int *) (self + 0x1bc0))++;
    } else if (phase == 1) {
        *(int *) (self + 0x247c) |= 4;
        func_ov002_02161b98(self);
        *(short *) (self + 0x1be8) =
            _Z26GetActiveScaledSum0205d794P15Struct_0205c570((struct Struct_0205c570 *) (self + 0xec8));
        *(short *) (self + 0x1c22) = GetInventoryItemByID(self, *(short *) (self + 0x1be8), *(signed char *) (self + 0x1c20));
        func_ov023_021dcae0(self + 0x50, *(short *) (self + 0x1c22));
        if (_Z29CheckFlagOrThreshold_02161b48Pci(self, 1)) {
            *(short *) (self + 0x1c22) = -1;
            *(short *) (self + 0x1be8) = -1;
            func_ov002_02156e90(self);
            func_ov023_021dca88(self + 0x50);
        }
    }
}
