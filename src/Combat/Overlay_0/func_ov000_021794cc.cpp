#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x28
#define REGION_OFFSET_1 0x800
#else
#define REGION_OFFSET_0 0x5c
#define REGION_OFFSET_1 0x960
#endif

#include "std_library_functions.h"

struct Elem_0205d81c {
    char pad0[0xC2];
    short fieldC2;
};
struct Struct_0205d81c;

extern "C" void func_ov000_0217964c(void* obj, void* entry);
extern "C" void func_ov000_0217ab8c(void* entry, int a, int b);
extern "C" int _Z18GetField0_0205bafcPv(void* obj);
extern "C" int _Z26GetGlobalField0x1c020421a0v();
extern "C" void func_ov000_0217979c(void* obj, void* entry, void* buf);
#if defined(jpn)
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g);
#else
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g, int h);
#endif
extern "C" struct Elem_0205d81c* _Z23FindElementByC40205d81cP15Struct_0205d81ci(struct Struct_0205d81c* s, int key);
extern "C" void func_ov000_02176210(void* a, int b, int c);

// USA: func_ov000_021794cc
extern "C" ARM void func_ov000_021794cc(char* obj, void* entry, int a, int b) {
    func_ov000_0217964c(obj, entry);

    int f44 = *(int*)((char*)entry + 0x44);
    int f48 = *(int*)((char*)entry + 0x48);
    func_ov000_0217ab8c(entry, a, b);

    char* base = obj + 0x188;
#if defined(jpn)
    *(short*)(base + 0xa0) = 0x10;
#else
    *(short*)(base + 0xa0) = 0x12;
#endif
    *(short*)(base + 0xa2) = 9;
#if defined(jpn)
    *(short*)(base + 0xa4) = (f44 >> 3) + 9;
#else
    *(short*)(base + 0xa4) = (f44 >> 3) + 0xe;
#endif
    *(short*)(base + 0xa6) = (f48 >> 3);
    *(short*)(base + 0xa8) = 0xc;
    *(short*)(base + 0xaa) = 8;
    *(short*)(base + 0xac) = 0xa;
    *(short*)(base + 0xae) = 0xc;
    *(unsigned char*)(base + 0xb1) = 0x11;

    int many = 0;
    if (_Z18GetField0_0205bafcPv(base + 0x54) > 4) many = 1;

    int g = _Z26GetGlobalField0x1c020421a0v();
    void* buf = *(void**)((char*)g + REGION_OFFSET_0);
    memset(buf, 0, REGION_OFFSET_1);
    func_ov000_0217979c(obj, entry, buf);
#if defined(jpn)
    func_0205d304(base, buf, 0, 0, many, 1, 0);
#else
    func_0205d304(base, buf, 0, 0, many, 1, 0, 0);
#endif

    struct Elem_0205d81c* e = _Z23FindElementByC40205d81cP15Struct_0205d81ci((struct Struct_0205d81c*)base, 0x24);
    if (e != NULL) e->fieldC2 = 0;
    func_ov000_02176210(obj + 0x188, 0x11, 0x24);
}
