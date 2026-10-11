#include "GameState/GameState.h"
#include <globaldefs.h>

struct Struct0205de24;
struct Struct_0205c570;
struct Struct_0205d81c;
struct StructA0205d5d0;
struct Obj0205eaa0;
struct Obj020d7aa0;

extern "C" int _Z37HasPositiveContainerAndField_0215edc8Ph(unsigned char *self);
extern "C" void func_ov002_02157174(char *self, int combatantId);
extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
extern "C" void func_ov002_02161cf0(char *self);
extern "C" void func_ov002_0215e900(char *self);
extern "C" void *memset(void *dst, int value, unsigned int length);
extern "C" void func_ov002_0215ece4(void *base, char *dst, int c, int productB, int clampedSum);
extern "C" char *_Z23FindElementByC40205d81cP15Struct_0205d81ci(struct Struct_0205d81c *s, int key);
extern "C" void _Z29SetOrClearByteC5Bit8_0216574cPvi(void *elem, int on);
extern "C" int _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(struct StructA0205d5d0 *, int, int, int, unsigned char);
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(struct Struct_0205c570 *s);
int TestFlag0SetAndFlag1Clear(unsigned short *pad, int buttons);
extern "C" int _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(void *obj, int flag);
extern "C" int func_0205df38(void *list, int key);
extern "C" Obj020d7aa0 *_Z25GetGlobalResetObj020d7a50v();
extern "C" void _Z29TeardownAndResetState020d7aa0P11Obj020d7aa0(Obj020d7aa0 *obj);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0 *obj, int a, int b);
extern "C" int _Z27IsFlagAt130Bit0Set_0216364cPv(void *member);
extern "C" int _Z29CheckFlagOrThreshold_02161b48Pci(char *self, int v);
extern "C" void func_ov002_02156e90(void *obj);

extern "C" unsigned short data_02114e30;
extern "C" char data_02108760;

// USA: func_ov002_02165378
extern "C" ARM void func_ov002_02165378(char *self) {
    int state = *(int *) (self + 0x1bc0);
    if (state == 0) {
        if (!_Z37HasPositiveContainerAndField_0215edc8Ph((unsigned char *) self)) {
            return;
        }
        *(short *) (self + 0x1c26) = -1;
        *(short *) (self + 0x1bf8) = 0;
        func_ov002_02157174(self, *(signed char *) (self + *(short *) (self + 0x1bf8) + 0x1c6e));
        _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((struct Struct0205de24 *) (self + 0x2c8 + 0xc00), 0, 2);
        func_ov002_02161cf0(self);
        func_ov002_0215e900(self);
        *(short *) (self + 0x1bfa)         = 0;
        *(short *) (self + 0x1bf8)         = 0;
        *(unsigned char *) (self + 0x1c20) = *(signed char *) (self + *(short *) (self + 0x1bf8) + 0x1c6e);
        memset(*(void **) (self + 0x1bd0), 0, 0x960);
        func_ov002_0215ece4(self, *(char **) (self + 0x1bd0), *(signed char *) (self + 0x1c20), 0, 8);
        int on = 0;
        if ((short) ((*(unsigned char *) (self + 0x2520) + 7) / 8) > 1) {
            on = 1;
        }
        char *e = _Z23FindElementByC40205d81cP15Struct_0205d81ci((struct Struct_0205d81c *) (self + 0x2c8 + 0xc00), 0x11);
        if (e != 0) {
            _Z29SetOrClearByteC5Bit8_0216574cPvi(e, on);
        }
        _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih((struct StructA0205d5d0 *) (self + 0x2c8 + 0xc00), 0x11,
                                                             *(int *) (self + 0x1bd0), 1, 0);
        *(int *) (self + 0x1bc0) += 1;
        return;
    }
    if (state != 1) {
        return;
    }
    *(unsigned int *) (self + 0x247c) |= 4;
    short old = *(short *) (self + 0x1bf8);
    *(short *) (self + 0x1bf8) =
        _Z26GetActiveScaledSum0205d794P15Struct_0205c570((struct Struct_0205c570 *) (self + 0x2c8 + 0xc00));
    *(unsigned char *) (self + 0x1c20) = *(signed char *) (self + *(short *) (self + 0x1bf8) + 0x1c6e);
    if (old != *(short *) (self + 0x1bf8)) {
        func_ov002_02157174(self, *(signed char *) (self + 0x1c20));
        memset(*(void **) (self + 0x1bd0), 0, 0x960);
        func_ov002_0215ece4(self, *(char **) (self + 0x1bd0), *(signed char *) (self + 0x1c20), 0, 8);
        int on = 0;
        if ((short) ((*(unsigned char *) (self + 0x2520) + 7) / 8) > 1) {
            on = 1;
        }
        char *e = _Z23FindElementByC40205d81cP15Struct_0205d81ci((struct Struct_0205d81c *) (self + 0x2c8 + 0xc00), 0x11);
        if (e != 0) {
            _Z29SetOrClearByteC5Bit8_0216574cPvi(e, on);
        }
        _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih((struct StructA0205d5d0 *) (self + 0x2c8 + 0xc00), 0x11,
                                                             *(int *) (self + 0x1bd0), 1, 0);
        return;
    }
    int t  = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x601);
    int u  = _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(self + 0x2c8 + 0xc00, 0x14);
    int ok = (t | u) ? 1 : 0;
    if (ok || func_0205df38(self + 0x2c8 + 0xc00, 0x11) != 0) {
        if (*(unsigned int *) (self + 0x247c) & 2) {
            return;
        }
        _Z29TeardownAndResetState020d7aa0P11Obj020d7aa0(_Z25GetGlobalResetObj020d7a50v());
        *(unsigned char *) (self + 0xf80) = *(int *) (self + 0x1bb8);
        *(unsigned int *) (self + 0x247c) &= ~4;
        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0 *) &data_02108760, 1, 0);
        *(int *) (self + 0x1bb8) = 0x11;
        *(int *) (self + 0x1bc0) = 0;
        if (_Z27IsFlagAt130Bit0Set_0216364cPv(
                GameState::GetInstance()->GetPartyMemberByIndex(*(signed char *) (self + 0x1c20))))
        {
            *(short *) (self + 0x1c28) = 0x2332;
            *(short *) (self + 0x1c2a) = -1;
            *(int *) (self + 0x1bb8)   = 0x26;
            *(int *) (self + 0x1bbc)   = 0x10;
            return;
        }
        if (*(unsigned char *) (self + 0x2520) != 0) {
            *(int *) (self + 0x1bb8) = 0x11;
            return;
        }
        *(short *) (self + 0x1c28) = 0x232e;
        *(short *) (self + 0x1c2a) = -1;
        *(int *) (self + 0x1bb8)   = 0x26;
        *(int *) (self + 0x1bbc)   = 0x10;
        return;
    }
    if (_Z29CheckFlagOrThreshold_02161b48Pci(self, 1)) {
        *(short *) (self + 0x1bf8)       = -1;
        *(signed char *) (self + 0x1c20) = -1;
        func_ov002_02156e90(self);
    }
}
