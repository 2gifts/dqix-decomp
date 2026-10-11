#include <globaldefs.h>

struct ThreeShorts021ded84 {
    unsigned short a;
    unsigned short b;
    unsigned short c;
};

void CopyThreeShorts021ded84(struct ThreeShorts021ded84* dst, struct ThreeShorts021ded84* src);

struct Table_021deda0 {
#if defined(jpn)
    char pad[0x78dc];
#else
    char pad[0x76ec];
#endif
    struct ThreeShorts021ded84 rows[5];
    unsigned short count;
};

// USA: func_ov025_021ded50  (semantic: AppendRow_021ded50)
extern "C" ARM void func_ov025_021ded50(struct Table_021deda0* t, struct ThreeShorts021ded84* src) {
    unsigned short idx = t->count;
    if (idx >= 5) return;

    struct ThreeShorts021ded84* dst = &t->rows[idx];
    t->count = idx + 1;
    CopyThreeShorts021ded84(dst, src);
}
