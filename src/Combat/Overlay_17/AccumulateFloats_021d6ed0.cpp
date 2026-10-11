#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_ov017_021d75b8[8];
extern float data_ov017_021d837c[8];

// USA: func_ov017_021d6ed0  (semantic: AccumulateFloats_021d6ed0)
extern "C" __declspec(initcode) ARM void __sinit_ov017_021d6ed0(void) {
#if defined(jpn)
    enum { inputIndex2 = 0, inputIndex3 = 5, inputIndex5 = 2, outputIndex1 = 2, outputIndex2 = 3, outputIndex3 = 4, outputIndex4 = 5, outputIndex5 = 1 };
#else
    enum { inputIndex2 = 2, inputIndex3 = 3, inputIndex5 = 5, outputIndex1 = 1, outputIndex2 = 2, outputIndex3 = 3, outputIndex4 = 4, outputIndex5 = 5 };
#endif
    float t;
    float a;
    float b;
    data_ov017_021d837c[outputIndex5] = data_ov017_021d75b8[4] + (data_ov017_021d75b8[inputIndex5] + (data_ov017_021d75b8[inputIndex2] + data_ov017_021d75b8[inputIndex3]));
    t = data_ov017_021d837c[outputIndex4] + data_ov017_021d75b8[inputIndex2];
    a = data_ov017_021d75b8[inputIndex3];
    data_ov017_021d837c[outputIndex3] = t;
    t = t + a;
    b = data_ov017_021d75b8[inputIndex5];
    data_ov017_021d837c[outputIndex1] = t;
    t = t + b;
    data_ov017_021d837c[outputIndex2] = t;
}
