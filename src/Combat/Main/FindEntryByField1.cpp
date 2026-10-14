#include <globaldefs.h>

extern "C" void* func_0202ae18(void);
int CheckField0NonZero_0202b7d8(int* obj);

struct Entry020e3054 {
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;
};

// USA: func_020e3054
ARM struct Entry020e3054* FindEntryByField1(struct Entry020e3054* list, int key) {
    int i;
    if (!CheckField0NonZero_0202b7d8((int*)func_0202ae18())) return NULL;
    for (i = 0; i < 8; i++) {
        if (list->f1 == key) return list;
        list++;
    }
    return NULL;
}
