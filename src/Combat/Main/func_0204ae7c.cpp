#include <globaldefs.h>

struct Tilemap0204ae44 {
    short width;
    short height;
    char _pad[8];
    unsigned short* buffer;
};

// USA: func_0204ae7c
extern "C" ARM void func_0204ae7c(struct Tilemap0204ae44* obj, short palette, short x0, short y0, short width, short height) {
    unsigned short* buffer = obj->buffer;
    if (buffer == NULL) {
        return;
    }
    unsigned short pal = palette & 0xF;
    pal = pal << 12;
    short xend = x0 + width;
    short yend = y0 + height;
    short pitch = obj->width;
    short y = y0;
    unsigned short* p;
    while (y < yend) {
        p = buffer + pitch * y + x0;
        short x = x0;
        while (x < xend) {
            p[0] = p[0] & 0xFFF;
            p[0] = p[0] | pal;
            p++;
            x = x + 1;
        }
        y = y;
        y += 1;
    }
}