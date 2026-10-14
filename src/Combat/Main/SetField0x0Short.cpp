#include <globaldefs.h>

// USA: func_020dde90
ARM void SetField0x0Short_020dde90(void* obj, short value) {
    *(short*)((char*)obj + 0x0) = value;
}
