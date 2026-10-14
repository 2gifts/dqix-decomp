#include <globaldefs.h>

int SendCommandToArm7(int, int, bool);

// USA: func_020d2880
ARM void WaitUntilChannel7Ready_020d2880() {
    while (SendCommandToArm7(7, 0, 0) < 0)
        ;
}
