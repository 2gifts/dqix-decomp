#include <globaldefs.h>

struct ContextFlags {
    unsigned short padding;
    unsigned short flags[6];
};

extern ContextFlags* data_ov031_02290d14;
extern unsigned short* data_ov031_0224bf60[6];
extern unsigned short* data_ov031_0224bf60_arg[6];

// USA: func_ov031_02239130
extern "C" ARM unsigned short func_ov031_02239130(int index) {
    ContextFlags* flags = data_ov031_02290d14;
    data_ov031_0224bf60[0] = &flags->flags[0];
    data_ov031_0224bf60[1] = &flags->flags[1];
    data_ov031_0224bf60[2] = &flags->flags[2];
    data_ov031_0224bf60[3] = &flags->flags[3];
    data_ov031_0224bf60[4] = &flags->flags[4];
    data_ov031_0224bf60[5] = &flags->flags[5];
    return *data_ov031_0224bf60_arg[index];
}
