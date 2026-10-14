#include <globaldefs.h>
int GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4*);

extern "C" void* func_0202ae18(void);
int CheckField0NonZero_0202b7d8(int* obj);
extern "C" void func_020e321c(void*, int, int);

// USA: func_020e3328
ARM void Dispatch020e3328(void* a, int b) {
    void* ctx = func_0202ae18();
    if (CheckField0NonZero_0202b7d8((int*)ctx)) {
        int v = GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)(ctx));
        func_020e321c(a, b, v & 0xff);
    }
}
