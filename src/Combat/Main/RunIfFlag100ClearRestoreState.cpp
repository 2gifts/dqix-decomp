#include <globaldefs.h>
#include "Resource/ResourceMutex.h"

struct FlagWord02046708;
int TestFlags02046708(struct FlagWord02046708* word, unsigned int mask);
void* GetDataPtr02114e04_020d6c00(void);

extern "C" void func_020dbae0(void* obj);

// USA: func_020dbc0c  (semantic: RunIfFlag100ClearRestoreState)
extern "C" ARM void func_020dbc0c(void* obj) {
    bool old = SetResourceMutexOperational(false);
    if (!TestFlags02046708((struct FlagWord02046708*)GetDataPtr02114e04_020d6c00(), 0x100)) {
        func_020dbae0(obj);
    }
    SetResourceMutexOperational(old);
}
