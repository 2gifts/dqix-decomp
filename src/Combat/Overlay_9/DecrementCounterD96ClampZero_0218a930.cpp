#include <globaldefs.h>

#if defined(jpn)
#define func_ov009_0218a930 func_ov009_0218b908
#endif

// USA: func_ov009_0218a930  (semantic: DecrementCounterD96ClampZero_0218a930)
extern "C" ARM int func_ov009_0218a930(char* self, int amount) {
    short v = *(short*)(self + 0xd96);
    if (v > amount) {
        *(short*)(self + 0xd96) = v - amount;
        goto ret1;
    }
    *(short*)(self + 0xd96) = 0;
    return 0;
ret1:
    return 1;
}
