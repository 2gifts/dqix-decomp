#include <globaldefs.h>
#include "System/Memory.h"

struct PackedSettings0221ae00 {
    unsigned long long first;
    unsigned long long second;
    unsigned short field_10;
    unsigned short field_12;
};
extern unsigned char data_ov031_0224e6ac[];
extern unsigned char data_ov031_0224e6b1[];
extern unsigned char data_ov031_0224e6b6[];
extern unsigned char data_ov031_0224e6b8[];

// USA: func_ov031_0221ae00
extern "C" ARM void func_ov031_0221ae00(PackedSettings0221ae00* settings) {
    VectorizedInvertedMemcpy(data_ov031_0224e6ac, &settings->first, 6);
    settings->first &= 0x7ffffffffffULL;
    VectorizedInvertedMemcpy(data_ov031_0224e6b1, &settings->second, 6);
    settings->second >>= 3;
    settings->second &= 0x7ffffffffffULL;
    VectorizedInvertedMemcpy(data_ov031_0224e6b6, &settings->field_10, 2);
    settings->field_10 >>= 6;
    settings->field_10 &= 0x3ff;
    VectorizedInvertedMemcpy(data_ov031_0224e6b8, &settings->field_12, 2);
}
