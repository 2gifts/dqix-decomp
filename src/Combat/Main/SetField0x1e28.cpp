#include <globaldefs.h>

// USA: func_02042b30
// JPN: func_0204320c
ARM void SetField0x1e28(void* obj, void* value) {
#if defined(jpn)
    *(void**)((char*)obj + 0x1c4c) = value;
#else
    *(void**)((char*)obj + 0x1e28) = value;
#endif
}
