#include <globaldefs.h>

// USA: func_020dde98
ARM void SetField0x2Short_020dde98(void* obj, short value) {
    *(short*)((char*)obj + 0x2) = value;
}
