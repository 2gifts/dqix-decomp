#include <globaldefs.h>

struct StreamCipherState {
    unsigned int first;
    unsigned int second;
    unsigned char* permutation;
    unsigned int length;
};

// USA: func_ov031_0221e27c
extern "C" THUMB unsigned char func_ov031_0221e27c(StreamCipherState* state) {
    unsigned int length = state->length;
    unsigned char* permutation = state->permutation;
    unsigned char first = (state->first + 1) % length;
    unsigned char firstValue = permutation[first];
    unsigned char second = (firstValue + state->second) % length;
    unsigned char secondValue = permutation[second];
    state->first = first;
    state->second = second;
    permutation[second] = firstValue;
    permutation[first] = secondValue;
    return permutation[(firstValue + secondValue) % state->length];
}
