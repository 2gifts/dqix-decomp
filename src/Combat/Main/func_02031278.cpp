#include <globaldefs.h>

typedef union Matrix4x3 {
    int m[4][3];
    int a[12];
} Matrix4x3;
Matrix4x3 RotationMatrixZ(int angle);
void IssueCommand0x19(int cmd);

// USA: func_02031278
extern "C" ARM void func_02031278(void* p) {
    Matrix4x3 rot;
    if (p == NULL) return;
    rot = RotationMatrixZ((int)p);
    IssueCommand0x19((int)&rot);
}
