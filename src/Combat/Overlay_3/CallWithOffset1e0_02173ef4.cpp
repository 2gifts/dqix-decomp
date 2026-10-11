#include <globaldefs.h>

extern "C" int func_ov003_0217bdb4(void* obj);

// USA: func_ov003_02173ef4
ARM int CallWithOffset1e0_02173ef4(void* obj) {
#if defined(jpn)
    enum { fieldOffset = 0x1ec };
#else
    enum { fieldOffset = 0x1e0 };
#endif
    return func_ov003_0217bdb4((char*)obj + fieldOffset);
}
