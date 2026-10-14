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

struct VariantNodeTag0x56 {
    int tag;
    int unused;
    unsigned char value;
    int vec1[3];
    int vec2[3];
    unsigned char flag;
};

// USA: func_ov000_0216be6c  (semantic: AllocateVariantNodeTag_0216be6c)
extern "C" ARM int func_ov000_0216be6c(struct Variant02030b0c* v, int count) {
    struct VariantNodeTag0x56* node = (struct VariantNodeTag0x56*)data_ov000_02184264.alloc->Allocate(sizeof(struct VariantNodeTag0x56));
    node->tag = 0;
    node->unused = 0;
    node->tag = 0x56;
    node->value = (unsigned char)((Script::Parameter*)v)->ToInt();
    struct TaggedValue02030b44* next = (extern TaggedValue02030b44*)((Script::Parameter*)((struct TaggedValue02030b44*)((char*)v + 8)))->ToVec3fix((Vector3i*)node->vec1);
    node->vec2[0] = (int)(4096.0f * ((Script::Parameter*)(next + 0))->ToFloat());
    node->vec2[1] = (int)(4096.0f * ((Script::Parameter*)(next + 1))->ToFloat());
    node->vec2[2] = (int)(4096.0f * ((Script::Parameter*)(next + 2))->ToFloat());
    node->flag = 0;
    if (count >= 8) {
        node->flag = (unsigned char)((Script::Parameter*)((struct Variant02030b0c*)(next + 3)))->ToInt();
    }
    func_ov000_02169b78(node);
    return 1;
}
