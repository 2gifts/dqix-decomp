#include "GameState/GameState.h"
#include <globaldefs.h>

struct Struct0205de24;
struct Struct_0205c570;
struct Obj0205eaa0;
struct Obj020d7aa0;

void FindAndLinkMatchingEntry0205de24(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
int GetActiveScaledSum0205d794(struct Struct_0205c570 *s);
int CheckFlagOrThreshold_02161b48(char *self, int flag);
int TestFlag0SetAndFlag1Clear_02012444(unsigned short *obj, int mask);
struct Obj_0205da38;
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
int GetWord0x0_0200fb8c(int *p);
void *GetFieldAt0x150_02053c6c(unsigned char *p);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0 *obj, int a, int b);
int GetCountByType02157108(void *self, int type);
Obj020d7aa0 *GetGlobalResetObj020d7a50();
void TeardownAndResetState020d7aa0(Obj020d7aa0 *obj);
extern "C" void func_020d7978(char *self);
extern "C" void func_ov002_02161cf0(char *self);
extern "C" void func_ov002_0215c474(char *self);
extern "C" void func_ov002_02156e90(char *self);

extern unsigned short data_02114e30;
extern Obj0205eaa0 data_02108760;

// USA: func_ov002_02162714
extern "C" ARM void func_ov002_02162714(char *self) {
    int phase = *(int *) (self + 0x1bc0);
    if (phase == 0) {
        *(short *) (self + 0x1be4) = 0;
        FindAndLinkMatchingEntry0205de24((struct Struct0205de24 *) (self + 0xec8), 0, 2);
        func_ov002_02161cf0(self);
        func_ov002_0215c474(self);
        (*(int *) (self + 0x1bc0))++;
    } else if (phase == 1) {
        *(int *) (self + 0x247c) |= 4;
        short old = *(short *) (self + 0x1be4);
        *(short *) (self + 0x1be4) =
            GetActiveScaledSum0205d794((struct Struct_0205c570 *) (self + 0xec8));
        if (old != *(short *) (self + 0x1be4)) {
            return;
        }
        int a  = TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 0x601);
        int b  = IsActiveElementFlag2Set0205da38((struct Obj_0205da38*)(self + 0xec8), 0x14);
        int ok = (a | b) ? 1 : 0;
        if (ok) {
            int flags = *(int *) (self + 0x247c);
            if (flags & 2) return;
            if (!(flags & 0x10)) return;
            GameState *gs = GameState::GetInstance();
            GetWord0x0_0200fb8c((int *) gs);
            GameObject *prot = gs->GetProtagonist();
            if (prot != 0) {
                *(short *) ((char *) GetFieldAt0x150_02053c6c((unsigned char *) prot) + 0x95a) = *(short *) (self + 0x1be4);
            }
            switch (*(short *) (self + 0x1be4)) {
                case 0:
                    DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
                    *(int *) (self + 0x1bb8) = 4;
                    *(int *) (self + 0x1bc0) = 0;
                    break;
                case 1:
                    *(unsigned char *) (self + 0xf80) = *(int *) (self + 0x1bb8);
                    *(int *) (self + 0x247c) &= ~4;
                    DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
                    *(signed char *) (self + 0x1c20) = 5;
                    *(int *) (self + 0x1bb8)         = 10;
                    *(int *) (self + 0x1bc0)         = 0;
                    if (GetCountByType02157108(self, *(signed char *) (self + 0x1c20)) != 0) {
                        return;
                    }
                    TeardownAndResetState020d7aa0(GetGlobalResetObj020d7a50());
                    *(short *) (self + 0x1c28) = 0x2395;
                    *(short *) (self + 0x1c2a) = -1;
                    *(int *) (self + 0x1bb8)   = 0x26;
                    *(int *) (self + 0x1bbc)   = 3;
                    break;
                case 2:
                    func_020d7978(self);
                    *(int *) (self + 0x1bb8) = 0x2b;
                    *(int *) (self + 0x1bc0) = 0;
                    break;
            }
        } else if (CheckFlagOrThreshold_02161b48(self, 1)) {
            *(short *) (self + 0x1be4) = -1;
            func_ov002_02156e90(self);
        }
    }
}
