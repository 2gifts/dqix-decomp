#include <globaldefs.h>

// USA: func_020d1b68
ARM void Crc8Update_020d1b68(const unsigned char* table, unsigned char* pcrc, const unsigned char* data, unsigned int len) {
    unsigned char crc = *pcrc;
    unsigned int i = 0;
    if (i < len) {
        do {
            crc = table[(unsigned char)(crc ^ *data++)];
            i++;
        } while (i < len);
    }
    *pcrc = crc;
}
