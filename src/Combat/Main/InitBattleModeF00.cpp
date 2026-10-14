#include <globaldefs.h>

extern "C" int func_020d3df8(int, int, int);
extern void* data_021142e0[];

#pragma optimize_for_size off

// USA: func_020d3dcc
ARM int InitBattleModeF00_020d3dcc(int a, int b) {
    int r = func_020d3df8(a, b, 0xf00);
    if (r != 0) return r;
    *(short*)((char*)data_021142e0[1] + 0x16) = 0;
    return r;
}
