#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

extern "C" void func_ov000_02169b78(void*);
extern "C" void __clear(void* buf, int size);

struct Struct02184264 {
    unsigned char pad[8];
    SafeAllocator* alloc;
};
extern struct Struct02184264 data_ov000_02184264;

struct Variant02030b0c { int tag; int u; };

struct TaggedValue02030b44 { int type; union { int i; float f; } value; };
struct Vector3i;

struct VariantNodeTag0x8a {
    int tag;
    int unused;
    int vec[3];
};

// USA: func_ov000_0216d038
ARM int AllocateVariantNodeTag_0216d038(struct Variant02030b0c* v) {
    struct VariantNodeTag0x8a* node = (struct VariantNodeTag0x8a*)data_ov000_02184264.alloc->Allocate(sizeof(struct VariantNodeTag0x8a));
    node->tag = 0;
    node->unused = 0;
    int tmp[3];
    node->tag = 0x8a;
    __clear(tmp, sizeof(tmp));
    (extern TaggedValue02030b44*)((Script::Parameter*)((struct TaggedValue02030b44*)v))->ToVec3fix((Vector3i*)tmp);
    *(Vector3i*)node->vec = *(Vector3i const*)tmp;
    func_ov000_02169b78(node);
    return 1;
}
