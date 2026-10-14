#include <globaldefs.h>

// USA: func_0201e2d8
extern "C" ARM void* _ZN12ZoneFeatures25GetOpcode64Entry_0201e2d8Ei(unsigned char* obj, int index) {
    if (index < 0 || *(int*)(obj + 4) <= index) {
        return NULL;
    }
    return *(unsigned char**)obj + index * 0x58;
}
