#include <globaldefs.h>

struct Inner021dd024 {
    unsigned char pad0[8];
    unsigned int f8;
};

struct Holder021dd024 {
    unsigned char pad0[8];
    Inner021dd024* ptr;
};

extern Holder021dd024 data_ov027_021e33e0;

// USA: func_ov027_021dd024  (semantic: Trans_021dd024)
extern "C" ARM unsigned int func_ov027_021dd024(void) {
    return data_ov027_021e33e0.ptr->f8;
}
