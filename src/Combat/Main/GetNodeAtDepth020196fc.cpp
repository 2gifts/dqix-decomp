#include <globaldefs.h>

struct Node020196fc {
    char unk[0x54];
    struct Node020196fc* next;
};

struct Obj020196fc {
#if defined(jpn)
    char unk[0x43c];
#else
    char unk[0x41c];
#endif
    struct Node020196fc* head;
};

// USA: func_020196fc
ARM struct Node020196fc* GetNodeAtDepth020196fc(struct Obj020196fc* obj, int count) {
    struct Node020196fc* cur = obj->head;
    int i;
    for (i = 0; i < count; i++) {
        if (cur == 0) {
            return 0;
        }
        cur = cur->next;
    }
    return cur;
}
