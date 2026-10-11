#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x28
#define REGION_OFFSET_1 0x800
#else
#define REGION_OFFSET_0 0x5c
#define REGION_OFFSET_1 0x960
#endif

#include "std_library_functions.h"

struct Struct_0205ba68;
struct Node0205bacc;

extern "C" int func_ov000_0217538c(void* obj);
extern "C" int func_ov000_021753d8(void* obj, int targetIndex);
extern "C" void func_ov000_0217c638(void* obj, int a, int b);
extern "C" void _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii(struct Struct_0205ba68* s, int a, int b, int mode);
extern "C" void _Z29SetField0AndPropagate0205baccP12Node0205bacci(struct Node0205bacc* s, int val);
extern "C" void func_0205bb04(void* s, int n);
extern "C" int _Z26GetGlobalField0x1c020421a0v();
extern "C" void func_ov000_0217a688(void* obj, void* entry, int b, void* buf);
#if defined(jpn)
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g);
#else
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g, int h);
#endif

// USA: func_ov000_0217a514
extern "C" ARM void func_ov000_0217a514(char* obj, char* entry, int a, int b) {
    if (entry == NULL) return;

    int groups = func_ov000_0217538c(obj);
    int group = func_ov000_021753d8(obj, *(signed char*)(entry + 0x1d));
    func_ov000_0217c638(obj, a, b);

    char* base = obj + 0x188;
#if defined(jpn)
    *(short*)(base + 0xa0) = 1;
#else
    *(short*)(base + 0xa0) = 0x10;
#endif
    *(short*)(base + 0xa2) = 1;
    *(short*)(base + 0xa4) = 0xd;
    *(short*)(base + 0xa6) = 9;
    *(short*)(base + 0xa8) = 0xc;
    *(short*)(base + 0xaa) = 6;
    *(short*)(base + 0xac) = 0xa;
    *(short*)(base + 0xae) = 0x10;
    *(unsigned char*)(base + 0xb1) = 0x19;

    _Z25SetupPointerTable0205ba68P15Struct_0205ba68iii((struct Struct_0205ba68*)(obj + 0x244), 1, groups, 0);
    *(int*)(obj + 0x248) = 1;
    _Z29SetField0AndPropagate0205baccP12Node0205bacci((struct Node0205bacc*)(obj + 0x244), groups);
    func_0205bb04(obj + 0x244, group);

    int g = _Z26GetGlobalField0x1c020421a0v();
    void* buf = *(void**)((char*)g + REGION_OFFSET_0);
    memset(buf, 0, REGION_OFFSET_1);
    func_ov000_0217a688(obj, entry, b, buf);
#if defined(jpn)
    func_0205d304(base, buf, 0, 1, 0, 1, 0);
#else
    func_0205d304(base, buf, 0, 1, 0, 1, 0, 0);
#endif
}
