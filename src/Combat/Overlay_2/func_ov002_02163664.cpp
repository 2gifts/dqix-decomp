#include "GameState/GameState.h"
#include <globaldefs.h>

struct Struct0205de24;
struct Struct_0205c570;
struct Obj_0205da38;
struct Obj0205eaa0;
struct Struct_0205d81c;
struct Obj0205dee8;
struct Container020dedd0;
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
int BuildFlaggedCombatantSlotList_02154f4c(unsigned char *obj);
int CountFlag0x800MatchesEqualsTarget020dcc20(int targetCount, int flag);
int CheckAnyByteMatches020dcbbc(unsigned char *arr, int count, int b, int c, int d);
char *FindElementByKey020dedd0(struct Container020dedd0 *c, int key);
void ClearMatchingEntry_02156ff0(unsigned char *self, int v);
int CheckAndClearEntryStatus_0215b7d0(char* base);
extern "C" int func_020dc920(int a, int b, int c, int d);
extern "C" void func_ov002_0215b814(char *base);
extern "C" void func_ov002_02161cf0(char *base);
extern "C" void func_ov002_0215ce94(char *base);
extern "C" void func_ov002_02156e90(char *base);
extern "C" void func_ov002_0215b9a4(char *self, unsigned char key, int flag);
extern "C" int func_ov002_0215b720(char *self, int id);
extern "C" void func_ov002_02157d40(char *base);
extern "C" void func_ov002_02157634(char *base);
extern "C" unsigned short data_02114e30[];
extern "C" char data_02108760[];

// USA: func_ov002_02163664
extern "C" ARM void func_ov002_02163664(char *base) {
    int state = *(int *) (base + 0x1000 + 0xbc0);
    if (state == 0) {
        *(short *) (base + 0x1b00 + 0xec) = BuildFlaggedCombatantSlotList_02154f4c((unsigned char *) base);
        int n                             = *(unsigned char *) (base + 0x1000 + 0xc6d);
        unsigned char *lst                = (unsigned char *) (base + 0x68 + 0x1c00);
        if (*(short *) (base + 0x1c00 + 0x26) < 0 && *(unsigned char *) (base + 0x1000 + 0xc84) == 7) {
            n   = *(unsigned char *) (base + 0x1000 + 0xc73);
            lst = (unsigned char *) (base + 0x6e + 0x1c00);
        }
        GameObject *p = GameState::GetInstance()->GetProtagonist();
        if (p != NULL) {
            int found = 0;
            short v   = *(short *) (GetFieldAt0x150_02053c6c((unsigned char *) p) + 0x900 + 0x5e);
            for (int i = 0; i < n; i++) {
                if (v == lst[i]) {
                    *(short *) (base + 0x1b00 + 0xec) = i;
                    found                             = 1;
                    break;
                }
            }
            if (!found) *(short *) (base + 0x1b00 + 0xec) = 0;
        }
        if (*(short *) (base + 0x1c00 + 0x26) != -1) *(short *) (base + 0x1b00 + 0xec) = 0;
        func_ov002_0215b814(base);
        FindAndLinkMatchingEntry0205de24((struct Struct0205de24 *) (base + 0x2c8 + 0xc00), 0, 3);
        func_ov002_02161cf0(base);
        func_ov002_0215ce94(base);
        *(int *) (base + 0x1000 + 0xbc0) += 1;
    } else if (state == 1) {
        *(unsigned int *) (base + 0x2000 + 0x47c) |= 4;
        short old = *(short *) (base + 0x1b00 + 0xec);
        *(short *) (base + 0x1b00 + 0xec) =
            GetActiveScaledSum0205d794((struct Struct_0205c570 *) (base + 0x2c8 + 0xc00));
        if (old != *(short *) (base + 0x1b00 + 0xec)) *(int *) (base + 0x1000 + 0xbcc) = 1;
        int n              = *(unsigned char *) (base + 0x1000 + 0xc6d);
        unsigned char *lst = (unsigned char *) (base + 0x68 + 0x1c00);
        unsigned char mode = *(unsigned char *) (base + 0x1000 + 0xc84);
        if (mode == 7) {
            n   = *(unsigned char *) (base + 0x1000 + 0xc73);
            lst = (unsigned char *) (base + 0x6e + 0x1c00);
        }
        if (mode != 7 && !CountFlag0x800MatchesEqualsTarget020dcc20(n, 0)) {
            *(short *) (base + 0x1b00 + 0xec) = -1;
            func_ov002_02156e90(base);
            return;
        }
        int special = 0;
        if (*(short *) (base + 0x1c00 + 0x26) == 0xd1) special = 1;
        if (*(unsigned char *) (base + 0x1000 + 0xcc4) != 0 || CheckAnyByteMatches020dcbbc(lst, n, 1, 1, special)) {
            *(int *) (base + 0x1000 + 0xbcc) = 1;
            func_ov002_0215b9a4(base, *(int *) (base + 0x1000 + 0xbb8) & 0xff, 0);
        }
        if (old != *(short *) (base + 0x1b00 + 0xec)) return;
        int a = TestFlag0SetAndFlag1Clear_02012444(data_02114e30, 0x601);
        int b = IsActiveElementFlag2Set0205da38((struct Obj_0205da38*)(base + 0x2c8 + 0xc00), 0x14);
        if ((a | b) ? 1 : 0) {
            if (!func_020dc920(lst[*(short *) (base + 0x1b00 + 0xec)], 1, 1, special)) return;
            func_ov002_0215b814(base);
            *(unsigned char *) (base + 0xf80)          = *(int *) (base + 0x1000 + 0xbb8);
            *(unsigned char *) (base + 0x1000 + 0xc21) = lst[*(short *) (base + 0x1b00 + 0xec)];
            DispatchWithShortB4_0205eaa0((struct Obj0205eaa0 *) data_02108760, 1, 0);
            *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
            func_ov002_0215b9a4(base, 0x10, 1);
            SetElementFieldC2_0205deb4((struct Struct_0205d81c *) (base + 0x2c8 + 0xc00), 0x10, 1);
            SetElementFieldC2_0205deb4((struct Struct_0205d81c *) (base + 0x2c8 + 0xc00), 0x13, 1);
            SetElementFieldC2_0205deb4((struct Struct_0205d81c *) (base + 0x2c8 + 0xc00), 7, 1);
            SetElementFieldC2_0205deb4((struct Struct_0205d81c *) (base + 0x2c8 + 0xc00), 8, 1);
            if (*(short *) (base + 0x1c00 + 0x26) != -1) {
                if (func_ov002_0215b720(base, *(short *) (base + 0x1c00 + 0x26))) {
                    *(int *) (base + 0x1000 + 0xbc0) = 2;
                    return;
                }
                func_ov002_02157d40(base);
                return;
            }
            char *e = FindElementByKey020dedd0((struct Container020dedd0 *) (base + 0x3ec + 0x400),
                                                                        *(short *) (base + 0x1c00 + 0x22));
            if (e != NULL && func_ov002_0215b720(base, *(short *) (e + 0x14))) {
                *(int *) (base + 0x1000 + 0xbc0) = 2;
                return;
            }
            GameObject *p = GameState::GetInstance()->GetProtagonist();
            if (p != NULL) {
                short sel                                                        = *(signed char *) (base + 0x1c00 + 0x21);
                *(short *) (GetFieldAt0x150_02053c6c((unsigned char *) p) + 0x900 + 0x5e) = sel;
            }
            func_ov002_02157634(base);
        } else if (CheckFlagOrThreshold_02161b48(base, 1)) {
            if (*(short *) (base + 0x1c00 + 0x26) != -1) {
                *(int *) (base + 0x1000 + 0xbb8) = 0x11;
                ClearMatchingEntry_02156ff0((unsigned char *) base, 0x13);
                SetFieldB0AndUpdate0205dee8((struct Obj0205dee8 *) (base + 0x2c8 + 0xc00), 0x11);
                SetElementFieldC2_0205deb4((struct Struct_0205d81c *) (base + 0x2c8 + 0xc00), 0x11, 0);
                *(int *) (base + 0x1000 + 0xbc0) = 1;
                *(int *) (base + 0x1000 + 0xbb8) = 0x11;
                func_ov002_02161cf0(base);
            } else {
                func_ov002_02156e90(base);
            }
            *(short *) (base + 0x1b00 + 0xec) = -1;
        }
    } else if (state == 2) {
        int r = CheckAndClearEntryStatus_0215b7d0(base);
        if (r > 0) {
            *(unsigned char *) (base + 0xf80) = *(int *) (base + 0x1000 + 0xbb8);
            if (*(short *) (base + 0x1c00 + 0x26) != -1) {
                func_ov002_02157d40(base);
                return;
            }
            GameObject *p = GameState::GetInstance()->GetProtagonist();
            if (p != NULL) {
                short sel                                                        = *(signed char *) (base + 0x1c00 + 0x21);
                *(short *) (GetFieldAt0x150_02053c6c((unsigned char *) p) + 0x900 + 0x5e) = sel;
            }
            func_ov002_02157634(base);
        } else if (r < 0) {
            if (*(short *) (base + 0x1c00 + 0x26) != -1) {
                *(short *) (base + 0x1c00 + 0x28) = 0x232d;
                *(short *) (base + 0x2400 + 0x88) = 0x232b;
                *(int *) (base + 0x1000 + 0xbbc)  = 0x11;
            } else {
                *(short *) (base + 0x1c00 + 0x28) = 0x7918;
                *(short *) (base + 0x2400 + 0x88) = 0x7919;
                *(int *) (base + 0x1000 + 0xbbc)  = 5;
            }
            *(short *) (base + 0x1c00 + 0x2a)          = -1;
            *(unsigned char *) (base + 0x2000 + 0x48a) = 1;
            *(int *) (base + 0x1000 + 0xbb8)           = 0x26;
            *(int *) (base + 0x1000 + 0xbc0)           = 0;
        }
    }
}
