#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_020f0420[8];
extern float data_021079cc[8];

// USA: func_020e5e2c
extern "C" __declspec(initcode) ARM void __sinit_020e5e2c(void) {
#if defined(jpn)
    enum { inputIndex0 = 6, inputIndex2 = 0, inputIndex4 = 2, outputIndex0 = 3, outputIndex1 = 2, outputIndex2 = 4, outputIndex3 = 0, outputIndex4 = 1 };
#else
    enum { inputIndex0 = 0, inputIndex2 = 2, inputIndex4 = 4, outputIndex0 = 0, outputIndex1 = 1, outputIndex2 = 2, outputIndex3 = 3, outputIndex4 = 4 };
#endif
    float t;
    float a;
    float b;
    data_021079cc[outputIndex1] = data_020f0420[3] + (data_020f0420[inputIndex0] + (data_020f0420[inputIndex4] + data_020f0420[inputIndex2]));
    t = data_021079cc[outputIndex0] + data_020f0420[inputIndex4];
    a = data_020f0420[inputIndex2];
    data_021079cc[outputIndex4] = t;
    t = t + a;
    b = data_020f0420[inputIndex0];
    data_021079cc[outputIndex3] = t;
    t = t + b;
    data_021079cc[outputIndex2] = t;
}
