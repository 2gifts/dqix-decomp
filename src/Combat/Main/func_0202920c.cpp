#include <globaldefs.h>

extern void* data_020fe9a4;

// USA: func_0202920c
extern "C" ARM void func_0202920c(int color, int x, int y, int w, int h) {
    if (data_020fe9a4 == 0) return;
    if (x + w < 0) return;
    if (y + h < 0) return;
    if (x >= 0x100 || y >= 0xc0) return;
    if (x < 0) {
        w = x + w;
        x = 0;
    }
    if (x + w >= 0x100) w = 0xff - x;
    if (y < 0) {
        h = y + h;
        y = 0;
    }
    if (y + h >= 0xc0) h = 0xbf - y;

    int parity;
    unsigned char odd;
    int even;
    unsigned char* row;
    int i;
    unsigned char* p;
    int j;

    even = color & 0xff;
    odd = (even << 4) & 0xff;
    row = (unsigned char*)data_020fe9a4 + y * 0x80 + x / 2;

    for (i = 0; i < h; i++) {
        p = row;
        parity = x;
        for (j = 0; j < w; j++) {
            if (parity & 1) {
                *p = (*p & 0xf) | odd;
                p++;
            } else {
                *p = (*p & 0xf0) | even;
            }
            parity++;
        }
        row += 0x80;
    }
}
