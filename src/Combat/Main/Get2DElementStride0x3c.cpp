#include <globaldefs.h>

// USA: func_020cf978
ARM void* Get2DElementStride0x3c_020cf978(unsigned char* obj) {
    int row = *(int*)obj;
    int col = *(int*)(obj + 4);
    return *(unsigned char**)(obj + 8) + (row * 0x3c + col) * 0x3c;
}
