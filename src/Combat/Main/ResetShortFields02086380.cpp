#include <globaldefs.h>

#if defined(jpn)
enum { kFirstHalf = 0x8c8, kSecondHalf = 0x8ca };
#else
enum { kFirstHalf = 0x960, kSecondHalf = 0x962 };
#endif

void ResetShortFields0x956(unsigned char* obj);

// USA: func_02086380
ARM void ResetShortFields02086380(unsigned char* obj) {
    ResetShortFields0x956(obj);
    *(unsigned short*)(obj + kFirstHalf) = 0;
    *(unsigned short*)(obj + kSecondHalf) = 0;
}
