#include <globaldefs.h>

extern "C" void func_020c6914(int cmd);

// USA: func_020c5188
ARM void IssueCommand0x17_020c5188(int cmd) {
    *(int*)0x4000400 = 0x17;
    func_020c6914(cmd);
}
