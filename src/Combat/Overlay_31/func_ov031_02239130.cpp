#include <globaldefs.h>

extern unsigned short* data_ov031_02290d14;
extern "C" unsigned short* data_ov031_0224bf60[6];
namespace DuplicatePool {
    extern "C" unsigned short* data_ov031_0224bf60[6];
}

// USA: func_ov031_02239130
extern "C" ARM int func_ov031_02239130(int index) {
    unsigned short* base = data_ov031_02290d14;
    data_ov031_0224bf60[0] = base + 1;
    data_ov031_0224bf60[1] = base + 2;
    data_ov031_0224bf60[2] = base + 3;
    data_ov031_0224bf60[3] = base + 4;
    data_ov031_0224bf60[4] = base + 5;
    data_ov031_0224bf60[5] = base + 6;
    return *DuplicatePool::data_ov031_0224bf60[index];
}
