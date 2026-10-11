#include <globaldefs.h>

// USA: func_020457e0  (semantic: GetFieldValue_020457e0)
extern "C" ARM int func_020457e0(char* obj) {
#if defined(jpn)
    return *(int*)(obj + 0x824);
#else
    return *(int*)(obj + 0x954);
#endif
}
