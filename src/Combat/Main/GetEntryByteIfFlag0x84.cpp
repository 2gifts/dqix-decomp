#include <globaldefs.h>

struct Entry02047a5c {
    unsigned char value;
    char pad[7];
};

struct Owner02047a5c {
    char pad0[0x8];
    struct Entry02047a5c* entries;
    char pad2[0x78];
    unsigned char flag : 1;
    unsigned char rest : 7;
};

#if defined(jpn)
#define GetEntryByteIfFlag0x84 func_0204887c
extern "C" ARM unsigned char func_0204887c(struct Owner02047a5c* owner, int index);
#endif

// USA: func_02047a5c
ARM unsigned char GetEntryByteIfFlag0x84(struct Owner02047a5c* owner, int index) {
    if (owner->flag) {
        return owner->entries[index].value;
    }
    return 0;
}
