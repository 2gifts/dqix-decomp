#include "GameState/GameState.h"
#include <globaldefs.h>

struct Struct0205de24;
struct Struct_0205c570;
struct Obj_0205da38;
struct Obj0205eaa0;
struct Struct_0205d81c;
struct Obj0205dee8;
struct Struct_0205def8;
struct ArrayContainsByteStruct;
struct KeyMap020a0b3c;
struct KeyMap020a0a08;
struct KeyMap020a095c;
struct Slots02083994;
struct Container020dedd0;
extern "C" int _Z38BuildFlaggedCombatantSlotList_02154f4cPh(unsigned char *obj);
void *GetFieldAt0x150(unsigned char *obj);
extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(struct Struct_0205c570 *s);
extern "C" int _Z41CountFlag0x800MatchesEqualsTarget020dcc20ii(int targetCount, int flag);
void *GetPtrField0x2a04(GameState *gs);
int ArrayContainsByte(struct ArrayContainsByteStruct *s, int val);
extern "C" void _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii(struct Struct_0205def8 *s, int clear, int key);
extern "C" int func_0205df38(void *list, int key);
extern "C" int _Z27CheckAnyByteMatches020dcbbcPhiiii(unsigned char *arr, int count, int b, int c, int d);
void SetElementFieldC2(struct Struct_0205d81c *s, int a, int b);
int TestFlag0SetAndFlag1Clear(unsigned short *p, int n);
extern "C" int _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(struct Obj_0205da38 *o);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0 *o, int a, int b);
extern "C" int _Z24LookupValueByKey020a0b3cP14KeyMap020a0b3ci(struct KeyMap020a0b3c *map, int key);
extern "C" int _Z25DecrementKeyValue020a0a08P14KeyMap020a0a08ii(struct KeyMap020a0a08 *map, int key, signed char amount);
extern "C" int _Z26AddKeyValueClamped020a095cP14KeyMap020a095cii(struct KeyMap020a095c *map, int key, signed char amount);
extern "C" char *_Z25GetCombatantWithFlag0x100P9GameStatei(GameState *gs, int id);
extern "C" int _Z34CountMatchingUntilNegative02083994P13Slots02083994i(struct Slots02083994 *s, int value);
extern "C" int func_020dc920(int a, int b, int c, int d);
extern "C" int *func_0202ae18(void);
int CheckField0NonZero(int *p);
extern "C" char *_Z24FindElementByKey020dedd0P17Container020dedd0i(struct Container020dedd0 *c, int key);
int GetField0x3acValue(GameState *gs);
extern "C" void _Z27SetFieldB0AndUpdate0205dee8P11Obj0205dee8i(struct Obj0205dee8 *o, int v);
extern "C" int _Z29CheckFlagOrThreshold_02161b48Pci(char *base, int a);
extern "C" void func_ov002_0215b814(char *base);
extern "C" void func_ov002_02161cf0(char *base);
extern "C" void func_ov002_0215d654(char *base);
extern "C" void func_ov002_02156e90(void *base);
extern "C" void func_ov002_0215b9a4(char *self, unsigned char key, int flag);
extern "C" void func_ov002_0215a7b4(char *base, int a, short b, int c, int d);
extern "C" void func_ov002_0215b2c8(char *self);
extern "C" void func_ov002_0216bfd4(char *self, int a);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);
extern "C" unsigned short data_02114e30[];
extern "C" char data_02108760[];

#define L(base) ((base) + 0x2c8 + 0xc00)

// USA: func_ov002_02163bd0
extern "C" ARM void func_ov002_02163bd0(char *base) {
    GameState *gs = GameState::GetInstance();
    int state     = *(int *) (base + 0x1000 + 0xbc0);
    if (state == 0) {
        *(short *) (base + 0x1b00 + 0xee) = _Z38BuildFlaggedCombatantSlotList_02154f4cPh((unsigned char *) base);
        if (gs->GetProtagonist() != NULL) {
            int i;
            for (i = 0; i <= *(unsigned char *) (base + 0x1000 + 0xc6d); i++) {
                GameObject *m = gs->GetPartyMemberByIndex(*(unsigned char *) (base + i + 0x1000 + 0xc68));
                if (m != NULL && *(int *) ((char *) m + 0x1c4) != 0) {
                    int j;
                    for (j = i; j <= *(unsigned char *) (base + 0x1000 + 0xc6d); j++) {
                        *(unsigned char *) (base + j + 0x1000 + 0xc68) = *(unsigned char *) (base + 0x68 + 0x1c00 + (j + 1));
                        *(unsigned char *) (base + 0x68 + 0x1c00 + (j + 1)) = 0xff;
                    }
                    (*(unsigned char *) (base + 0x6d + 0x1c00))--;
                }
            }
            int x = *(short *) ((char *) GetFieldAt0x150((unsigned char *) gs->GetProtagonist()) + 0x900 + 0x5e);
            int j;
            for (j = 0; j <= *(unsigned char *) (base + 0x1000 + 0xc6d); j++) {
                if (x == *(unsigned char *) (base + j + 0x1000 + 0xc68)) {
                    *(short *) (base + 0x1b00 + 0xee) = j;
                    break;
                }
            }
        }
        func_ov002_0215b814(base);
        *(unsigned char *) (base + 0x1000 + 0xc21) =
            *(unsigned char *) (base + *(short *) (base + 0x1b00 + 0xee) + 0x1000 + 0xc68);
        _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((struct Struct0205de24 *) L(base), 0, 3);
        func_ov002_02161cf0(base);
        func_ov002_0215d654(base);
        *(int *) (base + 0x1000 + 0xbc0) += 1;
    } else if (state == 1) {
        *(unsigned int *) (base + 0x2000 + 0x47c) |= 4;
        int old = *(short *) (base + 0x1b00 + 0xee);
        *(short *) (base + 0x1b00 + 0xee) =
            _Z26GetActiveScaledSum0205d794P15Struct_0205c570((struct Struct_0205c570 *) L(base));
        if (old != *(short *) (base + 0x1b00 + 0xee)) *(int *) (base + 0x1000 + 0xbcc) = 1;
        if (*(short *) (base + 0x1b00 + 0xee) < *(unsigned char *) (base + 0x1000 + 0xc6d)) {
            *(unsigned char *) (base + 0x1000 + 0xc21) =
                *(unsigned char *) (base + *(short *) (base + 0x1b00 + 0xee) + 0x1000 + 0xc68);
        } else {
            *(unsigned char *) (base + 0x1000 + 0xc21) = 4;
        }
        if (!_Z41CountFlag0x800MatchesEqualsTarget020dcc20ii(*(unsigned char *) (base + 0x1000 + 0xc6d), 1)) {
            *(short *) (base + 0x1b00 + 0xee)        = -1;
            *(signed char *) (base + 0x1000 + 0xc21) = -1;
            func_ov002_02156e90(base);
            return;
        }
        int flag = 0;
        if (!ArrayContainsByte((struct ArrayContainsByteStruct *) GetPtrField0x2a04(gs),
                               *(signed char *) (base + 0x1c00 + 0x21)) &&
            *(signed char *) (base + 0x1c00 + 0x21) != 4)
        {
            _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii((struct Struct_0205def8 *) L(base), flag, 0xd);
        } else {
            _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii((struct Struct_0205def8 *) L(base), 1, 0xd);
            if (func_0205df38(L(base), 0xd)) flag = 1;
        }
        if (*(unsigned char *) (base + 0x1000 + 0xcc4) != 0 ||
            _Z27CheckAnyByteMatches020dcbbcPhiiii((unsigned char *) (base + 0x68 + 0x1c00),
                                                  *(unsigned char *) (base + 0x1000 + 0xc6d), 0, 0, 0))
        {
            *(int *) (base + 0x1000 + 0xbcc) = 1;
            func_ov002_0215b9a4(base, *(int *) (base + 0x1000 + 0xbb8), 0);
        }
        SetElementFieldC2((struct Struct_0205d81c *) L(base), 0xd, 1);
        if (old != *(short *) (base + 0x1b00 + 0xee)) return;
        int ta = TestFlag0SetAndFlag1Clear(data_02114e30, 0x601);
        int tb = ((int (*)(void *, int)) _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38)(L(base), 0x14);
        if (((ta | tb) ? 1 : 0) || flag) {
            GameObject *pr = gs->GetProtagonist();
            if (pr != NULL) {
                int v = *(signed char *) (base + 0x1c00 + 0x21);
                *(short *) ((char *) GetFieldAt0x150((unsigned char *) pr) + 0x900 + 0x5e) = v;
            }
            if (*(signed char *) (base + 0x1c00 + 0x21) == 4) {
                _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0 *) data_02108760, 1, 0);
                *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
                if (*(signed char *) (base + 0x1c00 + 0x20) == 4) {
                    void *map = GetPtrField0x2a04(GameState::GetInstance());
                    int v     = _Z24LookupValueByKey020a0b3cP14KeyMap020a0b3ci((struct KeyMap020a0b3c *) map,
                                                                               *(short *) (base + 0x1c00 + 0x22));
                    _Z25DecrementKeyValue020a0a08P14KeyMap020a0a08ii((struct KeyMap020a0a08 *) map,
                                                                     *(short *) (base + 0x1c00 + 0x22), v);
                    _Z26AddKeyValueClamped020a095cP14KeyMap020a095cii((struct KeyMap020a095c *) map,
                                                                      *(short *) (base + 0x1c00 + 0x22), v);
                    *(short *) (base + 0x1c00 + 0x28) = 0x236e;
                } else {
                    GameState *g2 = GameState::GetInstance();
                    void *map     = GetPtrField0x2a04(g2);
                    char *m       = _Z25GetCombatantWithFlag0x100P9GameStatei(g2, *(signed char *) (base + 0x1c00 + 0x20));
                    if (m != NULL) {
                        func_ov002_0215a7b4(base, *(signed char *) (base + 0x1c00 + 0x20), *(short *) (base + 0x1c00 + 0x22),
                                            *(short *) (base + 0x1b00 + 0xe8), 0);
                        _Z26AddKeyValueClamped020a095cP14KeyMap020a095cii((struct KeyMap020a095c *) map,
                                                                          *(short *) (base + 0x1c00 + 0x22), 1);
                        func_ov002_0215b2c8(base);
                        if (**(int **) (m + 0x130) & 1) {
                            *(short *) (base + 0x1c00 + 0x28) = 0x2362;
                        } else {
                            *(short *) (base + 0x1c00 + 0x28) = 0x2361;
                        }
                        if (*(short *) (base + 0x1c00 + 0x22) == 0x570a &&
                            _Z34CountMatchingUntilNegative02083994P13Slots02083994i(
                                (struct Slots02083994 *) GetFieldAt0x150((unsigned char *) m), 0x570a) == 0)
                        {
                            *(unsigned char *) (*(char **) (m + 0x130) + 8) = 0;
                            func_ov017_021c9e00(*(short *) (m + 4), 0, 0, 1);
                        }
                    } else {
                        *(short *) (base + 0x1c00 + 0x28) = 0x2361;
                    }
                }
                func_ov002_0215b9a4(base, *(int *) (base + 0x1000 + 0xbb8), 1);
                func_ov002_0215b9a4(base, 0xd, 0);
                *(short *) (base + 0x1c00 + 0x2a)          = -1;
                *(int *) (base + 0x1000 + 0xbb8)           = 0x26;
                *(int *) (base + 0x1000 + 0xbbc)           = 5;
                *(int *) (base + 0x1000 + 0xbc0)           = 0;
                *(unsigned char *) (base + 0x2000 + 0x478) = 1;
            } else if (func_020dc920(*(signed char *) (base + 0x1c00 + 0x21) & 0xff, 0, 0, 0)) {
                _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0 *) data_02108760, 1, 0);
                *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
                func_ov002_0215b9a4(base, *(int *) (base + 0x1000 + 0xbb8), 1);
                if (CheckField0NonZero(func_0202ae18())) {
                    int ok = 1;
                    int i  = 0;
                    for (; i < *(int *) (base + 0x1000 + 0xc38); i++) {
                        if (*(signed char *) (base + 0x1c00 + 0x21) == *(int *) (base + i * 4 + 0x1000 + 0xc3c)) ok = 0;
                    }
                    if (ok) {
                        int good = 0;
                        char *e  = _Z24FindElementByKey020dedd0P17Container020dedd0i(
                            (struct Container020dedd0 *) (base + 0x3ec + 0x400), *(short *) (base + 0x1c00 + 0x22));
                        if (e != NULL && ((*(unsigned int *) (e + 8) << 14) >> 30) == 1) good = 1;
                        if (!good) {
                            *(short *) (base + 0x1c00 + 0x28) = 0x2376;
                            *(short *) (base + 0x1c00 + 0x2a) = -1;
                            *(int *) (base + 0x1000 + 0xbb8)  = 0x26;
                            *(int *) (base + 0x1000 + 0xbbc)  = 5;
                            *(int *) (base + 0x1000 + 0xbc0)  = 0;
                            return;
                        }
                        if (*(signed char *) (base + 0x1c00 + 0x20) == 4) {
                            *(signed char *) (base + 0x1000 + 0xc20)   = GetField0x3acValue(GameState::GetInstance());
                            *(unsigned char *) (base + 0x1000 + 0xc78) = 1;
                        }
                        func_ov002_0216bfd4(base, 0);
                        return;
                    }
                }
                *(int *) (base + 0x1000 + 0xbb8) = 0xd;
                *(int *) (base + 0x1000 + 0xbc0) = 0;
                _Z27SetFieldB0AndUpdate0205dee8P11Obj0205dee8i((struct Obj0205dee8 *) L(base), 0xd);
            }
        } else if (_Z29CheckFlagOrThreshold_02161b48Pci(base, 1)) {
            *(short *) (base + 0x1b00 + 0xee)        = -1;
            *(signed char *) (base + 0x1000 + 0xc21) = -1;
            func_ov002_02156e90(base);
        }
    }
}
