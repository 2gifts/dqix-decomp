#include <globaldefs.h>

ARM int GetField16_02222e0c(void);
ARM unsigned int GetField8Low4_02227558(void);
extern "C" int func_ov031_02236878(int index);
ARM void SetField18_02222e98(void);
extern void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_02227ce4(void);
ARM void SetField16_02222e40(int v);
ARM unsigned char GetFieldE7ByIndex_0223607c(int idx);
ARM unsigned char GetField0_02227548(void);
extern "C" void func_ov031_02237b2c(int, int, int, int, int);
extern "C" void func_ov031_02232f58(void);
extern "C" void func_ov031_02232fe8(void);
extern "C" void func_ov031_02236094(void);
extern "C" void func_ov031_02233178(void);
extern "C" void func_ov031_02232a84(void);
extern signed char data_ov031_0224910c[];

struct StateStruct1d_02232950 { unsigned char pad[0x1d]; unsigned char field1d; };
struct DataCC0_02232950 { unsigned char field0; unsigned char pad[3]; StateStruct1d_02232950 *ptr4; };
extern DataCC0_02232950 data_ov031_02290cc0;

// USA: func_ov031_02232950  (semantic: DispatchByField16AndField0_02232950)
#pragma optimize_for_size off
extern "C" ARM void func_ov031_02232950(void) {
    int f16 = GetField16_02222e0c();
    if (f16 == 0) goto handleZero;
    if (f16 == 1) goto handleOne;
    return;

handleZero:
    {
        unsigned int f8 = GetField8Low4_02227558();
        switch (f8) {
        case 0: goto setField1dAndFinal;
        case 1: goto handleF8One;
        default: goto final;
        }
    }

setField1dAndFinal:
    func_ov031_02236878(7);
    data_ov031_02290cc0.ptr4->field1d = 2;
    goto final;

handleF8One:
    SetField18_02222e98();
    SetField_022274c0_022274c0((int)func_ov031_02227ce4);
    return;

handleOne:
    {
        data_ov031_02290cc0.ptr4->field1d = 1;
        unsigned char b0 = data_ov031_02290cc0.field0;
        if (b0 < 4) goto lowField0;

        int idx = b0 - 4;
        unsigned char e = GetFieldE7ByIndex_0223607c(idx);
        if (e == 0xff) {
            func_ov031_02236878(9);
            SetField16_02222e40(-1);
            return;
        }
        func_ov031_02236878(6);
        signed char v = data_ov031_0224910c[GetField0_02227548()];
        int next = idx + 1;
        func_ov031_02237b2c(0x46, 0, 1, v, next);
        func_ov031_02232f58();
        SetField18_02222e98();
        SetField_022274c0_022274c0((int)func_ov031_02232fe8);
        return;
    }

lowField0:
    {
        unsigned char b0 = data_ov031_02290cc0.field0;
        if (b0 <= 2) {
            func_ov031_02236094();
        }
        func_ov031_02236878(6);
        func_ov031_02233178();
        goto final;
    }

final:
    SetField_022274c0_022274c0((int)func_ov031_02232a84);
}
