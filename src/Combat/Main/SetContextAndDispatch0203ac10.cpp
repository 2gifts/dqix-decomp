#include <globaldefs.h>

void* SetGlobalContext02110370_020bd42c(void*);
void* CallFunc020bc548OnField0_020bc018(void* obj, int arg2);

// USA: func_0203ac10
ARM void SetContextAndDispatch0203ac10(void* obj, void* a, int b) {
    char* p = (char*)obj;
    if (*(void**)p == NULL) return;
    SetGlobalContext02110370_020bd42c(p + 0x4);
    CallFunc020bc548OnField0_020bc018(a, b);
}
