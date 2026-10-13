#include <globaldefs.h>

#if defined(jpn)
enum { kSubobjectOffset = 0x1804 };
#else
enum { kSubobjectOffset = 0x19e0 };
#endif

extern "C" int func_0202f24c(void*);

// USA: func_020440a4
ARM int TailForward020440a4(void* obj) {
    return func_0202f24c((char*)obj + kSubobjectOffset);
}
