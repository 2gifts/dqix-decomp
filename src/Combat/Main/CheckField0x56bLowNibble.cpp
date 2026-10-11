#include <globaldefs.h>

struct SubObj02061bd8 {
    unsigned char pad[0x56b];
    unsigned char nibble : 4;
};

struct Obj02061bd8 {
#if defined(jpn)
    unsigned char pad[0x144];
#else
    unsigned char pad[0x150];
#endif
    struct SubObj02061bd8* sub;
};

// USA: func_02061bd8
ARM int CheckField0x56bLowNibble(struct Obj02061bd8* obj) {
    struct SubObj02061bd8* sub = obj->sub;
    if (sub != NULL) {
        return sub->nibble != 0;
    }
    return 0;
}
