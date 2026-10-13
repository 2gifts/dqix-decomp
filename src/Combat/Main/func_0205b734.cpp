#include <globaldefs.h>

struct Rect0205b1ac {
    int offset;
    short x;
    short y;
    short width;
    short height;
};
struct TileCanvas0205b734 {
    unsigned char* pixels;
    Rect0205b1ac* rectangles;
    unsigned char rectangleCount;
};
Rect0205b1ac* FindRectContainingPoint0205b1ac(Rect0205b1ac*, unsigned int, int, int);

// USA: func_0205b734
extern "C" ARM void func_0205b734(TileCanvas0205b734* canvas, short x, short y, short endX, short endY, unsigned char color) {
    unsigned char* pixels = canvas->pixels;
    unsigned char count;
    unsigned char highColor;
    unsigned char lowColor;
    short columnX;
    short row;
    short column;
    Rect0205b1ac* rectangles;
    if (!pixels || !(rectangles = canvas->rectangles)) return;
    lowColor = color & 15;
    highColor = lowColor << 4;
    count = canvas->rectangleCount;
    short width = endX - x;
    short height = endY - y;
    for (row = 0; row < height; row++) {
        columnX = x;
        for (column = 0; column < width; columnX++, column++) {
            Rect0205b1ac* rectangle = FindRectContainingPoint0205b1ac(rectangles, count, columnX, y);
            if (rectangle) {
                unsigned char* tile = pixels + rectangle->offset;
                short localX = columnX - rectangle->x;
                short localY = y - rectangle->y;
                tile += (((short)(localY >> 3) * (short)(rectangle->width >> 3) + (localX >> 3)) << 5);
                short pixelY = localY & 7;
                short pixelX = localX & 7;
                int pixelOffset = (pixelY << 2) + (pixelX >> 1);
                if (localX & 1) {
                    tile[pixelOffset] &= 15;
                    tile[pixelOffset] |= highColor;
                } else {
                    tile[pixelOffset] &= 0xf0;
                    tile[pixelOffset] |= lowColor;
                }
            }
        }
        y++;
    }
}
