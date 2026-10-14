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

struct VariantNodeTag0x4f {
    int tag;
    int unused;
    unsigned char value : 7;
    unsigned char flag : 1;
    unsigned char count;
};

// USA: func_ov000_0216bcf0  (semantic: AllocateVariantNodeTag_0216bcf0)
extern "C" ARM int func_ov000_0216bcf0(struct Variant02030b0c* v, int argc) {
    struct VariantNodeTag0x4f* node = (struct VariantNodeTag0x4f*)data_ov000_02184264.alloc->Allocate(sizeof(struct VariantNodeTag0x4f));
    node->tag = 0x4f;
    node->value = (unsigned char)((Script::Parameter*)v)->ToInt();
    node->count = 1;
    node->flag = 1;
    if (argc < 2) goto done;
    node->count = (unsigned char)((Script::Parameter*)((struct Variant02030b0c*)((char*)v + 8)))->ToInt();
    if (argc < 3) goto done;
    node->flag = ((Script::Parameter*)((struct Variant02030b0c*)((char*)v + 0x10)))->ToInt();
done:
    func_ov000_02169b78(node);
    return 1;
}
