#include <globaldefs.h>

struct Reloc02b02d0 {
    unsigned short count;
    unsigned short pad;
    unsigned int *arr;
};

void RelocateOffsetArray_020b02d0(struct Reloc02b02d0 *h);

// USA: func_020b0094
ARM void RelocateOffsetArrayAtOffset8_020b0094(char *base) {
    RelocateOffsetArray_020b02d0((struct Reloc02b02d0 *)(base + 8));
}
