#include <globaldefs.h>

extern void* data_020fb3cc;

// USA: func_02012bbc
ARM void ClearByte0x62IfArg0x10_02012bbc(int arg) {
    if (arg == 0x10) {
        *((char*)data_020fb3cc + 0x62) = 0;
    }
}
