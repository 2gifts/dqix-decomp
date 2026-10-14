#include <globaldefs.h>

// USA: func_02010768
ARM void* GetFieldPtrAt0x5ca4_02010768(void* obj) {
#if defined(jpn)
    return (char*)obj + 0x5a44;
#else
    return (char*)obj + 0x5ca4;
#endif
}
