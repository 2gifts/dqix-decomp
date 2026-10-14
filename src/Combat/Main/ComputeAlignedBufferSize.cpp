#include <globaldefs.h>

struct ComputeAlignedBufferSizeHeader { unsigned short a; unsigned short b; };

// USA: func_02096fd8
ARM int ComputeAlignedBufferSize_02096fd8(struct ComputeAlignedBufferSizeHeader *h) {
    char *base = (char *)(h->a * 0x30);
    char *end = (char *)(((int)base + h->b * 4 + 3) & ~3);
    return (int)base + (end - base);
}
