#include <globaldefs.h>

struct Sub148_021e110c {
    char pad[0x10];
    unsigned int flags;
};

struct Ent021e110c {
    unsigned char id;
    unsigned char val;
    char pad[6];
    unsigned char* obj;
};

int GetSubstructByte0x1c(unsigned char*);
int GetSubstructByte0x1d(unsigned char*);
int GetSubstructByte0x1e(unsigned char*);
extern "C" void func_ov025_021e12f8(unsigned char* map, int id, int val, int extra, int a, int b);

static inline void SetCell_021e110c(unsigned char* map, unsigned int id, unsigned char val) {
    if (id < 0x51) {
        map[id] = val;
    }
}

// USA: func_ov025_021e110c
extern "C" ARM void func_ov025_021e110c(unsigned char* map, Ent021e110c* ents, int n) {
    for (int i = 0; i < 0x51; i++) {
        if (map[i] < 0xff) {
            map[i] = 0;
        }
    }
    for (int j = 0; j < n; j++) {
        unsigned int id = GetSubstructByte0x1d(ents[j].obj);
        if (id >= 0x51) {
            id = GetSubstructByte0x1c(ents[j].obj);
        }
        if (id < 0x51) {
            SetCell_021e110c(map, id, ents[j].val);
        }
        unsigned char* c = ents[j].obj;
        Sub148_021e110c* sub;
        if ((*(unsigned short*)c & 0x400) && (sub = *(Sub148_021e110c**)(c + 0x148)) != 0) {
            unsigned int extra = (sub->flags << 1) >> 0x1e;
            if (extra != 0) {
                func_ov025_021e12f8(map, id, ents[j].val, extra & 0xff, 0, 0);
            }
        }
        unsigned int id2 = GetSubstructByte0x1e(ents[j].obj);
        if (id2 < 0x51) {
            SetCell_021e110c(map, id2, ents[j].val);
        }
    }
}
