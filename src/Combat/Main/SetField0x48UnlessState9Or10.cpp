#include <globaldefs.h>

extern char data_021015a0;

// USA: func_0202c848
ARM void SetField0x48UnlessState9Or10_0202c848(int arg) {
    if ((unsigned)(*(int*)(&data_021015a0 + 0x10) - 9) > 1)
        *(int*)(&data_021015a0 + 0x48) = arg;
}
