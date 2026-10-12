#include <globaldefs.h>
#include "System/Memory.h"

extern char data_ov031_0224e6ac[14];
union PackedBits0221b8e4 {
    unsigned long long value;
    struct { unsigned int low; unsigned int high; } words;
};

// USA: func_ov031_0221b8e4
extern "C" ARM void* func_ov031_0221b8e4(void* input) {
    unsigned char* data = (unsigned char*)input;
    PackedBits0221b8e4 bits;
    unsigned int low = *(unsigned int*)(data + 8);
    unsigned int high = *(unsigned int*)(data + 12);
    bits.words.high = high;
    bits.words.low = low;
    VectorizedInvertedMemcpy(data, data_ov031_0224e6ac, 5);
    data_ov031_0224e6ac[5] = (char)(((*(unsigned long long*)data >> 40) & 7) | ((bits.value & 0x1f) << 3));
    bits.value >>= 5;
    VectorizedInvertedMemcpy(&bits, data_ov031_0224e6ac + 6, 4);
    unsigned short tail = *(unsigned short*)(data + 0x10);
    data_ov031_0224e6ac[10] = (char)(((bits.value >> 32) & 0x3f) | ((tail & 3) << 6));
    data_ov031_0224e6ac[11] = (char)(*(unsigned short*)(data + 0x10) >> 2);
    VectorizedInvertedMemcpy(data + 0x12, data_ov031_0224e6ac + 12, 2);
    return data_ov031_0224e6ac;
}
