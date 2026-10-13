#include <globaldefs.h>

struct Queue0221e6d4 {
    int head;
    short count;
    short limit;
};

// USA: func_ov031_0221e6d4  (semantic: ClearQueue_0221e6d4)
extern "C" THUMB void func_ov031_0221e6d4(Queue0221e6d4* q) {
    q->head = 0;
    q->count = 0;
    q->limit = 0;
}
