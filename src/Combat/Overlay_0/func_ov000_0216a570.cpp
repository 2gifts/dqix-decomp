#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

extern "C" void func_ov000_02169b78(void* node);

struct Data02184264 {
    unsigned char pad[8];
    SafeAllocator* alloc;
};
extern struct Data02184264 data_ov000_02184264;

extern char data_ov000_02183fbc[];
extern char data_ov000_02183fc1[];

struct Node0216a570 {
    int tag;
    void* field4;
    signed char index;
    char* strBuf;
};

// USA: func_ov000_0216a570
extern "C" ARM int func_ov000_0216a570(Script::Parameter* params) {
    struct Node0216a570* node = (struct Node0216a570*)data_ov000_02184264.alloc->Allocate(sizeof(struct Node0216a570));
    if (params[0].type == 0) {
        node->tag = 0;
        node->field4 = 0;
        node->tag = 0x14;
        node->index = -1;
        const char* name = params[0].ToString();
        node->strBuf = (char*)data_ov000_02184264.alloc->Allocate(strlen(name) + 1);
        strcpy(node->strBuf, name);
        char* found = strstr(node->strBuf, data_ov000_02183fbc);
        if (found != NULL) {
            strcpy(found, data_ov000_02183fc1);
        }
    } else if (params[0].type == 1) {
        node->tag = 0;
        node->field4 = 0;
        node->tag = 0x14;
        node->index = params[0].ToInt();
        const char* name = params[1].ToString();
        node->strBuf = (char*)data_ov000_02184264.alloc->Allocate(strlen(name) + 1);
        strcpy(node->strBuf, name);
        char* found = strstr(node->strBuf, data_ov000_02183fbc);
        if (found != NULL) {
            strcpy(found, data_ov000_02183fc1);
        }
    }
    func_ov000_02169b78(node);
    return 1;
}
