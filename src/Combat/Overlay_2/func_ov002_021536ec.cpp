#include <globaldefs.h>

class PMFObj021536ec {
public:
    char *f0;
};
typedef int (PMFObj021536ec::*MemFn021536ec)(void *arg, void *item, int mode);

struct Entry021536ec {
    short key;
    MemFn021536ec fn;
};
struct Item021536ec {
    char pad[0x18];
    unsigned int keyB : 5;
    unsigned int keyA : 7;
    unsigned int rest : 20;
};
struct Slot021536ec {
    int ptr;
    int pad[2];
};

extern "C" void *_Z24SearchBothTables02079e2cPci(char *p, int key);

extern "C" unsigned int data_ov002_0216d3a0[2];
extern "C" MemFn021536ec data_020e6d5c;
extern "C" struct Entry021536ec data_ov002_0216cce4[12];
extern "C" struct Slot021536ec data_ov002_0216cce8[12];
extern "C" struct Entry021536ec data_ov002_0216ccc0[3];
extern "C" struct Slot021536ec data_ov002_0216ccc4[3];

// USA: func_ov002_021536ec
extern "C" ARM int func_ov002_021536ec(PMFObj021536ec *obj, short *arg) {
    if (obj->f0 == NULL) return 0;
    if (arg == NULL) return 0;
    struct Item021536ec *item = (struct Item021536ec *) _Z24SearchBothTables02079e2cPci(obj->f0, *arg);
    if (item == NULL) return 0;
    struct Entry021536ec *tb;

    int r1 = 0;
    if (!(data_ov002_0216d3a0[1] & 1)) {
        MemFn021536ec t            = data_020e6d5c;
        data_ov002_0216cce4[0].fn  = t;
        data_ov002_0216cce4[11].fn = t;
        data_ov002_0216d3a0[1] |= 1;
    }
    unsigned int key = item->keyA;
    for (int i = 0; data_ov002_0216cce4[i].key >= 0; i++) {
        if (key == data_ov002_0216cce4[i].key) {
            if (data_ov002_0216cce8[i].ptr != 0) {
                r1 = (obj->*data_ov002_0216cce4[i].fn)(arg, item, 0);
            }
            break;
        }
    }

    int r2 = 0;
    if (!(data_ov002_0216d3a0[0] & 1)) {
        MemFn021536ec t           = data_020e6d5c;
        data_ov002_0216ccc0[0].fn = t;
        data_ov002_0216ccc0[2].fn = t;
        data_ov002_0216d3a0[0] |= 1;
    }
    unsigned int key2 = item->keyB;
    int i;
    for (i = 0, tb = (data_ov002_0216cce4 - 3); tb[i].key >= 0; i++) {
        if (key2 == tb[i].key) {
            if (data_ov002_0216ccc4[i].ptr != 0) {
                r2 = (obj->*tb[i].fn)(arg, item, 1);
            }
            break;
        }
    }
    return (r1 || r2) ? 1 : 0;
}
