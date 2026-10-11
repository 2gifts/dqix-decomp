#include <globaldefs.h>

struct Obj021761c8 {
#if defined(jpn)
    char pad[0xf54];
#else
    char pad[0xd1c];
#endif
    int arr[8];
};

// USA: func_ov000_021761c8
// JPN: func_ov000_02177590
ARM int GetClampedArrayField0xd1c(char* base, int index) {
    if (index < 0 || index >= 8) index = 0;
    return ((struct Obj021761c8*)(base + 0x1000))->arr[index];
}
