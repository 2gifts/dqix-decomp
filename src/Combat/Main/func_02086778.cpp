#include <globaldefs.h>

extern "C" void* func_02086868(void*, void*);

struct Entry02086778 {
    signed char id : 6;
    unsigned char f6 : 1;
    unsigned char f7 : 1;
    char rest[0x23c - 1];
};

struct Container02086778 {
    char pad0[0xf80];
    struct Entry02086778 elems[13];
    unsigned char count;
};

// USA: func_02086778
extern "C" ARM int func_02086778(void* map, struct Entry02086778* buf, unsigned char c, unsigned char d) {
    struct Container02086778* m = (struct Container02086778*)map;
    signed char best = -1;
    signed char i = 0;
    int start = 0;
    for (i = 0; i < 16; i++) {
        bool found = start;
        unsigned char k = start;
        for (; k < m->count; k++) {
            if (i == m->elems[k].id) {
                found = true;
                break;
            }
        }
        if (!found) {
            best = i;
            break;
        }
    }
    if (best < 0) {
        return 0;
    }
    buf->id = best;
    buf->f6 = c;
    buf->f7 = d;
    func_02086868(&m->elems[m->count], buf);
    m->count++;
    return 1;
}