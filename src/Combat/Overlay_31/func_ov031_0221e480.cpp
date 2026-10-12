#include <globaldefs.h>
#include "System/ProcessorContext.h"

struct AddressConfiguration {
    unsigned char padding[0x18];
    unsigned int address;
    unsigned int mask;
    unsigned int gateway;
};

extern AddressConfiguration data_ov031_0224b070;
extern unsigned char data_ov031_0224b078[0x58];
extern int data_ov031_0224c9d0;
extern "C" unsigned int func_ov031_0221e5d0(unsigned int);
extern "C" int func_ov031_0220764c(void*);

// USA: func_ov031_0221e480
extern "C" THUMB int func_ov031_0221e480(unsigned int address, unsigned int mask, unsigned int gateway) {
    data_ov031_0224b070.address = func_ov031_0221e5d0(address);
    data_ov031_0224b070.mask = func_ov031_0221e5d0(mask);
    data_ov031_0224b070.gateway = func_ov031_0221e5d0(gateway);
    if (func_ov031_0220764c(data_ov031_0224b078) < 0) return -1;
    if (data_ov031_0224c9d0 == 0) do {
        SleepCurrentContext(100);
    } while (data_ov031_0224c9d0 == 0);
    return 0;
}
