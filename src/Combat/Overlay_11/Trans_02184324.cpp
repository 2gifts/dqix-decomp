#include <globaldefs.h>

struct Node02184324 { char pad[0x18]; Node02184324* next; };

// USA: func_ov011_02184324  (semantic: Trans_02184324)
extern "C" ARM void func_ov011_02184324(Node02184324* head, Node02184324* node) {
    if (head->next != 0) {
        Node02184324* p = head->next;
        while (p->next != 0) {
            p = p->next;
        }
        p->next = node;
    } else {
        head->next = node;
    }
}
