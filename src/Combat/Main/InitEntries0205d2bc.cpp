#include <globaldefs.h>

struct Entry0205d2bc { unsigned char b[0x20]; };

struct Obj0205d2bc {
    char pad0[0x98];
    struct Entry0205d2bc* field98;   // 0x98
    char pad1[0xb2 - 0x9c];
    unsigned char fieldB2;           // 0xb2
};

extern "C" void func_0204b088(struct Entry0205d2bc*, int);

// USA: func_0205d2bc
ARM void InitEntries0205d2bc(struct Obj0205d2bc* obj) {
    unsigned char i;
    if (obj->field98 == 0) return;
    for (i = 0; i < obj->fieldB2; i++) {
        func_0204b088(&obj->field98[i], 0);
    }
}
