#include <globaldefs.h>

void* SetGlobalContext02110370(void*);
void* CallFunc020bc548OnField0(void* obj, int arg2);

// USA: func_0203ac10
ARM void SetContextAndDispatch0203ac10(void* obj, void* a, int b) {
    char* p = (char*)obj;
    if (*(void**)p == NULL) return;
    SetGlobalContext02110370(p + 0x4);
    CallFunc020bc548OnField0(a, b);
}
