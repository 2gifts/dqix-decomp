#include <globaldefs.h>

struct Entry_0205d6a0;
struct Outer020e28dc;
struct Obj020e25e8;
extern "C" char *_Z26GetGlobalField0x1c020421a0v();
extern "C" void _Z24ReinitController02043204Pc(char *p);
extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(struct Entry_0205d6a0 *e, int a);
extern "C" void _Z27ResetSelectionState020e25e8P11Obj020e25e8(struct Obj020e25e8 *o);
extern "C" int _Z24GetInnerFlagBit0020e28dcP13Outer020e28dc(struct Outer020e28dc *o);
extern "C" void func_ov002_0215b9a4(char *self, unsigned char key, int flag);

// USA: func_ov002_0216bfd4
extern "C" ARM void func_ov002_0216bfd4(char *base, unsigned char mode) {
    char *g = _Z26GetGlobalField0x1c020421a0v();
    if (*(unsigned char *) (base + 0x1000 + 0xc2e) != 0) {
        *(unsigned int *) (base + 0x2000 + 0x47c) &= ~4;
        *(unsigned char *) (base + 0x1000 + 0xc2e) = 0;
        func_ov002_0215b9a4(base, *(int *) (base + 0x1000 + 0xbb8), 1);
        _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((struct Entry_0205d6a0 *) (base + 0x2c8 + 0xc00), 0);
    }
    *(unsigned char *) (base + 0x1000 + 0xc79) = mode;
    *(unsigned char *) (base + 0x1000 + 0xc30) = 1;
    *(int *) (base + 0x1000 + 0xbb8)           = 0x26;
    *(int *) (base + 0x1000 + 0xbbc)           = 0x26;
    int reset                                  = 0;
    int next                                   = 0;
    int reinit                                 = 0;
    int force                                  = 0;
    switch (*(unsigned char *) (base + 0x1000 + 0xc79)) {
        case 0:
            *(short *) (base + 0x1c00 + 0x28)          = 0x236f;
            *(short *) (base + 0x1c00 + 0x2a)          = -1;
            *(unsigned char *) (base + 0x1000 + 0xc2e) = 1;
            next                                       = 1;
            *(short *) (base + 0x1c00 + 0x12)          = 0;
            break;
        case 1: break;
        case 2:
            *(short *) (base + 0x1c00 + 0x28) = 0x2371;
            *(short *) (base + 0x1c00 + 0x2a) = -1;
            next                              = 1;
            break;
        case 3:
            *(short *) (base + 0x1c00 + 0x28)          = 0x2372;
            *(short *) (base + 0x1c00 + 0x2a)          = -1;
            *(unsigned char *) (base + 0x1000 + 0xc2e) = 1;
            next                                       = 1;
            *(short *) (base + 0x1c00 + 0x12)          = 0;
            break;
        case 4:
            *(short *) (base + 0x1c00 + 0x28) = 0x2373;
            *(short *) (base + 0x1c00 + 0x2a) = -1;
            reinit                            = 1;
            next                              = 1;
            break;
        case 5:
            *(short *) (base + 0x1c00 + 0x28)          = 0x2377;
            *(short *) (base + 0x1c00 + 0x2a)          = -1;
            reset                                      = 1;
            reinit                                     = 1;
            next                                       = 1;
            force                                      = 1;
            *(unsigned char *) (base + 0x1000 + 0xcc5) = 1;
            break;
        case 6:
            *(short *) (base + 0x1c00 + 0x28) = 0x2370;
            *(short *) (base + 0x1c00 + 0x2a) = -1;
            reset                             = 1;
            reinit                            = 1;
            next                              = 1;
            break;
        case 7:
            *(short *) (base + 0x1c00 + 0x28)          = 0x2375;
            *(short *) (base + 0x1c00 + 0x2a)          = -1;
            reset                                      = 1;
            reinit                                     = 1;
            next                                       = 1;
            force                                      = 1;
            *(unsigned char *) (base + 0x1000 + 0xcc5) = 1;
            break;
        case 8: reset = 1; break;
        case 9:
            *(short *) (base + 0x1c00 + 0x28) = 0x2374;
            *(short *) (base + 0x1c00 + 0x2a) = -1;
            reinit                            = 1;
            next                              = 1;
            force                             = 1;
            break;
    }
    if (reset && *(void **) (base + 4) != NULL &&
        _Z24GetInnerFlagBit0020e28dcP13Outer020e28dc(*(struct Outer020e28dc **) (base + 4)))
    {
        _Z27ResetSelectionState020e25e8P11Obj020e25e8(*(struct Obj020e25e8 **) (base + 4));
    }
    if (reinit) {
        if (!next) {
            _Z24ReinitController02043204Pc(g);
        } else if (force) {
            _Z24ReinitController02043204Pc(g);
        }
        *(int *) (base + 0x1000 + 0xbbc)           = 9;
        *(unsigned char *) (base + 0x1000 + 0xc30) = 0;
        if (*(unsigned char *) (base + 0x1000 + 0xc79) == 9) {
            *(int *) (base + 0x1000 + 0xbbc) = 5;
        }
        if (*(unsigned char *) (base + 0x1000 + 0xc78) != 0) {
            *(signed char *) (base + 0x1000 + 0xc20)   = 4;
            *(unsigned char *) (base + 0x1000 + 0xc78) = 0;
        }
    }
    if (next) {
        *(int *) (base + 0x1000 + 0xbb8) = 0x26;
        *(int *) (base + 0x1000 + 0xbc0) = 0;
    }
}
