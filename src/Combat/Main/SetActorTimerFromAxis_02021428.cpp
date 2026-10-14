#include <globaldefs.h>

extern "C" int func_ov017_0218b5b0(void);
struct AxisFloats0203b57c;
int GetAxisIntValue(struct AxisFloats0203b57c* s, int axis);
struct GameResources;
void SetSubBrightness(GameResources*, int, int);
extern "C" int abs(int x);
extern "C" int _s32_div_f(int a, int b);

// USA: func_02021428  (semantic: SetActorTimerFromAxis_02021428)
extern "C" ARM void func_02021428(void* unused0, int amount) {
    int t = func_ov017_0218b5b0();
    int v = GetAxisIntValue((struct AxisFloats0203b57c*)t, 1);
    if (v - 1 <= -16) {
        SetSubBrightness((GameResources*)t, -16, 0);
        return;
    }
    if (v + 1 >= 0x10) {
        SetSubBrightness((GameResources*)t, 0x10, 0);
        return;
    }
    if (v > 0) {
        if (v < 0) v = 0;
        if (v != 0) {
            amount = _s32_div_f(amount, abs(v));
        }
        SetSubBrightness((GameResources*)t, 0x10, amount);
    } else {
        if (v > 0) v = 0;
        if (v != 0) {
            amount = _s32_div_f(amount, abs(v));
        }
        SetSubBrightness((GameResources*)t, -16, amount);
    }
}
