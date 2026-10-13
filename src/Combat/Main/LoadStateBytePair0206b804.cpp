#include <globaldefs.h>

#if defined(jpn)
enum { kFlag = 0x17f0, kSetFlag = 0x17fe, kClearWord = 0xc, kIndex = 0x178b };
#else
enum { kFlag = 0x19c0, kSetFlag = 0x19cd, kClearWord = 0x40, kIndex = 0x195d };
#endif

extern const signed char data_020e7e10[];
extern const signed char data_020e7e1c[];

// USA: func_0206b804
ARM void LoadStateBytePair0206b804(char* obj, int* out1, int* out2) {
    *out2 = 0;
    *out1 = 0;
    if (*(unsigned char*)(obj + kFlag) != 0) {
        int idx;
        *(unsigned char*)(obj + kSetFlag) = 1;
        *(int*)(obj + kClearWord) = 0;
        idx = *(unsigned char*)(obj + kIndex) & 3;
        *out1 = data_020e7e10[idx];
        *out2 = data_020e7e1c[idx];
    }
}
