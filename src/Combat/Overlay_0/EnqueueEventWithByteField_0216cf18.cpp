#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c;

struct EventCtx0216cf18 {
    char pad[8];
    SafeAllocator* allocator;
};
extern struct EventCtx0216cf18 data_ov000_02184264;

struct Event0216cf18 {
    int type;
    int unused4;
    unsigned char field8;
};

extern "C" void func_ov000_02169b78(struct Event0216cf18*);

// USA: func_ov000_0216cf18
ARM int EnqueueEventWithByteField_0216cf18(struct Variant02030b0c* obj, int count) {
    struct Event0216cf18* e = (struct Event0216cf18*)data_ov000_02184264.allocator->Allocate(0xc);
    e->type = 0x82;
    e->field8 = 1;
    if (count >= 1) {
        e->field8 = (unsigned char)((Script::Parameter*)obj)->ToInt();
    }
    func_ov000_02169b78(e);
    return 1;
}
