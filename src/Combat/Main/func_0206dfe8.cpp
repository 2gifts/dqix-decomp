#include <globaldefs.h>

#include "std_library_functions.h"

// USA: func_0206dfe8
extern "C" ARM void func_0206dfe8(void *receiver, int first, int second) {
    int startByte  = first / 8 + 1;
    int firstShift = 8 - first % 8;
    int remaining  = second - firstShift;
    int wholeBytes = remaining / 8;
    int lastShift  = remaining % 8;
    if (wholeBytes > 0) {
        memset((unsigned char *) receiver + 0x8c + startByte, 0, wholeBytes);
    }
    int endByte         = startByte + wholeBytes;
    unsigned char *bits = (unsigned char *) receiver + 0x8c;
    bits[endByte] >>= lastShift;
    bits[endByte] <<= lastShift;
    bits[startByte - 1] <<= firstShift;
    bits[startByte - 1] >>= firstShift;
}
