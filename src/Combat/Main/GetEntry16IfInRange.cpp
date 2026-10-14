#include <globaldefs.h>

struct Entry02b005c { unsigned int w[4]; };
struct Table02b005c {
    unsigned short count;
    unsigned short pad;
    struct Entry02b005c *entries;
};

// USA: func_020b005c
ARM struct Entry02b005c *GetEntry16IfInRange_020b005c(struct Table02b005c *t, unsigned int i) {
    if (t->count > i) {
        return &t->entries[i];
    }
    return NULL;
}
