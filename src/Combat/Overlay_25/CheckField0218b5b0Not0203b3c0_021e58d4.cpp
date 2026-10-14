#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void);
struct GameResources;
int IsBrightnessTransitionActive(GameResources*);

// USA: func_ov025_021e58d4
ARM int CheckField0218b5b0Not0203b3c0_021e58d4(void) {
    return IsBrightnessTransitionActive((GameResources*)func_ov017_0218b5b0()) == 0;
}
