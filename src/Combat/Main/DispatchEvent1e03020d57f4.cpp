#include <globaldefs.h>

extern "C" void func_020ca3ec(int value, void* dest, int count);

struct Struct020d57f4 {
    int type;
    unsigned short valF1;
    unsigned short valF2;
    unsigned short valF3;
    unsigned short valG;
    unsigned char valH;
    unsigned char valI;
    unsigned char valK;
};

extern "C" void func_020d5684(int, int, int, int, unsigned short, struct Struct020d57f4*);

// USA: func_020d57f4
ARM void DispatchEvent1e03_020d57f4(int a, int b, int c, int d, unsigned short e, unsigned short f, unsigned short g, int h, int i, int j, int k) {
    struct Struct020d57f4 s;
    func_020ca3ec(0, &s, 0x10);
    s.type = 0x1e03;
    s.valG = g;
    s.valH = h;
    s.valI = i;
    s.valK = k;
    s.valF1 = f;
    s.valF2 = f;
    if (j != 0 && f != 0) {
        s.type |= 4;
        s.valF3 = f;
    }
    func_020d5684(a, b, c, d, e, &s);
}
