#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

extern "C" void func_ov000_02169b78(void* node);

struct Struct02184264 {
    unsigned char pad[8];
    SafeAllocator* alloc;
};
extern struct Struct02184264 data_ov000_02184264;

struct Variant02030b0c { int tag; int u; };

struct TaggedValue02030b44 { int type; union { int i; float f; } value; };

struct VariantNodeTag0216d110 {
    int tag;
    int unused;
    unsigned char value;
    int angle;
};

// USA: func_ov000_0216d110  (semantic: AllocateVariantNodeTagAngle_0216d110)
extern "C" ARM int func_ov000_0216d110(struct Variant02030b0c* v) {
    struct VariantNodeTag0216d110* node = (struct VariantNodeTag0216d110*)data_ov000_02184264.alloc->Allocate(0x10);
    node->tag = 0;
    node->unused = 0;
    node->tag = 0x8c;
    node->value = (unsigned char)((Script::Parameter*)v)->ToInt();
    float degrees = ((Script::Parameter*)((struct TaggedValue02030b44*)((char*)v + 8)))->ToFloat();
    node->angle = (int)(degrees * 3.14159274f / 180.0f * 4096.0f);
    func_ov000_02169b78(node);
    return 1;
}
