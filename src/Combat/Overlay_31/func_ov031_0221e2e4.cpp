#include <globaldefs.h>

#if defined(jpn)
#define func_ov031_0221e31c func_ov031_0221eafc
#endif

extern "C" void func_ov031_0221e31c(int, unsigned int*);

// USA: func_ov031_0221e2e4
extern "C" THUMB unsigned int func_ov031_0221e2e4(unsigned int checksum, const unsigned char* data, int length, int initialized, unsigned int* table) {
    if (initialized == 0) func_ov031_0221e31c(initialized, table);
    int index = 0;
    if (length > 0) do {
        checksum = (checksum >> 8) ^ table[(unsigned char)(data[index] ^ checksum)];
        index++;
    } while (index < length);
    return checksum;
}
