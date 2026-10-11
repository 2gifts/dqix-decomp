#include <globaldefs.h>

// USA: func_020399a8
ARM void* GetFieldPtrAt0x26c(void* obj) {
#if defined(jpn)
    return (char*)obj + 0x260;
#else
    return (char*)obj + 0x26c;
#endif
}
