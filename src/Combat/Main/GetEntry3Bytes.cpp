#include <globaldefs.h>

struct EntryDEE8 {
    unsigned char a;
    unsigned char b;
    unsigned char c;
    char pad[0x19];
};

// USA: func_0206dee8
ARM void GetEntry3Bytes_0206dee8(EntryDEE8* base, unsigned char index, unsigned char* outA, unsigned char* outB, unsigned char* outC) {
    *outA = base[index].a;
    *outB = base[index].b;
    *outC = base[index].c;
}
