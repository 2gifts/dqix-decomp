#include "GameState/GameState.h"
#include <globaldefs.h>

struct Struct0205de24;
struct Struct_0205c570;
struct Obj_0205da38;
struct Obj0205eaa0;
struct Struct_0205d81c;
struct Container020dedd0;
extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(struct Struct_0205c570 *s);
int TestFlag0SetAndFlag1Clear(unsigned short *p, int n);
extern "C" int _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(struct Obj_0205da38 *o);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0 *o, int a, int b);
extern "C" int _Z29CheckFlagOrThreshold_02161b48Pci(char *base, int a);
void SetElementFieldC2(struct Struct_0205d81c *s, int a, int b);
unsigned char *GetFieldAt0x150(unsigned char *p);
extern "C" void _Z21InitBattleTag0215ccc4Pc(char *base);
extern "C" int _Z27IsFlagAt130Bit0Set_0216364cPv(void *member);
extern "C" char *_Z24FindElementByKey020dedd0P17Container020dedd0i(struct Container020dedd0 *c, int key);
extern "C" void _Z32SetupTargetAndApplyState021575d4Pc(char *base);
extern "C" int _Z34GetInventoryItemFlagField_02157500Ph(unsigned char *base);
extern "C" int _Z33CheckAndClearEntryStatus_0215b7d0v();
extern "C" void func_ov002_02161cf0(char *base);
extern "C" void func_ov002_0215b814(char *base);
extern "C" int func_ov002_0215b720(char *self, int id);
extern "C" void func_ov002_02157634(char *base);
extern "C" void func_ov002_02156e90(char *base);
extern "C" unsigned short data_02114e30[];
extern "C" char data_02108760[];

static inline int InRange021631e8(int v) {
    return (v >= 0 && v <= 3) ? 1 : 0;
}

// USA: func_ov002_021631e8
extern "C" ARM void func_ov002_021631e8(char *base) {
    int state = *(int *) (base + 0x1000 + 0xbc0);
    if (state == 0) {
        *(short *) (base + 0x1b00 + 0xea) = 0;
        GameObject *p                     = GameState::GetInstance()->GetProtagonist();
        if (p == NULL) {
            *(short *) (base + 0x1b00 + 0xea) = 0;
        } else {
            *(short *) (base + 0x1b00 + 0xea) = *(short *) (GetFieldAt0x150((unsigned char *) p) + 0x900 + 0x5c);
        }
        _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((struct Struct0205de24 *) (base + 0x2c8 + 0xc00), 0, 2);
        func_ov002_02161cf0(base);
        _Z21InitBattleTag0215ccc4Pc(base);
        *(int *) (base + 0x1000 + 0xbc0) += 1;
    } else if (state == 1) {
        *(unsigned int *) (base + 0x2000 + 0x47c) |= 4;
        short old = *(short *) (base + 0x1b00 + 0xea);
        *(short *) (base + 0x1b00 + 0xea) =
            _Z26GetActiveScaledSum0205d794P15Struct_0205c570((struct Struct_0205c570 *) (base + 0x2c8 + 0xc00));
        if (old != *(short *) (base + 0x1b00 + 0xea)) return;
        int a = TestFlag0SetAndFlag1Clear(data_02114e30, 0x601);
        int b = ((int (*)(void *, int)) _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38)(base + 0x2c8 + 0xc00, 0x14);
        if ((a | b) ? 1 : 0) {
            func_ov002_0215b814(base);
            *(unsigned char *) (base + 0xf80) = *(int *) (base + 0x1000 + 0xbb8);
            *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
            GameObject *p = GameState::GetInstance()->GetProtagonist();
            if (p != NULL) {
                short cur                                                        = *(short *) (base + 0x1b00 + 0xea);
                *(short *) (GetFieldAt0x150((unsigned char *) p) + 0x900 + 0x5c) = cur;
            }
            switch (*(short *) (base + 0x1b00 + 0xea)) {
                case 0:
                    _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0 *) data_02108760, 1, 0);
                    int ok = 0;
                    int id = *(signed char *) (base + 0x1c00 + 0x20);
                    if (id >= 0 && id <= 3) ok = 1;
                    if (ok && _Z27IsFlagAt130Bit0Set_0216364cPv(
                                  GameState::GetInstance()->GetPartyMemberByIndex(*(char *) (base + 0x1c00 + 0x20))))
                    {
                        *(short *) (base + 0x1c00 + 0x28) = 0x7aa8;
                        *(short *) (base + 0x1c00 + 0x2a) = -1;
                        *(int *) (base + 0x1000 + 0xbb8)  = 0x26;
                        *(int *) (base + 0x1000 + 0xbbc)  = 5;
                        *(int *) (base + 0x1000 + 0xbc0)  = 0;
                        *(short *) (base + 0x1b00 + 0xea) = -1;
                        return;
                    }
                    {
                        char *e = _Z24FindElementByKey020dedd0P17Container020dedd0i(
                            (struct Container020dedd0 *) (base + 0x3ec + 0x400), *(short *) (base + 0x1c00 + 0x22));
                        if (e != NULL && func_ov002_0215b720(base, *(short *) (e + 0x14))) {
                            *(int *) (base + 0x1000 + 0xbc0) = 2;
                            return;
                        }
                    }
                    *(short *) (base + 0x1c00 + 0x28)          = 0x232a;
                    *(short *) (base + 0x1c00 + 0x2a)          = 0x232b;
                    *(unsigned char *) (base + 0x1000 + 0xc83) = 0;
                    *(unsigned char *) (base + 0x1000 + 0xc85) &= ~1;
                    *(unsigned char *) (base + 0x1000 + 0xc84) = 0;
                    _Z32SetupTargetAndApplyState021575d4Pc(base);
                    func_ov002_02157634(base);
                    return;
                case 1:
                    _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0 *) data_02108760, 1, 0);
                    *(int *) (base + 0x1000 + 0xbb8) = 9;
                    *(int *) (base + 0x1000 + 0xbc0) = 0;
                    return;
                case 2: {
                    _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0 *) data_02108760, 1, 0);
                    int r = ((int (*)(char *, int, int)) _Z34GetInventoryItemFlagField_02157500Ph)(
                        base, *(short *) (base + 0x1b00 + 0xe8), *(signed char *) (base + 0x1c00 + 0x20));
                    if (r != 0) {
                        *(unsigned char *) (base + 0x1000 + 0xc32) = 0;
                        if (r == 2) *(unsigned char *) (base + 0x1000 + 0xc32) = 1;
                        *(int *) (base + 0x1000 + 0xbb8)           = 0x26;
                        *(int *) (base + 0x1000 + 0xbbc)           = 5;
                        *(short *) (base + 0x1c00 + 0x28)          = 0x2365;
                        *(short *) (base + 0x1c00 + 0x2a)          = -1;
                        *(int *) (base + 0x1000 + 0xbc0)           = 0;
                        *(unsigned char *) (base + 0x1000 + 0xc2e) = 1;
                    } else {
                        *(int *) (base + 0x1000 + 0xbb8)  = 0x26;
                        *(int *) (base + 0x1000 + 0xbbc)  = 5;
                        *(short *) (base + 0x1c00 + 0x28) = 0x2368;
                        *(short *) (base + 0x1c00 + 0x2a) = -1;
                        *(int *) (base + 0x1000 + 0xbc0)  = 0;
                    }
                    return;
                }
                case 3:
                    *(short *) (base + 0x1b00 + 0xea) = -1;
                    func_ov002_02156e90(base);
                    return;
            }
        } else if (_Z29CheckFlagOrThreshold_02161b48Pci(base, 1)) {
            *(short *) (base + 0x1b00 + 0xea) = -1;
            func_ov002_02156e90(base);
            SetElementFieldC2((struct Struct_0205d81c *) (base + 0x2c8 + 0xc00), 4, 1);
        }
    } else if (state == 2) {
        int r = ((int (*)(char *)) _Z33CheckAndClearEntryStatus_0215b7d0v)(base);
        if (r > 0) {
            *(short *) (base + 0x1c00 + 0x28)          = 0x232a;
            *(short *) (base + 0x1c00 + 0x2a)          = 0x232b;
            *(unsigned char *) (base + 0x1000 + 0xc83) = 0;
            *(unsigned char *) (base + 0x1000 + 0xc85) &= ~1;
            *(unsigned char *) (base + 0x1000 + 0xc84) = 0;
            _Z32SetupTargetAndApplyState021575d4Pc(base);
            func_ov002_02157634(base);
        } else if (r < 0) {
            *(short *) (base + 0x1c00 + 0x28)          = 0x7918;
            *(short *) (base + 0x1c00 + 0x2a)          = -1;
            *(short *) (base + 0x2400 + 0x88)          = 0x7919;
            *(unsigned char *) (base + 0x2000 + 0x48a) = 1;
            *(int *) (base + 0x1000 + 0xbb8)           = 0x26;
            *(int *) (base + 0x1000 + 0xbbc)           = 5;
            *(int *) (base + 0x1000 + 0xbc0)           = 0;
        }
    }
}
