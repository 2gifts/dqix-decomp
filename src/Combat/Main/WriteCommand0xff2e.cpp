#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_02069e84
ARM int WriteCommand0xff2e_02069e84(void** dst) {
    void* d = *dst;
    unsigned short v = 0xff2e;
    memcpy(d, &v, 2);
    return 2;
}
