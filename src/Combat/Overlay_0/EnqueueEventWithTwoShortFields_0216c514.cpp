#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;

struct EventCtx0216c514 {
    char pad[8];
    SafeAllocator* allocator;
};
extern struct EventCtx0216c514 data_ov000_02184264;

struct Event0216c514 {
    int type;
    int field4;
    unsigned short field8;
    unsigned short fielda;
};

extern "C" void func_ov000_02169b78(struct Event0216c514*);

// USA: func_ov000_0216c514
ARM int EnqueueEventWithTwoShortFields_0216c514(struct Variant02030b0c* obj) {
    struct Event0216c514* e = (struct Event0216c514*)data_ov000_02184264.allocator->Allocate(0xc);
    e->type = 0;
    e->field4 = 0;
    e->type = 0x68;
    e->field8 = (unsigned short)((Script::Parameter*)obj)->ToInt();
    e->fielda = (unsigned short)((Script::Parameter*)((struct Variant02030b0c*)((char*)obj + 8)))->ToInt();
    func_ov000_02169b78(e);
    return 1;
}
