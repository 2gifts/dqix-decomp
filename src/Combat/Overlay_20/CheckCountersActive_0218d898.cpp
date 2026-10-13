#include <globaldefs.h>

#if defined(jpn)
enum { kCounterOffset = 0x480 };
#else
enum { kCounterOffset = 0x4f0 };
#endif


struct CounterState_0218d898 {
    char unknown0[kCounterOffset];
    int mainFadeRemaining;
    float subBrightness;
    int subBrightnessTarget;
    int subFadeRemaining;

    int IsMainFadeActive() const { return mainFadeRemaining > 0; }
    int IsSubFadeActive() const { return subFadeRemaining > 0; }
};

// USA: func_ov020_0218d898  (semantic: CheckCountersActive_0218d898)
extern "C" ARM int func_ov020_0218d898(struct CounterState_0218d898* obj) {
    return obj->IsMainFadeActive() || obj->IsSubFadeActive();
}
