#include <globaldefs.h>

// USA: func_02042b10
ARM void SetField0x1e20_02042b10(void* obj, void* value) {
#if defined(jpn)
    *(void**)((char*)obj + 0x1c44) = value;
#else
    *(void**)((char*)obj + 0x1e20) = value;
#endif
}
