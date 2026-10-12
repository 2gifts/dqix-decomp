#include <globaldefs.h>

struct Entry020429e4 {
    unsigned char k0;
    unsigned char k1;
};

struct Table020429e4 {
    unsigned short stride;
    char pad2[4];
    short count;
    struct Entry020429e4* entries;
    char* data;
};

#if defined(jpn)
#define FindEntryByKeyPair020429e4 func_02043060
extern "C" ARM char* func_02043060(struct Table020429e4*, unsigned char*);
extern "C" void func_02042ea4(unsigned char*, const unsigned char*);
#endif

// USA: func_020429e4
ARM char* FindEntryByKeyPair020429e4(struct Table020429e4* t, unsigned char* key) {
    int count;
    struct Entry020429e4* e;
    int i;
#if !defined(jpn)
    unsigned char k0, k1;
#endif
    if (t == NULL) {
        return NULL;
    }
#if defined(jpn)
    unsigned char converted[2];
    func_02042ea4(converted, key);
#else
    if (key == NULL) {
        k0 = 0;
        k1 = 0;
    } else {
        k0 = key[0];
        k1 = key[1];
    }
#endif
    count = t->count;
    e = t->entries;
    for (i = 0; i < count; e++, i++) {
#if defined(jpn)
        if (converted[0] == e->k0 && converted[1] == e->k1) {
#else
        if (k0 == e->k0 && k1 == e->k1) {
#endif
            return t->data + i * t->stride;
        }
    }
    return NULL;
}
