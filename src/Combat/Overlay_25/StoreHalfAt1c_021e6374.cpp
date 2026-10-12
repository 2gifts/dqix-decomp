#include <globaldefs.h>

struct Sub021e6374 {
    char pad[0x1c];
    unsigned short f1c;
};

struct Base021e6374 {
    char pad[0x540];
    struct Sub021e6374 sub;

    struct Sub021e6374* GetSub() { return &sub; }
};

struct Holder021e6374 {
    char pad[0xc];
    struct Base021e6374* base;
};
extern struct Holder021e6374 data_ov025_021ef988;

// USA: func_ov025_021e6374  (semantic: StoreHalfAt1c_021e6374)
extern "C" ARM int func_ov025_021e6374(void* obj) {
    data_ov025_021ef988.base->GetSub()->f1c =*(unsigned short*)((char*)obj + 8);
    return 1;
}
