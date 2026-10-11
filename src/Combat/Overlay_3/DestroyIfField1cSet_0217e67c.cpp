#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_ov009_02184848(int v);
void PopStack1AndTrigger(int flag);

// USA: func_ov003_0217e67c  (semantic: DestroyIfField1cSet_0217e67c)
extern "C" ARM void func_ov003_0217e67c(char* obj) {
    int v = *(int*)(obj + 0x1c);
    if (v != 0) {
        func_ov009_02184848(v);
        *(int*)(obj + 0x1c) = 0;
        PopStack1AndTrigger(1);
    }
    ((SafeAllocator*)(obj + 8))->Destroy();
}
