#include <globaldefs.h>

#if defined(jpn)
enum { kByteOffset = 0x175 };
#else
enum { kByteOffset = 0x3d5 };
#endif


#if defined(jpn)
#define SetByte0x63d5 func_02011dbc
extern "C" ARM void func_02011dbc(void* obj);
#endif

// USA: func_02012040
ARM void SetByte0x63d5(void* obj) {
    unsigned char* base = (unsigned char*)obj;
    (base + 0x6000)[kByteOffset] = 1;
}
