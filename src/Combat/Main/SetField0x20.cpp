#include <globaldefs.h>

// USA: func_020ddff4
ARM void SetField0x20_020ddff4(void* obj, int value) {
    *(int*)((char*)obj + 0x20) = value;
}
