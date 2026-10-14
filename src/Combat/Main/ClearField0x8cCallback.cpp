#include <globaldefs.h>

// USA: func_020bd8f0
ARM void ClearField0x8cCallback_020bd8f0(void*, void*, void* obj) {
    *(int*)((char*)obj + 0x8c) = 0;
}
