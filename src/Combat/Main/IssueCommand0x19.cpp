#include <globaldefs.h>

extern "C" void func_020c6914(int cmd);

// USA: func_020c51a4
ARM void IssueCommand0x19_020c51a4(int cmd) {
    *(int*)0x4000400 = 0x19;
    func_020c6914(cmd);
}
