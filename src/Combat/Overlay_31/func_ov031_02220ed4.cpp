#include <globaldefs.h>

struct Outcome02220ed4 {
    char padding_0[0x38];
    int phase;
    char padding_3c[0x78 - 0x3c];
    int result;
};
struct State02220ed4 {
    char padding[0xc];
    int active;
};
extern Outcome02220ed4 data_ov031_0224f670;
extern State02220ed4 data_ov031_0224b114;
extern "C" int func_ov031_02220af0();
extern "C" void func_ov031_0221fcb4();
extern "C" void func_ov031_02222af0();

// USA: func_ov031_02220ed4
extern "C" THUMB void func_ov031_02220ed4() {
    int result = func_ov031_02220af0();
    data_ov031_0224f670.result = result;
    func_ov031_0221fcb4();
    if (result == 1) data_ov031_0224f670.phase = 6;
    else data_ov031_0224f670.phase = 7;
    data_ov031_0224b114.active = -1;
    func_ov031_02222af0();
}
