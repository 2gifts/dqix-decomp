#include <globaldefs.h>

#if defined(jpn)
#define func_ov031_02220248 func_ov031_02220a28
#endif

struct FramedPayloadHeader {
    unsigned short length;
    unsigned char unknown02[6];
};
extern "C" int func_ov031_02220248(unsigned char**, unsigned char*, void*, int);

// USA: func_ov031_02220298
extern "C" THUMB int func_ov031_02220298(FramedPayloadHeader* packet, void* output, int count) {
    unsigned char* cursor = (unsigned char*)(packet + 1);
    unsigned short length = packet->length;
    unsigned short swapped = (unsigned char)(length >> 8) | ((length << 8) & 0xff00);
    return func_ov031_02220248(&cursor, cursor + swapped, output, count);
}
