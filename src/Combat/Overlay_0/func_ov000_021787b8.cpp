#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_0205ba68;
struct Node0205bacc;

extern "C" int _Z26GetGlobalField0x1c020421a0v();
extern "C" void _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii(struct Struct_0205ba68* s, int a, int b, int mode);
extern "C" void _Z29SetField0AndPropagate0205baccP12Node0205bacci(struct Node0205bacc* s, int val);
extern "C" void func_0205bb04(void* s, int n);
extern "C" int func_ov000_0217538c(void* objRaw);
extern "C" int func_ov000_021753d8(void* objRaw, int targetIndex);
extern "C" void func_ov000_0217ab8c(void* obj, int a, int b);
extern "C" void func_ov000_02178938(void* obj, void* in, int b, void* buf);
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g, int h);

struct InStruct_021787b8 {
    char pad0[0x1d];
    signed char position;
    char pad1e[0x44 - 0x1e];
    int x;
    int y;
};

// USA: func_ov000_021787b8
extern "C" ARM void func_ov000_021787b8(void* objRaw, struct InStruct_021787b8* in, int mode, int arg3) {
    char* obj = (char*)objRaw;
    if (in == 0) {
        return;
    }
    int x = in->x;
    int y = in->y;
    int groupCount = func_ov000_0217538c(obj);
    int group = func_ov000_021753d8(obj, in->position);
    func_ov000_0217ab8c(in, mode, arg3);
    char* s = obj + 0x188;
    *(short*)(s + 0xa0) = 0x10;
    *(short*)(s + 0xa2) = 1;
    *(short*)(s + 0xa4) = (x >> 3) + 0xe;
    *(short*)(s + 0xa6) = y >> 3;
    *(short*)(s + 0xa8) = 0xc;
    *(short*)(s + 0xaa) = 6;
    *(short*)(s + 0xac) = 0xa;
    *(short*)(s + 0xae) = 0x10;
    *(unsigned char*)(s + 0xb1) = 0xe;
    _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii((struct Struct_0205ba68*)(obj + 0x244), 1, groupCount, 0);
    *(int*)(obj + 0x248) = 1;
    _Z29SetField0AndPropagate0205baccP12Node0205bacci((struct Node0205bacc*)(obj + 0x244), groupCount);
    func_0205bb04(obj + 0x244, group);
    void* buf = *(void**)((char*)_Z26GetGlobalField0x1c020421a0v() + 0x5c);
    memset(buf, 0, 0x960);
    func_ov000_02178938(obj, in, arg3, buf);
    func_0205d304(s, buf, 0, 1, 0, 1, 0, 0);
}
