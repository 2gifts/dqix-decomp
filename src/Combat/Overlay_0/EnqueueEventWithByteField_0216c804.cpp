#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;

struct EventCtx0216c804 {
    char pad[8];
    SafeAllocator* allocator;
};
extern struct EventCtx0216c804 data_ov000_02184264;

struct Event0216c804 {
    int type;
    int unused4;
    unsigned char field8;
};

extern "C" void func_ov000_02169b78(struct Event0216c804*);

// USA: func_ov000_0216c804
#pragma optimize_for_size off
ARM int EnqueueEventWithByteField_0216c804(struct Variant02030b0c* obj, int count) {
    struct Event0216c804* e = (struct Event0216c804*)data_ov000_02184264.allocator->Allocate(0xc);
    e->type = 0x72;
    unsigned char v = 0;
    if (count >= 1) {
        v = (unsigned char)((Script::Parameter*)obj)->ToInt();
    }
    e->field8 = v;
    func_ov000_02169b78(e);
    return 1;
}
