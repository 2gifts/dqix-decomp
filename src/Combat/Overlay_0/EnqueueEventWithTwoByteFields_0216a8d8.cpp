#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;

struct EventCtx0216a8d8 {
    char pad[8];
    SafeAllocator* allocator;
};
extern struct EventCtx0216a8d8 data_ov000_02184264;

struct Event0216a8d8 {
    int type;
    int field4;
    unsigned char field8;
    unsigned char field9;
};

extern "C" void func_ov000_02169b78(struct Event0216a8d8*);

// USA: func_ov000_0216a8d8
ARM int EnqueueEventWithTwoByteFields_0216a8d8(struct Variant02030b0c* obj) {
    struct Event0216a8d8* e = (struct Event0216a8d8*)data_ov000_02184264.allocator->Allocate(0xc);
    e->type = 0;
    e->field4 = 0;
    e->type = 0x16;
    e->field8 = (unsigned char)((Script::Parameter*)obj)->ToInt();
    e->field9 = (unsigned char)((Script::Parameter*)((struct Variant02030b0c*)((char*)obj + 8)))->ToInt();
    func_ov000_02169b78(e);
    return 1;
}
