#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct TaggedValue02030b44 { int type; union { int i; float f; } value; };

struct Variant02030b0c;

struct EventCtx0216c8e4 {
    char pad[8];
    SafeAllocator* allocator;
};
extern struct EventCtx0216c8e4 data_ov000_02184264;

struct Event0216c8e4 {
    int type;
    int field4;
    unsigned short field8;
    unsigned short fielda;
    unsigned short fieldc;
};

extern "C" void func_ov000_02169b78(struct Event0216c8e4*);

// USA: func_ov000_0216c8e4  (semantic: EnqueueEventScaledFloatAndTwoInts_0216c8e4)
extern "C" ARM int func_ov000_0216c8e4(struct TaggedValue02030b44* obj) {
    struct Event0216c8e4* e = (struct Event0216c8e4*)data_ov000_02184264.allocator->Allocate(0x10);
    if (e == 0) return 0;
    e->type = 0x74;
    e->field8 = (unsigned short)(int)(((Script::Parameter*)obj)->ToFloat() * 4096.0f);
    e->fielda = (unsigned short)((Script::Parameter*)((struct Variant02030b0c*)((char*)obj + 8)))->ToInt();
    e->fieldc = (unsigned short)((Script::Parameter*)((struct Variant02030b0c*)((char*)obj + 0x10)))->ToInt();
    func_ov000_02169b78(e);
    return 1;
}
