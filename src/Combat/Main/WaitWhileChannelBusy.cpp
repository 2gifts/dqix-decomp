#include <globaldefs.h>

extern "C" void WaitByLoop(int);
int SendCommandToArm7(int, int, bool);

// USA: func_020d1564
ARM void WaitWhileChannelBusy_020d1564(int a) {
    if (SendCommandToArm7(0xd, a, 0) != 0) {
        do {
            WaitByLoop(1);
        } while (SendCommandToArm7(0xd, a, 0) != 0);
    }
}
