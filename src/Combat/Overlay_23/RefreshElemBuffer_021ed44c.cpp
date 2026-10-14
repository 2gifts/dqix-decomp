#include "Combat/TryApplyElemFields.h"
#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021ed44c func_ov023_021ed394
#endif
#include "std_library_functions.h"

extern "C" void func_ov023_021ed254(void* obj, void* buf);
struct StructA0205d5d0;
struct Obj021ed44c {
    char pad0[0x1c];
    void* buf1c;
    char pad20[0x438 - 0x20];
    unsigned short flags438;
};

// USA: func_ov023_021ed44c  (semantic: RefreshElemBuffer_021ed44c)
extern "C" ARM void func_ov023_021ed44c(Obj021ed44c* obj) {
    if ((obj->flags438 & 1) == 0) return;
    memset(obj->buf1c, 0,
#if defined(jpn)
        0x800);
#else
        0x960);
#endif
    func_ov023_021ed254(obj, obj->buf1c);
#if defined(jpn)
    TryApplyElemFields0205d5d0((struct StructA0205d5d0*)((char*)obj + 0xc4), 0, (int)obj->buf1c, 0);
#else
    TryApplyElemFields0205d5d0((struct StructA0205d5d0*)((char*)obj + 0xc4), 0, (int)obj->buf1c, 0, 1);
#endif
    obj->flags438 &= ~1;
}
