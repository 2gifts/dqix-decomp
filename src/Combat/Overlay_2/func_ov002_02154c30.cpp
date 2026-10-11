#include <globaldefs.h>

struct StatA02154c30 {
    unsigned int id;
    unsigned short v4;
    unsigned short v6;
};
struct StatB02154c30 {
    unsigned char pad[0x30];
    unsigned short v30;
    unsigned short v32;
};
struct StatC02154c30 {
    unsigned char pad[0x950];
    int v950;
};
struct Member02154c30 {
    unsigned char pad[0x130];
    StatA02154c30 *a;
    StatB02154c30 *b;
    unsigned char pad138[0x150 - 0x138];
    StatC02154c30 *c;
};
struct Cache02154c30 {
    unsigned int id;
    unsigned short v4;
    unsigned short v6;
    unsigned short v8;
    unsigned short va;
    unsigned char vc;
    unsigned char vd;
    unsigned char pad[2];
};

extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" Member02154c30 *_ZN9GameState21GetPartyMemberByIndexEi(void *gs, int idx);
int GetTableValue(void *p);

static inline int G16(unsigned short *p) {
    int v = *p;
    return v;
}
static inline int G32(unsigned int *p) {
    unsigned int v = *p;
    return v;
}
static inline int G8(int *p) {
    int v = *p;
    return v;
}

// USA: func_ov002_02154c30
extern "C" ARM int func_ov002_02154c30(Cache02154c30 *cache) {
    int changed = 0;
    void *gs    = _ZN9GameState11GetInstanceEv();
    Member02154c30 *m;
    Cache02154c30 *e;
    int i;
    for (i = 0; i < 4; i++) {
        m = _ZN9GameState21GetPartyMemberByIndexEi(gs, i);
        if (m == 0) continue;
        e = &cache[i];
        if (!(e->v4 != G16(&m->a->v4) || e->v6 != G16(&m->b->v30) || e->v8 != G16(&m->a->v6) || e->va != G16(&m->b->v32) ||
              e->vd != G8(&m->c->v950) || e->vc != GetTableValue(m) || e->id != G32(&m->a->id)))
            continue;
        e->v4   = m->a->v4;
        e->v6   = m->b->v30;
        e->v8   = m->a->v6;
        e->va   = m->b->v32;
        e->vd   = m->c->v950;
        e->vc   = GetTableValue(m);
        e->id   = m->a->id;
        changed = 1;
    }
    return changed;
}
