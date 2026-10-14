#include "GameState/GameState.h"
#include <globaldefs.h>

struct Struct0205de24;
struct Struct_0205c570;
struct Struct_0205d81c;
struct Struct_0205def8;
struct Obj0205eaa0;
struct Obj020d7aa0;

int GetWord0x0(int *p);
extern "C" void func_02012fe4(void);
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
extern "C" void func_ov002_02161cf0(char *self);
extern "C" void func_ov002_0215f3a0(void *base);
void SetElementFlag0x20ByKey0205def8(struct Struct_0205def8 *s, int clear, int key);
void SetElementFieldC2(struct Struct_0205d81c *s, int key, int value);
int GetActiveScaledSum0205d794(struct Struct_0205c570 *s);
char *FindElementByC40205d81c(struct Struct_0205d81c *s, int key);
int IsElementFlagBit40Set_0216197c(int key, struct Struct_0205d81c *s);
extern "C" void func_ov002_0215b9a4(void *self, int mode, int flag);
int TestFlag0SetAndFlag1Clear(unsigned short *pad, int buttons);
struct Obj_0205da38;
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
Obj020d7aa0 *GetGlobalResetObj020d7a50();
void TeardownAndResetState020d7aa0(Obj020d7aa0 *obj);
extern "C" void func_ov002_02156080(void *self, short *out, short *outCount);
extern "C" int func_ov002_02161920(void *self);
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0 *obj, int a, int b);
void InitNodeAndInsertAt_021c1798_021c1798(GameResources *res, unsigned char v);
void SetPendingFlagAndSync_0215a878(char *self);
int GetField0x3acValue(GameState *gs);
extern "C" void func_ov017_021bff8c(int a, int b);
int CheckFlagOrThreshold_02161b48(char *self, int v);
extern "C" void func_ov002_02156e90(void *obj);

extern "C" unsigned short data_02114e30;
extern "C" char data_02108760;

#define OBJ (self + 0x2c8 + 0xc00)

// USA: func_ov002_02166168
extern "C" ARM void func_ov002_02166168(char *self) {
    GameState *gs      = GameState::GetInstance();
    GameResources *res = (GameResources *) GetWord0x0((int *) gs);
    func_02012fe4();
    int state = *(int *) (self + 0x1bc0);
    if (state == 0) {
        *(short *) (self + 0x1bfe) = 0;
        FindAndLinkMatchingEntry0205de24((struct Struct0205de24 *) OBJ, 0, 2);
        func_ov002_02161cf0(self);
        func_ov002_0215f3a0(self);
        *(int *) (self + 0x1bc0) += 1;
    } else if (state == 1) {
        *(unsigned int *) (self + 0x247c) |= 4;
        SetElementFlag0x20ByKey0205def8((struct Struct_0205def8 *) OBJ, 1, 0x29);
        SetElementFlag0x20ByKey0205def8((struct Struct_0205def8 *) OBJ, 1, 1);
        SetElementFieldC2((struct Struct_0205d81c *) OBJ, 0x15, 0);
        short old                  = *(short *) (self + 0x1bfe);
        *(short *) (self + 0x1bfe) = GetActiveScaledSum0205d794((struct Struct_0205c570 *) OBJ);
        char *e                    = FindElementByC40205d81c((struct Struct_0205d81c *) OBJ, 0x16);
        if (e != 0) {
            *(short *) (e + 0xc2) = 0;
        }
        if (IsElementFlagBit40Set_0216197c(*(int *) (self + 0x1bb8) & 0xff,
                                                                  (struct Struct_0205d81c *) OBJ))
        {
            func_ov002_0215b9a4(self, *(int *) (self + 0x1bb8) & 0xff, 0);
        }
        if (old != *(short *) (self + 0x1bfe)) {
            func_ov002_0215b9a4(self, 0x16, 0);
        }
        int t  = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x601);
        int u  = IsActiveElementFlag2Set0205da38((struct Obj_0205da38*)OBJ, 0x14);
        int ok = (t | u) ? 1 : 0;
        if (ok) {
            unsigned int f = *(unsigned int *) (self + 0x247c);
            if (f & 2) {
                return;
            }
            if (!(f & 0x20)) {
                return;
            }
            TeardownAndResetState020d7aa0(GetGlobalResetObj020d7a50());
            short count = 0;
            short list[9];
            func_ov002_02156080(self, list, &count);
            func_ov002_02161920(self);
            switch (list[*(short *) (self + 0x1bfe)]) {
                case 0:
                    DispatchWithShortB4_0205eaa0((struct Obj0205eaa0 *) &data_02108760, 1, 0);
                    *(unsigned char *) (self + 0xf80) = *(int *) (self + 0x1bb8);
                    *(unsigned int *) (self + 0x247c) &= ~4;
                    *(int *) (self + 0x1bb8) = 0x17;
                    *(int *) (self + 0x1bc0) = 0;
                    break;
                case 1:
                    DispatchWithShortB4_0205eaa0((struct Obj0205eaa0 *) &data_02108760, 1, 0);
                    *(int *) (self + 0x1bb8) = 0x18;
                    *(int *) (self + 0x1bc0) = 0;
                    break;
                case 2:
                    DispatchWithShortB4_0205eaa0((struct Obj0205eaa0 *) &data_02108760, 1, 0);
                    *(unsigned char *) (self + 0xf80) = *(int *) (self + 0x1bb8);
                    *(unsigned int *) (self + 0x247c) &= ~4;
                    *(int *) (self + 0x1bb8) = 0x1f;
                    *(int *) (self + 0x1bc0) = 0;
                    break;
                case 3:
                    DispatchWithShortB4_0205eaa0((struct Obj0205eaa0 *) &data_02108760, 1, 0);
                    *(int *) (self + 0x1bb8) = 0x21;
                    *(int *) (self + 0x1bc0) = 0;
                    break;
                case 4:
                    DispatchWithShortB4_0205eaa0((struct Obj0205eaa0 *) &data_02108760, 1, 0);
                    InitNodeAndInsertAt_021c1798_021c1798(res, 1);
                    SetPendingFlagAndSync_0215a878(self);
                    *(int *) (self + 0x1bb8) = 0x2b;
                    *(int *) (self + 0x1bc0) = 0;
                    break;
                case 5:
                    DispatchWithShortB4_0205eaa0((struct Obj0205eaa0 *) &data_02108760, 1, 0);
                    *(int *) (self + 0x1bb8) = 0x23;
                    *(int *) (self + 0x1bc0) = 0;
                    break;
                case 7:
                    DispatchWithShortB4_0205eaa0((struct Obj0205eaa0 *) &data_02108760, 1, 0);
                    *(int *) (self + 0x1bb8) = 0x24;
                    *(int *) (self + 0x1bc0) = 0;
                    break;
                case 8: {
                    DispatchWithShortB4_0205eaa0((struct Obj0205eaa0 *) &data_02108760, 1, 0);
                    int id = (signed char) GetField0x3acValue(gs);
                    for (int i = 0; i < *(int *) (self + 0x1c50); i++) {
                        char *c = (char *) GetCombatantWithFlag0x100(gs, *(int *) (self + i * 4 + 0x1c54));
                        if (c != 0 && !(**(int **) (c + 0x130) & 1)) {
                            id = (signed char) ((int *) (self + 0x1c54))[i];
                            break;
                        }
                    }
                    func_ov017_021bff8c((int) res, id);
                    *(int *) (self + 0x1bb8) = 0x2b;
                    *(int *) (self + 0x1bc0) = 0;
                    break;
                }
            }
        } else if (CheckFlagOrThreshold_02161b48(self, 1)) {
            *(short *) (self + 0x1bfe) = -1;
            func_ov002_02156e90(self);
        }
    }
}
