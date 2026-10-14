#include <globaldefs.h>

// USA: func_02053cdc
ARM int IsField0x1b4Or0x1b8Positive_02053cdc(int* obj) {
#if defined(jpn)
    return obj[0x6a] > 0 || obj[0x6b] > 0;
#else
    return obj[0x6d] > 0 || obj[0x6e] > 0;
#endif
}
