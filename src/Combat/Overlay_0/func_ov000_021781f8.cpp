#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int _Z26GetGlobalField0x1c020421a0v();
extern "C" void _Z35NotifyLocalizedResourceLoad020dcfc8iPc(int id, char* buf);
extern "C" void func_02046608(int a, int b, void* fmt, void* dst, int p4, int p5, int p6);
struct Struct_0205d81c;
struct Elem_0205d81c;
extern "C" struct Elem_0205d81c* _Z23FindElementByC40205d81cP15Struct_0205d81ci(struct Struct_0205d81c* s, int key);
struct StructA0205d5d0;
extern "C" int _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(struct StructA0205d5d0*, int, int, int, unsigned char);
extern "C" void func_0205d304(void* s, void* buf, int a, int b, int c, int d, int e, int f);

struct InStruct_021781f8 {
    char pad[0x44];
    int x;
    int y;
};

// USA: func_ov000_021781f8
extern "C" ARM void func_ov000_021781f8(char* obj, struct InStruct_021781f8* in) {
    char text[0x800];
    char* msg;
    char* buf = *(char**)(_Z26GetGlobalField0x1c020421a0v() + 0x5c);
    memset(buf, 0, 0x960);
    _Z35NotifyLocalizedResourceLoad020dcfc8iPc(*(short*)(obj + 0x26 + *(signed char*)(obj + 0x1d6f) * 2), buf);
    func_02046608(_Z26GetGlobalField0x1c020421a0v(), 0xa, buf, text, 0x72, 0, 0);
    char* s = obj + 0x188;
    msg = text;
    if (_Z23FindElementByC40205d81cP15Struct_0205d81ci((struct Struct_0205d81c*)s, 0x21)) {
        _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih((struct StructA0205d5d0*)s, 0x21, (int)msg, 1, 0);
        return;
    }
    int x = in->x;
    int y = in->y;
    *(short*)(s + 0xa0) = 0x10;
    *(short*)(s + 0xa2) = 8;
    *(short*)(s + 0xa4) = (x >> 3) + 0x10;
    *(short*)(s + 0xa6) = y >> 3;
    *(short*)(s + 0xa8) = 7;
    *(short*)(s + 0xaa) = 5;
    *(short*)(s + 0xac) = 0xa;
    *(short*)(s + 0xae) = 0xe;
    *(unsigned char*)(s + 0xb1) = 0x21;
    func_0205d304(s, msg, 0, 0, 0, 1, 0, 0);
}
