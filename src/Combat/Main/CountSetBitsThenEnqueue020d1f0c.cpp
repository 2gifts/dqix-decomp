#include <globaldefs.h>

extern "C" int func_020d217c(int type, int arg1, int arg2, int arg3, int arg4);
void IncrementCallbackCount_020d2960(int idx);

// USA: func_020d1f0c
extern "C" ARM int func_020d1f0c(int a0, int a1, int a2, int a3) {
    int i;
    unsigned int mask = a2;
    for (i = 0; i < 8 && mask != 0; i++, mask >>= 1) {
        if (mask & 1) {
            IncrementCallbackCount_020d2960(i);
        }
    }
    return func_020d217c(0xd, a0, a1, a2, a3);
}
