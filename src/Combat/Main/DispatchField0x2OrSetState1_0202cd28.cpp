#include <globaldefs.h>

extern char data_021015a0;
void SetField0x48UnlessState9Or10_0202c848(int);

// USA: func_0202cd28
ARM void DispatchField0x2OrSetState1_0202cd28(unsigned short* obj) {
    if (obj[1] == 0) {
        *(int*)(&data_021015a0 + 0x10) = 1;
        return;
    }
    SetField0x48UnlessState9Or10_0202c848(obj[1]);
}
