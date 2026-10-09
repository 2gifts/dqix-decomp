#include <globaldefs.h>

struct StructDE234_020de234 {
    int a, b, c, d;
    unsigned int field10Low : 10;
    unsigned int field10Mid : 10;
    unsigned int field10High : 8;
    unsigned int field10Unused : 4;
    short e, f, g, h, i;
};

struct Container020dedd0 {
    unsigned short count;
    unsigned char pad2[10];
    StructDE234_020de234* base;
    unsigned char pad10[4];
    unsigned char useBinarySearch;
};

struct Holder021b5c88 {
    unsigned char pad0[0x2754];
    Container020dedd0 entries;
};

struct Settings021b5c88 {
    unsigned short pad0[2];
    unsigned short pad4 : 2;
    unsigned short mode : 2;
    unsigned short pad4b : 12;
};

struct Self021b5c88 {
    unsigned char pad0[0x12];
    short key;
    unsigned short value;
    unsigned char pad16;
    signed char category;
    unsigned char pad18[0x24 - 0x18];
    Settings021b5c88* settings;
};

extern "C" Holder021b5c88* func_02012fe4(void);
extern "C" StructDE234_020de234* _Z24FindElementByKey020dedd0P17Container020dedd0i(Container020dedd0* c, int key);
extern "C" unsigned short _Z31GetPreferredPackedField020de234P20StructDE234_020de234i(StructDE234_020de234* p, int preferMid);

// USA: func_ov017_021b5c88
extern "C" ARM int func_ov017_021b5c88(Self021b5c88* self) {
    Container020dedd0* entries = &func_02012fe4()->entries;
    if (self->settings->mode == 1) {
        self->category = 0x69;
        self->value = 0x7f;
    } else {
        StructDE234_020de234* entry = _Z24FindElementByKey020dedd0P17Container020dedd0i(entries, self->key);
        if (entry != NULL) {
            self->category = entry->field10High;
            self->value = _Z31GetPreferredPackedField020de234P20StructDE234_020de234i(entry, 0);
        }
    }
    return 2;
}
