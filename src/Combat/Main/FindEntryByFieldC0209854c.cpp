#include <globaldefs.h>

int IsInRange1To63_02098268(int a, int x);

struct Entry0209854c {
    char pad0[0xc];
    unsigned int lo : 24;
    unsigned int val : 6;
    unsigned int hi : 2;
    char pad10[0xe8 - 0x10];
};

// USA: func_0209854c
ARM struct Entry0209854c* FindEntryByFieldC0209854c(struct Entry0209854c* list, int target) {
    int i;
    if (IsInRange1To63_02098268((int)list, target) == 0) return 0;
    for (i = 0; i < 0x1e; i++) {
        if (target == list[i].val) return &list[i];
    }
    return 0;
}
