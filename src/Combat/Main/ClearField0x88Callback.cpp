#include <globaldefs.h>

// USA: func_020bd908
ARM void ClearField0x88Callback_020bd908(void*, void*, void* obj) {
    *(int*)((char*)obj + 0x88) = 0;
}
