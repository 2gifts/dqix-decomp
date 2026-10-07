#include <globaldefs.h>

// Decode the A-Z/a-z/0-9/./- alphabet in four-character groups. '*' adds no bits
// to the reported size; unrecognized characters decode to zero. A null output
// queries the size; capacity below that size returns -1 before writing.
// USA: func_ov031_0221ac6c
extern "C" ARM int func_ov031_0221ac6c(const char* input, unsigned int length, char* output, unsigned int capacity) {
    if (length & 3) return -1;
    int bits = 0;
    unsigned int i = 0;
    if (length > i) {
        do {
            if (input[i] != '*') bits += 6;
            ++i;
        } while (i < length);
    }
    int size = bits / 8;
    if (output == 0) return size;
    if (capacity < (unsigned int)size) return -1;
    if (length == 0) return 0;
    char* dst = output;
    int written;
    // The original always writes the first byte for nonempty input, including
    // all-padding input whose size query returned zero.
    do {
        char values[4];
        char* value = values;
        int i = 0;
        do {
            int c = input[i];
            if (c >= 'A' && c <= 'Z') *value = c - 'A';
            else if (c >= 'a' && c <= 'z') *value = c - 'G';
            else if (c >= '0' && c <= '9') *value = c + 4;
            else if (c == '.') *value = 62;
            else if (c == '-') *value = 63;
            else *value = 0;
            ++i;
            ++value;
        } while (i < 4);
        dst[0] = (values[0] << 2) | (values[1] >> 4);
        written = dst + 1 - output;
        input += 4;
        if (written >= size) break;
        dst[1] = (values[1] << 4) | (values[2] >> 2);
        written = dst + 2 - output;
        if (written >= size) break;
        dst[2] = (values[2] << 6) | values[3];
        dst += 3;
        written = dst - output;
    } while (written < size);
    return written;
}
