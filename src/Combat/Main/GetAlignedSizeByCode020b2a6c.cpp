#include <globaldefs.h>

struct FormatInfo020b2a6c {
    unsigned char pad[0x17];
    unsigned char field17;
    unsigned char field18;
};

// USA: func_020b2a6c
ARM int GetAlignedSizeByCode020b2a6c(unsigned char* code, struct FormatInfo020b2a6c* info) {
    unsigned char c;
    if (code == NULL || info == NULL) {
        return 0;
    }
    c = code[0];
    switch (c) {
    case 0x4d:
        return ((info->field18 << 1) + 0x1c) & ~3;
    case 0x4a:
    case 0x56:
        return ((info->field17 << 1) + 0x1c) & ~3;
    }
    return 0;
}
