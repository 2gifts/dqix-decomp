#include <globaldefs.h>

extern "C" ARM void func_ov031_0223bb58(void* obj, int idx, int a, int b);

struct Entry02226910 {
    unsigned int  word0;
    unsigned short hword4;
    unsigned short pad6;
};

extern void** data_ov031_02250c00;
extern const unsigned char data_ov031_02248c7c[];
extern const unsigned char data_ov031_02248c70[];

// USA: func_ov031_02226910
extern "C" ARM void func_ov031_02226910(int a, int b) {
    if (a < 0) {
        return;
    }
    if (a < 10) {
        void** tbl = data_ov031_02250c00;
        unsigned char t = data_ov031_02248c7c[b];
        Entry02226910* e = *(Entry02226910**)((char*)tbl + (a << 2) + 0x10);
        e->word0 &= ~0xc00;
        e->hword4 = (e->hword4 & ~0xf000) | (t << 12);
        return;
    }
    int i = a - 10;
    if (i < 2) {
        void** tbl = data_ov031_02250c00;
        unsigned char t = data_ov031_02248c7c[b];
        Entry02226910* e = *(Entry02226910**)((char*)tbl + (i << 2) + 0x38);
        e->word0 &= ~0xc00;
        e->hword4 = (e->hword4 & ~0xf000) | (t << 12);
        return;
    }
    void** tbl = data_ov031_02250c00;
    void* e = *(void**)((char*)tbl + ((a - 0xc) << 2) + 0x40);
    func_ov031_0223bb58(e, -1, 0, data_ov031_02248c70[b]);
}
