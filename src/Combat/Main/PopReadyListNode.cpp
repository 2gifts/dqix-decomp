#include <globaldefs.h>

unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int mask);

struct ListNode020d28a8 {
    struct ListNode020d28a8* next;
};
struct GlobalListState020d28a8 {
    struct ListNode020d28a8* head;
    unsigned char pad[0xc];
    struct ListNode020d28a8* tail;
};
extern struct GlobalListState020d28a8 data_02112780;

// USA: func_020d28a8
ARM struct ListNode020d28a8* PopReadyListNode_020d28a8(void) {
    unsigned int mask = DisableIRQInterrupts();
    struct ListNode020d28a8* node = data_02112780.head;
    if (node == NULL) {
        SetIRQInterruptState(mask);
        return NULL;
    }
    struct ListNode020d28a8* next = node->next;
    data_02112780.head = next;
    if (next == NULL) {
        data_02112780.tail = NULL;
    }
    SetIRQInterruptState(mask);
    return node;
}
