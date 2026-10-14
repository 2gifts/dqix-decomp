#include <globaldefs.h>

// USA: func_020c86d4
ARM void SetSharedWordDc4_020c86d4(int index, int value) {
    ((volatile int*)0x27ffdc4)[index] = value;
}
