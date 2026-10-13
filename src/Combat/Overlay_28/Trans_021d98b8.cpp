#include <globaldefs.h>

struct Trans_021d98b8 {
    float scale;
    unsigned int unk4;
    unsigned short unk8;
    unsigned short unkA;
};

// USA: func_ov028_021d98b8  (semantic: Trans_021d98b8)
extern "C" ARM Trans_021d98b8* func_ov028_021d98b8(Trans_021d98b8* self) {
    self->unk4 = 0;
    self->unk8 = 0;
    self->unkA = 0;
    self->scale = 1.0f;
    return self;
}
