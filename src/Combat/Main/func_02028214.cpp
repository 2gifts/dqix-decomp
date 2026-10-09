#include <globaldefs.h>

extern "C" void* _ZN13SafeAllocator8AllocateEj(void* self, unsigned int size);

struct Entry02028214 {
    unsigned char* a;
    unsigned char* b;
};

struct Elem02028214 {
    unsigned char key;
    char pad1;
    unsigned char count;
    char pad2[9];
    unsigned char** buf;
};

struct Struct02028214 {
    char pad0[2];
    unsigned char n;
    unsigned char m;
    struct Elem02028214* base;
    struct Entry02028214* entries;
    char pad1[0x10];
    int result;
};

// USA: func_02028214
extern "C" ARM void func_02028214(void* a, int b) {
    struct Struct02028214* s = (struct Struct02028214*)a;
    int i;
    for (i = 0; i < s->n; i++) {
        struct Elem02028214* e = &s->base[i];
        e->count = 0;
        int j;
        for (j = 0; j < s->m; j++) {
            struct Entry02028214* en = &s->entries[j];
            if (*en->a == e->key || *en->b == e->key) {
                e->count++;
            }
        }
    }
    int i2;
    for (i2 = 0; i2 < s->n; i2++) {
        struct Elem02028214* e = &s->base[i2];
        e->buf = (unsigned char**)_ZN13SafeAllocator8AllocateEj((void*)b, e->count << 2);
        int cnt = 0;
        if (e->buf == NULL) {
            e->count = 0;
            continue;
        }
        int k;
        for (k = 0; k < s->m; k++) {
            struct Entry02028214* en = &s->entries[k];
            unsigned char key = e->key;
            if (*en->a == key) {
                e->buf[cnt] = en->b;
                cnt++;
            } else if (*en->b == key) {
                e->buf[cnt] = en->a;
                cnt++;
            }
            if (cnt == e->count) break;
        }
        e->count = cnt;
    }
    s->result = 1;
}