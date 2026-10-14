#include <globaldefs.h>
void* GetOffsetEntry0x24_020bd5e4(int);
#pragma optimize_for_size off

extern "C" int func_020beed8(void* a, void* rec, unsigned char b6, unsigned char b5,
                             int arg1, int arg2, int z1, int z2, int z3, int z4);

struct Rec020bebb4 {
    char pad0[5];
    unsigned char field5;
    unsigned char field6;
};

// USA: func_020bebb4
ARM int LookupRecordAndDispatch020bebb4(void* a, int key, int arg2) {
    struct Rec020bebb4* rec = (struct Rec020bebb4*)GetOffsetEntry0x24_020bd5e4((int)(key));
    if (rec == NULL) return 0;
    return func_020beed8(a, rec, rec->field6, rec->field5, key, arg2, 0, 0, 0, 0);
}
