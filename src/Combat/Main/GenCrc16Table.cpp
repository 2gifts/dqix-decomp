#include <globaldefs.h>

// USA: func_020d1ba0
ARM void GenCrc16Table_020d1ba0(unsigned short* table, unsigned short poly) {
    unsigned int crc;
    unsigned int i;
    unsigned int bit;
    i = 0;
    do {
        crc = i;
        bit = 0;
        do {
            if (crc & 1) {
                crc = poly ^ (crc >> 1);
            } else {
                crc = crc >> 1;
            }
            bit++;
        } while (bit < 8);
        table[i] = (unsigned short)crc;
        i++;
    } while (i < 0x100);
}
