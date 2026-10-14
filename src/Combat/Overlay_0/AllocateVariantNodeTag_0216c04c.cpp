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
struct Vector3i;

struct VariantNodeTag0x59 {
    int tag;
    int unused;
    int vec1[3];
    int vec2[3];
};

// USA: func_ov000_0216c04c  (semantic: AllocateVariantNodeTag_0216c04c)
extern "C" ARM int func_ov000_0216c04c(struct Variant02030b0c* v) {
    struct VariantNodeTag0x59* node = (struct VariantNodeTag0x59*)data_ov000_02184264.alloc->Allocate(sizeof(struct VariantNodeTag0x59));
    node->tag = 0;
    node->unused = 0;
    node->tag = 0x59;
    struct TaggedValue02030b44* tv = (extern TaggedValue02030b44*)((Script::Parameter*)((struct TaggedValue02030b44*)v))->ToVec3fix((Vector3i*)node->vec1);
    node->vec2[0] = (int)(4096.0f * ((Script::Parameter*)(tv + 0))->ToFloat());
    node->vec2[1] = (int)(4096.0f * ((Script::Parameter*)(tv + 1))->ToFloat());
    node->vec2[2] = (int)(4096.0f * ((Script::Parameter*)(tv + 2))->ToFloat());
    func_ov000_02169b78(node);
    return 1;
}
