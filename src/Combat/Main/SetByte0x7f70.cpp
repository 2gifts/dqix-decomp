#include <globaldefs.h>

// USA: func_02012028
ARM void SetByte0x7f70_02012028(void* obj, unsigned char value) {
#if defined(jpn)
    ((unsigned char*)obj + 0x7000)[0xc9c] = value;
#else
    ((unsigned char*)obj + 0x7000)[0xf70] = value;
#endif
}
