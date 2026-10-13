#include <globaldefs.h>

struct Entry_02224fa4 {
    unsigned int w0;
    unsigned short h4;
    unsigned short pad6;
};

extern Entry_02224fa4** data_ov031_02250bfc;
extern const unsigned char data_ov031_022489ac[];
extern unsigned char data_ov031_022489b0[];

extern "C" void func_ov031_0223bb58(void* obj, int idx, int a, int b);

// USA: func_ov031_02224fa4
extern "C" ARM void func_ov031_02224fa4(int id, int sel) {
    if (id < 0) return;
    if (id < 0x2f) {
        unsigned char pal = data_ov031_022489ac[sel];
        Entry_02224fa4* e = *(Entry_02224fa4**)((char*)data_ov031_02250bfc + id * 4 + 0x30);
        e->w0 &= ~0xc00;
        e->h4 = (e->h4 & ~0xf000) | (pal << 12);
        return;
    }
    int k = id - 0x2f;
    if (k < 4) {
        unsigned char pal = data_ov031_022489ac[sel];
        Entry_02224fa4* e = *(Entry_02224fa4**)((char*)data_ov031_02250bfc + k * 4 + 0xec);
        e->w0 &= ~0xc00;
        e->h4 = (e->h4 & ~0xf000) | (pal << 12);
        return;
    }
    unsigned char pal = data_ov031_022489b0[sel];
    func_ov031_0223bb58(*(Entry_02224fa4**)((char*)data_ov031_02250bfc + (id - 0x33) * 4 + 0xfc), -1, 0, pal);
}
