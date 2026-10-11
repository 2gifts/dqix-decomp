#if defined(jpn)
#define R(j,u) (j)
#define _Z26CallVTableFnAt244_021f66f4PviS_ _Z26CallVTableFnAt240_021f66bcPviS_
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" void* func_ov004_0215e47c(void* a, int key);
extern "C" void func_ov023_021fcc68(void* node, void* a);
#if defined(jpn)
#define CallVTableFnAt244_021f66f4 _Z26CallVTableFnAt240_021f66bcPviS_
extern "C" void CallVTableFnAt244_021f66f4(void* a, int key, void* arg3);
#else
void CallVTableFnAt244_021f66f4(void* a, int key, void* arg3);
#endif

// USA: func_ov004_02162acc
ARM int DispatchAndCallVTable244_02162acc(void* a) {
    void* node = func_ov004_0215e47c(a, 0x82);
    if (node != NULL) {
        func_ov023_021fcc68(node, a);
        CallVTableFnAt244_021f66f4(a, 0x86, (void*)1);
    }
    return 0;
}
