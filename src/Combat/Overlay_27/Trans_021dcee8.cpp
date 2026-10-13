#include <globaldefs.h>

struct Data021e33e0 {
    char pad0[0x26];
    unsigned short f26;
};

extern Data021e33e0 data_ov027_021e33e0;

// USA: func_ov027_021dcee8  (semantic: Trans_021dcee8)
extern "C" ARM void func_ov027_021dcee8(unsigned short value) {
    data_ov027_021e33e0.f26 = value;
}
