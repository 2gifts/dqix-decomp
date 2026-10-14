#include <globaldefs.h>

struct AppendNode {
    char unk[0x18];
    struct AppendNode* next;
};

struct AppendList {
    char unk[0x30];
    struct AppendNode* head;
};

// USA: func_0206445c
ARM void AppendNodeToListField30_0206445c(int unused, struct AppendNode* node, struct AppendList* list) {
    struct AppendNode* cur;
    node->next = 0;
    cur = list->head;
    if (cur == 0) {
        list->head = node;
        return;
    }
    while (cur->next != 0) {
        cur = cur->next;
    }
    cur->next = node;
}
