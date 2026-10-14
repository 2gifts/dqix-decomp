#include <globaldefs.h>

struct BoundedArray {
    unsigned short items[0xc];
    unsigned short count;
};

// USA: func_0209c08c
ARM void AppendHalfwordCapped_0209c08c(struct BoundedArray* s, unsigned short value) {
    unsigned short count = s->count;
    if (count < 0xc) {
        s->count = count + 1;
        s->items[count] = value;
    }
}
