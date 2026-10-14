#include <globaldefs.h>

// USA: func_02084fc8
ARM float AccumulateSlotBits20To29AsTenths_02084fc8(char* base) {
    float sum = 0.0f;
    int i;
    for (i = 0; i < 11; i++) {
        char* e = base + i * 0x20;
        if (*(short*)(e + 0x1ac) > 0) {
            unsigned int* p = *(unsigned int**)(e + 0x194);
            unsigned int bits = (p[2] << 2) >> 22;
            sum += (float)bits / 10.0f;
        }
    }
    return sum;
}
