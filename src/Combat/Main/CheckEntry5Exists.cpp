#include <globaldefs.h>

int SendCommandToArm7(int, int, bool);

// USA: func_020cf8bc
ARM int CheckEntry5Exists_020cf8bc(int arg) {
    return SendCommandToArm7(5, (arg << 8) & 0x7f00, 0) >= 0 ? 1 : 0;
}
