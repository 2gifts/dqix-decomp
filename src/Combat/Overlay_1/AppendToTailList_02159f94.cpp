#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct AppendNode02159f94 { char pad[0x3c]; void* next; };

void* FindFreeSlotAndReset_02159eb0(void* obj);

// USA: func_ov001_02159f94  (semantic: AppendToTailList_02159f94)
extern "C" ARM void* func_ov001_02159f94(char* obj) {
    AppendNode02159f94* node = (AppendNode02159f94*)FindFreeSlotAndReset_02159eb0(obj);
    if (node == NULL) return NULL;
    AppendNode02159f94** tail = (AppendNode02159f94**)(obj + 0x1c);
    if (*tail != NULL) (*tail)->next = node;
    *tail = node;
    node->next = NULL;
    AppendNode02159f94** head = (AppendNode02159f94**)(obj + 0x18);
    if (*head == NULL) *head = node;
    return node;
}
