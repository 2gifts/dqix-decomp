#include <globaldefs.h>

// USA: func_020483f0
ARM int TrySetFlags0x130_020483f0(unsigned char* obj, unsigned short flag) {
    int* p = *(int**)(obj + 0x130);
    if (flag & p[0]) {
        return 0;
    }
    p[0] = (unsigned short)(p[0] | flag);
    return 1;
}
