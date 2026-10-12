#include <globaldefs.h>

struct Obj021e31b0 {
    #if defined(jpn)
    char pad[0x4e4];
#else
    char pad[0x4e8];
#endif
    int field4e8;
    int arr4ec[4];
};

// USA: func_ov023_021e31b0
ARM void CopyBytesToInts_021e31b0(struct Obj021e31b0* o, unsigned char* src, int c) {
    int i;
    if (src == NULL || c == 0) return;
    o->field4e8 = c;
    for (i = 0; i < 4; i++) {
        o->arr4ec[i] = src[i];
    }
}
