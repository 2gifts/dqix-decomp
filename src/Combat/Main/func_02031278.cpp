#include <globaldefs.h>
#include <System/Matrix.h>

Matrix4x3 RotationMatrixZ(int angle);
void IssueCommand0x19_020c51a4(int cmd);

// USA: func_02031278
extern "C" ARM void func_02031278(void* p) {
    Matrix4x3 rot;
    if (p == NULL) return;
    rot = RotationMatrixZ((int)p);
    IssueCommand0x19_020c51a4((int)&rot);
}
