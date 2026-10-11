#include <globaldefs.h>

struct S_020113e0 {
#if defined(jpn)
    char unk[0x5a70];
#else
    char unk[0x5cd0];
#endif
    unsigned char bits[10];
};

// USA: func_020113e0
ARM void FillBits5cd0(struct S_020113e0* obj) {
    int i;
    for (i = 0; i < 10; i++) {
        obj->bits[i] = 0xff;
    }
}
