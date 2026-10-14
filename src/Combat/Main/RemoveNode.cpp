#include <globaldefs.h>

struct RemoveNodeEntry {
    struct RemoveNodeEntry* prev;
    struct RemoveNodeEntry* next;
};

// USA: func_020c8784
ARM struct RemoveNodeEntry* RemoveNode_020c8784(struct RemoveNodeEntry* head, struct RemoveNodeEntry* node) {
    if (node->next != 0) {
        node->next->prev = node->prev;
    }
    if (node->prev == 0) {
        head = node->next;
    } else {
        node->prev->next = node->next;
    }
    return head;
}
