#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

extern "C" void func_ov000_02169b78(void*);

struct Struct02184264 {
    unsigned char pad[8];
    SafeAllocator* alloc;
};
extern struct Struct02184264 data_ov000_02184264;

struct Variant02030b0c { int tag; int u; };

struct VariantNodeTag0x84 {
    int tag;
    int unused;
    unsigned char value;
};

// USA: func_ov000_0216cf84
ARM int AllocateVariantNodeTag_0216cf84(struct Variant02030b0c* v, int count) {
    struct VariantNodeTag0x84* node = (struct VariantNodeTag0x84*)data_ov000_02184264.alloc->Allocate(sizeof(struct VariantNodeTag0x84));
    node->tag = 0x84;
    if (count >= 1) {
        node->value = (unsigned char)((Script::Parameter*)v)->ToInt();
    }
    func_ov000_02169b78(node);
    return 1;
}
