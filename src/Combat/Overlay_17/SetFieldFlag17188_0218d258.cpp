#include <globaldefs.h>

// USA: func_ov017_0218d258
ARM void SetFieldFlag17188_0218d258(void* obj) {
    #if defined(jpn)
    *(int*)((char*)obj + 0x4104) = 1;
#else
    *(int*)((char*)obj + 0x4324) = 1;
#endif
}
