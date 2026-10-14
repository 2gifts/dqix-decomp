#include <globaldefs.h>

struct Element_1f2cc {
    short key;
    char unk[0x1e];
};

struct Manager_1f2cc {
    char unk[0xc];
    struct Element_1f2cc* elements;
    int count;
};

// USA: func_0201f2cc
ARM struct Element_1f2cc* FindElementByHalfwordKey_0201f2cc(struct Manager_1f2cc* manager, int key) {
    int i;
    for (i = 0; i < manager->count; i++) {
        if (key == manager->elements[i].key) {
            return &manager->elements[i];
        }
    }
    return 0;
}
