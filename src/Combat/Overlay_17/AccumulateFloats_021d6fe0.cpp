#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_ov017_021d79c0[8];
extern "C" float _ZZ19GetTransferProgressvE1s[8];

// USA: func_ov017_021d6fe0  (semantic: AccumulateFloats_021d6fe0)
extern "C" __declspec(initcode) ARM void __sinit_ov017_021d6fe0(void) {
    float t;
    float a;
    float b;
    _ZZ19GetTransferProgressvE1s[5] = data_ov017_021d79c0[1] + (data_ov017_021d79c0[2] + (data_ov017_021d79c0[0] + data_ov017_021d79c0[3]));
    t = _ZZ19GetTransferProgressvE1s[4] + data_ov017_021d79c0[0];
    a = data_ov017_021d79c0[3];
    _ZZ19GetTransferProgressvE1s[3] = t;
    t = t + a;
    b = data_ov017_021d79c0[2];
    _ZZ19GetTransferProgressvE1s[2] = t;
    t = t + b;
    _ZZ19GetTransferProgressvE1s[1] = t;
}
