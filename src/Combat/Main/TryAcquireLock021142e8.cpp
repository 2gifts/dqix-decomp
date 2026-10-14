#include <globaldefs.h>

extern "C" int func_020c7ea0(void*, void*, int);
extern "C" void func_020c7f44(void*, void*, int);
void InvalidateDataCacheRange(const void* addr, unsigned int size);

extern int data_021142e8;

// USA: func_020d4064
ARM void* TryAcquireLock021142e8_020d4064(void) {
    void* local;
    if (func_020c7ea0(&data_021142e8, &local, 0) == 0) {
        return NULL;
    }
    InvalidateDataCacheRange((const void*)((int)local), 2);
    if (*(unsigned short*)local & 0x8000) {
        return local;
    }
    func_020c7f44(&data_021142e8, local, 1);
    return NULL;
}
