#include <globaldefs.h>

extern char data_021015a0;

// USA: func_0202d0b4
ARM int AdvanceStateIfState2_0202d0b4(void) {
    if (*(int*)(&data_021015a0 + 0x10) != 2) return 0;
    *(short*)(&data_021015a0 + 0x4) = 0;
    *(int*)(&data_021015a0 + 0x10) = 3;
    return 1;
}
