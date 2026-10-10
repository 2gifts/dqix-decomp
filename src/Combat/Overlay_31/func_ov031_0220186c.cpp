#include <globaldefs.h>

extern "C" int _Z30CompareThreeU16sDiffer02200824PtS_(unsigned short*, unsigned short*);
extern "C" void func_ov031_02200e38(void* a, unsigned int b, int c);
extern "C" void func_ov031_022017c4(void* a);

extern unsigned char data_ov031_0224ce68[6];

struct GlobalStruct0224c980_0220186c {
    unsigned char pad[0x50];
    unsigned int field50;
};
extern GlobalStruct0224c980_0220186c data_ov031_0224c980;

struct Struct0220186c {
    unsigned short f0;
    unsigned short f2;
    unsigned short f4;
    unsigned short f6;
    unsigned char pad8[6];
    unsigned short fe;
    unsigned short f10;
    unsigned char pad12[6];
    unsigned short f18;
    unsigned short f1a;
};

#define SwapBytes16_0220186c(v) (unsigned short)(((v) >> 8) | ((v) << 8))

// USA: func_ov031_0220186c
extern "C" ARM void func_ov031_0220186c(Struct0220186c* a, unsigned int b) {
    if (b < 0x1c) return;
    if (_Z30CompareThreeU16sDiffer02200824PtS_((unsigned short*)a->pad8, (unsigned short*)data_ov031_0224ce68) == 0 ||
        data_ov031_0224c980.field50 == 0) return;

    if (a->f0 != 0x100 || a->f2 != 8 || a->f4 != 0x406) return;

    unsigned short type = SwapBytes16_0220186c(a->f6);
    if (type != 1 && type != 2) return;

    unsigned int combined = ((unsigned int)SwapBytes16_0220186c(a->fe) << 16) | SwapBytes16_0220186c(a->f10);
    unsigned int combined2 = ((unsigned int)SwapBytes16_0220186c(a->f18) << 16) | SwapBytes16_0220186c(a->f1a);
    int match1 = combined == data_ov031_0224c980.field50;
    int match2 = data_ov031_0224c980.field50 == combined2;

    if (!match1) func_ov031_02200e38(a->pad8, combined, match2);

    if (type == 1 && match2) {
        func_ov031_022017c4(a);
        return;
    }
    if (type != 2) return;
    if (match2 && match1) data_ov031_0224c980.pad[1] = 1;
}
