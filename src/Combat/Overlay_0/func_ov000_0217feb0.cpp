#include <globaldefs.h>

struct Entry0217feb0 {
    char pad0[0x4c];
    int id;
#if defined(jpn)
    char pad1[0xc7 - 0x50];
#else
    char pad1[0x87 - 0x50];
#endif
    unsigned char field87;
    char pad2[0x448 - 0x88];
};

struct Battle0217feb0 {
    char pad0[0x6c];
    signed char slots[4];
    char pad1[0x958 - 0x70];
    struct Entry0217feb0 entries[1];
};

static inline struct Entry0217feb0* GetSlotEntry(struct Battle0217feb0* obj, int i) {
    return &obj->entries[obj->slots[i]];
}

// USA: func_ov000_0217feb0
extern "C" ARM void func_ov000_0217feb0(struct Battle0217feb0* obj, unsigned char value, int id) {
    if (id < 0) {
        for (int i = 0; i < 4; i++) {
            struct Entry0217feb0* e = GetSlotEntry(obj, i);
            e->field87 = value;
        }
    } else {
        for (int i = 0; i < 4; i++) {
            struct Entry0217feb0* e = GetSlotEntry(obj, i);
            if (id == e->id) {
                e->field87 = value;
                return;
            }
        }
    }
}
