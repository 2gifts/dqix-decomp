#include <globaldefs.h>

#if defined(jpn)
enum { kCountOffset = 0x9d4 };
#else
enum { kCountOffset = 0xaa0 };
#endif


struct Entry02021394 {
    unsigned short key1;
    unsigned char key2;
    unsigned char pad3;
    short val1;
    short val2;
};

struct Container02021394 {
    unsigned char pad[kCountOffset];
    unsigned short count;
    struct Entry02021394 entries[1];
};

#if defined(jpn)
#define FindEntryByKeyPair02021394 func_02020f88
extern "C" ARM int func_02020f88(struct Container02021394* c, int key1, int key2, short* out1, short* out2);
#endif

// USA: func_02021394
ARM int FindEntryByKeyPair02021394(struct Container02021394* c, int key1, int key2, short* out1, short* out2) {
    int i;
    for (i = 0; i < c->count; i++) {
        struct Entry02021394* p = &c->entries[i];
        if (p->key1 == key1 && p->key2 == key2) {
            *out1 = p->val1;
            *out2 = p->val2;
            return 1;
        }
    }
    return 0;
}
