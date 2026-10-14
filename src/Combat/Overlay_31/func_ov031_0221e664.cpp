#include <globaldefs.h>

extern "C" void func_ov031_0221e52c(void* destination, int value, int length);
int RegisterSlotB020cf1a8(int output);

struct RandomState0221e664 {
    char padding0[8];
    int initialized;
    char paddingc[12];
    unsigned int seed;
    unsigned int multiplier;
    unsigned int increment;
};

extern RandomState0221e664 data_ov031_0224e6e0;

// USA: func_ov031_0221e664
extern "C" THUMB unsigned short func_ov031_0221e664() {
    if (data_ov031_0224e6e0.initialized == 0) {
        int seed = 0;
        int time[3];
        func_ov031_0221e52c(time, 0, 12);
        if (RegisterSlotB020cf1a8((int)time) == 0) {
            seed += time[0] << 10;
            seed += time[1] << 3;
            seed += time[2];
        }
        data_ov031_0224e6e0.seed = seed;
        data_ov031_0224e6e0.multiplier = 0x5d588b65;
        data_ov031_0224e6e0.increment = 0x269ec3;
        data_ov031_0224e6e0.initialized = 1;
    }
    data_ov031_0224e6e0.seed = data_ov031_0224e6e0.multiplier * data_ov031_0224e6e0.seed + data_ov031_0224e6e0.increment;
    return ((data_ov031_0224e6e0.seed >> 16) * 0x7fff) >> 16;
}
