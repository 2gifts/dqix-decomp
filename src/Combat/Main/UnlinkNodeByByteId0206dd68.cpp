#include <globaldefs.h>

#include "Combat/NodeLookup.h"

struct DLNode0206dd68 {
    char pad[0x64];
    struct DLNode0206dd68* prev;
    struct DLNode0206dd68* next;
};


// USA: func_0206dd68
ARM void UnlinkNodeByByteId0206dd68(void* base, int key) {
    struct DLNode0206dd68* node = (DLNode0206dd68*)FindNodeByByteId(base, key);
    if (node == NULL) {
        return;
    }
    if (node->prev != NULL) {
        node->prev->next = node->next;
    } else {
        *(struct DLNode0206dd68**)base = node->next;
    }
    if (node->next != NULL) {
        node->next->prev = node->prev;
    }
}
