#include <globaldefs.h>

struct HalfwordArray {
    unsigned short arr[12];
    unsigned short count;
};

// USA: func_0209c0c0
ARM unsigned short CopyHalfwordArrayByCount_0209c0c0(struct HalfwordArray* src, struct HalfwordArray* dst) {
    int i;
    for (i = 0; i < src->count; i++) {
        dst->arr[i] = src->arr[i];
    }
    return src->count;
}
