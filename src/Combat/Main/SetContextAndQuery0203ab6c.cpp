#include <globaldefs.h>

void* SetGlobalContext02110370_020bd42c(void*);
int IsQueryResultZero020bdcc4(void*, int, int);

// USA: func_0203ab6c
ARM int SetContextAndQuery0203ab6c(void* obj, void* arg1) {
    char* p = (char*)obj;
    if (*(void**)p == NULL) return 0;
    SetGlobalContext02110370_020bd42c(p + 0x4);
    IsQueryResultZero020bdcc4(arg1, 6, *(int*)p);
    return 1;
}
