#include <globaldefs.h>

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: WriteTexImageParam0208b548
// USA: func_0208b548
ARM void WriteTexImageParam0208b548(int a, int b, int c, int d, int e, int f, int g, unsigned int h) {
    *(volatile unsigned int*)0x040004a8 = (h >> 3) | (a << 26) | (b << 30) | (c << 20) | (d << 23) | (e << 16) | (f << 18) | (g << 29);
}
