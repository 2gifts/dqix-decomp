#include <globaldefs.h>

struct Mtx43_02030d84 { unsigned int v[12]; };
extern "C" struct Mtx43_02030d84 _Z15RotationMatrixYi(int angle);
extern "C" void _Z16IssueCommand0x19i(int cmd);

// USA: func_02031234
extern "C" ARM void func_02031234(int angle) {
    struct Mtx43_02030d84 mtx;

    if (angle == 0) {
        return;
    }

    mtx = _Z15RotationMatrixYi(angle);
    _Z16IssueCommand0x19i((int)&mtx);
}
