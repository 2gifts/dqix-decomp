#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct TaggedValue02030b44 { int type; union { int i; float f; } value; };

struct EventCtx0216cd28 {
    char pad[8];
    SafeAllocator* allocator;
};
extern struct EventCtx0216cd28 data_ov000_02184264;

struct Event0216cd28 {
    int type;
    int field4;
    int field8;
};

extern "C" void func_ov000_02169b78(struct Event0216cd28*);

// USA: func_ov000_0216cd28
ARM int EnqueueEventWithScaledFloatField_0216cd28(struct TaggedValue02030b44* obj, int flag) {
    struct Event0216cd28* e = (struct Event0216cd28*)data_ov000_02184264.allocator->Allocate(0xc);
    e->type = 0x7b;
    int result = 0xf000;
    if (flag > 0) {
        float val = ((Script::Parameter*)obj)->ToFloat();
        result = (int)(val * 4096.0f);
    }
    e->field8 = result;
    func_ov000_02169b78(e);
    return 1;
}
