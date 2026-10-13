// USA: func_ov031_0223fc7c
#include <globaldefs.h>
extern "C" ARM int func_ov031_0223fc7c(unsigned char* dest, unsigned int value, int count) {
    int len = 0;
    if (count > 8) return -1;
    int i = 1;
    if (count >= 1) {
        do {
            unsigned int nibble = (value >> ((count - i) * 4)) & 0xf;
            if (nibble < 10)
                dest[len++] = nibble + 0x30;
            else
                dest[len++] = nibble + 0x57;
            i++;
        } while (i <= count);
    }
    return len;
}
