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

struct VariantNodeTag0x50 {
    int tag;
    int unused;
    short intval;
    short floatval;
};

// USA: func_ov000_0216bd9c
ARM int AllocateVariantNodeTag_0216bd9c(struct Variant02030b0c* v) {
    struct VariantNodeTag0x50* node = (struct VariantNodeTag0x50*)data_ov000_02184264.alloc->Allocate(sizeof(struct VariantNodeTag0x50));
    node->tag = 0x50;
    node->floatval = (short)(int)(4096.0f * ((Script::Parameter*)((struct TaggedValue02030b44*)v))->ToFloat());
    node->intval = (short)((Script::Parameter*)((struct Variant02030b0c*)((char*)v + 8)))->ToInt();
    func_ov000_02169b78(node);
    return 1;
}
