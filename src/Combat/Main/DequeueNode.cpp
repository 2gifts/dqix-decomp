#include <globaldefs.h>

struct QNode0205e1e4 {
    char pad[0x18];
    struct QNode0205e1e4* next;
};
struct QList0205e1e4 {
    struct QNode0205e1e4* head;
    struct QNode0205e1e4* tail;
    int count;
};

void PushInterruptDisableState_020d8654(void);
extern "C" void func_020d8694(void);

// USA: func_0205e1e4
ARM struct QNode0205e1e4* DequeueNode(struct QList0205e1e4* list) {
    struct QNode0205e1e4* head;
    PushInterruptDisableState_020d8654();
    head = list->head;
    if (head != NULL) {
        list->head = head->next;
        list->count--;
    }
    func_020d8694();
    return head;
}
