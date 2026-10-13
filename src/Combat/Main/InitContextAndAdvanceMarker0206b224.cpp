#include <globaldefs.h>

#if defined(jpn)
#define func_0206b224 func_0206cba0
enum { kInitialPad = 0x18, kBufferSize = 0x140 };
#else
enum { kInitialPad = 0x4c, kBufferSize = 0x280 };
#endif

#include "std_library_functions.h"

extern "C" void func_0206b104(void* obj);
extern "C" void func_0206aa28(void* p);
extern "C" void func_0206b974(void* p, int a1, void* a2, void* a3, void* a4, int a5, int a6, int a7);
extern int StringLength(const char* s);

struct Ctx0206b224 {
    char pad0[kInitialPad];
    void* field4c;
    void* field50;
    void* field54;
    unsigned char* field58;
    char pad5c[4];
    void* field60;
};

// USA: func_0206b224  (semantic: InitContextAndAdvanceMarker0206b224)
extern "C" ARM void func_0206b224(struct Ctx0206b224* obj) {
    func_0206b104(obj);
    memset(obj->field4c, 0, kBufferSize);
    memset(obj->field50, 0, kBufferSize);

#if defined(jpn)
    int skip = 2;
    unsigned char* base = obj->field58;
#else
    int skip = 1;
    unsigned char* base = obj->field58;
    if (base[1] == 0xff) {
        skip = 2;
    }
#endif
    obj->field54 = base + skip;
    obj->field58 = base + skip;

    func_0206aa28(obj);
#if !defined(jpn)
    func_0206b974(obj, 1, obj->field50, obj->field60, (void*)0xe3, 0, 1, 1);
    int len = StringLength((const char*)obj->field60);
    memcpy(obj->field50, obj->field60, len);
#endif
}
