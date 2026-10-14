#include <globaldefs.h>

// KEEP-NAME
// USA: func_02026420
ARM void SetByteFieldAt0x765_02026420(unsigned char* obj, unsigned char value) {
#if defined(jpn)
    obj[0x6b9] = value;
#else
    obj[0x765] = value;
#endif
}
