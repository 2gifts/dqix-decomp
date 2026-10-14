#include <globaldefs.h>

struct ListNode {
    char unk[0x28];
    struct ListNode* field28;
    struct ListNode* field2c;
    struct ListNode* field30;
};

// USA: func_020130b0
ARM void AppendToNodeList_020130b0(struct ListNode* a, struct ListNode* b) {
    struct ListNode* node;
    b->field28 = a;
    node = a->field2c;
    if (node == 0) {
        a->field2c = b;
        return;
    }
    while (node->field30 != 0) {
        node = node->field30;
    }
    node->field30 = b;
}
