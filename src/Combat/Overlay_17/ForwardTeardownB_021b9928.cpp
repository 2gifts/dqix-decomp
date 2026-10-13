#include <globaldefs.h>

#if defined(jpn)
#define func_ov008_02184968 func_ov008_02185a64
#endif
extern "C" void func_ov008_02184968(void* a);
#if defined(jpn)
#define BlankFunction0208be90 func_0208c768
extern "C" void BlankFunction0208be90(void*);
#else
void BlankFunction0208be90(void*);
#endif

struct EmbeddedTeardownState {
    unsigned char unknown0[0x30];
    unsigned char embeddedState[0xe8];
    void* overlayState;
};

// USA: func_ov017_021b9928
ARM void ForwardTeardownB_021b9928(char* context) {
    EmbeddedTeardownState* state = (EmbeddedTeardownState*)context;
	if (state->overlayState != NULL) func_ov008_02184968(state->overlayState);
	BlankFunction0208be90(state->embeddedState);
}
