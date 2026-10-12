#include <globaldefs.h>

struct DataOv02290d18_0223a060 { void* unk0; void* field4; };
extern DataOv02290d18_0223a060 data_ov031_02290d18 __attribute__((aligned(4)));
extern "C" int func_ov031_0223a060(void);

struct ResetActionState {
    int field0;
    short field4;
    char unknown6[0x48 - 6];
    int field48;
    int field4c;
    short field50;
    short field52;
    int field54;
    char unknown58[0x12a0 - 0x58];
    int field12a0;
    int field12a4;
};

// USA: func_ov031_02239fc8
extern "C" ARM int func_ov031_02239fc8(void) {
    ((ResetActionState*)data_ov031_02290d18.field4)->field12a4 = 0;
    ((ResetActionState*)data_ov031_02290d18.field4)->field12a0 = 0;
    ((ResetActionState*)data_ov031_02290d18.field4)->field48 = 0;
    ((ResetActionState*)data_ov031_02290d18.field4)->field50 = 0;
    ((ResetActionState*)data_ov031_02290d18.field4)->field52 = 1;
    ((ResetActionState*)data_ov031_02290d18.field4)->field54 = 0;
    ((ResetActionState*)data_ov031_02290d18.field4)->field0 = 0;
    ((ResetActionState*)data_ov031_02290d18.field4)->field4 = 0;
    ((ResetActionState*)data_ov031_02290d18.field4)->field4c = 0;
    if (func_ov031_0223a060() == 0) return 0;
    return 1;
}
