#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValue68_38 = 0x38 };
enum { kRegionValue74_44 = 0x44 };
enum { kRegionValue70_40 = 0x40 };
#else
enum { kRegionValue68_38 = 0x68 };
enum { kRegionValue74_44 = 0x74 };
enum { kRegionValue70_40 = 0x70 };
#endif


struct Obj0207fc6c;
void CallFunc0204c87cOverEntries0207fc6c(struct Obj0207fc6c* obj, int arg);

struct Obj02167494 {
    char pad0[0x10];
    void* field10;
    char pad14[kRegionValue68_38 - 0x14];
    int field68;
    int field6c;
    char pad70[kRegionValue74_44 - kRegionValue70_40];
    unsigned char field74;
};

// USA: func_ov003_02167494  (semantic: UpdateHwRegsFromCounter_02167494)
// JPN: func_ov003_02167374
extern "C" ARM void func_ov003_02167494(struct Obj02167494* obj, int arg) {
    if (obj->field74 == 0 || obj->field10 == 0) return;

    if (arg == 0) arg = 1;
    CallFunc0204c87cOverEntries0207fc6c((struct Obj0207fc6c*)obj->field10, arg);

    *(volatile int*)0x4001010 = 0;

    obj->field68 -= arg << 11;
    obj->field6c += arg << 11;

    if (obj->field68 < -0x100000) {
        obj->field68 += 0x100000;
    }
    if (obj->field6c > 0x100000) {
        obj->field6c -= 0x100000;
    }

    int mask = 0x1ff;
    int shiftedField6c = obj->field6c >> 12;
    int maskHi = mask << 16;
    int hi = maskHi & (shiftedField6c << 16);
    int lo = mask & (obj->field68 >> 12);
    *(volatile int*)0x4001014 = lo | hi;
}
