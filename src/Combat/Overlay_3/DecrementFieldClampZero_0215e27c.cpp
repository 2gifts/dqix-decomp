#include <globaldefs.h>

#if defined(jpn)
enum { counterOffset = 0x400 };
#else
enum { counterOffset = 0x3e8 };
#endif
struct Obj0215e27c { char unk[counterOffset]; int counter; };

// USA: func_ov003_0215e27c
#pragma optimize_for_size off
ARM int DecrementFieldClampZero_0215e27c(struct Obj0215e27c* obj, int amount) {
    if (obj->counter > amount) {
        obj->counter -= amount;
    } else {
        obj->counter = 0;
        return 0;
    }
    return 1;
}
