#include <globaldefs.h>
#include "System/ColorEffects.h"

#if defined(jpn)
#define func_ov023_021dac40 func_ov023_021db4b4
#endif

extern "C" void func_ov023_021dacd4(void*, int, int);

struct Obj021dac40 {
#if defined(jpn)
    char unknown0[0xd5c];
#else
    char unknown0[0xd98];
#endif
    short fadeTicksRemaining;
    char unknownAfterTimer[2];
    int flags;
};

enum { kFadeDurationTicks = 90, kMaxPolygonAlpha = 31, kMaxBrightnessAdjustment = 16 };

// USA: func_ov023_021dac40  (semantic: AdjustAngleField_021dac40)
extern "C" ARM void func_ov023_021dac40(Obj021dac40* obj, int elapsedTicks) {
    if (!(obj->flags & 0x10000)) return;
    obj->fadeTicksRemaining -= elapsedTicks;
    if (obj->fadeTicksRemaining < 0) obj->fadeTicksRemaining = 0;
    if (obj->flags & 0x800000) {
        int alphaRemaining = obj->fadeTicksRemaining * kMaxPolygonAlpha / kFadeDurationTicks;
        func_ov023_021dacd4(obj, 0, kMaxPolygonAlpha - alphaRemaining);
        return;
    }
    int brightness = -((kFadeDurationTicks - obj->fadeTicksRemaining) * kMaxBrightnessAdjustment) / kFadeDurationTicks;
    ColorEffect_ConfigureBrightnessAdjust(0x4000050, 0x16, brightness);
}
