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

struct VariantNodeTag0x77 {
    int tag;
    int unused;
    unsigned char value;
};

// USA: func_ov000_0216cc88
ARM int AllocateVariantNodeTag_0216cc88(struct Variant02030b0c* v) {
    struct VariantNodeTag0x77* node = (struct VariantNodeTag0x77*)data_ov000_02184264.alloc->Allocate(sizeof(struct VariantNodeTag0x77));
    node->tag = 0x77;
    node->value = (unsigned char)(((Script::Parameter*)v)->ToInt() != 0);
    func_ov000_02169b78(node);
    return 1;
}
