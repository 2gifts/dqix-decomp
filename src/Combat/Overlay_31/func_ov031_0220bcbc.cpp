#include <globaldefs.h>
#include "System/Memory.h"

int TrimTrailingZeroShorts_0220bb24(unsigned short*, int);

// USA: func_ov031_0220bcbc
extern "C" ARM void func_ov031_0220bcbc(unsigned short* destination, unsigned short* left, unsigned short* right, int length) {
    int leftLength = TrimTrailingZeroShorts_0220bb24(left, length);
    int rightLength = TrimTrailingZeroShorts_0220bb24(right, length);
    int limit = leftLength;
    if (limit < rightLength) limit = rightLength;
    int i;
    int borrow;
    if (limit != length) limit++;
    i = borrow = 0;
    while (i < limit || (i < length && borrow != 0)) {
        int difference = left[i] - right[i] + borrow;
        destination[i] = difference;
        borrow = difference >> 16;
        i++;
    }
    if (destination == left || destination == right) return;
    VectorizedMemset(destination + i, 0, (length - i) * 2);
}
