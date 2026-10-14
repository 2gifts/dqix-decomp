#include <globaldefs.h>

struct ListNode0220eea0 {
    unsigned char padding_0[4];
    unsigned int id;
    ListNode0220eea0* previous;
    ListNode0220eea0* next;
};
struct ListHeader0220eea0 {
    unsigned int count;
    ListNode0220eea0* first;
    ListNode0220eea0* last;
};
struct ListContext0220eea0 {
    char padding[0x2270];
    ListHeader0220eea0* list;
    unsigned int capacity;
};
ListContext0220eea0* GetData0224e53c_0220d60c();

// USA: func_ov031_0220eea0
extern "C" ARM void func_ov031_0220eea0(ListNode0220eea0* node) {
    ListContext0220eea0* context = GetData0224e53c_0220d60c();
    ListHeader0220eea0* list = context->list;
    if (!node || !list) return;
    if (context->capacity <= 12) return;
    ListNode0220eea0* current = list->first;
    if (current) do {
        if (current == node) {
            if (current->previous) current->previous->next = current->next;
            else list->first = current->next;
            if (current->next) current->next->previous = current->previous;
            else list->last = current->previous;
            break;
        }
        current = current->next;
    } while (current);
    node->next = NULL;
    node->previous = list->last;
    list->last = node;
    if (node->previous) node->previous->next = node;
    else list->first = node;
    if (current == NULL) {
        node->id = list->count;
        list->count++;
    } else return;
}
