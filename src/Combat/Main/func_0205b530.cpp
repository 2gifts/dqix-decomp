#include <globaldefs.h>
struct Rect0205b1ac { int offset; short x, y, w, h; };
struct Canvas0205b530 { unsigned char* pixels; Rect0205b1ac* rects; unsigned char count; };
extern "C" Rect0205b1ac* _Z31FindRectContainingPoint0205b1acP12Rect0205b1acjii(Rect0205b1ac*, unsigned int, int, int);
// USA: func_0205b530
extern "C" ARM void func_0205b530(Canvas0205b530* self, unsigned char* src, short x, short y) {
    if (!src) return;
    unsigned char count = self->count;
    unsigned char* pixels = self->pixels;
    Rect0205b1ac* rects = self->rects;
    short px;
    for (short row = 0; row < 8; src += 4, y++, row++) {
        px = x;
        for (short col = 0; col < 8; px++, col++) {
            Rect0205b1ac* rect = _Z31FindRectContainingPoint0205b1acP12Rect0205b1acjii(rects, count, px, y);
            if (rect) {
                short rx = px - rect->x;
                short ry = y - rect->y;
                short width = rect->w >> 3;
                unsigned char* base = pixels + rect->offset;
                short byteX = (short)(rx & 7) >> 1;
                short byteY = ry & 7;
                int byte;
                unsigned char* tile = base + (((short)(ry >> 3) * width + (rx >> 3)) << 5);
                byte = (byteY << 2) + byteX;
                int value = src[col >> 1];
                unsigned char nibble;
                if (rx & 1) {
                    if (col & 1) nibble = value & 0xf0; else nibble = (value << 4) & 0xf0;
                    if (nibble) { tile[byte] &= 15; tile[byte] |= nibble; }
                } else {
                    if (col & 1) nibble = (value >> 4) & 15; else nibble = value & 15;
                    if (nibble) { tile[byte] &= 0xf0; tile[byte] |= nibble; }
                }
            }
        }
    }
}
