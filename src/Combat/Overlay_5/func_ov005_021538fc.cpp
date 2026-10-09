#include <globaldefs.h>
#include <Graphics/Vector.h>

static inline fix32_t FxMul(fix32_t a, fix32_t b) {
    long long product = (long long)a * b;
    return (fix32_t)((product + 0x800) >> 12);
}

// USA: func_ov005_021538fc
extern "C" ARM void func_ov005_021538fc(void* self, fix32_t* target, fix32_t* value, fix32_t rate, fix32_t threshold) {
    fix32_t delta = *target - *value;
    if (fix32abs(delta) < threshold) {
        *value = *target;
        return;
    }
    *value += FxMul(delta, rate);
}
