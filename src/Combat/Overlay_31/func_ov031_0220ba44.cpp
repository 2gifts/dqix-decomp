#include <globaldefs.h>

struct CipherState0220ba44 {
    unsigned char index;
    unsigned char shuffle;
    unsigned char permutation[256];
};

// USA: func_ov031_0220ba44
extern "C" ARM void func_ov031_0220ba44(CipherState0220ba44* state, const unsigned char* key, int keyLength) {
    int value;
    state->index = 0;
    state->shuffle = 0;
    unsigned char* permutation = state->permutation;
    int initialIndex = 0;
    do {
        permutation[initialIndex] = initialIndex;
        initialIndex++;
    } while (initialIndex < 256);
    unsigned char shuffle;
    unsigned char keyIndex = 0;
    shuffle = keyIndex;
    int index = keyIndex;
    do {
        value = permutation[index];
        unsigned char keyValue = key[keyIndex];
        keyIndex++;
        shuffle = shuffle + (value + keyValue);
        unsigned char otherValue = permutation[shuffle];
        if (keyIndex >= keyLength) keyIndex = 0;
        permutation[index] = otherValue;
        permutation[shuffle] = value;
        index++;
    } while (index < 256);
}
