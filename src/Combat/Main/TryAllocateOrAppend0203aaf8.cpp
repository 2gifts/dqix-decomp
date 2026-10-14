#include <globaldefs.h>

struct Obj020bdac0;
int SaveStateAndAllocateChild020bdac0(struct Obj020bdac0* obj);
void* SetGlobalContext02110370_020bd42c(void*);
int IsQueryResultZero020bdcc4(void*, int, int);
int IsQueryResultZeroWildcard020bdc98(void*, int);

// USA: func_0203aaf8
ARM int TryAllocateOrAppend0203aaf8(void* obj, void* arg1, int* out) {
    char* p = (char*)obj;
    if (*(void**)p == NULL) return 0;
    SetGlobalContext02110370_020bd42c(p + 0x4);
    if (out != NULL) {
        IsQueryResultZero020bdcc4(arg1, 3, *(int*)p);
        *out = SaveStateAndAllocateChild020bdac0(*(struct Obj020bdac0**)p);
        IsQueryResultZero020bdcc4(arg1, 4, *(int*)p);
    } else {
        IsQueryResultZeroWildcard020bdc98(arg1, *(int*)p);
    }
    return 1;
}
