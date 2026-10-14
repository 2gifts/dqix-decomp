#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct TaggedValue02030b44;

struct EventCtx0216be00 {
    char pad[8];
    SafeAllocator* allocator;
};
extern struct EventCtx0216be00 data_ov000_02184264;

struct Event0216be00 {
    int type;
    int unused4;
    short field8;
};

extern "C" void func_ov000_02169b78(struct Event0216be00*);

// USA: func_ov000_0216be00
ARM int EnqueueEvent_0216be00(struct TaggedValue02030b44* obj) {
    struct Event0216be00* e = (struct Event0216be00*)data_ov000_02184264.allocator->Allocate(0xc);
    e->type = 0x54;
    e->field8 = (short)(int)(4096.0f * ((Script::Parameter*)obj)->ToFloat());
    func_ov000_02169b78(e);
    return 1;
}
