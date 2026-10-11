#include <globaldefs.h>

struct Mtx43_02030d84 { unsigned int v[12]; };
extern "C" void _Z15RotationMatrixYi(struct Mtx43_02030d84* dst, int angle);
extern "C" void _Z16IssueCommand0x19i(int cmd);

// USA: func_02031234
extern "C" ARM void func_02031234(int angle) {
    struct Mtx43_02030d84 mtxCopy;
    struct Mtx43_02030d84 mtx;

    if (angle == 0) {
        return;
    }

    _Z15RotationMatrixYi(&mtx, angle);
    mtxCopy = mtx;
    _Z16IssueCommand0x19i((int)&mtxCopy);
}
