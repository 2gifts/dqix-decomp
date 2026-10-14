#include <globaldefs.h>

// USA: func_020968a4
ARM void GetVec3FromShorts_020968a4(unsigned char* obj, int* out) {
    out[0] = *(short*)(obj + 0x228);
    out[1] = *(short*)(obj + 0x22a);
    out[2] = *(short*)(obj + 0x22c);
}
