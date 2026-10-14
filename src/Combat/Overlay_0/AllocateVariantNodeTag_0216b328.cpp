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

struct VariantNodeTag0x32 {
    int tag;
    int unused;
    int vec[3];
    unsigned char flag;
};

// USA: func_ov000_0216b328
ARM int AllocateVariantNodeTag_0216b328(struct Variant02030b0c* v, int count) {
    struct VariantNodeTag0x32* node = (struct VariantNodeTag0x32*)data_ov000_02184264.alloc->Allocate(sizeof(struct VariantNodeTag0x32));
    node->tag = 0;
    node->unused = 0;
    node->tag = 0x32;
    struct TaggedValue02030b44* tv = (extern TaggedValue02030b44*)((Script::Parameter*)((struct TaggedValue02030b44*)v))->ToVec3fix((Vector3i*)node->vec);
    unsigned char flag = 0;
    if (count >= 4) {
        flag = (unsigned char)((Script::Parameter*)((struct Variant02030b0c*)tv))->ToInt();
    }
    node->flag = flag;
    func_ov000_02169b78(node);
    return 1;
}
