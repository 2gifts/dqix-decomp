#include <globaldefs.h>

extern "C" void WaitByLoop(int);
int SendCommandToArm7(int, int, bool);

// USA: func_020d1294
ARM void WaitWhileChannel0xEBusy_020d1294(int a, int b) {
    if (SendCommandToArm7(0xe, a, 0) != 0) {
        do {
            WaitByLoop(b);
        } while (SendCommandToArm7(0xe, a, 0) != 0);
    }
}
