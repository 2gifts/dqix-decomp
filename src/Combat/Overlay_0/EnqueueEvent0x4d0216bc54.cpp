#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct TaggedValue02030b44;

struct EventCtx0216bc54 {
    char pad[8];
    SafeAllocator* allocator;
};
extern struct EventCtx0216bc54 data_ov000_02184264;

struct Event0216bc54 {
    int type;
    int unused4;
    int field8;
};

extern "C" void func_ov000_02169b78(struct Event0216bc54*);

// USA: func_ov000_0216bc54
ARM int EnqueueEvent_0216bc54(struct TaggedValue02030b44* obj) {
    struct Event0216bc54* e = (struct Event0216bc54*)data_ov000_02184264.allocator->Allocate(0xc);
    e->type = 0x4d;
    e->field8 = (int)(4096.0f * ((Script::Parameter*)obj)->ToFloat());
    func_ov000_02169b78(e);
    return 1;
}
