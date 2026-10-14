#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_02069b84
ARM int WriteCommand0xff08_02069b84(void** dst) {
    void* d = *dst;
    unsigned short v = 0xff08;
    memcpy(d, &v, 2);
    return 2;
}
