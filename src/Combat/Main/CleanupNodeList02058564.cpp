#include <globaldefs.h>

void* Field0x1cCall0207ecd4OrNull_02055624(void* obj);
void* Field0x1cCall0207ecf8OrNull_0205560c(void* obj);

struct Node02058564 {
    unsigned char pad[0x1ec];
    struct Node02058564* next;
};

struct NodeList02058564 {
    struct Node02058564* head;
    int count;
};

// USA: func_02058564
ARM void CleanupNodeList02058564(struct NodeList02058564* list) {
    struct Node02058564* node;
    if (list->count <= 0) return;
    node = list->head;
    while (node != NULL) {
        Field0x1cCall0207ecd4OrNull_02055624(node);
        Field0x1cCall0207ecf8OrNull_0205560c(node);
        node = node->next;
    }
}
