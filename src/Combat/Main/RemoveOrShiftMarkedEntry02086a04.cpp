#include <globaldefs.h>

extern "C" void* func_02086868(void*, void*);

struct FindEntry02086a04 {
    signed char id : 6;
    char rest[0x23c - 1];
};

struct FindEntryContainer02086a04 {
    char pad0[0xf80];
    struct FindEntry02086a04 elems[13];
    unsigned char count;
};

// USA: func_02086a04
ARM int RemoveOrShiftMarkedEntry02086a04(struct FindEntryContainer02086a04* c, int id) {
    if (id < 0) return 0;
    int found = 0;
    unsigned char i;
    for (i = 0; i < c->count; i++) {
        struct FindEntry02086a04* e = &c->elems[i];
        if (id == e->id) {
            e->id = -1;
            c->count--;
            found = 1;
            break;
        }
    }
    if (found) {
        unsigned char j;
        for (j = 0; j < c->count; j++) {
            struct FindEntry02086a04* e = &c->elems[j];
            if (e->id < 0) {
                int next = j + 1;
                struct FindEntry02086a04* nextE = &c->elems[next];
                func_02086868(e, nextE);
                nextE->id = -1;
            }
        }
    }
    return found;
}
