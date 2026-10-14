#include <globaldefs.h>

// USA: func_ov000_0218155c
ARM int CountSetBitsLow12_0x68_ov000_0218155c(void* obj) {
    int count = 0;
    for (unsigned int i = 0; i < 12; i++) {
        if (*(unsigned int*)((char*)obj + 0x68) & (1 << i)) count++;
    }
    return count;
}
