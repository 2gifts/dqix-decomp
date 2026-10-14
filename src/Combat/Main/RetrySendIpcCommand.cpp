#include <globaldefs.h>

int SendCommandToArm7(int, int, bool);

// USA: func_020c98c4
ARM void RetrySendIpcCommand_020c98c4(int arg) {
    int packed = arg << 8;
    while (SendCommandToArm7(0xc, packed, 0)) {
    }
}
