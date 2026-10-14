#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;

struct EventCtx0216c624 {
    char pad[8];
    SafeAllocator* allocator;
};
extern struct EventCtx0216c624 data_ov000_02184264;

struct Event0216c624 {
    int type;
    int field4;
    unsigned char field8;
    char pad1;
    unsigned short fielda;
};

extern "C" void func_ov000_02169b78(struct Event0216c624*);

// USA: func_ov000_0216c624
ARM int EnqueueEventWithByteAndShortField_0216c624(struct Variant02030b0c* obj) {
    struct Event0216c624* e = (struct Event0216c624*)data_ov000_02184264.allocator->Allocate(0xc);
    e->type = 0;
    e->field4 = 0;
    e->type = 0x6c;
    e->field8 = (unsigned char)((Script::Parameter*)obj)->ToInt();
    e->fielda = (unsigned short)((Script::Parameter*)((struct Variant02030b0c*)((char*)obj + 8)))->ToInt();
    func_ov000_02169b78(e);
    return 1;
}
