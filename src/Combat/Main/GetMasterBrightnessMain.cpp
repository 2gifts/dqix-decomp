#include <globaldefs.h>

int GetSignedField020c39c8(volatile unsigned short* p);

// USA: func_020dbff4
ARM int GetMasterBrightnessMain_020dbff4() {
    return GetSignedField020c39c8((volatile unsigned short*)0x400006c);
}
