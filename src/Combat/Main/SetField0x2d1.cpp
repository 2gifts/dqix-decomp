#include <globaldefs.h>

#if defined(jpn)
enum { kObjectEventByteOffset = 0x2c5 };
#else
enum { kObjectEventByteOffset = 0x2d1 };
#endif

// USA: func_020546b4
ARM void SetField0x2d1_020546b4(void* obj, int value) {
    *(unsigned char*)((char*)obj + kObjectEventByteOffset) = value;
}
