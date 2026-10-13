#include <globaldefs.h>

struct DecodeBlock0223e54c {
    signed char decoded[3];
    unsigned char encoded[4];
};
extern "C" int func_ov031_0223e38c(unsigned char*, const char*, int);
extern "C" int func_ov031_0223e3d4(unsigned char);

// USA: func_ov031_0223e54c
extern "C" ARM int func_ov031_0223e54c(signed char* output, const char* input, int remaining) {
    DecodeBlock0223e54c block;
    int value;
    int count;
    int total;
    total = 0;
    count = func_ov031_0223e38c(block.encoded, input, 4);
    value = total;
    while (count > 0 && value >= 0) {
        block.decoded[0] = 0;
        block.decoded[1] = 0;
        block.decoded[2] = 0;
        do {
            value = func_ov031_0223e3d4(block.encoded[0]);
            if (value < 0) break;
            block.decoded[0] = value << 2;
            value = func_ov031_0223e3d4(block.encoded[1]);
            if (value < 0) break;
            block.decoded[0] |= value >> 4;
            block.decoded[1] = value << 4;
            value = func_ov031_0223e3d4(block.encoded[2]);
            if (value < 0) break;
            block.decoded[1] |= value >> 2;
            block.decoded[2] = value << 6;
            value = func_ov031_0223e3d4(block.encoded[3]);
            if (value >= 0) block.decoded[2] |= value;
        } while (0);
        int copied = count - 1;
        int index = 0;
        if (copied > 0) {
            signed char* source = block.decoded;
            do {
                *output++ = *source++;
                ++index;
            } while (index < copied);
        }
        input += count;
        total += count - 1;
        remaining -= 4;
        if (remaining <= 0) break;
        count = func_ov031_0223e38c(block.encoded, input, 4);
    }
    return total;
}
