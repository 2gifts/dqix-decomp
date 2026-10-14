#include <globaldefs.h>

int PopCount32_020d1ae4(unsigned int);

// USA: func_020d6884
ARM int ComputeMaskedIndexOffset_020d6884(void *obj, int value, int base, int bits) {
    return PopCount32_020d1ae4(value & ((1 << bits) - 1)) * *(unsigned short*)((char*)obj + 0x810) + base;
}
