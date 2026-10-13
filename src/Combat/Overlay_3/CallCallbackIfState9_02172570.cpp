#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0();
int GetField24ThenCall_021b2074(void* obj, void* extra);

// USA: func_ov003_02172570  (semantic: CallCallbackIfState9_02172570)
extern "C" ARM int func_ov003_02172570(unsigned char* obj, void* extra) {
    if (*obj != 9) {
        return 0;
    }
    char* base = (char*)func_ov017_0218b5b0();
    GetField24ThenCall_021b2074(*(void**)(base + 0x3b48), extra);
    return 1;
}
