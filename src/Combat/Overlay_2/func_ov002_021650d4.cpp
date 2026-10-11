#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"
#include <globaldefs.h>

struct Struct0205de24;
struct Struct_0205def8;
struct PMFObj021e7bc4;
int GetWord0x0(int *p);
extern "C" void *_Z27GetDataPtr02114e04_020d6c00v();
void OrBitsIntoField0(unsigned int *p, unsigned int mask);
extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
extern "C" void _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii(struct Struct_0205def8 *s, int a, int b);
extern "C" void _Z30CreateThreeAllocators_021e71b4PvP13SafeAllocator(void *p, SafeAllocator *alloc);
void OrGlobalFlag0x40();
extern "C" void _Z29SetCombatModeFromCase020dc2d0i(int c);
extern "C" void _Z29DispatchEntryByIndex_021e7bc4P14PMFObj021e7bc4ji(struct PMFObj021e7bc4 *o, unsigned int idx, int v);
int GetField0x3acValue(GameState *gs);
extern "C" int _Z29CheckFlagOrThreshold_02161b48Pci(char *base, int a);
extern "C" void func_020dc7e8(int a, int b);
extern "C" void func_ov002_02161cf0(void *base);
extern "C" void func_ov002_0215e44c(void *base);
extern "C" void func_ov002_02156e90(void *base);
extern "C" short func_020dc428();
extern "C" void func_ov023_021e7220(void *p, int a);
extern "C" int func_ov023_021e76c4(void *p);
extern "C" void func_ov023_021e7b34(void *p, int a);
extern "C" void func_ov023_021e7340(void *p);
extern "C" unsigned char data_ov002_0216cc88[];
extern "C" unsigned char data_02114e54[];

// USA: func_ov002_021650d4
extern "C" ARM void func_ov002_021650d4(char *base) {
    GameState *gs      = GameState::GetInstance();
    GameResources *res = (GameResources *) GetWord0x0((int *) gs);
    if (*(unsigned char *) (base + 0x1000 + 0xcc3) == 0) {
        int state = *(int *) (base + 0x1000 + 0xbc0);
        if (state == 0) {
            OrBitsIntoField0((unsigned int *) _Z27GetDataPtr02114e04_020d6c00v(), 1);
            func_020dc7e8(1, -1);
            _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((struct Struct0205de24 *) (base + 0x2c8 + 0xc00), 0, 3);
            func_ov002_02161cf0(base);
            func_ov002_0215e44c(base);
            for (int i = 0; i < 3; i++) {
                _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii((struct Struct_0205def8 *) (base + 0x2c8 + 0xc00), 0,
                                                                        data_ov002_0216cc88[i]);
            }
            SetSubBrightness(res, -16, 0xf);
            *(unsigned char *) (base + 0x1000 + 0xcc3) = 1;
            ((SafeAllocator *) (base + 0x64 + 0x800))->Reset();
            func_ov023_021e7220(base + 0xb4 + 0x800, 0);
            _Z30CreateThreeAllocators_021e71b4PvP13SafeAllocator(base + 0xb4 + 0x800, (SafeAllocator *) (base + 0x64 + 0x800));
            *(int *) (base + 0x1000 + 0xbc0) += 1;
        } else if (state == 6) {
            *(int *) (base + 0x1000 + 0xbc0) = state + 1;
        } else if (state == 7) {
            func_ov002_02156e90(base);
            func_ov002_02156e90(base);
            *(int *) (base + 0x1000 + 0xbb8)  = 0xe;
            *(short *) (base + 0x1b00 + 0xf6) = func_020dc428();
            *(int *) (base + 0x1000 + 0xbc0)  = 0;
        }
    } else {
        int st = *(int *) (base + 0x1000 + 0xbc0);
        if (st == 1) {
            if (IsSubBrightnessTransitionActive(res)) return;
            OrGlobalFlag0x40();
            *(int *) (base + 0x1000 + 0xbc0) += 1;
        } else if (st == 2) {
            if (!func_ov023_021e76c4(base + 0xb4 + 0x800)) return;
            func_ov023_021e7b34(base + 0xb4 + 0x800, GetField0x3acValue(gs));
            _Z29DispatchEntryByIndex_021e7bc4P14PMFObj021e7bc4ji((struct PMFObj021e7bc4 *) (base + 0xb4 + 0x800), 0,
                                                                 GetField0x3acValue(gs));
            *(int *) (base + 0x1000 + 0xbc0) += 1;
        } else if (st == 3) {
            SetSubBrightness(res, 0, 0xf);
            *(int *) (base + 0x1000 + 0xbc0) += 1;
        } else if (st == 4) {
            if (!_Z29CheckFlagOrThreshold_02161b48Pci(base, 1) && data_02114e54[0x55] == 0) return;
            SetSubBrightness(res, -16, 0xa);
            *(int *) (base + 0x1000 + 0xbc0) += 1;
        } else if (st == 5) {
            if (IsSubBrightnessTransitionActive(res)) return;
            _Z29SetCombatModeFromCase020dc2d0i(0);
            func_ov023_021e7340(base + 0xb4 + 0x800);
            *(unsigned char *) (base + 0x1000 + 0xcc3) = 0;
            *(int *) (base + 0x1000 + 0xbc0) += 1;
        }
    }
}
