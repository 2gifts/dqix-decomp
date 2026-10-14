#include <globaldefs.h>

struct Timer021d94e4 {
    char pad0[0x84];
    long long f84;
    long long f8c;
    int f94;
    int f98;
    unsigned char f9c;
    char pad9d[3];
    long long fa0;
    long long fa8;
};

extern "C" void func_ov028_021d8c20(void* obj);

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_ov028_021d94e4  (semantic: ResetFields_021d94e4)
ARM void ResetFields_021d94e4(void* p) {
    struct Timer021d94e4* obj = (struct Timer021d94e4*)p;
    obj->f9c = 0;
    obj->f98 = 0;
    obj->f94 = 0;
    obj->f8c = 0;
    obj->f84 = obj->f8c;
    obj->fa8 = 0;
    obj->fa0 = obj->fa8;
    func_ov028_021d8c20(p);
}
