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

struct VariantNodeTag0x3a {
    int tag;
    int unused;
    int value;
};

// USA: func_ov000_0216b754
ARM int AllocateVariantNodeTag_0216b754(struct Variant02030b0c* v, int flag) {
    struct VariantNodeTag0x3a* node = (struct VariantNodeTag0x3a*)data_ov000_02184264.alloc->Allocate(sizeof(struct VariantNodeTag0x3a));
    if (node == NULL) return 0;
    node->tag = 0;
    node->unused = 0;
    node->tag = 0x3a;
    int value;
    if (flag == 0) {
        value = 1;
    } else {
        value = ((Script::Parameter*)v)->ToInt();
    }
    node->value = value;
    func_ov000_02169b78(node);
    return 1;
}
