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
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
int GetActiveScaledSum0205d794(struct Struct_0205c570 *s);
int TestFlag0SetAndFlag1Clear_02012444(unsigned short *p, int n);
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0 *o, int a, int b);
int CheckFlagOrThreshold_02161b48(char *base, int a);
void SetElementFieldC2_0205deb4(struct Struct_0205d81c *s, int a, int b);
void SetFieldB0AndUpdate0205dee8(struct Obj0205dee8 *o, int v);
unsigned char *GetFieldAt0x150_02053c6c(unsigned char *p);
int GetCountByType02157108(void *base, int id);
GameObject *GetCombatantWithFlag0x100_0200ff1c(GameState *gameState, int combatantId);
void *GetPtrField0x2a04_02010828(GameState *gameState);
void InsertIntoEmptySlot02083834(struct Slots02083834 *s, int v);
int CountMatchingUntilNegative02083994(struct Slots02083994 *s, int v);
void AddKeyValueClamped020a095c(struct KeyMap020a095c *m, int key, int val);
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
        *(short *) (base + 0x1b00 + 0xf4) = GetCountByType02157108(base, *(signed char *) (base + 0x1c00 + 0x21)) & 7;
        FindAndLinkMatchingEntry0205de24((struct Struct0205de24 *) (base + 0x2c8 + 0xc00), 0, 3);
        SetElementFieldC2_0205deb4((struct Struct_0205d81c *) (base + 0x2c8 + 0xc00), 9, 1);
        SetElementFieldC2_0205deb4((struct Struct_0205d81c *) (base + 0x2c8 + 0xc00), 0xd, 0);
        func_ov002_02161cf0(base);
        *(int *) (base + 0x1000 + 0xbc8) = 1;
        func_ov002_0215bba8(base);
        *(int *) (base + 0x1000 + 0xbc0) += 1;
    } else if (state == 1) {
        *(unsigned int *) (base + 0x2000 + 0x47c) |= 4;
        short old = *(short *) (base + 0x1b00 + 0xf4);
        *(short *) (base + 0x1b00 + 0xf4) =
            GetActiveScaledSum0205d794((struct Struct_0205c570 *) (base + 0x2c8 + 0xc00));
        if (old != *(short *) (base + 0x1b00 + 0xf4)) return;
        int ta = TestFlag0SetAndFlag1Clear_02012444(data_02114e30, 0x601);
        int tb = IsActiveElementFlag2Set0205da38((struct Obj_0205da38*)(base + 0x2c8 + 0xc00), 0x14);
        if ((ta | tb) ? 1 : 0) {
            DispatchWithShortB4_0205eaa0((struct Obj0205eaa0 *) data_02108760, 1, 0);
            GameState *gs = GameState::GetInstance();
            GameObject *a = GetCombatantWithFlag0x100_0200ff1c(gs, *(signed char *) (base + 0x1c00 + 0x21));
            if (a == NULL) return;
            unsigned char *fa = GetFieldAt0x150_02053c6c((unsigned char *) a);
            GameObject *b     = GetCombatantWithFlag0x100_0200ff1c(gs, *(signed char *) (base + 0x1c00 + 0x20));
            if (b == NULL && *(signed char *) (base + 0x1c00 + 0x20) != 4) return;
            int done                          = 0;
            short v                           = SLOT(fa, *(short *) (base + 0x1b00 + 0xf4));
            *(short *) (base + 0x1c00 + 0x24) = v;
            if (v <= 0) {
                func_ov002_0215a7b4(base, *(signed char *) (base + 0x1c00 + 0x20), *(short *) (base + 0x1c00 + 0x22),
                                    *(short *) (base + 0x1b00 + 0xe8), 0);
                InsertIntoEmptySlot02083834((struct Slots02083834 *) fa,
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
                    void *party = GetPtrField0x2a04_02010828(gs);
                    func_ov002_0215a7b4(base, *(signed char *) (base + 0x1c00 + 0x20), *(short *) (base + 0x1c00 + 0x22),
                                        *(short *) (base + 0x1b00 + 0xe8), 0);
                    AddKeyValueClamped020a095c((struct KeyMap020a095c *) party,
                                                                      *(short *) (base + 0x1c00 + 0x24), done);
                    SLOT(fa, *(short *) (base + 0x1b00 + 0xf4)) = *(short *) (base + 0x1c00 + 0x22);
                    if (FLAG(a))
                        *(short *) (base + 0x1c00 + 0x28) = 0x236d;
                    else
                        *(short *) (base + 0x1c00 + 0x28) = 0x236c;
                } else {
                    GameObject *b2 = GetCombatantWithFlag0x100_0200ff1c(gs, *(signed char *) (base + 0x1c00 + 0x20));
                    if (b2 == NULL) return;
                    unsigned char *fb                           = GetFieldAt0x150_02053c6c((unsigned char *) b2);
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
                    short cnt = CountMatchingUntilNegative02083994(
                        (struct Slots02083994 *) GetFieldAt0x150_02053c6c((unsigned char *) b), 0x570a);
                    if (cnt == 0 || (cnt == 1 && same)) {
                        *(unsigned char *) (*(char **) ((char *) b + 0x130) + 8) = 0;
                        func_ov017_021c9e00(*(short *) ((char *) b + 4), 0, 0, 1);
                    }
                }
                if (*(short *) (base + 0x1c00 + 0x24) == 0x570a) {
                    short cnt = CountMatchingUntilNegative02083994((struct Slots02083994 *) fa, 0x570a);
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
        } else if (CheckFlagOrThreshold_02161b48(base, 1)) {
            *(short *) (base + 0x1b00 + 0xf4) = -1;
            *(int *) (base + 0x1000 + 0xbb8)  = 9;
            func_ov002_02161cf0(base);
            SetElementFieldC2_0205deb4((struct Struct_0205d81c *) (base + 0x2c8 + 0xc00), 9, 0);
            SetFieldB0AndUpdate0205dee8((struct Obj0205dee8 *) (base + 0x2c8 + 0xc00), 9);
            *(int *) (base + 0x1000 + 0xbc8) = 1;
            *(int *) (base + 0x1000 + 0xbcc) = 1;
            func_ov002_0215b9a4(base, *(int *) (base + 0x1000 + 0xbb8) & 0xff, 0);
        }
    }
}
