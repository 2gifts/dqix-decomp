#include <globaldefs.h>

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: _Z26WriteTexImageParam0208b548iiiiiiij
// USA: func_0208b548
extern "C" ARM void _Z26WriteTexImageParam0208b548iiiiiiij(int a, int b, int c, int d, int e, int f, int g, unsigned int h) {
    *(volatile unsigned int*)0x040004a8 = (h >> 3) | (a << 26) | (b << 30) | (c << 20) | (d << 23) | (e << 16) | (f << 18) | (g << 29);
}