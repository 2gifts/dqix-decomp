#include <globaldefs.h>

// USA: func_0206b7b0
ARM void StoreClampedDeltas_0206b7b0(char* base) {
    short a = *(short*)(base + 0x914);
    short b = *(short*)(base + 0x918);
    short c = *(short*)(base + 0x148);
    short d = *(short*)(base + 0x14a);
    short e = *(short*)(base + 0x916);
    short v2 = a + b - c;
    if (v2 < 0) v2 = 0;
    short v1 = e - d;
    if (v1 < 0) v1 = 0;
    *(short*)(base + 0x144) = v2;
    *(short*)(base + 0x146) = v1;
}
