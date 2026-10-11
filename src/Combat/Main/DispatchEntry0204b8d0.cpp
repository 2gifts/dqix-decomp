#include <globaldefs.h>

extern "C" void func_0204b620(void*, void*, int, int, int, int, int, int, int, int);

struct Obj0204b8d0 {
    char pad0[0x10];
    int field10;
    void* field14;
    char pad18[5];
    unsigned char field1d;
};

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_0204b8d0
ARM void DispatchEntry0204b8d0(struct Obj0204b8d0* obj, unsigned int a1, int a2, int a3,
                              short a4, short a5, short a6, short a7, unsigned short a8) {
    if (obj->field1d <= a1) return;
    int v = obj->field10;
    if (v == 0) return;
    v += a1 << 4;
    void* p = obj->field14;
    if (p == NULL) return;
    func_0204b620(obj, p, v, a2, a3, a4, a5, a6, a7, a8);
}
