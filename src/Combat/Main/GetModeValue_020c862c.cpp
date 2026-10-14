#include <globaldefs.h>

unsigned int SetData020f2284_020c7dcc();

struct MemoryRegionState {
    int initialized;
    int optionalRegionEnabled;
};
extern MemoryRegionState data_0211155c;

// USA: func_020c862c  (semantic: GetModeValue_020c862c)
extern "C" ARM unsigned int func_020c862c(unsigned int mode) {
    switch (mode) {
    case 0:
#if defined(jpn)
        return 0x022a39a0;
#else
        return 0x022a3200;
#endif
    case 2: {
        if (data_0211155c.optionalRegionEnabled == 0 || (SetData020f2284_020c7dcc() & 3) == 1) return 0;
        return 0x023e0000;
    }
    case 3:
#if defined(jpn)
        return 0x01fff2c0;
#else
        return 0x01fff280;
#endif
    case 4:
        return 0x027e0080;
    case 5:
        return 0x027ff000;
    case 6:
        return 0x037f8000;
    case 1:
    default:
        return 0;
    }
}
