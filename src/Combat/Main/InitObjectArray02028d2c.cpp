#include <globaldefs.h>
void FinalizeSubObjects02028cfc(void*);

extern "C" void func_020287b4(void* obj);
extern "C" void func_0200ef44(void* obj, int count, int size, void* initFn);

// USA: func_02028d2c
ARM void* InitObjectArray02028d2c(void* obj) {
    func_020287b4(obj);
#if defined(jpn)
    func_0200ef44(obj, 4, 0x314, (void*)FinalizeSubObjects02028cfc);
#else
    func_0200ef44(obj, 4, 0x318, (void*)FinalizeSubObjects02028cfc);
#endif
    return obj;
}
