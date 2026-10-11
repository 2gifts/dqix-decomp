#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include <globaldefs.h>

struct Struct0205de24;
struct Struct_0205c570;
struct Obj_0205da38;
struct Obj0205eaa0;
struct Struct_0205d81c;
struct Obj0205dee8;
extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(struct Struct_0205c570 *s);
int TestFlag0SetAndFlag1Clear(unsigned short *p, int n);
extern "C" int _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(struct Obj_0205da38 *o);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0 *o, int a, int b);
extern "C" int _Z29CheckFlagOrThreshold_02161b48Pci(char *base, int a);
void SetElementFieldC2(struct Struct_0205d81c *s, int a, int b);
extern "C" void _Z27SetFieldB0AndUpdate0205dee8P11Obj0205dee8i(struct Obj0205dee8 *o, int v);
extern "C" void *_Z27GetDataPtr02114e04_020d6c00v();
void OrBitsIntoField0(unsigned int *p, unsigned int mask);
unsigned char *GetFieldAt0x150(unsigned char *p);
extern "C" int GetInventoryItemByID(char *self, int idx, int member);
extern "C" void func_ov002_02161cf0(void *base);
extern "C" void func_ov002_02161b98(char *self);
extern "C" void func_ov002_0215b9a4(char *self, unsigned char key, int flag);
extern "C" void func_ov002_0215b458(char *self, int a);
extern "C" int func_0205df38(void *list, int key);
extern "C" void func_ov023_021dc9e8(char *obj, SafeAllocator *alloc, int item, char *list, int n);
extern "C" void func_ov023_021dc134(char *obj, int item, int flag);
extern "C" void func_ov023_021dbfd0(char *obj, SafeAllocator *alloc);
extern "C" void func_ov023_021dcae0(char *obj, int item);
extern "C" void func_ov023_021dca88(char *obj);
extern "C" unsigned short data_02114e30[];
extern "C" char data_02108760[];

static inline int InRange02162e50(int v) {
    return (v >= 0 && v <= 3) ? 1 : 0;
}

// USA: func_ov002_02162e50
extern "C" ARM void func_ov002_02162e50(char *base) {
    int state = *(int *) (base + 0x1000 + 0xbc0);
    if (state == 0) {
        *(short *) (base + 0x1b00 + 0xfa) = -1;
        _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((struct Struct0205de24 *) (base + 0x2c8 + 0xc00), 0, 2);
        func_ov002_02161cf0(base);
        func_ov002_0215b9a4(base, 5, 0);
        *(int *) (base + 0x1000 + 0xbc0) += 1;
        SetElementFieldC2((struct Struct_0205d81c *) (base + 0x2c8 + 0xc00), 4, 1);
        SetElementFieldC2((struct Struct_0205d81c *) (base + 0x2c8 + 0xc00), 5, 0);
        _Z27SetFieldB0AndUpdate0205dee8P11Obj0205dee8i((struct Obj0205dee8 *) (base + 0x2c8 + 0xc00), 5);
        int item = GetInventoryItemByID(base, *(short *) (base + 0x1b00 + 0xe8), *(signed char *) (base + 0x1c00 + 0x20));
        OrBitsIntoField0((unsigned int *) _Z27GetDataPtr02114e04_020d6c00v(), 1);
        if (*(unsigned int *) (base + 0x2000 + 0x47c) & 1) {
            ((SafeAllocator *) (base + 0x64 + 0x800))->Reset();
            func_ov023_021dc9e8(base + 0x50, (SafeAllocator *) (base + 0x64 + 0x800), item, base + 0x3ec + 0x400, 0x50);
        } else {
            ((SafeAllocator *) (base + 0x64 + 0x800))->Reset();
            func_ov023_021dc134(base + 0x50, item, 0);
            struct F {
                char pad[0x774];
                unsigned short flags;
            };
            ((F *) (base + 0x50))->flags |= 0x50;
            func_ov023_021dbfd0(base + 0x50, (SafeAllocator *) (base + 0x64 + 0x800));
            *(char **) (base + 0x98) = base + 0x3ec + 0x400;
            *(unsigned int *) (base + 0x2000 + 0x47c) |= 1;
        }
    } else if (state == 1) {
        *(unsigned int *) (base + 0x2000 + 0x47c) |= 4;
        func_ov002_02161b98(base);
        int prev = *(short *) (base + 0x1b00 + 0xe8);
        *(short *) (base + 0x1b00 + 0xe8) =
            _Z26GetActiveScaledSum0205d794P15Struct_0205c570((struct Struct_0205c570 *) (base + 0x2c8 + 0xc00));
        if (TestFlag0SetAndFlag1Clear(data_02114e30, 4) || func_0205df38(base + 0x2c8 + 0xc00, 0x28)) {
            if (*(short *) (base + 0x1b00 + 0xe6) == *(signed char *) (base + 0x1c00 + 0x73)) {
                func_ov002_0215b458(base, 1);
                *(short *) (base + 0x1c00 + 0x22) =
                    GetInventoryItemByID(base, *(short *) (base + 0x1b00 + 0xe8), *(signed char *) (base + 0x1c00 + 0x20));
                func_ov023_021dcae0(base + 0x50, *(short *) (base + 0x1c00 + 0x22));
                return;
            }
        }
        *(short *) (base + 0x1c00 + 0x22) =
            GetInventoryItemByID(base, *(short *) (base + 0x1b00 + 0xe8), *(signed char *) (base + 0x1c00 + 0x20));
        func_ov023_021dcae0(base + 0x50, *(short *) (base + 0x1c00 + 0x22));
        if (prev != *(short *) (base + 0x1b00 + 0xe8)) return;
        int a = TestFlag0SetAndFlag1Clear(data_02114e30, 0x601);
        int b = ((int (*)(void *, int)) _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38)(base + 0x2c8 + 0xc00, 0x14);
        if ((a | b) ? 1 : 0) {
            *(unsigned char *) (base + 0xf80) = *(int *) (base + 0x1000 + 0xbb8);
            *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0 *) data_02108760, 1, 0);
            if (*(unsigned char *) (base + 0x2000 + 0x485))
                *(int *) (base + 0x1000 + 0xbb8) = 0x27;
            else
                *(int *) (base + 0x1000 + 0xbb8) = 6;
            int ok                           = 0;
            *(int *) (base + 0x1000 + 0xbc0) = ok;
            int actor                        = *(signed char *) (base + 0x1c00 + 0x20);
            if (actor >= 0 && actor <= 3) ok = 1;
            if (ok) return;
            GameObject *p = GameState::GetInstance()->GetProtagonist();
            if (p == NULL) return;
            *(short *) (GetFieldAt0x150((unsigned char *) p) + 0x900 + 0x58) = *(short *) (base + 0x1c00 + 0x22);
        } else if (_Z29CheckFlagOrThreshold_02161b48Pci(base, 1)) {
            *(short *) (base + 0x1c00 + 0x22) = -1;
            *(short *) (base + 0x1b00 + 0xe8) = -1;
            *(int *) (base + 0x1000 + 0xbb8)  = 4;
            *(int *) (base + 0x1000 + 0xbc0)  = 1;
            _Z27SetFieldB0AndUpdate0205dee8P11Obj0205dee8i((struct Obj0205dee8 *) (base + 0x2c8 + 0xc00), 4);
            SetElementFieldC2((struct Struct_0205d81c *) (base + 0x2c8 + 0xc00), 4, 0);
            func_ov002_02161cf0(base);
            func_ov023_021dca88(base + 0x50);
        }
    }
}
