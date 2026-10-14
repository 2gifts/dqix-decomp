#include <globaldefs.h>

extern "C" void func_020ca528(int cmd);

// USA: func_020c51c0
ARM void IssueCommand0x1A_020c51c0(int cmd) {
    *(int*)0x4000400 = 0x1a;
    func_020ca528(cmd);
}
