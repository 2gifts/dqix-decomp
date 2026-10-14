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

struct VariantNodeTag0x40 {
    int tag;
    int unused;
    int value;
};

// USA: func_ov000_0216b900
ARM int AllocateVariantNodeTag_0216b900_0216b900(struct Variant02030b0c* v) {
    struct VariantNodeTag0x40* node = (struct VariantNodeTag0x40*)data_ov000_02184264.alloc->Allocate(sizeof(struct VariantNodeTag0x40));
    if (node == NULL) return 0;
    node->tag = 0;
    node->unused = 0;
    node->tag = 0x40;
    node->value = ((Script::Parameter*)v)->ToInt();
    func_ov000_02169b78(node);
    return 1;
}
