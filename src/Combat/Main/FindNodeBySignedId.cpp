#include <globaldefs.h>

struct NodeEF18 {
    short id;
    char unk[0xe];
    struct NodeEF18* next;
};

// USA: func_0206ef18
ARM struct NodeEF18* FindNodeBySignedId_0206ef18(void* base, int key) {
    struct NodeEF18* node = *(struct NodeEF18**)base;
    while (node != 0) {
        if (node->id == key) {
            return node;
        }
        node = node->next;
    }
    return 0;
}
