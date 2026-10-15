#include <globaldefs.h>

void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern int data_021052b4;
extern int data_021056b4;

// USA: func_0203bd88
ARM void CleanInvalidateOamBuffers0203bd88(void*) {
    CleanInvalidateCacheRange((const void*)((int)&data_021052b4), 0x400);
    CleanInvalidateCacheRange((const void*)((int)&data_021056b4), 0x400);
}
