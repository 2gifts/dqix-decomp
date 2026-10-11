#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif


struct Sub020657c8 {
    unsigned char pad0[IS_JPN ? 0x789 : 0x95b];
    unsigned char flagByte;
};

struct Obj020657c8 {
    unsigned char pad0[IS_JPN ? 0x870 : 0x9a0];
    int f9a0;
    int f9a4;
    int f9a8;
    int f9ac;
    int f9b0;
    unsigned char pad1[0x1000 - (IS_JPN ? 0x884 : 0x9b4)];
    struct Sub020657c8 sub;
};

// USA: func_020657c8
extern "C" ARM int func_020657c8(struct Obj020657c8* obj, int step) {
    unsigned char flags = obj->sub.flagByte;
    int ret = 0;
    if (flags & 4) {
        if (obj->f9a0 == 0) {
            if (flags & 8) {
                obj->f9b0 = obj->f9b0 + (IS_JPN ? 1 : step) * 0x8444;
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
                #if defined(jpn)
                step = obj->f9b0 - 0x44;
                step -= 0x8400;
                obj->f9b0 = step;
#else
                obj->f9b0 = obj->f9b0 - step * 0x8444;
#endif
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