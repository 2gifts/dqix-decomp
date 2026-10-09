#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

extern "C" void func_ov000_02169b78(void* node);

struct Struct02184264 {
    unsigned char pad[8];
    SafeAllocator* alloc;
};
extern struct Struct02184264 data_ov000_02184264;

struct Node02169d08 {
    int tag;
    int unk_4;
    char* name;
    short count;
    unsigned char kind;
    unsigned char extra;
};

// USA: func_ov000_02169d08
extern "C" ARM int func_ov000_02169d08(Script::Parameter* params, int numParams) {
    struct Node02169d08* node = (struct Node02169d08*)data_ov000_02184264.alloc->Allocate(sizeof(struct Node02169d08));
    node->tag = 3;
    if (params->type == 0) {
        const char* name = (params++)->ToString();
        int count = 1;
        if (numParams >= 2) {
            count = (params++)->ToInt();
        }
        node->name = (char*)data_ov000_02184264.alloc->Allocate(strlen(name) + 1);
        strcpy(node->name, name);
        node->count = count;
        node->kind = 7;
        int extra = 0;
        if (numParams >= 3) {
            extra = params->ToInt();
        }
        node->extra = extra;
    } else if (params->type == 1) {
        node->kind = (params++)->ToInt();
        const char* name = (params++)->ToString();
        int count = 1;
        if (numParams >= 3) {
            count = (params++)->ToInt();
        }
        node->name = (char*)data_ov000_02184264.alloc->Allocate(strlen(name) + 1);
        strcpy(node->name, name);
        node->count = count;
        int extra = 0;
        if (numParams >= 4) {
            extra = params->ToInt();
        }
        node->extra = extra;
    } else {
        return 0;
    }
    func_ov000_02169b78(node);
    return 1;
}
