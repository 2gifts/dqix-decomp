#include <globaldefs.h>

extern char data_021015a0;
extern "C" int func_0202c958(void);
void SetField0x48UnlessState9Or10_0202c848(int arg);

// USA: func_0202c918
ARM void CheckField2ThenSetState9_0202c918(unsigned short* a) {
    unsigned short v = a[1];
    if (v != 0) {
        SetField0x48UnlessState9Or10_0202c848(v);
        *(int*)(&data_021015a0 + 0x10) = 9;
        return;
    }
    if (func_0202c958() == 0) {
        *(int*)(&data_021015a0 + 0x10) = 9;
    }
}
