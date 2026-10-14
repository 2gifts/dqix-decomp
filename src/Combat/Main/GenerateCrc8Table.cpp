#include <globaldefs.h>

// USA: func_020d1b28
ARM void GenerateCrc8Table_020d1b28(unsigned char* table, unsigned int poly) {
    unsigned int crc;
    unsigned int i = 0;
    unsigned int bit;
    do {
        crc = i;
        bit = 0;
        do {
            if (crc & 0x80) {
                crc = poly ^ (crc << 1);
            } else {
                crc = crc << 1;
            }
            bit++;
        } while (bit < 8);
        table[i] = crc;
        i++;
    } while (i < 0x100);
}
