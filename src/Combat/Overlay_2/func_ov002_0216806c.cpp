#include "GameState/GameState.h"
#include <globaldefs.h>

struct Struct_0205c570;
struct Obj0205eaa0;

int GetActiveScaledSum0205d794(struct Struct_0205c570 *s);
int CheckFlagOrThreshold_02161b48(char *self, int flag);
int TestFlag0SetAndFlag1Clear(unsigned short *obj, int mask);
extern "C" int _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(void *obj, int key);
void *GetFieldAt0x150(unsigned char *p);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0 *obj, int a, int b);
void CopyPaletteEntry0215af64(char *self);
extern "C" void func_ov002_02161cf0(char *self);
extern "C" void func_ov002_02160068(char *self);
extern "C" void func_ov002_0215b9a4(char *self, unsigned char key, int flag);
extern "C" void func_ov017_0218f5a4(void *obj, int id, int b, int c, int d);
extern "C" void func_ov002_02161a8c();
extern "C" void func_020dc7e8(int a, int b);
extern "C" int *func_0202ae18();
int CheckField0NonZero(int *p);
void ForEachEntry_021d0dbc();
extern "C" void func_ov002_02156e90(char *self);
extern "C" void _Z17SetElementFieldC2P15Struct_0205d81cii(char *obj, int a, int b);

extern unsigned short data_02114e30;
extern Obj0205eaa0 data_02108760;

// USA: func_ov002_0216806c
extern "C" ARM void func_ov002_0216806c(char *self) {
    int phase = *(int *) (self + 0x1bc0);
    if (phase == 0) {
        func_ov002_02161cf0(self);
        func_ov002_02160068(self);
        func_ov002_02161cf0(self);
        CopyPaletteEntry0215af64(self);
        (*(int *) (self + 0x1bc0))++;
    } else if (phase == 1) {
        short old                  = *(short *) (self + 0x1c06);
        *(short *) (self + 0x1c06) = GetActiveScaledSum0205d794((struct Struct_0205c570 *) (self + 0xec8));
        if (old != *(short *) (self + 0x1c06)) {
            CopyPaletteEntry0215af64(self);
            func_ov002_0215b9a4(self, 0x1d, 0);
        }
        int a  = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x601);
        int b  = _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(self + 0xec8, 0x14);
        int ok = (a | b) ? 1 : 0;
        if (ok) {
            DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
            int id             = *(signed char *) (self + 0x1c20);
            GameObject *member = GameState::GetInstance()->GetPartyMemberByIndex(id);
            if (member == 0) return;
            unsigned char *f = (unsigned char *) GetFieldAt0x150((unsigned char *) member);
            if (f[0x56a] != *(short *) (self + 0x1c06) && *(short *) (f + 0x488) < 0) {
                *(short *) ((char *) member + 2) = -1;
                func_ov017_0218f5a4(func_ov017_0218b5b0(), id, 0, 0, 0);
            }
            f[0x56a] = *(short *) (self + 0x1c06);
            func_ov002_02161a8c();
            func_020dc7e8(1, -1);
            func_020dc7e8(8, -1);
            func_020dc7e8(6, -1);
            func_020dc7e8(7, -1);
            int *p = func_0202ae18();
            if (p != 0 && CheckField0NonZero(p)) {
                ForEachEntry_021d0dbc();
            }
            func_ov002_02156e90(self);
            func_ov002_02156e90(self);
            _Z17SetElementFieldC2P15Struct_0205d81cii(self + 0xec8, 0x18, 0);
            _Z17SetElementFieldC2P15Struct_0205d81cii(self + 0xec8, 0x1a, 0);
            _Z17SetElementFieldC2P15Struct_0205d81cii(self + 0xec8, 0x1b, 0);
        } else if (CheckFlagOrThreshold_02161b48(self, 1)) {
            func_ov002_02156e90(self);
            func_ov002_02156e90(self);
            _Z17SetElementFieldC2P15Struct_0205d81cii(self + 0xec8, 0x18, 0);
            _Z17SetElementFieldC2P15Struct_0205d81cii(self + 0xec8, 0x1a, 0);
            _Z17SetElementFieldC2P15Struct_0205d81cii(self + 0xec8, 0x1b, 0);
        }
    }
}
