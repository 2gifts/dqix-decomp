#include <globaldefs.h>

struct CountNode {
    char pad[4];
    struct CountNode* next;
};

struct CountHead {
    struct CountNode* first;
};

// USA: func_02046c78
ARM int CountListNodes_02046c78(struct CountHead* head) {
    int count = 0;
    struct CountNode* n = head->first;
    while (n != 0) {
        n = n->next;
        count++;
    }
    return count;
}
