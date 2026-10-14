#include <globaldefs.h>

#pragma optimize_for_size off

struct NodeCEE68 {
    char _pad[8];
    struct NodeCEE68* next;
};

struct ListHeadCEE68 {
    struct NodeCEE68* head;
};

// USA: func_020cee68
ARM void AppendNodeToTail_020cee68(struct ListHeadCEE68* list, struct NodeCEE68* node) {
    struct NodeCEE68* cur;
    struct NodeCEE68* next;
    if (list == 0) return;
    cur = list->head;
    if (cur == 0) {
        node->next = 0;
        list->head = node;
        return;
    }
    next = cur->next;
    if (next != 0) {
        do {
            cur = next;
            next = next->next;
        } while (next != 0);
    }
    node->next = next;
    cur->next = node;
}
