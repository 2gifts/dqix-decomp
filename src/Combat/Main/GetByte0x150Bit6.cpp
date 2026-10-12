#include <globaldefs.h>

#if defined(jpn)
enum { kByteOffset = 0xf0 };
#else
enum { kByteOffset = 0x150 };
#endif


struct BitFlags020d805c {
    char pad[kByteOffset];
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 1;
};

#if defined(jpn)
#define GetByte0x150Bit6 func_020d99d0
extern "C" ARM int func_020d99d0(struct BitFlags020d805c* obj);
#endif

// USA: func_020d805c
ARM int GetByte0x150Bit6(struct BitFlags020d805c* obj) {
    return obj->b6;
}
