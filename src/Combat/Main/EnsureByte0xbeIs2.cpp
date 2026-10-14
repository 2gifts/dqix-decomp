#include <globaldefs.h>

extern "C" int func_0207964c(void* obj);

struct Obj02033b68 {
    char pad[0xbe];
    unsigned char fbe;
    unsigned char fbf;
};
void SetByteIfChanged02033b68(struct Obj02033b68* obj, int newVal);

// USA: func_0207872c
ARM int EnsureByte0xbeIs2_0207872c(struct Obj02033b68* p) {
    if (p->fbe != 2) {
        SetByteIfChanged02033b68(p, 2);
    }
    return func_0207964c(p);
}
