#include <globaldefs.h>

extern "C" void func_020c6938(const void* src, volatile void* fifo);

// USA: func_020c516c
ARM void GxLoadMatrix4x4_020c516c(const void* mtx) {
    *(volatile unsigned int*)0x4000400 = 0x16;
    func_020c6938(mtx, (volatile void*)0x4000400);
}
