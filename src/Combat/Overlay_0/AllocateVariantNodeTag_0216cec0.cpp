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

struct VariantNodeTag0x80 {
    int tag;
    int unused;
    short value;
};

// USA: func_ov000_0216cec0
ARM int AllocateVariantNodeTag_0216cec0(struct Variant02030b0c* v) {
    struct VariantNodeTag0x80* node = (struct VariantNodeTag0x80*)data_ov000_02184264.alloc->Allocate(sizeof(struct VariantNodeTag0x80));
    node->tag = 0x80;
    node->value = (short)((Script::Parameter*)v)->ToInt();
    func_ov000_02169b78(node);
    return 1;
}
