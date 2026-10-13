#include <globaldefs.h>
#include "System/Interrupts.h"

struct Region0221f26c {
    unsigned int type;
    unsigned int start;
    unsigned int size;
    unsigned int field_0xc;
};
typedef void (*Callback0221f26c)();
struct Allocator0221f26c {
    unsigned int start;
    unsigned int field_0x4;
    Region0221f26c* region;
    char field_0xc[0xc];
    int state;
    void* owner;
    unsigned int workspace;
    unsigned int base;
};
extern Allocator0221f26c data_ov031_0224f620;
extern "C" int func_ov031_0220c970(unsigned int, unsigned int);
extern "C" int func_ov031_0220cae0(Region0221f26c*, Callback0221f26c);
extern "C" void func_ov031_0221ecc8();

// USA: func_ov031_0221f26c
extern "C" THUMB int func_ov031_0221f26c(void* owner, unsigned int base, unsigned int size) {
    int irq = DisableIRQInterrupts();
    Region0221f26c* region = (Region0221f26c*)((base + 0x53) & ~3u);
    data_ov031_0224f620.base = base;
    data_ov031_0224f620.region = region;
    unsigned int start = ((unsigned int)region + 0x2f) & ~31u;
    data_ov031_0224f620.start = start;
    start = (start + 0x231f) & ~31u;
    data_ov031_0224f620.workspace = start;
    start = (start + 0xdf) & ~31u;
    region->start = start;
    data_ov031_0224f620.region->size = base + size - data_ov031_0224f620.region->start;
    data_ov031_0224f620.region->field_0xc = 0;
    data_ov031_0224f620.region->type = 3;
    data_ov031_0224f620.owner = owner;
    if (data_ov031_0224f620.state == 0) {
        if (func_ov031_0220c970(data_ov031_0224f620.start, 0x2300) != 0) {
            SetIRQInterruptState(irq);
            return 0;
        }
        data_ov031_0224f620.state = 1;
    }
    if (data_ov031_0224f620.state == 1) {
        if (func_ov031_0220cae0(data_ov031_0224f620.region, func_ov031_0221ecc8) != 3) {
            SetIRQInterruptState(irq);
            return 0;
        }
        data_ov031_0224f620.state = 4;
        SetIRQInterruptState(irq);
        return 1;
    }
    SetIRQInterruptState(irq);
    return 0;
}
