#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
enum { layoutOffset = 0x1f0 };
#else
enum { layoutOffset = 0 };
#endif

// USA: func_ov025_021dcd5c
ARM void ResetBlockFields_021dcd5c(void* obj) {
    char* p = (char*)obj;
    p[0x6e4d + layoutOffset] = 0;
    p[0x6e4c + layoutOffset] = 0;
    memset(p + 0x6ef0 + layoutOffset, -1, 10);
    *(short*)(p + 0x6efa + layoutOffset) = 0;
}
