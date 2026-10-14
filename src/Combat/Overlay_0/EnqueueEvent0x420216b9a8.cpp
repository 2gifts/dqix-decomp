#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;

struct EventCtx0216b9a8 {
    char pad[8];
    SafeAllocator* allocator;
};
extern struct EventCtx0216b9a8 data_ov000_02184264;

struct Event0216b9a8 {
    int type;
    int unused4;
    short field8;
};

extern "C" void func_ov000_02169b78(struct Event0216b9a8*);

// USA: func_ov000_0216b9a8
ARM int EnqueueEvent_0216b9a8(struct Variant02030b0c* obj) {
    int v = ((Script::Parameter*)obj)->ToInt();
    if (v < 0) return 1;
    struct Event0216b9a8* e = (struct Event0216b9a8*)data_ov000_02184264.allocator->Allocate(0xc);
    if (e == NULL) return 0;
    e->type = 0;
    e->unused4 = 0;
    e->type = 0x42;
    e->field8 = (short)v;
    func_ov000_02169b78(e);
    return 1;
}
