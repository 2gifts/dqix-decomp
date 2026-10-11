#include <globaldefs.h>

#if defined(jpn)
#define func_ov005_0215a620 func_ov005_0215bb74
#endif

struct Obj0204b8d0;
extern "C" void _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(struct Obj0204b8d0*, unsigned int, int, int, short, short, short, short, unsigned short);

struct List0204b0e8;
extern "C" void _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(struct List0204b0e8*, void*);

// USA: func_ov005_0215a620
#pragma opt_propagation off
extern "C" ARM void func_ov005_0215a620(char* obj) {
    if ((*(unsigned int*)(obj + 0x3dcc) & 0x800) == 0) return;

    unsigned char state = *(unsigned char*)(obj + 0x3db8);
    if (!(state != 0 && state != 1)) {
        _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst((struct Obj0204b8d0*)(obj + 0x284 + 0xc00), 0, 0x16, 0x16, 0x16, 0x16, 0xa, 2, 0xffff);
    } else {
        unsigned char mode = *(unsigned char*)(obj + 0x3dbc);
        unsigned char* table = (unsigned char*)(obj + 0x1d4 + 0x3c00);
        unsigned char kind = table[mode];
        unsigned int j = 5;
        if (kind == 1) j = 4;
        else if (kind == 2) j = 2;
        else if (kind == 3) j = 3;
        _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst((struct Obj0204b8d0*)(obj + 0x284 + 0xc00), j, 0, 0, 0x16, 0x16, 0xa, 2, 0xffff);
    }
    _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv((struct List0204b0e8*)(obj + 0x284 + 0xc00), 0);
    *(unsigned int*)(obj + 0x3dcc) &= ~0x800;
}
