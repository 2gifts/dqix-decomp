#include <globaldefs.h>
void InsertShortIntoTable021098f4_0209953c(unsigned short value);
// USA: func_0206ec64
void IncrementNibble0206ec64(int unused, int index, unsigned char* data, unsigned int count) {
    int rem = index % 2;
    int half = index / 2;
    if (count <= (unsigned int)half) {
        InsertShortIntoTable021098f4_0209953c(0x3e7);
        return;
    }

    unsigned char byte = data[half];
    if (rem != 0) {
        unsigned int nibble = byte & 0xf;
        if (nibble >= 0xf) {
            return;
        }
        nibble = nibble + 1;
        data[half] = (nibble & 0xff) | (byte & 0xf0);
    } else {
        unsigned int nibble = (byte >> 4) & 0xff;
        if (nibble < 0xf) {
            unsigned int inc = nibble + 1;
            unsigned int low = byte & 0xf;
            unsigned char masked = (unsigned char)inc;
            data[half] = (masked << 4) | low;
        }
    }
}
