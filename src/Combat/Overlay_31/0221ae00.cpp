#include <globaldefs.h>
#include "System/Memory.h"

extern char data_ov031_0224e6ac[14];
struct Buf0221c3f8 {
    unsigned long long u0;
    unsigned long long u1;
    int pad;
};

// USA: func_ov031_0221ae00
extern "C" ARM void func_ov031_0221ae00(void* output) {
    Buf0221c3f8* data = (Buf0221c3f8*)output;
    VectorizedInvertedMemcpy(data_ov031_0224e6ac, &data->u0, 6);
    data->u0 &= 0x7ffffffffffULL;
    VectorizedInvertedMemcpy(data_ov031_0224e6ac + 5, &data->u1, 6);
    data->u1 >>= 3;
    data->u1 &= 0x7ffffffffffULL;
    unsigned short* tail = (unsigned short*)&data->pad;
    VectorizedInvertedMemcpy(data_ov031_0224e6ac + 10, tail, 2);
    tail[0] >>= 6;
    tail[0] &= 0x3ff;
    VectorizedInvertedMemcpy(data_ov031_0224e6ac + 12, tail + 1, 2);
}
