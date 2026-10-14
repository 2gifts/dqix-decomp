#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_0206980c
ARM int WriteCommand0xff0a_0206980c(void** dst) {
    void* d = *dst;
    unsigned short v = 0xff0a;
    memcpy(d, &v, 2);
    return 2;
}
