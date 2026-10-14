#include <globaldefs.h>

// USA: func_020119d8
ARM void SetByte0x6480_020119d8(void* obj) {
    unsigned char* base = (unsigned char*)obj;
    (base + 0x6000)[0x480] = 1;
}
