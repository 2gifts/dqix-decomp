#include <globaldefs.h>

struct Packet0221e028 {
    unsigned short type;
    unsigned short field_0x2;
    unsigned short field_0x4;
    unsigned short value1;
    unsigned short field_0x8;
    unsigned short value2;
    unsigned short value3;
    signed char flag1;
    signed char flag2;
    unsigned char data[8];
};
extern "C" unsigned short func_ov031_0221e5f8(short);
typedef unsigned short (*UnsignedSwap16_0221e028)(unsigned short);
inline unsigned short SwapUnsigned16_0221e028(unsigned short value) { return ((UnsignedSwap16_0221e028)func_ov031_0221e5f8)(value); }
extern "C" void func_ov031_0221e51c(void*, const void*, unsigned int);

// USA: func_ov031_0221e028
extern "C" THUMB void func_ov031_0221e028(Packet0221e028* packet, int value1, int value2, int value3, signed char flag1, signed char flag2, const void* data) {
    packet->type = SwapUnsigned16_0221e028(1);
    packet->field_0x2 = 0;
    packet->field_0x4 = 0;
    packet->value1 = SwapUnsigned16_0221e028(value1);
    packet->field_0x8 = 0;
    packet->value2 = SwapUnsigned16_0221e028(value2);
    packet->value3 = SwapUnsigned16_0221e028(value3);
    packet->flag1 = flag1;
    packet->flag2 = flag2;
    func_ov031_0221e51c(packet->data, data, 8);
}
