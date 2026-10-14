#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;

struct EventCtx0216cdec {
    char pad[8];
    SafeAllocator* allocator;
};
extern struct EventCtx0216cdec data_ov000_02184264;

struct Event0216cdec {
    int type;
    int unused4;
    signed short field8;
};

extern "C" void func_ov000_02169b78(struct Event0216cdec*);

// USA: func_ov000_0216cdec
ARM int EnqueueEventWithSignedShortField_0216cdec(struct Variant02030b0c* obj, int count) {
    struct Event0216cdec* e = (struct Event0216cdec*)data_ov000_02184264.allocator->Allocate(0xc);
    e->type = 0x7d;
    signed short v = -1;
    if (count > 0) {
        v = (signed short)((Script::Parameter*)obj)->ToInt();
    }
    e->field8 = v;
    func_ov000_02169b78(e);
    return 1;
}
