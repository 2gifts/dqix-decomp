#include <globaldefs.h>

struct WindowBounds {
    unsigned short x1;
    unsigned short y1;
    unsigned short x2;
    unsigned short y2;
};

// USA: func_ov031_0223cc18
// Set the selected display window's horizontal and vertical bounds.
// Coordinates use their low byte; side 1 selects sub display, window 0 selects WIN0.
extern "C" ARM void func_ov031_0223cc18(int side, int window, const WindowBounds* bounds) {
    if (side == 1) {
        if (window == 0) {
            int x1 = bounds->x1;
            int y1 = bounds->y1;
            int x2 = bounds->x2;
            int y2 = bounds->y2;
            *(volatile unsigned short*)0x04001040 = ((x1 << 8) & 0xff00) | (x2 & 0xff);
            *(volatile unsigned short*)0x04001044 = ((y1 << 8) & 0xff00) | (y2 & 0xff);
        } else {
            int x1 = bounds->x1;
            int y1 = bounds->y1;
            int x2 = bounds->x2;
            int y2 = bounds->y2;
            *(volatile unsigned short*)0x04001042 = ((x1 << 8) & 0xff00) | (x2 & 0xff);
            *(volatile unsigned short*)0x04001046 = ((y1 << 8) & 0xff00) | (y2 & 0xff);
        }
    } else {
        if (window == 0) {
            int x1 = bounds->x1;
            int y1 = bounds->y1;
            int x2 = bounds->x2;
            int y2 = bounds->y2;
            *(volatile unsigned short*)0x04000040 = ((x1 << 8) & 0xff00) | (x2 & 0xff);
            *(volatile unsigned short*)0x04000044 = ((y1 << 8) & 0xff00) | (y2 & 0xff);
        } else {
            int x1 = bounds->x1;
            int y1 = bounds->y1;
            int x2 = bounds->x2;
            int y2 = bounds->y2;
            *(volatile unsigned short*)0x04000042 = ((x1 << 8) & 0xff00) | (x2 & 0xff);
            *(volatile unsigned short*)0x04000046 = ((y1 << 8) & 0xff00) | (y2 & 0xff);
        }
    }
}
