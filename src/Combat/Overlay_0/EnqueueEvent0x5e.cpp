#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_ov000_02169b78(void* node);

struct EventQueueGlobals0216c28c {
    char pad[8];
    SafeAllocator* allocator;
};
extern EventQueueGlobals0216c28c data_ov000_02184264;

struct EventNode0216c28c {
    int type;
    int next;
    int unused;
};

// USA: func_ov000_0216c28c
ARM int EnqueueEvent0x5e_ov000_0216c28c(void) {
    struct EventNode0216c28c* node = (struct EventNode0216c28c*)data_ov000_02184264.allocator->Allocate(0xc);
    node->type = 0;
    node->next = 0;
    node->type = 0x5e;
    func_ov000_02169b78(node);
    return 1;
}
