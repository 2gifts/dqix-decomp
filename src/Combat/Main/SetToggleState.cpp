#include <globaldefs.h>

struct ToggleState;

// KEEP-NAME
// USA: func_02021410
ARM void SetToggleState(ToggleState* state, int active, int mode) {
    unsigned char* storage = (unsigned char*)state;
#if defined(jpn)
    storage[0x918] = active != 0;
    storage[0x91c] = mode;
#else
    storage[0x9c4] = active != 0;
    storage[0x9c8] = mode;
#endif
}
