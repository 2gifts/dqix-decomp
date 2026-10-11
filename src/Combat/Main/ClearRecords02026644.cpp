#include <globaldefs.h>
#include "System/Memory.h"

// USA: func_02026644
ARM void ClearRecords02026644(char* obj) {
    if (((unsigned char*)obj)[0x12] != 0) {
#if defined(jpn)
        obj[0x6cd] = 0;
#else
        obj[0x779] = 0;
#endif
#if defined(jpn)
        obj[0x90e] = 0;
#else
        obj[0x9ba] = 0;
#endif
    }
#if defined(jpn)
    obj[0x6d4] = 0;
#else
    obj[0x780] = 0;
#endif
#if defined(jpn)
    VectorizedMemset(obj + 0x6d8, 0, 0x230);
#else
    VectorizedMemset(obj + 0x784, 0, 0x230);
#endif
}
