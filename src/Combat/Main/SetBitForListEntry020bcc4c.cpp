#include <globaldefs.h>

void PostEvent0x15_020d2018(int, int);

struct Obj020bcc4c {
    char pad[0x48];
    int count;
    unsigned char table[1];
};

// USA: func_020bcc4c
ARM void SetBitForListEntry020bcc4c(struct Obj020bcc4c* obj, int i, int arg) {
    if (i > obj->count - 1) return;
    PostEvent0x15_020d2018(1 << obj->table[i], arg);
}
