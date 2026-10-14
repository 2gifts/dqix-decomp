#include <globaldefs.h>

extern char data_0210fd74;

// USA: func_020bce9c
ARM void Reset0210fd74State_020bce9c(void) {
    *(int*)(&data_0210fd74 + 0x0) = 0;
    *(int*)(&data_0210fd74 + 0x48) = 0;
}
