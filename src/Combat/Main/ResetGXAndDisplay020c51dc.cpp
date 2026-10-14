#include <globaldefs.h>

void FlushGXFifoAndWaitGeometryIdle_020c5354(void);
void ResetMatrixStacks020c537c(void);
void ClearTwoRegionsAndFifo020c55b0(void);

// USA: func_020c51dc  (semantic: ResetGXAndDisplay020c51dc)
extern "C" ARM void func_020c51dc(void) {
    FlushGXFifoAndWaitGeometryIdle_020c5354();

    *(volatile unsigned int*)0x4000504 = 0;
    while (*(volatile unsigned int*)0x4000600 & 0x8000000) {}

    *(volatile unsigned short*)0x4000060 = 0;
    *(volatile unsigned int*)0x4000600 = 0;
    *(volatile unsigned int*)0x4000010 = 0;

    *(volatile unsigned short*)0x4000060 |= 0x2000;
    *(volatile unsigned short*)0x4000060 |= 0x1000;
    *(volatile unsigned short*)0x4000060 &= 0xffffcffd;
    *(volatile unsigned short*)0x4000060 = (*(volatile unsigned short*)0x4000060 & ~0x3000) | 0x10;
    *(volatile unsigned short*)0x4000060 &= 0xcffb;

    *(volatile unsigned int*)0x4000600 |= 0x8000;
    *(volatile unsigned int*)0x4000600 = (*(volatile unsigned int*)0x4000600 & ~0xc0000000) | 0x80000000;

    ResetMatrixStacks020c537c();

    *(volatile unsigned int*)0x4000350 = 0;
    *(volatile unsigned short*)0x4000354 = 0x7fff;
    *(volatile unsigned short*)0x4000356 = 0;
    *(volatile unsigned int*)0x4000358 = 0;
    *(volatile unsigned short*)0x400035c = 0;
    *(volatile unsigned short*)0x4000008 &= ~0x3;

    ClearTwoRegionsAndFifo020c55b0();

    *(volatile unsigned int*)0x40004a4 = 0x1f0080;
    *(volatile unsigned int*)0x40004a8 = 0;
    *(volatile unsigned int*)0x40004ac = 0;
}
