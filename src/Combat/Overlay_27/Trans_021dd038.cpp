#include <globaldefs.h>

struct Unk021dd038_Inner {
    char pad0[0xc];
    unsigned short fc;
};

struct Unk021dd038 {
    char pad0[0x8];
    Unk021dd038_Inner* p8;
};

extern Unk021dd038 data_ov027_021e33e0;

// USA: func_ov027_021dd038  (semantic: Trans_021dd038)
extern "C" ARM unsigned short func_ov027_021dd038(void) {
    return data_ov027_021e33e0.p8->fc;
}
