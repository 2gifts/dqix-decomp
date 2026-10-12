#include <globaldefs.h>

// USA: func_ov031_0221e3d0
extern "C" THUMB void func_ov031_0221e3d0(int seed, signed char* destination, int length, const signed char* key, int keyLength) {
    int count = length / 2;
    int keyIndex = seed % keyLength;
    int index = 0;
    if (index < count) {
        do {
            destination[index] = index;
            destination[index] ^= key[keyIndex++];
            if (keyIndex >= keyLength) keyIndex = 0;
            ++index;
        } while (index < count);
    }
}
