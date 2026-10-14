#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;

struct EventCtx0216cd90 {
    char pad[8];
    SafeAllocator* allocator;
};
extern struct EventCtx0216cd90 data_ov000_02184264;

struct Event0216cd90 {
    int type;
    int unused4;
    unsigned short field8;
};

extern "C" void func_ov000_02169b78(struct Event0216cd90*);

// USA: func_ov000_0216cd90
ARM int EnqueueEventWithShortField_0216cd90(struct Variant02030b0c* obj, int count) {
    struct Event0216cd90* e = (struct Event0216cd90*)data_ov000_02184264.allocator->Allocate(0xc);
    e->type = 0x7c;
    unsigned short v = 0;
    if (count > 0) {
        v = (unsigned short)((Script::Parameter*)obj)->ToInt();
    }
    e->field8 = v;
    func_ov000_02169b78(e);
    return 1;
}
