#include <globaldefs.h>

extern "C" int LoadToMainObjVRAM(int, int, unsigned int);
extern "C" int LoadToSubObjVRAM(int, int, unsigned int);

struct Obj02076994 {
    char pad0[0x50];
    int f50;
    char pad54[0xa];
    unsigned char f5e;
    char pad5f[1];
};

// USA: func_02076994
extern "C" ARM void func_02076994(struct Obj02076994* s, char* src, char* dest, unsigned int width, unsigned int rows) {
    unsigned int lim = rows;
    unsigned int n = width >> 3;
    unsigned int tile = 4;
    unsigned int row = 0x20;
    if (s->f50 == 1) {
        tile = 8;
        row = 0x40;
    }
    unsigned int step = n * tile;
    unsigned int rstep = n * row;
    unsigned int base = 0;
    unsigned int m;
    unsigned int i;
    unsigned int c;
    unsigned int j, o;
    char* d = dest;

    for (o = 0; o < (lim >> 3); o++) {
        m = base;
        for (i = 0; i < n; i++) {
            c = m;
            for (j = 0; j < 8; j++) {
                if (s->f5e == 0) {
                    LoadToMainObjVRAM((int)(src + c), (int)d, tile);
                } else {
                    LoadToSubObjVRAM((int)(src + c), (int)d, tile);
                }
                d += tile;
                c += step;
            }
            m += tile;
        }
        base += rstep;
    }
}
