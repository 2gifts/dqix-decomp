#include <globaldefs.h>

struct Node64af8 {
    char unk[0x2c];
    struct Node64af8* next;
};

struct Obj64af8 {
    char unk[0x494];
    struct Node64af8* head;
};

// USA: func_02064af8
ARM void AppendNodeToField494_02064af8(struct Obj64af8* obj, struct Node64af8* node) {
    struct Node64af8* cur = obj->head;
    if (cur == 0) {
        obj->head = node;
        return;
    }
    while (cur->next != 0) {
        cur = cur->next;
    }
    cur->next = node;
}
