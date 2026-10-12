#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021dac40 func_ov023_021db4b4
#endif

extern "C" int _s32_div_f(int, int);
extern "C" void ColorEffect_ConfigureBrightnessAdjust(unsigned short*, int, int);
extern "C" void func_ov023_021dacd4(void*, int, int);

struct Obj021dac40 {
    char pad0[0xd00];
#if defined(jpn)
    char padd00[0x5c];
#else
    char padd00[0x98];
#endif
    short fd98;
    char padd9a[0xd9c - 0xd9a];
    int fd9c;
};

// USA: func_ov023_021dac40  (semantic: AdjustAngleField_021dac40)
extern "C" ARM void func_ov023_021dac40(Obj021dac40* obj, int delta) {
    if (!(obj->fd9c & 0x10000)) return;
    obj->fd98 = obj->fd98 - delta;
    if (obj->fd98 < 0) obj->fd98 = 0;
    if (obj->fd9c & 0x800000) {
        int q = _s32_div_f(obj->fd98 * 31, 90);
        func_ov023_021dacd4(obj, 0, 31 - q);
        return;
    }
    int q2 = _s32_div_f(-((90 - obj->fd98) * 16), 90);
    ColorEffect_ConfigureBrightnessAdjust((unsigned short*)0x4000050, 0x16, q2);
}
