#include <globaldefs.h>

struct S02055080;
void* GetField0x4OrNull(struct S02055080* p);

// USA: func_02055138
ARM void* GetField0x4Field0x1cOrNull_02055138(struct S02055080* obj) {
    void* x = GetField0x4OrNull(obj);
    if (x == NULL) return NULL;
    return *(void**)((char*)x + 0x1c);
}
