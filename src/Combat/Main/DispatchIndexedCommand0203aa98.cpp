#include <globaldefs.h>

void* SetGlobalContext02110370_020bd42c(void* value);
int IsDispatchResultZero020bdc80(void* obj, int arg);

// USA: func_0203aa98
ARM int DispatchIndexedCommand0203aa98(void* obj, int index) {
    if (*(int*)obj == 0) return 0;
    if (index >= 0xffff || index < 0) return 0;
    SetGlobalContext02110370_020bd42c((char*)obj + 4);
    return IsDispatchResultZero020bdc80((void*)index, *(int*)obj) != 0 ? 1 : 0;
}
