#include <globaldefs.h>

// USA: func_ov031_0223fc7c
extern "C" ARM int func_ov031_0223fc7c(char* output, unsigned int value, int digits) {
    int digit;
    int written = 0;
    if (digits > 8) return -1;
    digit = 1;
    if (digits >= 1) {
        do {
            unsigned int nibble = (value >> ((digits - digit) * 4)) & 15;
            if (nibble < 10) output[written++] = (char)(nibble + '0');
            else output[written++] = (char)(nibble + 'a' - 10);
            ++digit;
        } while (digit <= digits);
    }
    return written;
}
