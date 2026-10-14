#include <globaldefs.h>

extern "C" void func_020c9be0(void);
extern short data_02111668;

// USA: func_020c9890
#pragma optimize_for_size off
ARM void ValidateCode0x10OrHalt_020c9890(int unused, unsigned int code) {
    if ((((code & 0x7f00) << 8) >> 16) == 0x10) {
        data_02111668 = 1;
        return;
    }
    func_020c9be0();
}
