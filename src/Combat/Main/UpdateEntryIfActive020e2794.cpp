#include <globaldefs.h>

struct Container0205a3d0;
void SetEntryPosition_020e27ec(struct Container0205a3d0* c, int key, short a, short b);
extern "C" void func_0205ae8c(void* p);
extern "C" void func_020e1780(void* p);

struct Inner020e2794 {
    unsigned char pad[0x3f];
    unsigned char flag0 : 1;
};

struct Struct020e2794 {
    unsigned char pad0[0xc];
    struct Inner020e2794* c;
    void* field_10;
    unsigned char pad1[4];
    short field_18;
    short field_1a;
    unsigned short field_1c;
    unsigned char pad2[2];
    struct Container0205a3d0* field_20;
};

// USA: func_020e2794
ARM void UpdateEntryIfActive020e2794(struct Struct020e2794* self, void* b) {
    if (!self->c->flag0) return;
    if (self->field_20 != NULL) {
        SetEntryPosition_020e27ec(self->field_20, self->field_1c, self->field_18, self->field_1a);
        if (b != NULL) func_0205ae8c(b);
    }
    func_020e1780(self->field_10);
}
