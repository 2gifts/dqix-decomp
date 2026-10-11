#if defined(jpn)
enum {regionalOffset0=0x4e0, regionalOffset1=0x4e4, regionalOffset2=0x56c, regionalOffset3=0x3d44, regionalOffset4=0x4e2};
#else
enum {regionalOffset0=0x4e4, regionalOffset1=0x4e8, regionalOffset2=0x634, regionalOffset3=0x3dcc, regionalOffset4=0x4e6};
#endif
#include <globaldefs.h>

int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
extern "C" int func_ov023_021e29d0(void* a);

extern unsigned short data_02114e30;

struct Obj021e3e98 {
    void* f0;
    char pad4[0xd4 - 4];
    char fd4[1];
    char pad4e4[regionalOffset0 - 0xd5];
    unsigned char f4e4;
    char pad4e6[1];
    unsigned char f4e6;
    unsigned char f4e7;
    char pad634[regionalOffset2 - regionalOffset1];
    unsigned short f634;
};

// JPN: func_ov023_021e40f4
// USA: func_ov023_021e3e98  (semantic: UpdateFlagsAndByte4e6_021e3e98)
extern "C" ARM void func_ov023_021e3e98(struct Obj021e3e98* obj) {
    int cond = (func_ov023_021e29d0(&obj->fd4) == 0x1f);
    if (cond) {
        obj->f634 |= 0x800;
    }

    if (obj->f0 != 0 && (*(int*)((char*)obj->f0 + regionalOffset3) & 0x400) == 0) {
        return;
    }

    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 2) != 0) {
        cond = 1;
    }
    if (!cond) {
        return;
    }

    obj->f634 |= 0x800;
    signed char tmp = *(signed char*)((char*)obj + regionalOffset4);
    obj->f4e7 = tmp;
    obj->f4e6 = 1;
    obj->f4e4 = 0;
}
