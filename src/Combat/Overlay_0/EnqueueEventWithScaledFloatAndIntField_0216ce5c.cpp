#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct TaggedValue02030b44 { int type; union { int i; float f; } value; };

struct Variant02030b0c;

struct EventCtx0216ce5c {
    char pad[8];
    SafeAllocator* allocator;
};
extern struct EventCtx0216ce5c data_ov000_02184264;

struct Event0216ce5c {
    int type;
    int field4;
    unsigned short field8;
    unsigned short fielda;
};

extern "C" void func_ov000_02169b78(struct Event0216ce5c*);

// USA: func_ov000_0216ce5c  (semantic: EnqueueEventWithScaledFloatAndIntField_0216ce5c)
extern "C" ARM int func_ov000_0216ce5c(struct TaggedValue02030b44* obj) {
    struct Event0216ce5c* e = (struct Event0216ce5c*)data_ov000_02184264.allocator->Allocate(0xc);
    e->type = 0x7f;
    e->field8 = (unsigned short)(int)(((Script::Parameter*)obj)->ToFloat() * 4096.0f);
    e->fielda = (unsigned short)((Script::Parameter*)((struct Variant02030b0c*)((char*)obj + 8)))->ToInt();
    func_ov000_02169b78(e);
    return 1;
}
