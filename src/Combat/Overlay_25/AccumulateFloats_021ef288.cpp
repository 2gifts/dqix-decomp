#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_ov025_021ef464[8];
extern float data_ov025_021ef988[8];

// USA: func_ov025_021ef288  (semantic: AccumulateFloats_021ef288)
extern "C" __declspec(initcode) ARM void __sinit_ov025_021ef288(void) {
#if defined(jpn)
    enum { inputIndex2 = 3, inputIndex3 = 2, outputIndex0 = 2, outputIndex5 = 6, outputIndex6 = 4, outputIndex1 = 7, outputIndex4 = 0 };
#else
    enum { inputIndex2 = 2, inputIndex3 = 3, outputIndex0 = 0, outputIndex5 = 5, outputIndex6 = 6, outputIndex1 = 1, outputIndex4 = 4 };
#endif
    float t;
    float a;
    float b;
    data_ov025_021ef988[outputIndex0] = data_ov025_021ef464[1] + (data_ov025_021ef464[inputIndex3] + (data_ov025_021ef464[inputIndex2] + data_ov025_021ef464[4]));
    t = data_ov025_021ef988[outputIndex5] + data_ov025_021ef464[inputIndex2];
    a = data_ov025_021ef464[4];
    data_ov025_021ef988[outputIndex6] = t;
    t = t + a;
    b = data_ov025_021ef464[inputIndex3];
    data_ov025_021ef988[outputIndex1] = t;
    t = t + b;
    data_ov025_021ef988[outputIndex4] = t;
}
