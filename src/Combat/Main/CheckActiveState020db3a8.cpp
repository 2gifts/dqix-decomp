#include <globaldefs.h>
#if defined(jpn)
enum { kStateOffset = 0x3508 };
#else
enum { kStateOffset = 0x3718 };
#endif


extern "C" int func_ov017_0218b5b0(void);

struct Entity020db3a8 {
    unsigned char pad[0x54];
    unsigned char field54;
};

// USA: func_020db3a8
ARM int CheckActiveState020db3a8(Entity020db3a8* s) {
    if (s->field54 == 1 && ((*(unsigned short*)0x4000304 & 0x8000) >> 15) == 1) {
        return 1;
    }
    int base = func_ov017_0218b5b0();
    int p = *(int*)(base + kStateOffset);
    return *(unsigned char*)(p + 3) != 0;
}
