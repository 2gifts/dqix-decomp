#include <globaldefs.h>

#if defined(jpn)
#define func_ov025_021e24a8 func_ov000_021717f8
#endif

struct Node021e24a8 { int unk0; int unk1; struct Node021e24a8* next; };
struct Head021e24a8 { struct Node021e24a8* head; };

// USA: func_ov025_021e24a8  (semantic: Func_021e24a8)
extern "C" ARM int func_ov025_021e24a8(struct Head021e24a8* container, struct Node021e24a8* target) {
    struct Node021e24a8* node = container->head;
    while (node != 0) {
        if (node == target) return 1;
        node = node->next;
    }
    return 0;
}
