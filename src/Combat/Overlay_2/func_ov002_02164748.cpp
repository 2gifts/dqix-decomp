#include "GameState/GameState.h"
#include <globaldefs.h>

struct Struct0205de24;
struct Struct_0205c570;
struct Obj_0205da38;
struct Obj0205eaa0;
struct Struct_0205d81c;
struct Obj0205dee8;
struct Slots02083834;
struct Slots02083994;
struct KeyMap020a095c;
extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(struct Struct_0205c570 *s);
int TestFlag0SetAndFlag1Clear(unsigned short *p, int n);
extern "C" int _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(struct Obj_0205da38 *o);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0 *o, int a, int b);
extern "C" int _Z29CheckFlagOrThreshold_02161b48Pci(char *base, int a);
void SetElementFieldC2(struct Struct_0205d81c *s, int a, int b);
extern "C" void _Z27SetFieldB0AndUpdate0205dee8P11Obj0205dee8i(struct Obj0205dee8 *o, int v);
unsigned char *GetFieldAt0x150(unsigned char *p);
extern "C" int _Z22GetCountByType02157108Pvi(void *base, int id);
GameObject *GetCombatantWithFlag0x100(GameState *gameState, int combatantId);
void *GetPtrField0x2a04(GameState *gameState);
extern "C" void _Z27InsertIntoEmptySlot02083834P13Slots02083834i(struct Slots02083834 *s, int v);
extern "C" int _Z34CountMatchingUntilNegative02083994P13Slots02083994i(struct Slots02083994 *s, int v);
extern "C" void _Z26AddKeyValueClamped020a095cP14KeyMap020a095cii(struct KeyMap020a095c *m, int key, int val);
extern "C" void func_ov002_02161cf0(char *base);
extern "C" void func_ov002_0215bba8(char *base);
extern "C" void func_ov002_0215a7b4(char *base, int a, short b, int c, int d);
extern "C" void func_ov002_0215b9a4(char *self, unsigned char key, int flag);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);
extern "C" unsigned short data_02114e30[];
extern "C" char data_02108760[];

#define FLAG(m) (**(int **) ((char *) (m) + 0x130) & 1)
#define SLOT(f, i) (*(short *) ((f) + (i) * 2 + 0x400 + 0x54))

// USA: func_ov002_02164748
extern "C" ARM void func_ov002_02164748(char *base) {
    int state = *(int *) (base + 0x1000 + 0xbc0);
    if (state == 0) {
        *(short *) (base + 0x1b00 + 0xf4) = _Z22GetCountByType02157108Pvi(base, *(signed char *) (base + 0x1c00 + 0x21)) & 7;
        _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((struct Struct0205de24 *) (base + 0x2c8 + 0xc00), 0, 3);
        SetElementFieldC2((struct Struct_0205d81c *) (base + 0x2c8 + 0xc00), 9, 1);
        SetElementFieldC2((struct Struct_0205d81c *) (base + 0x2c8 + 0xc00), 0xd, 0);
        func_ov002_02161cf0(base);
        *(int *) (base + 0x1000 + 0xbc8) = 1;
        func_ov002_0215bba8(base);
        *(int *) (base + 0x1000 + 0xbc0) += 1;
    } else if (state == 1) {
        *(unsigned int *) (base + 0x2000 + 0x47c) |= 4;
        short old = *(short *) (base + 0x1b00 + 0xf4);
        *(short *) (base + 0x1b00 + 0xf4) =
            _Z26GetActiveScaledSum0205d794P15Struct_0205c570((struct Struct_0205c570 *) (base + 0x2c8 + 0xc00));
        if (old != *(short *) (base + 0x1b00 + 0xf4)) return;
        int ta = TestFlag0SetAndFlag1Clear(data_02114e30, 0x601);
        int tb = ((int (*)(void *, int)) _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38)(base + 0x2c8 + 0xc00, 0x14);
        if ((ta | tb) ? 1 : 0) {
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0 *) data_02108760, 1, 0);
            GameState *gs = GameState::GetInstance();
            GameObject *a = GetCombatantWithFlag0x100(gs, *(signed char *) (base + 0x1c00 + 0x21));
            if (a == NULL) return;
            unsigned char *fa = GetFieldAt0x150((unsigned char *) a);
            GameObject *b     = GetCombatantWithFlag0x100(gs, *(signed char *) (base + 0x1c00 + 0x20));
            if (b == NULL && *(signed char *) (base + 0x1c00 + 0x20) != 4) return;
            int done                          = 0;
            short v                           = SLOT(fa, *(short *) (base + 0x1b00 + 0xf4));
            *(short *) (base + 0x1c00 + 0x24) = v;
            if (v <= 0) {
                func_ov002_0215a7b4(base, *(signed char *) (base + 0x1c00 + 0x20), *(short *) (base + 0x1c00 + 0x22),
                                    *(short *) (base + 0x1b00 + 0xe8), 0);
                _Z27InsertIntoEmptySlot02083834P13Slots02083834i((struct Slots02083834 *) fa,
                                                                 *(short *) (base + 0x1c00 + 0x22));
                int t = *(signed char *) (base + 0x1c00 + 0x20);
                if (t == 4) {
                    if (FLAG(a))
                        *(short *) (base + 0x1c00 + 0x28) = 0x236b;
                    else
                        *(short *) (base + 0x1c00 + 0x28) = 0x236a;
                } else if (t == *(signed char *) (base + 0x1c00 + 0x21)) {
                    if (FLAG(b))
                        *(short *) (base + 0x1c00 + 0x28) = 0x2364;
                    else
                        *(short *) (base + 0x1c00 + 0x28) = 0x2363;
                } else {
                    if ((**(int **) ((char *) b + 0x130) & 1) && FLAG(a))
                        *(short *) (base + 0x1c00 + 0x28) = 0x2360;
                    else if (!(**(int **) ((char *) b + 0x130) & 1U) && FLAG(a))
                        *(short *) (base + 0x1c00 + 0x28) = 0x235f;
                    else if ((**(int **) ((char *) b + 0x130) & 1L) && !FLAG(a))
                        *(short *) (base + 0x1c00 + 0x28) = 0x235e;
                    else
                        *(short *) (base + 0x1c00 + 0x28) = 0x235b;
                    done = 1;
                }
            } else if (v > 0) {
                done = 1;
                if (*(signed char *) (base + 0x1c00 + 0x20) == 4) {
                    void *party = GetPtrField0x2a04(gs);
                    func_ov002_0215a7b4(base, *(signed char *) (base + 0x1c00 + 0x20), *(short *) (base + 0x1c00 + 0x22),
                                        *(short *) (base + 0x1b00 + 0xe8), 0);
                    _Z26AddKeyValueClamped020a095cP14KeyMap020a095cii((struct KeyMap020a095c *) party,
                                                                      *(short *) (base + 0x1c00 + 0x24), done);
                    SLOT(fa, *(short *) (base + 0x1b00 + 0xf4)) = *(short *) (base + 0x1c00 + 0x22);
                    if (FLAG(a))
                        *(short *) (base + 0x1c00 + 0x28) = 0x236d;
                    else
                        *(short *) (base + 0x1c00 + 0x28) = 0x236c;
                } else {
                    GameObject *b2 = GetCombatantWithFlag0x100(gs, *(signed char *) (base + 0x1c00 + 0x20));
                    if (b2 == NULL) return;
                    unsigned char *fb                           = GetFieldAt0x150((unsigned char *) b2);
                    SLOT(fb, *(short *) (base + 0x1b00 + 0xe8)) = *(short *) (base + 0x1c00 + 0x24);
                    SLOT(fa, *(short *) (base + 0x1b00 + 0xf4)) = *(short *) (base + 0x1c00 + 0x22);
                    if (*(signed char *) (base + 0x1c00 + 0x20) == *(signed char *) (base + 0x1c00 + 0x21)) {
                        if (FLAG(b2))
                            *(short *) (base + 0x1c00 + 0x28) = 0x2364;
                        else
                            *(short *) (base + 0x1c00 + 0x28) = 0x2363;
                    } else if (FLAG(b2) && FLAG(a)) {
                        *(short *) (base + 0x1c00 + 0x28) = 0x235d;
                    } else {
                        *(short *) (base + 0x1c00 + 0x28) = 0x235c;
                    }
                }
            }
            if (done) {
                int same = 0;
                int t20  = *(signed char *) (base + 0x1c00 + 0x20);
                if (t20 != *(signed char *) (base + 0x1c00 + 0x21) &&
                    *(short *) (base + 0x1c00 + 0x22) == *(short *) (base + 0x1c00 + 0x24))
                    same = 1;
                if (*(short *) (base + 0x1c00 + 0x22) == 0x570a && t20 != 4) {
                    short cnt = _Z34CountMatchingUntilNegative02083994P13Slots02083994i(
                        (struct Slots02083994 *) GetFieldAt0x150((unsigned char *) b), 0x570a);
                    if (cnt == 0 || (cnt == 1 && same)) {
                        *(unsigned char *) (*(char **) ((char *) b + 0x130) + 8) = 0;
                        func_ov017_021c9e00(*(short *) ((char *) b + 4), 0, 0, 1);
                    }
                }
                if (*(short *) (base + 0x1c00 + 0x24) == 0x570a) {
                    short cnt = _Z34CountMatchingUntilNegative02083994P13Slots02083994i((struct Slots02083994 *) fa, 0x570a);
                    if (cnt == 0 || (cnt == 1 && same)) {
                        *(unsigned char *) (*(char **) ((char *) a + 0x130) + 8) = 0;
                        func_ov017_021c9e00(*(short *) ((char *) a + 4), 0, 0, 1);
                    }
                }
            }
            *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
            func_ov002_0215b9a4(base, *(int *) (base + 0x1000 + 0xbb8) & 0xff, 1);
            *(short *) (base + 0x1c00 + 0x2a)          = -1;
            *(int *) (base + 0x1000 + 0xbb8)           = 0x26;
            *(int *) (base + 0x1000 + 0xbbc)           = 5;
            *(int *) (base + 0x1000 + 0xbc0)           = 0;
            *(unsigned char *) (base + 0x2000 + 0x478) = 1;
        } else if (_Z29CheckFlagOrThreshold_02161b48Pci(base, 1)) {
            *(short *) (base + 0x1b00 + 0xf4) = -1;
            *(int *) (base + 0x1000 + 0xbb8)  = 9;
            func_ov002_02161cf0(base);
            SetElementFieldC2((struct Struct_0205d81c *) (base + 0x2c8 + 0xc00), 9, 0);
            _Z27SetFieldB0AndUpdate0205dee8P11Obj0205dee8i((struct Obj0205dee8 *) (base + 0x2c8 + 0xc00), 9);
            *(int *) (base + 0x1000 + 0xbc8) = 1;
            *(int *) (base + 0x1000 + 0xbcc) = 1;
            func_ov002_0215b9a4(base, *(int *) (base + 0x1000 + 0xbb8) & 0xff, 0);
        }
    }
}
