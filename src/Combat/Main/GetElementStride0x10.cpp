#include <globaldefs.h>

// USA: func_020999d8
ARM void* GetElementStride0x10_020999d8(unsigned char* obj, unsigned int index) {
    if (*(unsigned int*)(obj + 4) <= index) {
        return NULL;
    }
    return *(unsigned char**)obj + index * 0x10;
}
