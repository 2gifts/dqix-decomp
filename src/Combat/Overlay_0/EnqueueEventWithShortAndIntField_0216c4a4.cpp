#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;

struct EventCtx0216c4a4 {
    char pad[8];
    SafeAllocator* allocator;
};
extern struct EventCtx0216c4a4 data_ov000_02184264;

struct Event0216c4a4 {
    int type;
    int field4;
    unsigned short field8;
    unsigned short pad2;
    int fieldc;
};

extern "C" void func_ov000_02169b78(struct Event0216c4a4*);

// USA: func_ov000_0216c4a4
ARM int EnqueueEventWithShortAndIntField_0216c4a4(struct Variant02030b0c* obj) {
    struct Event0216c4a4* e = (struct Event0216c4a4*)data_ov000_02184264.allocator->Allocate(0x10);
    e->type = 0;
    e->field4 = 0;
    e->type = 0x66;
    e->field8 = (unsigned short)((Script::Parameter*)obj)->ToInt();
    e->fieldc = ((Script::Parameter*)((struct Variant02030b0c*)((char*)obj + 8)))->ToInt();
    func_ov000_02169b78(e);
    return 1;
}
