#include <globaldefs.h>

struct Mtx43_02030d84 { unsigned int v[12]; };
struct Mtx43_02030d84 RotationMatrixY(int angle);
void IssueCommand0x19_020c51a4(int cmd);

// USA: func_02031234
extern "C" ARM void func_02031234(int angle) {
    struct Mtx43_02030d84 mtx;

    if (angle == 0) {
        return;
    }

    mtx = RotationMatrixY(angle);
    IssueCommand0x19_020c51a4((int)&mtx);
}
