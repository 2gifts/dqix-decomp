#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_02069de4
ARM int WriteCommand0xff2b_02069de4(void** dst) {
    void* d = *dst;
    unsigned short v = 0xff2b;
    memcpy(d, &v, 2);
    return 2;
}
