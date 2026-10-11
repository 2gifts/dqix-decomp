#include <globaldefs.h>

struct N528cNode {
    unsigned short id;
#if defined(jpn)
    char unk[0x1a];
#else
    char unk[0xe];
#endif
    struct N528cNode* next;
};

struct N528cList {
    struct N528cNode* head;
};

// USA: func_0206528c
ARM struct N528cNode* FindNodeByHalfwordKey(struct N528cList* list, int key) {
    struct N528cNode* node = list->head;
    while (node != 0) {
        if (node->id == key) {
            return node;
        }
        node = node->next;
    }
    return 0;
}
