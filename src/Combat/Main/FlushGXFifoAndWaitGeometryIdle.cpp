#include <globaldefs.h>

void WriteGXFifoZeroBurst_020c56dc(volatile void* fifo);

// USA: func_020c5354
ARM void FlushGXFifoAndWaitGeometryIdle_020c5354(void) {
    WriteGXFifoZeroBurst_020c56dc((volatile void*)0x4000400);
    while (*(volatile unsigned int*)0x4000600 & 0x8000000);
}
