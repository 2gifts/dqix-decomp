#include <globaldefs.h>

struct Packet02220298 {
    unsigned short length;
    unsigned char pad_0x2[6];
    unsigned char payload[1];
};
extern "C" int func_ov031_02220248(unsigned char**, unsigned char*, void*, int);

// USA: func_ov031_02220298
extern "C" THUMB int func_ov031_02220298(Packet02220298* packet, void* output, int count) {
    unsigned char* cursor = packet->payload;
    unsigned short length = packet->length;
    unsigned short swapped = (unsigned char)(length >> 8) | ((length << 8) & 0xff00);
    return func_ov031_02220248(&cursor, cursor + swapped, output, count);
}
