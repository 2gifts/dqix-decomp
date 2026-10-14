#include <globaldefs.h>

extern char data_021015a0;

// USA: func_0202d664
ARM void SetStateFromField0x2_0202d664(unsigned short* obj) {
    if (obj[1] != 0)
        *(int*)(&data_021015a0 + 0x10) = 0xa;
    else
        *(int*)(&data_021015a0 + 0x10) = 0;
}
