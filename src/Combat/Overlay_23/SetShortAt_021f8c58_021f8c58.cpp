#include <globaldefs.h>

// USA: func_ov023_021f8c58
ARM void SetShortAt_021f8c58_021f8c58(unsigned char* obj, unsigned short value) {
    *(short*)(obj + 0x40) = value;
}
