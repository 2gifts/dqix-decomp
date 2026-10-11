#include <globaldefs.h>
#if defined(jpn)
enum { kNodeOffset = 0x43c };
#else
enum { kNodeOffset = 0x41c };
#endif


struct Elem0201b600 { unsigned short key; unsigned char pad[0x6e]; };
struct Node0201b600 {
    int f0;                      // 0x00
    unsigned char pad4[0x10];    // 0x04
    int count;                   // 0x14
    unsigned char pad18[0x2c];   // 0x18
    struct Elem0201b600* arr;    // 0x44
    unsigned char pad48[0xc];    // 0x48
    struct Node0201b600* next;   // 0x54
};
struct Obj0201b600 {
    unsigned char pad0[kNodeOffset];
    struct Node0201b600* head;   // kNodeOffset
    unsigned char pad420[4];     // 0x420
    int f424;                    // 0x424
};

// USA: func_0201b600
ARM struct Elem0201b600* FindElemByKeys(struct Obj0201b600* obj, int key1, short key2) {
    struct Node0201b600* node;
    int count;
    int i;
    if (obj->f424 != 0) return NULL;
    node = obj->head;
    while (node != NULL) {
        if (node->f0 == key1) break;
        node = node->next;
    }
    if (node != NULL) {
        struct Elem0201b600* result = NULL;
        count = node->count;
        for (i = 0; i < count; i++) {
            if (key2 == node->arr[i].key) { result = &node->arr[i]; break; }
        }
        return result;
    }
    return NULL;
}
