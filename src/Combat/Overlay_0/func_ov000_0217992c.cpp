#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x28
#define REGION_OFFSET_1 0x800
#else
#define REGION_OFFSET_0 0x5c
#define REGION_OFFSET_1 0x960
#endif

#include "std_library_functions.h"

extern "C" void func_ov000_0217ab8c(void* obj, int a, int b);
extern "C" void func_ov000_02179a70(void* obj, void* ptr, int val2, void* buf);
int GetGlobalField0x1c020421a0(void);
#if defined(jpn)
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g);
#else
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g, int h);
#endif

// USA: func_ov000_0217992c  (semantic: ApplyElemFieldsAndDispatch_0217992c)
extern "C" ARM void func_ov000_0217992c(char* obj, void* ptr, int val2, int val3) {
    if (ptr == NULL) return;

    int f44 = *(int*)((char*)ptr + 0x44);
    int f48 = *(int*)((char*)ptr + 0x48);
    func_ov000_0217ab8c(ptr, val2, val3);

    signed char kind = *(signed char*)(obj + 0x78);
    char* base = obj + 0x188;
    if (kind == 3) {
#if defined(jpn)
        *(short*)(base + 0xa0) = 0xa;
#else
        *(short*)(base + 0xa0) = 0xc;
#endif
        *(short*)(base + 0xa2) = 6;
    } else {
#if defined(jpn)
        *(short*)(base + 0xa0) = 0xa;
#else
        *(short*)(base + 0xa0) = 0xc;
#endif
        *(short*)(base + 0xa2) = 1;
    }
#if defined(jpn)
    *(short*)(base + 0xa4) = (f44 >> 3) + 0x16;
#else
    *(short*)(base + 0xa4) = (f44 >> 3) + 0x14;
#endif
    *(short*)(base + 0xa6) = (f48 >> 3);
    *(short*)(base + 0xa8) = 0xc;
    *(short*)(base + 0xaa) = 8;
    *(short*)(base + 0xac) = 0xa;
    *(short*)(base + 0xae) = 0xb;
    *(unsigned char*)(base + 0xb1) = 0x12;

    int g = GetGlobalField0x1c020421a0();
    void* buf = *(void**)((char*)g + REGION_OFFSET_0);
    memset(buf, 0, REGION_OFFSET_1);
    func_ov000_02179a70(obj, ptr, val2, buf);
#if defined(jpn)
    func_0205d304(base, buf, 0, 1, 0, 1, 0);
#else
    func_0205d304(base, buf, 0, 1, 0, 1, 0, 0);
#endif
}
