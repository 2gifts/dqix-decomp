#include <globaldefs.h>

struct NodeEeec {
    char unk[0x10];
    struct NodeEeec* next;
};

struct ListEeec {
    struct NodeEeec* head;
    unsigned char count;
};

// USA: func_0206eeec
ARM void PushNodeToList_0206eeec(struct ListEeec* list, struct NodeEeec* node) {
    struct NodeEeec* head = list->head;
    if (head != 0) {
        node->next = head;
        list->head = node;
    } else {
        list->head = node;
        node->next = 0;
    }
    list->count++;
}
