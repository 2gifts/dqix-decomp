#include <globaldefs.h>

typedef union Matrix4x3 {
    int m[4][3];
    int a[12];
} Matrix4x3;
Matrix4x3 RotationMatrixX(int angle);
void IssueCommand0x19(int cmd);

// USA: func_020311f0
extern "C" ARM void func_020311f0(int angle) {
    if (angle) {
        Matrix4x3 rot;
        rot = RotationMatrixX(angle);
        IssueCommand0x19((int)&rot);
    }
}
