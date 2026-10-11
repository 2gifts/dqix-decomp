#include <globaldefs.h>

struct Obj021761ec {
#if defined(jpn)
    char pad[0xf74];
#else
    char pad[0xd3c];
#endif
    int arr[8];
};

// USA: func_ov000_021761ec
// JPN: func_ov000_021775b4
ARM int GetClampedArrayField0xd3c(char* base, int index) {
    if (index < 0 || index >= 8) index = 0;
    return ((struct Obj021761ec*)(base + 0x1000))->arr[index];
}
