#include <globaldefs.h>
#include "System/Memory.h"

struct PacketContext396 {
    unsigned char padding[0x50];
    unsigned int address;
    unsigned char padding54[0x14];
    unsigned long long state;
    unsigned long long multiplier;
    unsigned long long increment;
};
extern PacketContext396 data_ov031_0224c980;
extern unsigned char data_ov031_0224ce68[];
extern const char data_ov031_02249698[];

// USA: func_ov031_02203fdc
extern "C" ARM unsigned char* func_ov031_02203fdc(void* buffer, int messageType, int* output) {
    unsigned char* bytes = (unsigned char*)buffer;
    unsigned short* halves = (unsigned short*)buffer;
    VectorizedMemset(buffer, 0, 0xec);
    halves[0] = 0x101;
    bytes[2] = 6;
    data_ov031_0224c980.state = data_ov031_0224c980.multiplier * data_ov031_0224c980.state + data_ov031_0224c980.increment;
    unsigned int random = data_ov031_0224c980.state >> 32;
    if (output) *output = random;
    int randomHigh = (unsigned short)(random >> 16);
    halves[2] = (randomHigh >> 8) | (randomHigh << 8);
    int randomLow = (unsigned short)random;
    halves[3] = (randomLow >> 8) | (randomLow << 8);
    int addressHigh = (unsigned short)(data_ov031_0224c980.address >> 16);
    halves[6] = (addressHigh >> 8) | (addressHigh << 8);
    int addressLow = (unsigned short)data_ov031_0224c980.address;
    halves[7] = (addressLow >> 8) | (addressLow << 8);
    VectorizedInvertedMemcpy(data_ov031_0224ce68, bytes + 0x1c, 6);
    halves[0x76] = 0x8263;
    halves[0x77] = 0x6353;
    halves[0x78] = 0x135;
    bytes[0xf2] = messageType;
    bytes[0xf3] = 0x3d;
    bytes[0xf4] = 7;
    bytes[0xf5] = 1;
    VectorizedInvertedMemcpy(data_ov031_0224ce68, bytes + 0xf6, 6);
    bytes[0xfc] = 12;
    bytes[0xfd] = 10;
    VectorizedInvertedMemcpy(data_ov031_02249698, bytes + 0xfe, 10);
    bytes[0x108] = 0x37;
    bytes[0x109] = 3;
    bytes[0x10a] = 1;
    bytes[0x10b] = 3;
    bytes[0x10c] = 6;
    return bytes + 0x10d;
}
