#include <globaldefs.h>

struct Sub020657c8 {
    unsigned char pad0[0x95b];
    unsigned char flagByte;
};

struct Obj020657c8 {
    unsigned char pad0[0x9a0];
    int f9a0;
    int f9a4;
    int f9a8;
    int f9ac;
    int f9b0;
    unsigned char pad1[0x1000 - 0x9b4];
    struct Sub020657c8 sub;
};

// USA: func_020657c8
extern "C" ARM int func_020657c8(struct Obj020657c8* obj, int step) {
    unsigned char flags = obj->sub.flagByte;
    int ret = 0;
    if (flags & 4) {
        if (obj->f9a0 == 0) {
            if (flags & 8) {
                obj->f9b0 = obj->f9b0 + step * 0x8444;
                if (obj->f9b0 >= 0x1f0000) {
                    obj->f9b0 = 0x1f0000;
                    obj->f9ac = 0;
                    obj->sub.flagByte &= ~8;
                    obj->sub.flagByte |= 0x10;
                }
            } else if (flags & 0x10) {
                obj->f9ac = obj->f9ac + step;
                if (obj->f9a8 <= obj->f9ac) {
                    obj->f9ac = obj->f9a8;
                    obj->sub.flagByte &= ~0x10;
                    obj->sub.flagByte |= 0x20;
                }
            } else if (flags & 0x20) {
                obj->f9b0 = obj->f9b0 - step * 0x8444;
                if (obj->f9b0 <= 0) {
                    obj->f9b0 = 0;
                    obj->sub.flagByte = obj->sub.flagByte & ~0x20;
                }
            }
            ret = 1;
        }
    }
    return ret;
}