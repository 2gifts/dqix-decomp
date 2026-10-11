#include <globaldefs.h>



class PMFObj021537d4 { public: virtual void Dummy021537d4(); };
typedef void (PMFObj021537d4::*MemFn021537d4)();

struct Entry021537d4 { unsigned int a; unsigned int b; };

extern int data_ov003_02180ca0;
extern struct Entry021537d4 data_020e6d5c;
extern struct Entry021537d4 data_ov003_0217fc80[];
extern struct Entry021537d4 data_ov003_0217fc80_tbl[];

union PMFCast021537d4 { struct Entry021537d4* raw; MemFn021537d4* fn; };

// USA: func_ov003_021537d4
// JPN: func_ov003_02154f54
extern "C" ARM int func_ov003_021537d4(PMFObj021537d4* obj) {
    if (!(data_ov003_02180ca0 & 1)) {
        *(unsigned long long*)((char*)data_ov003_0217fc80 + 0x18) = *(const unsigned long long*)&data_020e6d5c;
        data_ov003_02180ca0 |= 1;
    }
    unsigned char idx = *((unsigned char*)obj + 0x5a);
    struct Entry021537d4* tbl = data_ov003_0217fc80_tbl;
    if (tbl[idx].a == 0) {
        return 1;
    }
    union PMFCast021537d4 pmf;
    pmf.raw = &tbl[idx];
    (obj->*(*pmf.fn))();
    return 0;
}
