#include <globaldefs.h>

int SendCommandToArm7(int a, int b, bool c);

// USA: func_020ce870
ARM void RetryHelperUntilZero_020ce870(int arg) {
    while (SendCommandToArm7(8, arg, 0) != 0) {}
}
