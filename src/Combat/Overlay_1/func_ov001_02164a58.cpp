#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern float data_ov001_02164ba0[4];
extern float data_ov001_0216580c[7];

struct Obj021d49d0;
Obj021d49d0* SetupObj_021d49d0(Obj021d49d0* obj);
extern Obj021d49d0 data_ov001_02165828;

// USA: func_ov001_02164a58
extern "C" __declspec(initcode) ARM void __sinit_ov001_02164a58(void) {
    float t1 = data_ov001_02164ba0[0] + data_ov001_02164ba0[3];
    float t2 = data_ov001_02164ba0[2] + t1;
    float t3 = data_ov001_02164ba0[1] + t2;
    data_ov001_0216580c[6] = t3;
    float t4 = data_ov001_0216580c[5] + data_ov001_02164ba0[0];
    float bc = data_ov001_02164ba0[3];
    data_ov001_0216580c[4] = t4;
    float t5 = t4 + bc;
    float b8 = data_ov001_02164ba0[2];
    data_ov001_0216580c[3] = t5;
    float t6 = t5 + b8;
    data_ov001_0216580c[2] = t6;
    SetupObj_021d49d0(&data_ov001_02165828);
}
