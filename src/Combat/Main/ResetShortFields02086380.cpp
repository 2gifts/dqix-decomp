#include <globaldefs.h>

#if defined(jpn)
enum { kFirstHalf = 0x8c8, kSecondHalf = 0x8ca };
#define ResetShortFields0x956 func_02086cc0
extern "C" void func_02086cc0(unsigned char* obj);
#else
enum { kFirstHalf = 0x960, kSecondHalf = 0x962 };
#endif


void ResetShortFields0x956(unsigned char* obj);

#if defined(jpn)
#define ResetShortFields02086380 func_02086ca0
extern "C" ARM void func_02086ca0(unsigned char* obj);
#endif

// USA: func_02086380
ARM void ResetShortFields02086380(unsigned char* obj) {
    ResetShortFields0x956(obj);
    *(unsigned short*)(obj + kFirstHalf) = 0;
    *(unsigned short*)(obj + kSecondHalf) = 0;
}
