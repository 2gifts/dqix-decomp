#include <globaldefs.h>

struct Node021e23d0 {
    char pad0[8];
    struct Node021e23d0* next;
};
struct List021e23d0 {
    struct Node021e23d0* head;
};

// USA: func_ov025_021e23d0
#if defined(jpn)
extern "C" ARM void func_ov000_02171720(struct List021e23d0* list, struct Node021e23d0* node)
#else
ARM void PushFrontNode021e23d0(struct List021e23d0* list, struct Node021e23d0* node)
#endif
{
    node->next = list->head ? list->head : NULL;
    list->head = node;
}
