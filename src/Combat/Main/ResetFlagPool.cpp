#include <globaldefs.h>

extern char data_0210f3c0;

// USA: func_020bbf18
ARM void ResetFlagPool_020bbf18(void) {
    *(int*)(&data_0210f3c0 + 0x8) = 0;
    *(int*)(&data_0210f3c0 + 0x0) = 0;
    *(int*)(&data_0210f3c0 + 0x4) = 0;
}
