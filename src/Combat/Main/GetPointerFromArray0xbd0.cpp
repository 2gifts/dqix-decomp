#include <globaldefs.h>

// USA: func_0207c5f8
ARM void* GetPointerFromArray0xbd0_0207c5f8(unsigned char* obj, unsigned int index) {
    if (index > 7) {
        return NULL;
    }
    return *(void**)(obj + index * 4 + 0xbd0);
}
