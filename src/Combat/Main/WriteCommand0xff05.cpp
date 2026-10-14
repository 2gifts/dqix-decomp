#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_02069b0c
ARM int WriteCommand0xff05_02069b0c(void** dst) {
    void* d = *dst;
    unsigned short v = 0xff05;
    memcpy(d, &v, 2);
    return 2;
}
