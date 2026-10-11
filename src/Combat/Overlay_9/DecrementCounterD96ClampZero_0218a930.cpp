#include <globaldefs.h>
#if defined(jpn)
#define COUNTER_OFFSET 0xd5a
#else
#define COUNTER_OFFSET 0xd96
#endif

#if defined(jpn)
#define func_ov009_0218a930 func_ov009_0218b908
#endif

// USA: func_ov009_0218a930  (semantic: DecrementCounterD96ClampZero_0218a930)
extern "C" ARM int func_ov009_0218a930(char* self, int amount) {
    short v = *(short*)(self + COUNTER_OFFSET);
    if (v > amount) {
        *(short*)(self + COUNTER_OFFSET) = v - amount;
        goto ret1;
    }
    *(short*)(self + COUNTER_OFFSET) = 0;
    return 0;
ret1:
    return 1;
}
