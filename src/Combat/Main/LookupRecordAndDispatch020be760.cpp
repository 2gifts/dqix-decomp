#include <globaldefs.h>
void* GetOffsetEntry0x8(int);
#pragma optimize_for_size off

extern "C" int func_020be828(void* a, unsigned char b, unsigned short c, unsigned char d, void* e, void* f);

struct Rec020be760 {
    char pad0[4];
    unsigned short field4;
    char pad6[2];
    unsigned char field8;
    unsigned char field9;
};

// USA: func_020be760
ARM int LookupRecordAndDispatch020be760(void* a, void* key) {
    struct Rec020be760* rec = (struct Rec020be760*)GetOffsetEntry0x8((int)(key));
    if (rec == NULL) return 0;
    return func_020be828(a, rec->field9, rec->field4, rec->field8, rec, key);
}
