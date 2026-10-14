#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Resource/Script.h"

extern "C" void func_ov000_02169b78(void*);

struct Struct02184264 {
    unsigned char pad[8];
    SafeAllocator* alloc;
};
extern struct Struct02184264 data_ov000_02184264;

struct Variant02030b0c { int tag; int u; };

struct TaggedValue02030b44 { int type; union { int i; float f; } value; };

struct VariantNodeTag0x75 {
    int tag;
    int unused;
    short x;
    short y;
    unsigned char type;
};

// USA: func_ov000_0216c9fc  (semantic: AllocateVariantNodeTag_0216c9fc)
extern "C" ARM int func_ov000_0216c9fc(struct Variant02030b0c* v) {
    struct VariantNodeTag0x75* node = (struct VariantNodeTag0x75*)data_ov000_02184264.alloc->Allocate(sizeof(struct VariantNodeTag0x75));
    if (node == 0) {
        return 0;
    }
    memset(node, 0, sizeof(struct VariantNodeTag0x75));
    int type = ((Script::Parameter*)v)->ToInt();
    node->type = (unsigned char)type;
    switch (type & 0xff) {
    case 0:
        node->x = (short)(int)(4096.0f * ((Script::Parameter*)((struct TaggedValue02030b44*)((char*)v + 8)))->ToFloat());
        node->y = (short)(int)(4096.0f * ((Script::Parameter*)((struct TaggedValue02030b44*)((char*)v + 0x10)))->ToFloat());
        break;
    case 1:
        node->x = (short)((Script::Parameter*)((struct Variant02030b0c*)((char*)v + 8)))->ToInt();
        node->y = (short)(int)(4096.0f * ((Script::Parameter*)((struct TaggedValue02030b44*)((char*)v + 0x10)))->ToFloat());
        break;
    }
    node->tag = 0x75;
    func_ov000_02169b78(node);
    return 1;
}
