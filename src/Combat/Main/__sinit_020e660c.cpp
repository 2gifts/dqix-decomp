#include <globaldefs.h>

#pragma define_section initcode ".init" RX

struct Data020f1bbc {
    float f00;
    float f04;
    float f08;
    float f0c;
    int i10;
    int i14;
};

extern struct Data020f1bbc data_020f1bbc;
extern float data_02109fe8[5];

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020e660c
extern "C" __declspec(initcode) ARM void __sinit_020e660c(void) {
    float t;
    float a;
    data_020f1bbc.i10 = data_020f1bbc.i14 + 11;
    data_02109fe8[4] = data_020f1bbc.f00 + (data_020f1bbc.f04 + (data_020f1bbc.f0c + data_020f1bbc.f08));
    t = data_02109fe8[0] + data_020f1bbc.f0c;
    a = data_020f1bbc.f08;
    data_02109fe8[3] = t;
    t = t + a;
    data_02109fe8[2] = t;
    t = t + data_020f1bbc.f04;
    data_02109fe8[1] = t;
}