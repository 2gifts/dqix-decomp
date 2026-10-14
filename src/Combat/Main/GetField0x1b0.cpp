#include <globaldefs.h>

#if defined(jpn)
enum { MEMBER_OFFSET = 0x1a4 };
#else
enum { MEMBER_OFFSET = 0x1b0 };
#endif

// USA: func_02053f74
ARM unsigned char GetField0x1b0_02053f74(void* obj) {
    return *(unsigned char*)((char*)obj + MEMBER_OFFSET);
}
