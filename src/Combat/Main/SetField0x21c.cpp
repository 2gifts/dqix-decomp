#include <globaldefs.h>

// USA: func_020a2770
ARM void SetField0x21c_020a2770(void* obj, short value) {
    *(short*)((char*)obj + 0x21c) = value;
}
