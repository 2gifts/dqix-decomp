#include <globaldefs.h>
#include "Resource/Script.h"
#include "Memory/SafeAllocator.h"

struct ListNode_0218de60 {
    short id;
    short kind;
    char* name;
    char* resource;
    char* option;
#if !defined(jpn)
    bool enabled;
    bool alternate;
#endif
    short priority;
    int value;
    ListNode_0218de60* next;
};
struct ListHead_0218e020 {
    ListNode_0218de60* head;
    unsigned int count;
    SafeAllocator* allocator;
};
extern ListHead_0218e020* data_ov016_0219d1bc;
extern "C" void _Z23AppendListNode_0218e020P17ListHead_0218e020Pv(ListHead_0218e020*, void*);

// USA: func_ov016_0218de60
extern "C" ARM int func_ov016_0218de60(Script::Parameter* params, int count) {
    SafeAllocator* allocator = data_ov016_0219d1bc->allocator;
    ListNode_0218de60 node;
    memset(&node, 0, sizeof(node));
    node.id = params[0].ToInt();
    node.kind = params[1].ToInt();
    const char* text = params[2].ToString();
    if (text) {
        node.name = (char*)allocator->Allocate(strlen(text) + 1);
        if (node.name) strcpy(node.name, text);
    }
    text = params[3].ToString();
    if (text && strlen(text)) {
        node.resource = (char*)allocator->Allocate(strlen(text) + 1);
        if (node.resource) strcpy(node.resource, text);
    }
    text = params[4].ToString();
    if (text && strlen(text)) {
        node.option = (char*)allocator->Allocate(strlen(text) + 1);
        if (node.option) strcpy(node.option, text);
    }
    node.priority = params[5].ToInt();
    params += 6;
    node.value = (params++)->ToInt();
#if !defined(jpn)
    count -= 7;
    if (count > 0) {
        node.enabled = (params++)->ToInt() != 0;
        --count;
    } else {
        node.enabled = true;
    }
    if (count > 0) node.alternate = params->ToInt() != 0;
    else node.alternate = false;
#endif
    _Z23AppendListNode_0218e020P17ListHead_0218e020Pv(data_ov016_0219d1bc, &node);
    return 1;
}
