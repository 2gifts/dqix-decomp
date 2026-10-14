#include <globaldefs.h>

struct StateFlags3c9 {
#if defined(jpn)
    char pad[0x139];
#else
    char pad[0x3c9];
#endif
    unsigned char bit0 : 1;
    unsigned char rest : 7;
    unsigned char unk3ca;
    signed char value3cb;
};

// USA: func_0209494c
ARM int CheckFlag0x3c9Bit0OrByteNonPositive_0209494c(struct StateFlags3c9* obj) {
    if (obj->bit0) {
        return obj->value3cb <= 0;
    }
    return 1;
}
