#include "GameState/GameState.h"
#include "System/Cache.h"
#include "System/LoadToVRAM.h"
#include <globaldefs.h>

struct Struct0205de24;
struct Struct_0205c570;
struct Struct_0205def8;
struct Obj_0205da38;
struct Obj0205eaa0;
struct Obj02061bd8;
extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(struct Struct_0205c570 *s);
extern "C" void _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii(struct Struct_0205def8 *s, int a, int b);
extern "C" void _Z32FilterSlotsWithFlag0x800020dc4d0PaS_(signed char *out, signed char *outCount);
GameObject *GetCombatantWithFlag0x100(GameState *gameState, int combatantId);
int CheckField0x56bLowNibble(struct Obj02061bd8 *obj);
int TestFlag0SetAndFlag1Clear(unsigned short *p, int n);
extern "C" int _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(struct Obj_0205da38 *o);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0 *o, int a, int b);
extern "C" int _Z27GetDataPtr02114e04_020d6c00v(void);
void OrBitsIntoField0(unsigned int *p, unsigned int bits);
extern "C" int _Z29CheckFlagOrThreshold_02161b48Pci(char *base, int a);
extern "C" void func_ov002_0215b814(char *base);
extern "C" void func_ov002_02161cf0(char *base);
extern "C" void func_ov002_0215e1d0(char *base);
extern "C" void func_ov002_02156e90(char *base);
extern "C" void func_020d79e0(char *base, int id);
extern "C" void func_02012fe4(void);
extern "C" void func_02017c58(void);
extern "C" unsigned short data_02114e30[];
extern "C" char data_02108760[];
extern "C" unsigned short data_ov002_0216cca4[];
extern "C" unsigned short data_ov002_0216cc86[];

struct L02164d14 {
    char pad[0x60];
    int f60;
};
// USA: func_ov002_02164d14
extern "C" ARM void func_ov002_02164d14(char *base) {
    int state = *(int *) (base + 0x1000 + 0xbc0);
    if (state == 0) {
        func_ov002_0215b814(base);
        _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((struct Struct0205de24 *) (base + 0x2c8 + 0xc00), 0, 2);
        func_ov002_02161cf0(base);
        func_ov002_0215e1d0(base);
        *(int *) (base + 0x1000 + 0xbc0) += 1;
    } else if (state == 1) {
        GameState *gs = GameState::GetInstance();
        if (*(short *) (base + 0x1b00 + 0xf6) != 0) {
            _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii((struct Struct_0205def8 *) (base + 0x2c8 + 0xc00), 1, 1);
            _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii((struct Struct_0205def8 *) (base + 0x2c8 + 0xc00), 1, 0xe);
            _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii((struct Struct_0205def8 *) (base + 0x2c8 + 0xc00), 1,
                                                                    0x29);
        }
        *(unsigned int *) (base + 0x2000 + 0x47c) |= 4;
        short old = *(short *) (base + 0x1b00 + 0xf6);
        *(short *) (base + 0x1b00 + 0xf6) =
            _Z26GetActiveScaledSum0205d794P15Struct_0205c570((struct Struct_0205c570 *) (base + 0x2c8 + 0xc00));
        signed char ids[7];
        signed char count;
        L02164d14 *list = (L02164d14 *) (base + 0x2c8 + 0xc00) + 1;
        int bad         = 0;
        _Z32FilterSlotsWithFlag0x800020dc4d0PaS_(ids, &count);
        int dead = bad;
        for (int i = 0; i < count; i++) {
            GameObject *c = GetCombatantWithFlag0x100(gs, ids[i]);
            if (c != NULL && CheckField0x56bLowNibble((struct Obj02061bd8 *) c)) dead++;
        }
        count -= dead;
        if (count + 1 != (list - 1)->f60) bad = 1;
        if ((list - 1)->f60 <= *(short *) (base + 0x1b00 + 0xf6)) bad = 1;
        if (bad) {
            *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
            *(short *) (base + 0x1b00 + 0xf6) = -1;
            func_ov002_02156e90(base);
            *(int *) (base + 0x1000 + 0xbb8) = 0xe;
            *(int *) (base + 0x1000 + 0xbc0) = 0;
            return;
        }
        if (old != *(short *) (base + 0x1b00 + 0xf6)) return;
        int a = TestFlag0SetAndFlag1Clear(data_02114e30, 0x601);
        int b = ((int (*)(void *, int)) _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38)(base + 0x2c8 + 0xc00, 0x14);
        if ((a | b) ? 1 : 0) {
            if (*(unsigned int *) (base + 0x2000 + 0x47c) & 2) return;
            if (*(short *) (base + 0x1b00 + 0xf6) == count) {
                *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
                _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0 *) data_02108760, 1, 0);
                *(int *) (base + 0x1000 + 0xbb8) = 0xf;
                *(int *) (base + 0x1000 + 0xbc0) = 0;
                for (int i = 0; i < 4; i++) {
                    unsigned short off = data_ov002_0216cca4[i] * 0x20;
                    CleanInvalidateCacheRange(data_ov002_0216cc86, 2);
                    LoadToMainBGStandardPalette(data_ov002_0216cc86, (unsigned short) (off + 2), 2);
                    CleanCacheRange(data_ov002_0216cc86, 2);
                }
                return;
            }
            if (ids[*(short *) (base + 0x1b00 + 0xf6)] < 0) return;
            OrBitsIntoField0((unsigned int *) _Z27GetDataPtr02114e04_020d6c00v(), 1);
            if (CheckField0x56bLowNibble(
                    (struct Obj02061bd8 *) GetCombatantWithFlag0x100(gs, ids[*(short *) (base + 0x1b00 + 0xf6)])))
            {
                for (int j = 0; j < 4; j++) {
                    short *cur = (short *) (base + 0xf6 + 0x1b00);
                    (*cur)++;
                    *cur          = *cur % 4;
                    GameObject *c = GetCombatantWithFlag0x100(gs, ids[*(short *) (base + 0x1b00 + 0xf6)]);
                    if (c != NULL && !CheckField0x56bLowNibble((struct Obj02061bd8 *) c)) break;
                }
            }
            func_020d79e0(base, ids[*(short *) (base + 0x1b00 + 0xf6)]);
            *(int *) (base + 0x1000 + 0xbb8) = 0x2b;
            *(int *) (base + 0x1000 + 0xbc0) = 0;
            func_02012fe4();
            func_02017c58();
        } else if (_Z29CheckFlagOrThreshold_02161b48Pci(base, 1)) {
            *(short *) (base + 0x1b00 + 0xf6) = -1;
            func_ov002_02156e90(base);
        }
    }
}
