#include <globaldefs.h>

#if defined(jpn)
enum { MEMBER_OFFSET = 0x1a4 };
#else
enum { MEMBER_OFFSET = 0x1b0 };
#endif

#if defined(jpn)
#define GetField0x1b0 func_020552ec
extern "C" ARM unsigned char func_020552ec(void* obj);
#endif

// USA: func_02053f74
ARM unsigned char GetField0x1b0(void* obj) {
    return *(unsigned char*)((char*)obj + MEMBER_OFFSET);
}
