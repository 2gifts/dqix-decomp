#include <globaldefs.h>

// USA: func_020d1c64
ARM void Crc32Update_020d1c64(const unsigned int* table, unsigned int* pcrc, const unsigned char* data, unsigned int len) {
    unsigned int crc = *pcrc;
    unsigned int i = 0;
    if (i < len) {
        do {
            crc = table[(unsigned char)(crc ^ *data++)] ^ (crc >> 8);
            i++;
        } while (i < len);
    }
    *pcrc = crc;
}
