#include <globaldefs.h>

// USA: func_0208b4c0
ARM void SetField0xacMinusOneClearField0xb0_0208b4c0(unsigned char* obj) {
    *(int*)(obj + 0xb0) = 0;
    *(int*)(obj + 0xac) = -1;
}
