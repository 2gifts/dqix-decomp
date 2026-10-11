#include <globaldefs.h>

#pragma define_section initcode ".init" RX

#if defined(jpn)
extern float data_ov001_02164d14[8];
#else
extern float func_ov002_02164d14[8];
#endif
extern float data_ov001_02165880[8];

// USA: func_ov001_02164aec  (semantic: AccumulateFloats_02164aec)
extern "C" __declspec(initcode) ARM void __sinit_ov001_02164aec(void) {
#if defined(jpn)
    float *values = data_ov001_02164d14;
#else
    float *values = func_ov002_02164d14;
#endif
    float t;
    float a;
    float b;
    data_ov001_02165880[13] = values[1] + (values[0] + (values[2] + values[3]));
    t = data_ov001_02165880[0] + values[2];
    a = values[3];
    data_ov001_02165880[4] = t;
    t = t + a;
    b = values[0];
    data_ov001_02165880[12] = t;
    t = t + b;
    data_ov001_02165880[11] = t;
}
