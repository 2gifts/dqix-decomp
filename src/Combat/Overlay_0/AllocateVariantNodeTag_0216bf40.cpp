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
struct TaggedValue02030b44 { int type; union { int i; float f; } value; };

struct VariantNodeTag0x57 {
    int tag;
    int unused;
    short floatval;
};

// USA: func_ov000_0216bf40
ARM int AllocateVariantNodeTag_0216bf40(struct Variant02030b0c* v) {
    struct VariantNodeTag0x57* node = (struct VariantNodeTag0x57*)data_ov000_02184264.alloc->Allocate(sizeof(struct VariantNodeTag0x57));
    node->tag = 0;
    node->unused = 0;
    node->tag = 0x57;
    node->floatval = (short)(int)(4096.0f * ((Script::Parameter*)((struct TaggedValue02030b44*)v))->ToFloat());
    func_ov000_02169b78(node);
    return 1;
}
