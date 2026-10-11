#include <globaldefs.h>

// USA: func_02011408
ARM void ClearBitArray(void* obj) {
    char* base = (char*)obj;
    int i;
    for (i = 0; i < 10; i++) {
#if defined(jpn)
        (base + i)[0x5a70] = 0;
#else
        (base + i)[0x5cd0] = 0;
#endif
    }
}
