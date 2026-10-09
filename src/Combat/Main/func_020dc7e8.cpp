#include <globaldefs.h>
extern "C" void _Z29UpdateObjPaletteEntry020dc70ciiiittj(int, int, int, int, unsigned short, unsigned short, unsigned int);
static inline int IsObjectMode020dc7e8(unsigned int mode) { return mode >= 6; }
// USA: func_020dc7e8
extern "C" ARM void func_020dc7e8(unsigned int mode, int id) {
    int source;
    int sub = 0;
    unsigned short palette = 0;
    unsigned short entry = 0;
    source = 15;
    unsigned int count = 2;
    int object = IsObjectMode020dc7e8(mode);
    switch (mode) {
    case 0: sub = 1; palette = 2; entry = 9; break;
    case 1: palette = 6; entry = 14; break;
    case 2: source = 0; sub = 1; palette = 12; count = 32; break;
    case 3: sub = 1; entry = 13; break;
    case 4: entry = 13; break;
    case 5: palette = 2; entry = 4; break;
    case 6: sub = 1; entry = 2; break;
    case 7: sub = 1; palette = 4; entry = 3; break;
    case 8: palette = 9; entry = 15; break;
    }
    if (id < 0) {
        signed char i = 0;
        while (i < 4) {
            _Z29UpdateObjPaletteEntry020dc70ciiiittj(i, source, sub, object, palette, entry, count);
            palette++;
            i++;
        }
    } else _Z29UpdateObjPaletteEntry020dc70ciiiittj(id, source, sub, object, palette, entry, count);
}
