#include <globaldefs.h>

// USA: func_0202b828
ARM void SetField0To5AndField0x1008To1_0202b828(unsigned char* obj) {
    *(int*)(obj + 0x1008) = 1;
    *(int*)obj = 5;
}
