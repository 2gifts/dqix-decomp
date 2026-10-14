#include <globaldefs.h>

// USA: func_02085038
ARM int SumField4Bits20To26_02085038(char* base) {
    int sum = 0;
    int i;
    for (i = 0; i < 11; i++) {
        char* e = base + i * 0x20;
        if (*(short*)(e + 0x1ac) > 0) {
            unsigned int* p = *(unsigned int**)(e + 0x194);
            sum += (p[1] << 5) >> 25;
        }
    }
    return sum;
}
