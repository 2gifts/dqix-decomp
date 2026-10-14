#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct TaggedValue02030b44 { int type; union { int i; float f; } value; };

struct Variant02030b0c;

struct EventCtx02184264 {
    char pad[8];
    SafeAllocator* allocator;
};
extern struct EventCtx02184264 data_ov000_02184264;

struct Event0216c314 {
    int type;
    int field4;
    unsigned short field8;
    unsigned short fielda;
};

extern "C" void func_ov000_02169b78(struct Event0216c314*);

// USA: func_ov000_0216c314
extern "C" ARM int func_ov000_0216c314(struct TaggedValue02030b44* obj) {
    struct Event0216c314* e = (struct Event0216c314*)data_ov000_02184264.allocator->Allocate(0xc);
    e->type = 0;
    e->field4 = 0;
    e->type = 0x60;
    e->field8 = (unsigned short)(int)(((Script::Parameter*)obj)->ToFloat() * 4096.0f);
    e->fielda = (unsigned short)((Script::Parameter*)((struct Variant02030b0c*)((char*)obj + 8)))->ToInt();
    func_ov000_02169b78(e);
    return 1;
}
