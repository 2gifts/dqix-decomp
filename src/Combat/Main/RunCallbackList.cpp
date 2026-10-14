#include <globaldefs.h>

struct CallbackNodeCEF0C {
    void (*fn)(void*);
    void* arg;
    struct CallbackNodeCEF0C* next;
};

// USA: func_020cef0c
ARM void RunCallbackList_020cef0c(struct CallbackNodeCEF0C* node) {
    if (node == 0) return;
    do {
        node->fn(node->arg);
        node = node->next;
    } while (node != 0);
}
