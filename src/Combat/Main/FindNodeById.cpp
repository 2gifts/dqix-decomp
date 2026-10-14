#include <globaldefs.h>

struct ListNode {
    unsigned short id;
    char unk[0x6e];
    struct ListNode* next;
};

// USA: func_0201e844
ARM struct ListNode* FindNodeById_0201e844(void* base, int index, int key) {
    struct ListNode* node;
    if (key < 0) {
        return 0;
    }
    node = *(struct ListNode**)((char*)base + index * 4 + 0x3c);
    while (node != 0) {
        if (node->id == key) {
            return node;
        }
        node = node->next;
    }
    return node;
}
