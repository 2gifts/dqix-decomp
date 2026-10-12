#include <globaldefs.h>
#include "System/Mutex.h"

struct AllocationCallbacks {
    unsigned char padding[4];
    void* (*allocate)(int);
};

extern Mutex data_ov031_0224f704;
extern AllocationCallbacks data_ov031_0224f670;

// USA: func_ov031_0221f9a0
extern "C" THUMB void* func_ov031_0221f9a0(void* unused, int size) {
    if (size > 0) {
        LockMutex(&data_ov031_0224f704);
        void* allocation = data_ov031_0224f670.allocate(size);
        UnlockMutex(&data_ov031_0224f704);
        return allocation;
    }
    return NULL;
}
