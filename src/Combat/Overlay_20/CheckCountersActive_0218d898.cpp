#include <globaldefs.h>

#if defined(jpn)
enum { kCounterOffset = 0x480 };
#else
enum { kCounterOffset = 0x4f0 };
#endif


#if defined(jpn)
#define func_ov020_0218d898 func_ov020_0218e0e8
#endif

struct CounterState_0218d898 {
    char pad0[kCounterOffset];
    int f4f0;
    int f4f4;
    int f4f8;
    int f4fc;
};

// USA: func_ov020_0218d898  (semantic: CheckCountersActive_0218d898)
extern "C" ARM int func_ov020_0218d898(struct CounterState_0218d898* obj) {
    int cond1 = obj->f4f0 > 0;
    int cond2;
    if (cond1) {
        goto ret1;
    }
    cond2 = obj->f4fc > 0;
    if (!cond2) {
        goto ret0;
    }
ret1:
    return 1;
ret0:
    return 0;
}
