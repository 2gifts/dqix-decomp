#include <globaldefs.h>

extern char data_021015a0;
int TryTransitionState0202d224(void);
void SetField0x48UnlessState9Or10_0202c848(int arg);

// USA: func_0202d1e4
ARM void CheckField2ThenSetState9_0202d1e4(unsigned short* a) {
    unsigned short v = a[1];
    if (v != 0) {
        SetField0x48UnlessState9Or10_0202c848(v);
        *(int*)(&data_021015a0 + 0x10) = 9;
        return;
    }
    if (TryTransitionState0202d224() == 0) {
        *(int*)(&data_021015a0 + 0x10) = 9;
    }
}
