#include <globaldefs.h>

struct Inner_0222bdac {
    unsigned char field_0[0x38];
    void* task;
    unsigned char field_3c[4];
    unsigned short limit;
    unsigned char field_42[0xf];
    unsigned char selectionCount;
    unsigned char field_52;
    unsigned char divisor;
    unsigned char field_54;
    unsigned char cooldown;
    unsigned char field_56;
    unsigned char active;
    unsigned char latched;
};
struct Holder_0222bdac { unsigned char field_0[2]; unsigned short position; Inner_0222bdac* inner; };
extern Holder_0222bdac data_ov031_02290c8c;
unsigned char GetField1d_022351e4();
unsigned char GetField1a_022351d0();
void SetField18_02222e98();
void ClearField18_02222e80();
extern "C" void func_ov031_022238cc();
extern "C" void func_ov031_0222c3b4();
extern "C" void func_ov031_0222c8cc();
extern "C" int func_ov031_02236878(int);
extern "C" void func_ov031_0222c71c();
extern "C" void func_ov031_0222c7d8();
void* CallWithZeroExtra_0223e218(void*, void*, void*, int);
extern "C" int FastIntDivide(int, int);
extern "C" int FastIntModulus(int, int);

// USA: func_ov031_0222bdac
extern "C" ARM void func_ov031_0222bdac() {
    if (data_ov031_02290c8c.inner->task) return;
    if (data_ov031_02290c8c.inner->cooldown) data_ov031_02290c8c.inner->cooldown--;
    switch (GetField1d_022351e4()) {
    case 1:
        data_ov031_02290c8c.inner->active = 1;
        SetField18_02222e98();
        return;
    case 2:
        if (data_ov031_02290c8c.inner->cooldown) return;
        func_ov031_022238cc();
        data_ov031_02290c8c.position = FastIntDivide(data_ov031_02290c8c.inner->limit * GetField1a_022351d0(), data_ov031_02290c8c.inner->divisor);
        func_ov031_0222c3b4();
        data_ov031_02290c8c.inner->cooldown = 4;
        return;
    case 3: {
        data_ov031_02290c8c.inner->active = 0;
        ClearField18_02222e80();
        data_ov031_02290c8c.position = FastIntDivide(data_ov031_02290c8c.inner->limit * GetField1a_022351d0(), data_ov031_02290c8c.inner->divisor);
        func_ov031_02236878(0x13);
        func_ov031_0222c3b4();
        int remainder = FastIntModulus(data_ov031_02290c8c.position, 0x1c);
        if (remainder == 0) {
            func_ov031_0222c8cc();
            return;
        }
        if (remainder < 0xe) {
            data_ov031_02290c8c.inner->task = CallWithZeroExtra_0223e218(0, (void*)func_ov031_0222c71c, 0, 0x78);
            return;
        } else {
            data_ov031_02290c8c.inner->task = CallWithZeroExtra_0223e218(0, (void*)func_ov031_0222c7d8, 0, 0x78);
        }
        return;
    }
    case 4:
        if (data_ov031_02290c8c.position == 0) {
            if (data_ov031_02290c8c.inner->latched) return;
            func_ov031_02236878(9);
            data_ov031_02290c8c.inner->latched = 1;
        } else {
            func_ov031_02236878(0x13);
            data_ov031_02290c8c.inner->task = CallWithZeroExtra_0223e218(0, (void*)func_ov031_0222c71c, 0, 0x78);
        }
        return;
    case 6:
        if (data_ov031_02290c8c.inner->selectionCount <= 4 || data_ov031_02290c8c.position == data_ov031_02290c8c.inner->limit) {
            if (data_ov031_02290c8c.inner->latched) return;
            func_ov031_02236878(9);
            data_ov031_02290c8c.inner->latched = 1;
        } else {
            func_ov031_02236878(0x13);
            data_ov031_02290c8c.inner->task = CallWithZeroExtra_0223e218(0, (void*)func_ov031_0222c7d8, 0, 0x78);
        }
        return;
    case 5:
    case 7:
        data_ov031_02290c8c.inner->latched = 0;
        return;
    }
}
