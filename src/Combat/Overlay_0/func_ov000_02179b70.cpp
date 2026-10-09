#include <globaldefs.h>
#include "std_library_functions.h"

struct Elem_0205d81c {
    char pad0[0xc2];
    unsigned short fieldC2;
    char pad1[0xe0 - 0xc4];
};

struct Struct_0205d81c;

extern "C" void func_ov000_02179cdc(void* obj, void* ptr);
extern "C" void func_ov000_0217ab8c(void* obj, int a, int b);
extern "C" int _Z26GetGlobalField0x1c020421a0v(void);
extern "C" void func_ov000_02179ed8(void* obj, void* entry, void* buf);
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g, int h);
extern "C" struct Elem_0205d81c* _Z23FindElementByC40205d81cP15Struct_0205d81ci(struct Struct_0205d81c* s, int key);
extern "C" void func_ov000_02176210(void* obj, int a, int b);

// USA: func_ov000_02179b70
extern "C" ARM void func_ov000_02179b70(char* obj, void* ptr, int val2, int val3) {
    func_ov000_02179cdc(obj, ptr);
    int f44 = *(int*)((char*)ptr + 0x44);
    int f48 = *(int*)((char*)ptr + 0x48);
    func_ov000_0217ab8c(ptr, val2, val3);

    char* base = obj + 0x188;
    *(short*)(base + 0xa0) = 0x10;
    *(short*)(base + 0xa2) = 1;
    *(short*)(base + 0xa4) = (f44 >> 3) + 0x10;
    *(short*)(base + 0xa6) = (f48 >> 3);
    *(short*)(base + 0xa8) = 0xc;
    *(short*)(base + 0xaa) = 0xa;
    *(short*)(base + 0xac) = 0xa;
    *(short*)(base + 0xae) = 0xe;
    *(unsigned char*)(base + 0xb1) = 0x15;

    void* buf = *(void**)(_Z26GetGlobalField0x1c020421a0v() + 0x5c);
    memset(buf, 0, 0x960);
    func_ov000_02179ed8(obj, ptr, buf);
    func_0205d304(base, buf, 0, 1, 0, 1, 0, 0);

    struct Elem_0205d81c* e = _Z23FindElementByC40205d81cP15Struct_0205d81ci((struct Struct_0205d81c*)base, 0x16);
    if (e != NULL) {
        e->fieldC2 = 0;
    }
    func_ov000_02176210(obj + 0x188, 0x15, 0x16);
}
