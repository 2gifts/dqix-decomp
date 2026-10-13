#include <globaldefs.h>
#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

#include "std_library_functions.h"

extern "C" void func_ov008_02187708(void* obj, void* ptr, int arg2);
#if defined(jpn)
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g);
#else
extern "C" void func_0205d304(void* a, void* b, int c, int d, int e, int f, int g, int h);
#endif

struct Manager02187664 {
    char pad0[0xb8];
    void* ptrB8;
    char pad1[0x1d0 - 0xbc];
    unsigned short f1d0;
    unsigned short f1d2;
    unsigned short f1d4;
    unsigned short f1d6;
    unsigned short f1d8;
    unsigned short f1da;
    unsigned short f1dc;
    unsigned short f1de;
    char pad2[0x1e1 - 0x1e0];
    unsigned char f1e1;
    char pad3[0x1e5 - 0x1e2];
    unsigned char f1e5;
    unsigned char f1e6;
    unsigned char f1e7;
};

// USA: func_ov008_02187664
ARM void InitConfig02187664(Manager02187664* obj, int arg1) {
    obj->f1d0 = 0x1e;
    obj->f1d2 = LOW_REGION(2, 3);
    obj->f1d4 = 2;
    obj->f1d6 = 0;
    obj->f1d8 = LOW_REGION(0, 1);
    obj->f1da = LOW_REGION(3, 2);
    obj->f1dc = 0xa;
    obj->f1de = 0xa;
    obj->f1e7 = 0xa;
    obj->f1e1 = 0;
    obj->f1e5 = 1;
    obj->f1e6 = 1;
    memset(obj->ptrB8, 0, LOW_REGION(0x800, 0x960));
    func_ov008_02187708(obj, obj->ptrB8, arg1);
#if defined(jpn)
    func_0205d304((char*)obj + 0x130, obj->ptrB8, 0, 0, 0, 0, 0);
#else
    func_0205d304((char*)obj + 0x130, obj->ptrB8, 0, 0, 0, 0, 0, 0);
#endif
}
