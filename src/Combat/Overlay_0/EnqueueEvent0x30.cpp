#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

extern "C" void func_ov000_02169b78(void* node);

struct EventQueueGlobals0216b26c {
    char pad[8];
    SafeAllocator* allocator;
};
extern EventQueueGlobals0216b26c data_ov000_02184264;

struct TaggedValue02030b44 {
    int type;
    union { int i; float f; } value;
};
struct Vector3i;

struct EventNode0216b26c {
    int type;
    int next;
    int vec[3];
};

// USA: func_ov000_0216b26c
ARM int EnqueueEvent_0216b26c_0216b26c(struct TaggedValue02030b44* obj) {
    struct EventNode0216b26c* node = (struct EventNode0216b26c*)data_ov000_02184264.allocator->Allocate(0x14);
    node->type = 0;
    node->next = 0;
    node->type = 0x30;
    (TaggedValue02030b44*)((Script::Parameter*)obj)->ToVec3fix((Vector3i*)node->vec);
    func_ov000_02169b78(node);
    return 1;
}
