#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
enum { layoutOffset = 0x1f0 };
#else
enum { layoutOffset = 0 };
#endif

// USA: func_ov025_021dcd98
ARM void ResetFields021dcd98(char* obj) {
    obj[0x6f00 + layoutOffset] = 0;
    obj[0x6eff + layoutOffset] = 0;
    memset(obj + 0x6fba + layoutOffset, -1, 8);
    *(short*)(obj + 0x6fc2 + layoutOffset) = 0;
    *(int*)(obj + 0x6fc4 + layoutOffset) = 0;
    *(int*)(obj + 0x6fc8 + layoutOffset) = 0;
    *(int*)(obj + 0x6fcc + layoutOffset) = 0;
    *(int*)(obj + 0x6fd0 + layoutOffset) = 0;
}
