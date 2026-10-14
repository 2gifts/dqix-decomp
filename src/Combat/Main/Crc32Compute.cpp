#include <globaldefs.h>

void Crc32Update_020d1c64(const unsigned int* table, unsigned int* pcrc, const unsigned char* data, unsigned int len);

// USA: func_020d1cf0
ARM unsigned int Crc32Compute_020d1cf0(const unsigned int* table, const unsigned char* data, unsigned int len) {
    unsigned int crc = ~0;
    Crc32Update_020d1c64(table, &crc, data, len);
    return ~crc;
}
