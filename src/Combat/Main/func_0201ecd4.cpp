#include <globaldefs.h>
#include <Resource/Script.h>
#include <Memory/SafeAllocator.h>
struct Node0201ecd4 {
    unsigned short id;
    unsigned char flags;
    unsigned char field_0x3;
    char* text;
    Node0201ecd4* next;
};
struct Container0201ecd4 { Node0201ecd4* head; SafeAllocator* allocator; int field_0x8; };
extern Container0201ecd4 data_020fdc40;
// USA: func_0201ecd4
extern "C" ARM int func_0201ecd4(Script::Parameter* parameter, int count) {
    if (!data_020fdc40.head) return 0;
    Node0201ecd4* node = (Node0201ecd4*)data_020fdc40.allocator->Allocate(12);
    node->id = parameter->ToInt();
    parameter++;
    const char* text = (parameter++)->ToString();
    if (!text) return 0;
    node->text = (char*)data_020fdc40.allocator->Allocate(strlen(text) + 1);
    strcpy(node->text, text);
    node->flags = 0;
    if (count >= 3) {
        node->flags = parameter->ToInt();
        node->flags &= 31;
        parameter++;
    }
    node->field_0x3 = 0;
    if (count >= 4) node->field_0x3 = parameter->ToInt();
    node->next = 0;
    Node0201ecd4* tail = data_020fdc40.head;
    while (tail->next) tail = tail->next;
    tail->next = node;
    return 1;
}
