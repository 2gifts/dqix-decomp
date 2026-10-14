#include <globaldefs.h>

struct S02055080;
void* GetField0x4OrNull(struct S02055080* p);

// USA: func_020550a8
ARM void* GetField0x4Field0x4OrNull_020550a8(struct S02055080* obj) {
    void* x = GetField0x4OrNull(obj);
    if (x == NULL) return NULL;
    return *(void**)((char*)x + 4);
}
