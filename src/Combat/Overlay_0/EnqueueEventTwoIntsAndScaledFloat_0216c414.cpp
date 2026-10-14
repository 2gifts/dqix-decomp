#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct TaggedValue02030b44 { int type; union { int i; float f; } value; };

struct Variant02030b0c;

struct EventCtx0216c414 {
    char pad[8];
    SafeAllocator* allocator;
};
extern struct EventCtx0216c414 data_ov000_02184264;

struct Event0216c414 {
    int type;
    int field4;
    unsigned short field8;
    unsigned short fielda;
    unsigned short fieldc;
};

extern "C" void func_ov000_02169b78(struct Event0216c414*);

// USA: func_ov000_0216c414  (semantic: EnqueueEventTwoIntsAndScaledFloat_0216c414)
extern "C" ARM int func_ov000_0216c414(struct Variant02030b0c* obj) {
    struct Event0216c414* e = (struct Event0216c414*)data_ov000_02184264.allocator->Allocate(0x10);
    e->type = 0;
    e->field4 = 0;
    e->type = 0x64;
    e->field8 = (unsigned short)((Script::Parameter*)obj)->ToInt();
    e->fielda = (unsigned short)(int)(((Script::Parameter*)((struct TaggedValue02030b44*)((char*)obj + 8)))->ToFloat() * 4096.0f);
    e->fieldc = (unsigned short)((Script::Parameter*)((struct Variant02030b0c*)((char*)obj + 0x10)))->ToInt();
    func_ov000_02169b78(e);
    return 1;
}
