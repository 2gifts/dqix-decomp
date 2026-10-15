#include <globaldefs.h>
#include "std_library_functions.h"

extern int StringLength_020d2ff0(const char* s);

extern "C" void func_0206aa28(void* p);
extern "C" void func_0206b974(void* p, int a1, void* a2, void* a3, int a4, int a5, int a6, int a7);

struct Ctx0206a974 {
    char pad0[0x48];
    void* field48;
    void* field4c;
    void* field50;
    void* field54;
    void* field58;
    char pad5c[4];
    void* field60;
    char pad64[4];
    int field68;
};

// USA: func_0206a974
ARM void InitContextString0206a974(struct Ctx0206a974* p, const char* src, int boxWidth) {
    if (src == 0) return;
    {
        void* buf = p->field48;
        memcpy(buf, (void*)src, (p->field68 = StringLength_020d2ff0(src)));
    }
    {
        void* buf2 = p->field48;
        p->field58 = buf2;
        p->field54 = buf2;
    }
    memset(p->field4c, 0, 0x280);
    memset(p->field50, 0, 0x280);
    func_0206aa28(p);
    func_0206b974(p, 1, p->field50, p->field60, boxWidth, 0, 1, 1);
    {
        int len2 = StringLength_020d2ff0((const char*)p->field60);
        memcpy(p->field50, p->field60, len2);
    }
}
