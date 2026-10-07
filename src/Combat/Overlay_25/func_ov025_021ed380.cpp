#include <globaldefs.h>

// USA: func_ov025_021ed380
extern "C" ARM int func_ov025_021ed380(char* obj, int id, int val2, int type, int val3, short val4, unsigned short val5) {
    if (type >= 6) return -1;

    int result = -1;
    if (id != 0) {
        unsigned char count = *(unsigned char*)(obj + 0x150);
        if (count < 0x10) {
            *(unsigned short*)(obj + count * 2) = id;
            count = *(unsigned char*)(obj + 0x150);
            *(short*)(obj + count * 2 + 0x20) = val2;
            count = *(unsigned char*)(obj + 0x150);
            *(unsigned char*)(obj + count + 0xa0) = type;
            count = *(unsigned char*)(obj + 0x150);
            *(int*)(obj + count * 4 + 0xb0) = val3;

            if (*(short*)(obj + 0x152) == 0x7fff) {
                *(short*)(obj + 0x152) = 0;
            }
            *(short*)(obj + 0x152) = *(short*)(obj + 0x152) + 1;
            short assigned = *(short*)(obj + 0x152);

            count = *(unsigned char*)(obj + 0x150);
            *(short*)(obj + count * 2 + 0x60) = assigned;
            count = *(unsigned char*)(obj + 0x150);
            *(short*)(obj + count * 2 + 0x40) = val4;
            count = *(unsigned char*)(obj + 0x150);
            *(unsigned short*)(obj + count * 2 + 0x80) = val5;
            count = *(unsigned char*)(obj + 0x150);
            *(unsigned char*)(obj + 0x150) = count + 1;
            result = assigned;
        }
    }
    return result;
}
