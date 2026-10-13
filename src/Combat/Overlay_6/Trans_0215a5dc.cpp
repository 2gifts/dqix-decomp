#include <globaldefs.h>

struct CallIfFlag0x800_021571ccStruct;

void SetByte_021571b8_021571b8(void* p, unsigned char v);
void CallIfFlag_021571cc_021571cc(CallIfFlag0x800_021571ccStruct* s);

struct AlchemyMenu {
    char pad0[0x10];
    CallIfFlag0x800_021571ccStruct* f10;
    char pad14[0x38b - 0x14];
    unsigned char f38b;
};

// USA: func_ov006_0215a5dc  (semantic: Trans_0215a5dc)
extern "C" ARM void func_ov006_0215a5dc(AlchemyMenu* self) {
    SetByte_021571b8_021571b8(self->f10, self->f38b);
    CallIfFlag_021571cc_021571cc(self->f10);
}
