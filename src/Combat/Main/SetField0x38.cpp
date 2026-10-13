#include <globaldefs.h>

#if defined(jpn)
enum { kInitialPad = 0x4 };
#else
enum { kInitialPad = 0x38 };
#endif

struct S020466c8 {
    char pad[kInitialPad];
    int field0x38;
};

// USA: func_020466c8
ARM void SetField0x38(struct S020466c8* p, int v) {
    p->field0x38 = v;
}
