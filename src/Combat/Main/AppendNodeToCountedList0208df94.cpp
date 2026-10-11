#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Copy0208e000;
void CopyStruct0208e000(struct Copy0208e000* dst, struct Copy0208e000* src);

struct Node0208df94 {
    short field0;
    unsigned short field2;
    int field4;
#if defined(jpn)
    int regionalField8;
#endif
    struct Node0208df94* next;
};

struct List0208df94 {
    struct Node0208df94* head;
    short count;
};

// USA: func_0208df94
ARM void AppendNodeToCountedList0208df94(struct List0208df94* list, SafeAllocator* alloc, struct Copy0208e000* src) {
    struct Node0208df94* node = (struct Node0208df94*)alloc->Allocate(sizeof(Node0208df94));
    struct Node0208df94* tail = list->head;
    if (tail != NULL) {
        while (tail->next != NULL) {
            tail = tail->next;
        }
        CopyStruct0208e000((struct Copy0208e000*)node, src);
        tail->next = node;
    } else {
        list->head = node;
        CopyStruct0208e000((struct Copy0208e000*)node, src);
    }
    list->count++;
}
