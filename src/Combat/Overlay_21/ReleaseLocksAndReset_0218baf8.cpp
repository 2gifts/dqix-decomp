#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" int func_ov009_02184a18(int handle);
extern "C" void _Z20ResetXYField0203aa08Pv(void* p);
extern "C" void func_020bbd9c(void);
extern int data_02108760;

struct Obj0218baf8 {
    unsigned char pad0[0x40];
    int field40;
    unsigned char pad44[0xb8 - 0x44];
    int fieldb8;
};

// USA: func_ov021_0218baf8
ARM void ReleaseLocksAndReset_0218baf8(struct Obj0218baf8* obj) {
    BackgroundLoader::GetInstance()->RemoveAllLocks();
    if (func_ov009_02184a18(obj->field40) != 0) {
        obj->fieldb8 = 1;
    }
    _Z20ResetXYField0203aa08Pv(&data_02108760);
    func_020bbd9c();
}
