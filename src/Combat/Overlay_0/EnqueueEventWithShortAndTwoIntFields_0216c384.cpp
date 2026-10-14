#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;

struct EventCtx0216c384 {
    char pad[8];
    SafeAllocator* allocator;
};
extern struct EventCtx0216c384 data_ov000_02184264;

struct Event0216c384 {
    int type;
    int field4;
    unsigned short field8;
    int fieldc;
    int field10;
};

extern "C" void func_ov000_02169b78(struct Event0216c384*);

// USA: func_ov000_0216c384
ARM int EnqueueEventWithShortAndTwoIntFields_0216c384(struct Variant02030b0c* obj) {
    struct Event0216c384* e = (struct Event0216c384*)data_ov000_02184264.allocator->Allocate(0x14);
    e->type = 0;
    e->field4 = 0;
    e->type = 0x61;
    e->field8 = (unsigned short)((Script::Parameter*)obj)->ToInt();
    e->fieldc = ((Script::Parameter*)((struct Variant02030b0c*)((char*)obj + 8)))->ToInt();
    e->field10 = ((Script::Parameter*)((struct Variant02030b0c*)((char*)obj + 0x10)))->ToInt();
    func_ov000_02169b78(e);
    return 1;
}
