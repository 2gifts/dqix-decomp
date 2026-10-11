#include "GameState/GameState.h"
#include <globaldefs.h>

struct Struct0205de24;
struct Struct_0205c570;
struct Obj0205eaa0;
struct Obj020d7aa0;

extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(struct Struct_0205c570 *s);
extern "C" int _Z29CheckFlagOrThreshold_02161b48Pci(char *self, int flag);
int TestFlag0SetAndFlag1Clear(unsigned short *obj, int mask);
extern "C" int _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(void *obj, int key);
int GetWord0x0(int *p);
void *GetFieldAt0x150(unsigned char *p);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0 *obj, int a, int b);
extern "C" int _Z22GetCountByType02157108Pvi(void *self, int type);
extern "C" Obj020d7aa0 *_Z25GetGlobalResetObj020d7a50v();
extern "C" void _Z29TeardownAndResetState020d7aa0P11Obj020d7aa0(Obj020d7aa0 *obj);
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
        _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((struct Struct0205de24 *) (self + 0xec8), 0, 2);
        func_ov002_02161cf0(self);
        func_ov002_0215c474(self);
        (*(int *) (self + 0x1bc0))++;
    } else if (phase == 1) {
        *(int *) (self + 0x247c) |= 4;
        short old = *(short *) (self + 0x1be4);
        *(short *) (self + 0x1be4) =
            _Z26GetActiveScaledSum0205d794P15Struct_0205c570((struct Struct_0205c570 *) (self + 0xec8));
        if (old != *(short *) (self + 0x1be4)) {
            return;
        }
        int a  = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x601);
        int b  = _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(self + 0xec8, 0x14);
        int ok = (a | b) ? 1 : 0;
        if (ok) {
            int flags = *(int *) (self + 0x247c);
            if (flags & 2) return;
            if (!(flags & 0x10)) return;
            GameState *gs = GameState::GetInstance();
            GetWord0x0((int *) gs);
            GameObject *prot = gs->GetProtagonist();
            if (prot != 0) {
                *(short *) ((char *) GetFieldAt0x150((unsigned char *) prot) + 0x95a) = *(short *) (self + 0x1be4);
            }
            switch (*(short *) (self + 0x1be4)) {
                case 0:
                    _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 1, 0);
                    *(int *) (self + 0x1bb8) = 4;
                    *(int *) (self + 0x1bc0) = 0;
                    break;
                case 1:
                    *(unsigned char *) (self + 0xf80) = *(int *) (self + 0x1bb8);
                    *(int *) (self + 0x247c) &= ~4;
                    _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 1, 0);
                    *(signed char *) (self + 0x1c20) = 5;
                    *(int *) (self + 0x1bb8)         = 10;
                    *(int *) (self + 0x1bc0)         = 0;
                    if (_Z22GetCountByType02157108Pvi(self, *(signed char *) (self + 0x1c20)) != 0) {
                        return;
                    }
                    _Z29TeardownAndResetState020d7aa0P11Obj020d7aa0(_Z25GetGlobalResetObj020d7a50v());
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
        } else if (_Z29CheckFlagOrThreshold_02161b48Pci(self, 1)) {
            *(short *) (self + 0x1be4) = -1;
            func_ov002_02156e90(self);
        }
    }
}
