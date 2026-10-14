#include <globaldefs.h>

// USA: func_0207f700
ARM void* GetElementStride0x30_0207f700(unsigned char* obj, short index) {
    if (index < 0) {
        return NULL;
    }
    if (*(short*)(obj + 4) <= index) {
        return NULL;
    }
    return *(unsigned char**)obj + index * 0x30;
}
