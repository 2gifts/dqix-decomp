#include <globaldefs.h>

// USA: func_0203db34
ARM void StoreVec3AtField0x50_0203db34(unsigned char* obj, int a, int b, int c) {
    *(int*)(obj + 0x50) = a;
    *(int*)(obj + 0x54) = b;
    *(int*)(obj + 0x58) = c;
}
