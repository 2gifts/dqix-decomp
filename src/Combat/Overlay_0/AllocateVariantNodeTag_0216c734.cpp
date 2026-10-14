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

struct VariantNodeTag0x70 {
    int tag;
    int unused;
    short value;
};

// USA: func_ov000_0216c734
ARM int AllocateVariantNodeTag_0216c734(struct Variant02030b0c* v, int count) {
    struct VariantNodeTag0x70* node = (struct VariantNodeTag0x70*)data_ov000_02184264.alloc->Allocate(sizeof(struct VariantNodeTag0x70));
    if (node == NULL) return 0;
    node->tag = 0;
    node->unused = 0;
    node->tag = 0x70;
    unsigned short value = 0;
    if (count >= 1) {
        value = (unsigned short)((Script::Parameter*)v)->ToInt();
    }
    node->value = value;
    func_ov000_02169b78(node);
    return 1;
}
