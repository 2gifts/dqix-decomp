#include <globaldefs.h>
#include "System/Matrix.h"

Matrix4x3 RotationMatrixX(int angle);
void IssueCommand0x19_020c51a4(int cmd);

// USA: func_020311f0
extern "C" ARM void func_020311f0(int angle) {
    if (angle) {
        Matrix4x3 rot;
        rot = RotationMatrixX(angle);
        IssueCommand0x19_020c51a4((int)&rot);
    }
}
