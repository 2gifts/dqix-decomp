#include <globaldefs.h>

struct GameResources;

unsigned int IsBrightnessTransitionActive(GameResources*);
extern "C" unsigned int func_ov011_02184c68(unsigned int, unsigned int);
extern "C" GameResources* func_ov017_0218b5b0();

// USA: func_ov011_02186e30  (semantic: Trans_02186e30)
extern "C" ARM unsigned int func_ov011_02186e30(unsigned int arg0) {
    func_ov011_02184c68(arg0, IsBrightnessTransitionActive(func_ov017_0218b5b0()));
    return 1;
}
