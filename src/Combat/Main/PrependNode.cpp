#include <globaldefs.h>

struct NodeCEE54 {
    char _pad[8];
    struct NodeCEE54* next;
};

struct ListHeadCEE54 {
    struct NodeCEE54* head;
};

// USA: func_020cee54
ARM void PrependNode_020cee54(struct ListHeadCEE54* list, struct NodeCEE54* node) {
    if (list != 0) {
        node->next = list->head;
        list->head = node;
    }
}
