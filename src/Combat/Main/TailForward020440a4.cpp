#include <globaldefs.h>

#if defined(jpn)
enum { kSubobjectOffset = 0x1804 };
#else
enum { kSubobjectOffset = 0x19e0 };
#endif


extern "C" int func_0202f24c(void*);

#if defined(jpn)
#define TailForward020440a4 func_0204486c
extern "C" ARM int func_0204486c(void* obj);
#endif

// USA: func_020440a4
ARM int TailForward020440a4(void* obj) {
    return func_0202f24c((char*)obj + kSubobjectOffset);
}
