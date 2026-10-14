#include <globaldefs.h>
#include "System/ProcessorContext.h"
#include "Memory/SignedAllocator.h"

struct FourWords;
struct Mutex;
void ZeroInitializeMutex(Mutex*);
extern "C" void func_020c015c();

// USA: func_020bf2f8  (semantic: InitTaskContext020bf2f8)
extern "C" ARM void func_020bf2f8(void* obj, unsigned int param1) {
    PopulateContext((ProcessorContext*)obj, (unsigned int)func_020c015c, (unsigned int)obj, (unsigned int)((char*)obj + 0x4c0), 0x400, param1);
    ((SignedAllocatorList*)((char*)obj + 0x4e0))->Initialize(0);
    ZeroInitializeMutex((Mutex*)((char*)obj + 0x4c8));
    *(int*)((char*)obj + 0x4c4) = 0;
    *(int*)((char*)obj + 0x4c0) = 0;
    MarkContextReadyAndSwitch((ProcessorContext*)obj);
}
