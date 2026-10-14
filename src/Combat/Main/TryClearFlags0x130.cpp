#include <globaldefs.h>

// USA: func_02048418
ARM int TryClearFlags0x130_02048418(unsigned char* obj, unsigned short flag) {
    int* p = *(int**)(obj + 0x130);
    if (!(flag & p[0])) {
        return 0;
    }
    p[0] = (unsigned short)(p[0] & ~flag);
    return 1;
}
