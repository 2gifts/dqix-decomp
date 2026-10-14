#include <globaldefs.h>

// USA: func_0207f100
ARM void* GetElementStride0x18_0207f100(unsigned char* obj, short index) {
    if (index < 0) {
        return NULL;
    }
    if (*(short*)(obj + 0x4) <= index) {
        return NULL;
    }
    return *(unsigned char**)(obj + 0x0) + index * 0x18;
}
