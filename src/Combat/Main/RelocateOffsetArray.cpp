#include <globaldefs.h>

struct Reloc02b02d0 {
    unsigned short count;
    unsigned short pad;
    unsigned int *arr;
};

// USA: func_020b02d0
ARM void RelocateOffsetArray_020b02d0(struct Reloc02b02d0 *h) {
    unsigned short i = 0;
    h->arr = (unsigned int *)((unsigned int)h->arr + (unsigned int)h);
    if (h->count > i) {
        do {
            h->arr[i] = (unsigned int)((unsigned char *)h + h->arr[i]);
            i++;
        } while (h->count > i);
    }
}
