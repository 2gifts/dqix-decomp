#include <globaldefs.h>

// USA: func_ov031_02201e70
extern "C" ARM void func_ov031_02201e70(void *source, void *destination) {
    unsigned char *bytes  = static_cast<unsigned char *>(source);
    unsigned short *value = reinterpret_cast<unsigned short *>(static_cast<unsigned char *>(destination) + 0x2e);
    *value                = 0x218;
    int length            = (bytes[0xc] & 0xf0) / 4 - 0x14;
    int remaining         = length - 1;
    unsigned char *cursor = bytes + 0x14;
    if (length == 0) {
        return;
    }
    do {
        int tag = *cursor++;
        switch (tag) {
            case 0: return;
            case 1: break;
            case 2:
                *value = (cursor[1] << 8) | cursor[2];
                cursor += 3;
                remaining -= 3;
                break;
            default:
                int skip = *cursor - 1;
                remaining -= skip;
                cursor += skip;
                break;
        }
    } while (remaining-- != 0);
}
