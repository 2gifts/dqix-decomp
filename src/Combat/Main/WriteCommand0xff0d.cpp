#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_02069790
ARM int WriteCommand0xff0d_02069790(void** dst) {
    void* d = *dst;
    unsigned short v = 0xff0d;
    memcpy(d, &v, 2);
    return 2;
}
