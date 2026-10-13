#include <globaldefs.h>

struct Node0208f3b4 {
    int key;
    char _pad[0x10];
    struct Node0208f3b4* next;
};

struct Cont0208f3b4 {
    char _pad[0xc];
    struct Node0208f3b4* head;
};

// USA: func_0208f3b4
ARM void RemoveNodeByKey0208f3b4(struct Cont0208f3b4 *c, int key) {
    struct Node0208f3b4 *cur = c->head;
    struct Node0208f3b4 *prev = NULL;
    while (cur != NULL) {
        if (cur->key == key) {
            if (cur == c->head) {
                c->head = cur->next;
            } else if (cur->next == NULL) {
                prev->next = NULL;
            } else {
                prev->next = cur->next;
            }
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}
