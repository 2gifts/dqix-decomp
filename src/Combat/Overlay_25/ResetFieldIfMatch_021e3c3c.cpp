#include <globaldefs.h>

#if defined(jpn)
enum { kGlobalHolderInnerOffset = 0x4 };
#else
enum { kGlobalHolderInnerOffset = 0xc };
#endif


#if defined(jpn)
#define ResetFieldIfMatch_021e3c3c func_ov025_021e412c
#endif

extern "C" int func_ov025_021eb050(void* obj);
extern "C" void func_ov025_021eb044(void* obj, int val);
extern int data_ov025_021ef988;

struct Obj021e3c3c {
    char pad[0x8];
    unsigned short field8;
};

// USA: func_ov025_021e3c3c
#if defined(jpn)
extern "C"
#endif
ARM int ResetFieldIfMatch_021e3c3c(struct Obj021e3c3c* obj) {
    char* base = *(char**)((char*)&data_ov025_021ef988 + kGlobalHolderInnerOffset);
    int val = func_ov025_021eb050(base);
    if (obj->field8 == val) {
        base = *(char**)((char*)&data_ov025_021ef988 + kGlobalHolderInnerOffset);
        func_ov025_021eb044(base, 0);
    }
    return 1;
}
