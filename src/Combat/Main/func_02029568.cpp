#include <globaldefs.h>

struct Menu02029568 {
    int type;
    char pad04[0x3c];
    int f40;
    void* entries;
    int f48;
    int f4c;
    short f50;
    short f52;
    short f54;
    short f56;
    short f58;
    unsigned short count;
    short f5c;
    short f5e;
    short f60;
    unsigned short f62;
    short f64;
    short f66;
    short f68;
    short f6a;
    unsigned char f6c;
    unsigned char f6d;
    unsigned char f6e;
    unsigned char f6f;
    unsigned char f70;
    unsigned char f71;
    unsigned char f72;
    unsigned char f73;
    unsigned char f74;
    char pad75[3];
    int arr[2];
};

extern unsigned short data_020ef74c;

extern "C" void _Z12Init0202949cPc(char* obj);

// USA: func_02029568
extern "C" ARM void func_02029568(struct Menu02029568* m) {
    _Z12Init0202949cPc((char*)m);
    m->type = 1;
    m->f50 = 0;
    m->f52 = 0;
    m->f54 = 0;
    m->f56 = 0;
    m->f58 = 0;
    m->f6c = 1;
    m->count = 0;
    m->f5c = -1;
    m->f5e = -1;
    m->f60 = -1;
    m->f6d = 0;
    m->f6e = 0;
    m->entries = 0;
    m->f48 = 0;
    m->f62 = 10;
    m->f64 = 0;
    m->f66 = (short)(m->f62 + m->f64);
    m->f6f = 0;
    m->f6a = 0;
    m->f68 = 0;
    data_020ef74c = 0x7d40;
    m->f71 = 0;
    m->f72 = 0;
    m->f73 = 0;
    m->f74 = 0;
    m->f40 = 0;
    m->f70 = 0;
    m->f4c = 8;
    for (int i = 0; i < 2; i++) {
        m->arr[i] = 0;
    }
}
