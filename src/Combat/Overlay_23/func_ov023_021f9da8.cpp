#include <globaldefs.h>

struct Cursor021f9da8 {
    char pad0[0x20];
    unsigned short* table;
    unsigned short rows;
    unsigned short cols;
};

struct Sub_021f9da8 {
    char pad[0xa8];
    short f_a8;
    short f_aa;
    short f_ac;
    short f_ae;
};

static inline Sub_021f9da8* GetSub_021f9da8(void* n) {
    return (Sub_021f9da8*)((char*)n + 0x20);
}

extern "C" void* func_ov011_021849c8(void* obj);
extern "C" void* func_ov023_021f6880(void* base, int key);
extern "C" void* _Z29GetLinkedNodeIfKind6_021f9cb8PvS_S_(void* unused, void* other, void* node);

// USA: func_ov023_021f9da8
extern "C" ARM int func_ov023_021f9da8(Cursor021f9da8* self, void* other, int x, int y) {
    void* nodes = func_ov011_021849c8(other);
    unsigned short total = self->rows * self->cols;
    unsigned short i;
    for (i = 0; i < total; i++) {
        void* node = func_ov023_021f6880(nodes, self->table[i]);
        void* linked = _Z29GetLinkedNodeIfKind6_021f9cb8PvS_S_(self, other, node);
        if (linked == 0) {
            continue;
        }
        Sub_021f9da8* sub = GetSub_021f9da8(linked);
        if (sub == 0) {
            continue;
        }
        short ht = sub->f_ae * 8;
        short lc = sub->f_ac;
        short wd = sub->f_a8;
        lc = lc * 8;
        wd = wd * 8;
        short bottom = (short)(sub->f_aa * 8) + ht;
        short right = lc + wd;
        short left = lc;
        int r = 0;
        if (bottom - 16 > y) {
            return 0;
        }
        if (y >= bottom) {
            return 0;
        }
        if (left <= x && x < left + 16) {
            r--;
        }
        if (right - 16 > x) {
            return r;
        }
        if (x < right) {
            r = 1;
        }
        return r;
    }
    return 0;
}
