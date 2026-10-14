#include <globaldefs.h>

void PushInterruptDisableState_020d8654(void);
void BlankFunction020d84e4(void);
void BlankFunction020d84e8(void);
extern "C" void* func_0202ae18(void);
extern "C" void func_020d8694(void);
int CheckField0NonZero_0202b7d8(int* obj);

struct QNode0205e1e4 {
    char pad[0x18];
    struct QNode0205e1e4* next;
};
struct QList0205e1e4 {
    struct QNode0205e1e4* head;
    struct QNode0205e1e4* tail;
    int count;
};
struct QNode0205e1e4* DequeueNode(struct QList0205e1e4* list);

struct QNode0205e18c {
    char pad[0x18];
    struct QNode0205e18c* next;
};
struct QList0205e18c {
    struct QNode0205e18c* head;
    struct QNode0205e18c* tail;
    int count;
};
void EnqueueNode(struct QList0205e18c* list, struct QNode0205e18c* node);

// USA: func_0205e41c
ARM struct QNode0205e1e4* PopAndRequeueNode_0205e41c(void* obj, int* outPtr) {
    struct QNode0205e1e4* node;
    PushInterruptDisableState_020d8654();
    BlankFunction020d84e4();
    node = NULL;
    if (CheckField0NonZero_0202b7d8((int*)func_0202ae18())) {
        node = DequeueNode((struct QList0205e1e4*)((char*)obj + 0x1518));
        if (node == NULL) {
            *outPtr = -1;
            node = NULL;
        } else {
            EnqueueNode((struct QList0205e18c*)((char*)obj + 0x1500), (struct QNode0205e18c*)node);
            *outPtr = *(short*)((char*)node + 0x14);
        }
    }
    BlankFunction020d84e8();
    func_020d8694();
    return node;
}
