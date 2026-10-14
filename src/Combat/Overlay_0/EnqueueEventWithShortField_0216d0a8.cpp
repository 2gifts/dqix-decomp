#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;

struct EventCtx0216d0a8 {
    char pad[8];
    SafeAllocator* allocator;
};
extern struct EventCtx0216d0a8 data_ov000_02184264;

struct Event0216d0a8 {
    int type;
    int field4;
    short field8;
};

extern "C" void func_ov000_02169b78(struct Event0216d0a8*);

// USA: func_ov000_0216d0a8
ARM int EnqueueEventWithShortField_0216d0a8(struct Variant02030b0c* obj, int flag) {
    struct Event0216d0a8* e = (struct Event0216d0a8*)data_ov000_02184264.allocator->Allocate(0xc);
    e->type = 0;
    e->field4 = 0;
    e->type = 0x8b;
    short result = -1;
    if (flag >= 1) {
        result = (short)((Script::Parameter*)obj)->ToInt();
    }
    e->field8 = result;
    func_ov000_02169b78(e);
    return 1;
}
