#include <globaldefs.h>

extern unsigned long long data_ov031_02249440[16] __attribute__((aligned(4)));

// USA: func_ov031_0223fba4
extern "C" ARM int func_ov031_0223fba4(char* output, unsigned long long value, int width) {
    int index;
    int length = 0;
    if (value >= 100000000000000000ULL) return length - 1;
    index = 0;
    int started = 0;
    do {
        unsigned long long divisor = data_ov031_02249440[index];
        if (value >= divisor) {
            unsigned int digit = value / divisor;
            unsigned long long product = digit * divisor;
            output[length] = digit + '0';
            value -= product;
            started = 1;
            length++;
        } else {
            if (started || 17 - index <= width) {
                output[length] = '0';
                length++;
            }
        }
        index++;
    } while (index < 16);
    output[length] = value + '0';
    return length + 1;
}
