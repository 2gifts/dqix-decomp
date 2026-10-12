#include <globaldefs.h>

#if defined(jpn)
enum { FIELD_OFFSET = 0x5a70 };
#else
enum { FIELD_OFFSET = 0x5cd0 };
#endif

struct S_02011430 {
    char unk[FIELD_OFFSET];
    unsigned char bits[32];
};

#if defined(jpn)
#define GetBit5cd0 func_020111a0
extern "C" ARM int func_020111a0(struct S_02011430* obj, int a, int b);
#endif

// USA: func_02011430
ARM int GetBit5cd0(struct S_02011430* obj, int a, int b) {
    unsigned int idx = b + (a - 1) * 5;
    unsigned int q = idx / 8;
    unsigned char mask = 1 << (idx - q * 8);
    return (obj->bits[idx / 8] & mask) != 0;
}
