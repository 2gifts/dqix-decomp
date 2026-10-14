#include <globaldefs.h>

// USA: func_020d1be4
ARM void Crc16Update_020d1be4(const unsigned short* table, unsigned short* pcrc, const unsigned char* data, unsigned int len) {
    unsigned int crc = *pcrc;
    unsigned int i = 0;
    if (i < len) {
        do {
            crc = table[((crc ^ *data++) << 24) >> 24] ^ (crc >> 8);
            i++;
        } while (i < len);
    }
    *pcrc = (unsigned short)crc;
}
