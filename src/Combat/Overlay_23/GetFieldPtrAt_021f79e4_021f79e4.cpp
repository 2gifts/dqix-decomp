#include <globaldefs.h>
#if defined(jpn)
#define REGION_FIELD 0x24
#else
#define REGION_FIELD 0x28
#endif

// USA: func_ov023_021f79e4
ARM void* GetFieldPtrAt_021f79e4_021f79e4(void* obj) {
    return (char*)obj + REGION_FIELD;
}
