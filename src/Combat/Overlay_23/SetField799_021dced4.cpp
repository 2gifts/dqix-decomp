#include <globaldefs.h>

struct StatusTextMultiplier021dced4 {
#if defined(jpn)
    char padding[0x715];
#else
    char padding[0x799];
#endif
    unsigned char multiplier;
};

// USA: func_ov023_021dced4  (semantic: SetField799_021dced4)
extern "C" ARM void func_ov023_021dced4(void* obj, unsigned char v) {
    ((StatusTextMultiplier021dced4*)obj)->multiplier = v;
}
