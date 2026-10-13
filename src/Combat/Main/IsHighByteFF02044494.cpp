#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
extern "C" ARM int func_02069430(void* obj, unsigned short token) {
    return (token & 0xff00) == 0xff00;
}
#else
// USA: func_02044494
ARM bool IsHighByteFF02044494(void* obj, void* src) {
    unsigned short buf;
    memcpy(&buf, src, 2);
    return (buf & 0xff00) == 0xff00;
}

#endif
