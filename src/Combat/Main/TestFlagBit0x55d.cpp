#include <globaldefs.h>

// USA: func_02020084
ARM int TestFlagBit0x55d_02020084(unsigned char* base, int bit) {
    int valid;
    if (bit >= 0 && bit <= 3) valid = 1;
    else valid = 0;
    if (valid) {
        return (base[0x55d] & (1 << bit)) != 0;
    }
    return 0;
}
