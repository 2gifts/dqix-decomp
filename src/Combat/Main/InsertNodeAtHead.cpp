#include <globaldefs.h>

struct DListNode {
    struct DListNode* field0;
    struct DListNode* field4;
};

// USA: func_020c8768
ARM struct DListNode* InsertNodeAtHead_020c8768(struct DListNode* oldHead, struct DListNode* newNode) {
    newNode->field4 = oldHead;
    newNode->field0 = 0;
    if (oldHead != 0) {
        oldHead->field0 = newNode;
    }
    return newNode;
}
