#include <globaldefs.h>
#include "Resource/ResourceMutex.h"

extern "C" void func_ov028_021d9574(void* obj);
extern "C" void func_ov028_021d9188(void* obj);

struct Obj9668 {
    char pad[0x9c];
    unsigned char f9c;
};

// USA: func_ov028_021d9668
extern "C" ARM void func_ov028_021d9668(Obj9668* obj) {
    if (obj == 0) return;
    bool old = SetResourceMutexOperational(false);
    if (obj->f9c == 0) {
        func_ov028_021d9574(obj);
    } else {
        func_ov028_021d9188(obj);
        obj->f9c = (obj->f9c == 0) ? 1 : 0;
    }
    SetResourceMutexOperational(old);
}
