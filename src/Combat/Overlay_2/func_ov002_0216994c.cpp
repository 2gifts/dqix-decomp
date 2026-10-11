#include <globaldefs.h>

struct Struct0205de24;
struct Struct_0205c570;
struct Struct_0205d81c;
struct Obj0205eaa0;
struct StructA0205d5d0;

extern "C" int _Z31GetIndexedOffsetByte7c_0215a9f0Pv(void *self);
extern "C" char *func_0205ec34();
extern "C" short _Z22FindShortIndex0206e3e8ii(int unused, int key);
extern "C" void _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh(struct Struct0205de24 *obj, unsigned char keyLow,
                                                                        unsigned char keyHigh);
extern "C" void func_ov002_02161cf0(char *self);
extern "C" void _Z21InitBattleTag021609d4Pc(char *self);
extern "C" void func_ov002_02161b98(char *self);
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(struct Struct_0205c570 *s);
extern "C" void func_ov002_0215bba8(char *self);
int TestFlag0SetAndFlag1Clear(unsigned short *pad, int buttons);
extern "C" int _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(void *obj, int flag);
extern "C" int _Z24NextIndexOrZero_0215a9b4Pvs(void *self, short idx);
extern "C" int _Z25GetShortFromTable0206e3d4ii(int a, int b);
extern "C" char *_Z23FindElementByC40205d81cP15Struct_0205d81ci(struct Struct_0205d81c *s, int key);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0 *obj, int a, int b);
extern "C" void _Z35SetFieldByIndexedOffsetC7c_0215a9ccPvi(void *self, int idx);
extern "C" char *_Z26GetGlobalField0x1c020421a0v();
extern "C" void *memset(void *dst, int value, unsigned int length);
extern "C" void func_ov002_021607cc(void *obj, void *ptr, int flag);
extern "C" int _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(struct StructA0205d5d0 *, int, int, int, unsigned char);
extern "C" void func_ov002_02156e90(void *obj);
extern "C" int _Z29CheckFlagOrThreshold_02161b48Pci(char *self, int v);

extern "C" unsigned short data_02114e30;
extern "C" char data_02108760;

struct Fld0216994c {
    char pad[0x68];
    int f68;
};

// USA: func_ov002_0216994c
extern "C" ARM void func_ov002_0216994c(char *self) {
    int state = *(int *) (self + 0x1bc0);
    if (state == 0) {
        *(unsigned int *) (self + 0x247c) &= ~4;
        int key                    = _Z31GetIndexedOffsetByte7c_0215a9f0Pv(self);
        *(short *) (self + 0x1c0c) = _Z22FindShortIndex0206e3e8ii((int) func_0205ec34(), key) - 1;
        if (*(short *) (self + 0x1c0c) < 0) {
            *(short *) (self + 0x1c0c) = 0;
        }
        _Z32FindAndLinkMatchingEntry0205de24P14Struct0205de24hh((struct Struct0205de24 *) (self + 0x2c8 + 0xc00), 0, 3);
        func_ov002_02161cf0(self);
        _Z21InitBattleTag021609d4Pc(self);
        *(int *) (self + 0x1bc0) += 1;
        return;
    }
    if (state != 1) {
        return;
    }
    *(unsigned int *) (self + 0x247c) |= 4;
    func_ov002_02161b98(self);
    *(short *) (self + 0x1c0c) =
        _Z26GetActiveScaledSum0205d794P15Struct_0205c570((struct Struct_0205c570 *) (self + 0x2c8 + 0xc00));
    struct Fld0216994c *l = (struct Fld0216994c *) (self + 0x2c8 + 0xc00) + 1;
    l--;
    int f = l->f68;
    if (*(unsigned char *) (self + 0x2484) != f) {
        func_ov002_0215bba8(self);
    }
    int a  = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x601);
    int b  = _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(self + 0x2c8 + 0xc00, 0x14);
    int ok = (a | b) ? 1 : 0;
    if (ok) {
        int next = _Z24NextIndexOrZero_0215a9b4Pvs(self, *(short *) (self + 0x1c0c));
        int idx  = _Z25GetShortFromTable0206e3d4ii((int) func_0205ec34(), next);
        int one  = 1;
        int en   = one;
        if (idx >= 0 && *(short *) (self + 0x1c0c) != 0x1f) {
            en = 0;
            if (*(unsigned int *) (self + 0x2480) & (one << (idx - 1))) {
                en = one;
            }
        }
        if (!en) {
            return;
        }
        *(unsigned int *) (self + 0x247c) &= ~4;
        unsigned char *elem = (unsigned char *) _Z23FindElementByC40205d81cP15Struct_0205d81ci(
            (struct Struct_0205d81c *) (self + 0x2c8 + 0xc00), 0x21);
        if (elem == 0) {
            return;
        }
        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0 *) &data_02108760, 1, 0);
        _Z35SetFieldByIndexedOffsetC7c_0215a9ccPvi(self, idx);
        void *buf = *(void **) (_Z26GetGlobalField0x1c020421a0v() + 0x5c);
        memset(buf, 0, 0x960);
        func_ov002_021607cc(self, buf, (elem[0xc5] & 2) ? 1 : 0);
        _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih((struct StructA0205d5d0 *) (self + 0x2c8 + 0xc00), 0x21,
                                                             (int) buf, 1, 0);
        func_ov002_02156e90(self);
        return;
    }
    if (_Z29CheckFlagOrThreshold_02161b48Pci(self, 1)) {
        *(unsigned int *) (self + 0x247c) &= ~4;
        *(short *) (self + 0x1c0c) = 0;
        func_ov002_02156e90(self);
    }
}
