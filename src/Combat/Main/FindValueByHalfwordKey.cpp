#include <globaldefs.h>

struct Node794c {
    short unk0;
    short key;
    int value;
    struct Node794c* next;
};

struct List794c {
    struct Node794c* head;
};

// USA: func_020d794c
ARM int FindValueByHalfwordKey_020d794c(struct List794c* list, int key) {
    struct Node794c* node = list->head;
    while (node != 0) {
        if (node->key == key) {
            return node->value;
        }
        node = node->next;
    }
    return 0;
}
