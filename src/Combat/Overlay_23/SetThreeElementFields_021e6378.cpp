#include <globaldefs.h>

struct Struct_0205d81c;
void SetElementFieldC2_0205deb4(struct Struct_0205d81c* s, int key, int value);

// USA: func_ov023_021e6378
ARM void SetThreeElementFields_021e6378(void* obj, int a, int b, int c, unsigned char d) {
    *((unsigned char*)obj + 0x1371) = (unsigned char)a;
    SetElementFieldC2_0205deb4((struct Struct_0205d81c*)((char*)obj + 0xac), 7, b);
    SetElementFieldC2_0205deb4((struct Struct_0205d81c*)((char*)obj + 0xac), 8, c);
    SetElementFieldC2_0205deb4((struct Struct_0205d81c*)((char*)obj + 0xac), 9, d);
}
