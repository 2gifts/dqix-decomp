#include <globaldefs.h>

struct B190Inner {
    char unk[0x4];
    unsigned short flag;
};

struct B190Outer {
    char unk[4];
    struct B190Inner* inner;
};

// USA: func_0205b190
ARM int GetBits12To15_0205b190(int unused, struct B190Outer* obj) {
    if (obj == 0) {
        return 0;
    }
    return ((unsigned int)obj->inner->flag >> 12) & 0xf;
}
