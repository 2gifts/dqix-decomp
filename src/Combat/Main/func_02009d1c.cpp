#include <globaldefs.h>

struct DigitBuf020098fc {
    unsigned char flag0;
    char pad1;
    short exponent;
    unsigned char count;
    unsigned char digits[0x20] __attribute__((aligned(1)));
};

// USA: func_02009d1c
extern "C" ARM int func_02009d1c(DigitBuf020098fc* first, DigitBuf020098fc* second) {
    unsigned char firstDigit = first->digits[0];
    if (firstDigit == 0) return second->digits[0] == 0;
    if (second->digits[0] == 0) return firstDigit == 0;
    if (first->exponent != second->exponent) goto different;
    int i;
    int limit;
    int firstCount;
    firstCount = first->count;
    int secondCount = second->count;
    i = 0;
    limit = firstCount;
    if (limit > secondCount) limit = secondCount;
    if (limit > 0) {
        do {
            if (first->digits[i] != second->digits[i]) return 0;
            i++;
        } while (i < limit);
    }
    if (limit == firstCount) first = second;
    if (i < first->count) {
        do {
            if (first->digits[i]) return 0;
            i++;
        } while (i < first->count);
    }
    return 1;
different:
    return 0;
}
