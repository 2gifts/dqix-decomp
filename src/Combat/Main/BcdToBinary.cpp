#include <globaldefs.h>

// USA: func_020cf7e4
ARM int BcdToBinary_020cf7e4(unsigned int packed) {
    int result = 0;
    int i;
    int shift;
    i = 0;
    shift = 0;
    do {
        if (((packed >> shift) & 0xf) >= 0xa) {
            return 0;
        }
        i++;
        shift += 4;
    } while (i < 8);
    {
        int mult;
        int digitShift;
        int digitIndex;
        digitIndex = 0;
        digitShift = 0;
        mult = 1;
        do {
            int digit = (packed >> digitShift) & 0xf;
            result += mult * digit;
            mult = mult * 10;
            digitIndex++;
            digitShift += 4;
        } while (digitIndex < 8);
    }
    return result;
}
