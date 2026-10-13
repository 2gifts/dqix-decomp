#include <globaldefs.h>

extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(char *obj, unsigned char keyLow, unsigned char keyHigh);
extern "C" void func_ov002_02161cf0(char *base);
extern "C" void func_ov002_0215dae0(unsigned char *obj);
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(void *s);
extern "C" int _Z29GetFieldC54ArrayValue021573f8Pvi(void *self, int v);
extern "C" void _Z17SetElementFieldC2P15Struct_0205d81cii(void *self, int a, int b);
extern "C" void func_ov002_0215b9a4(char *self, unsigned char key, int flag);
extern "C" void _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii(void *s, int clear, int key);
extern "C" void *_Z23FindElementByC40205d81cP15Struct_0205d81ci(void *s, int key);
extern "C" int _Z25TestFlag0SetAndFlag1ClearPti(void *p, int mask);
struct Obj_0205da38;
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(void *obj, int a, int b);
extern "C" int _Z29CheckFlagOrThreshold_02161b48Pci(char *self, int flag);
extern "C" void func_ov002_02156e90(char *base);
extern "C" void _Z27SetFieldB0AndUpdate0205dee8P11Obj0205dee8i(void *obj, int val);

extern int data_02114e30;
extern int data_02108760;

// USA: func_ov002_021644a8
extern "C" ARM void func_ov002_021644a8(char *self) {
    int phase = *(int *) (self + 0x1bc0);
    if (phase == 0) {
        *(short *) (self + 0x1bf0) = 0;
        _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(self + 0xec8, 0, 2);
        func_ov002_02161cf0(self);
        func_ov002_0215dae0((unsigned char *) self);
        (*(int *) (self + 0x1bc0))++;
    } else if (phase == 1) {
        *(int *) (self + 0x247c) |= 4;
        short saved = *(short *) (self + 0x1bf0);
        *(short *) (self + 0x1bf0) = _Z26GetActiveScaledSum0205d794P15Struct_0205c570(self + 0xec8);
        *(char *) (self + 0x1c20) = _Z29GetFieldC54ArrayValue021573f8Pvi(self, *(short *) (self + 0x1bf0));
        signed char cur = *(signed char *) (self + 0x1c20);
        *(char *) (self + 0x1c21) = cur;
        _Z17SetElementFieldC2P15Struct_0205d81cii(self + 0xec8, 0xd, 1);
        if (*(short *) (self + 0x1bf0) != 0) {
            func_ov002_0215b9a4(self, 0xd, 0);
            _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii(self + 0xec8, 1, 0xd);
            unsigned char *ea = (unsigned char *) _Z23FindElementByC40205d81cP15Struct_0205d81ci(self + 0xec8, 0xb);
            unsigned char *eb = (unsigned char *) _Z23FindElementByC40205d81cP15Struct_0205d81ci(self + 0xec8, 0xd);
            if (ea != 0 && eb != 0) {
                short ac = *(short *) (ea + 0xac);
                short a8 = *(short *) (ea + 0xa8);
                *(short *) (eb + 0xac) = ac + a8;
                *(short *) (eb + 0xae) = 1;
            }
        } else {
            _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii(self + 0xec8, 0, 0xd);
        }
        if (saved != *(short *) (self + 0x1bf0)) {
            return;
        }
        int t = _Z25TestFlag0SetAndFlag1ClearPti(&data_02114e30, 0x601);
        int u = IsActiveElementFlag2Set0205da38((struct Obj_0205da38*)(self + 0xec8), 0x14);
        int hit = (t | u) != 0;
        if (hit != 0) {
            *(char *) (self + 0x1c32) = 0;
            *(char *) (self + 0xf80) = *(int *) (self + 0x1bb8);
            *(int *) (self + 0x247c) &= ~4;
            _Z17SetElementFieldC2P15Struct_0205d81cii(self + 0xec8, 0xb, 1);
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 1, 0);
            *(short *) (self + 0x1c12) = 0;
            *(short *) (self + 0x1c28) = 0x238d;
            *(short *) (self + 0x1c2a) = -1;
            *(int *) (self + 0x1bb8) = 0x26;
            *(int *) (self + 0x1bbc) = 0xb;
            *(int *) (self + 0x1bc0) = 0;
            *(char *) (self + 0x1c2e) = 1;
        } else {
            if (_Z29CheckFlagOrThreshold_02161b48Pci(self, 1) == 0) {
                return;
            }
            func_ov002_02156e90(self);
            *(short *) (self + 0x1bf0) = -1;
            *(char *) (self + 0x1c20) = -1;
            *(char *) (self + 0x1c21) = -1;
            _Z27SetFieldB0AndUpdate0205dee8P11Obj0205dee8i(self + 0x2c8 + 0xc00, (*(int *) (self + 0x1bb8) = 4));
            func_ov002_0215b9a4(self, *(int *) (self + 0x1bb8), 0);
            func_ov002_02161cf0(self);
        }
    }
}
