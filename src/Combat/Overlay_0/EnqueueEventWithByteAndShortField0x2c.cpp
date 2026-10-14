#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;

struct EventCtx0216b110 {
    char pad[8];
    SafeAllocator* allocator;
};
extern struct EventCtx0216b110 data_ov000_02184264;

struct Event0216b110 {
    int type;
    int field4;
    unsigned short field8;
    unsigned char fielda;
};

extern "C" void func_ov000_02169b78(struct Event0216b110*);

// USA: func_ov000_0216b110
ARM int EnqueueEventWithByteAndShortField_0216b110(struct Variant02030b0c* obj) {
    struct Event0216b110* e = (struct Event0216b110*)data_ov000_02184264.allocator->Allocate(0xc);
    e->type = 0;
    e->field4 = 0;
    e->type = 0x2c;
    e->fielda = (unsigned char)((Script::Parameter*)obj)->ToInt();
    e->field8 = (unsigned short)((Script::Parameter*)((struct Variant02030b0c*)((char*)obj + 8)))->ToInt();
    func_ov000_02169b78(e);
    return 1;
}
