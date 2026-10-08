#include <globaldefs.h>

extern const unsigned long data_020ee278[256];

extern "C"
{
    unsigned long func_01ff85f0(unsigned char byte, unsigned long crc);

    unsigned long func_01ff85b8(const unsigned char* data, unsigned long length)
    {
        unsigned long crc = 0xffffffff;
        if (data != NULL)
        {
            for (; length != 0; length--)
                crc = func_01ff85f0(*data++, crc);
        }
        return ~crc;
    }

    unsigned long func_01ff85f0(unsigned char byte, unsigned long crc)
    {
        return data_020ee278[(crc ^ byte) & 0xff] ^ (crc >> 8);
    }

    unsigned long func_01ff860c(const unsigned char* string)
    {
        unsigned long crc = 0xffffffff;
        if (string != NULL)
        {
            for (; *string != '\0'; string++)
                crc = func_01ff85f0(*string, crc);
        }
        return ~crc;
    }
}
