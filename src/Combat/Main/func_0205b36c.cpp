#include <globaldefs.h>

struct Rect0205b1ac { int offset; short x, y, width, height; };
struct GlyphEntry0205b36c { const char* text; signed char width; unsigned char flags; short bitOffset; };
struct GlyphSheet0205b36c { int field_0; unsigned short width; unsigned short height; int field_8; unsigned char* bitmap; };
struct GlyphDestination0205b36c { unsigned char* pixels; Rect0205b1ac* rectangles; unsigned char rectangleCount; };
extern "C" extern int _Z24GetWordFromTable02042638i(int);
extern "C" extern Rect0205b1ac* _Z31FindRectContainingPoint0205b1acP12Rect0205b1acjii(Rect0205b1ac*, unsigned int, int, int);

// USA: func_0205b36c
extern "C" ARM void func_0205b36c(GlyphDestination0205b36c* destination, GlyphEntry0205b36c* glyph, short x, short y, unsigned char color, unsigned char font) {
    GlyphSheet0205b36c* sheet = (GlyphSheet0205b36c*)_Z24GetWordFromTable02042638i(font);
    short bitOffset = glyph->bitOffset;
    unsigned char upperColor = color << 4;
    unsigned char lowerColor = color & 15;
    int pitch = sheet->width >> 3;
    signed char firstShift = 7 - (glyph->bitOffset & 7);
    unsigned int count = destination->rectangleCount;
    Rect0205b1ac* rectangles = destination->rectangles;
    for (int row = 0; row < 12; ++row) {
        short destinationY = y + row;
        signed char shift = firstShift;
        unsigned char* source = sheet->bitmap + pitch * row + (bitOffset >> 3);
        for (int column = 0; column < glyph->width; ++column) {
            if (*source & (1 << shift)) {
                short destinationX = x + column;
                Rect0205b1ac* rectangle = _Z31FindRectContainingPoint0205b1acP12Rect0205b1acjii(rectangles, count, destinationX, destinationY);
                if (rectangle) {
                    unsigned char* pixels = destination->pixels + rectangle->offset;
                    short localX = destinationX - rectangle->x;
                    short localY = destinationY - rectangle->y;
                    short tileX = localX >> 3;
                    short tileY = localY >> 3;
                    short tileWidth = rectangle->width >> 3;
                    short tile = tileY * tileWidth + tileX;
                    pixels += tile << 5;
                    short withinX = localX & 7;
                    short withinY = localY & 7;
                    int within = (withinY << 2) + (withinX >> 1);
                    unsigned char* pixel = pixels + within;
                    if (destinationX & 1) {
                        *pixel &= 15;
                        *pixel |= upperColor;
                    } else {
                        *pixel &= 240;
                        *pixel |= lowerColor;
                    }
                }
            }
            --shift;
            if (shift < 0) { shift = 7; ++source; }
        }
    }
}
