#include <globaldefs.h>

struct Struct_0205d81c;
struct Elem_0205d81c;
struct ShortArrays0204c654;

struct Offsets_0216c98a {
    short v[4];
};

extern "C" struct Elem_0205d81c *_Z23FindElementByC40205d81cP15Struct_0205d81ci(struct Struct_0205d81c *s, int key);
extern "C" void _Z22SetEntryFields02154bcciiPvihh(int a, int b, void *obj, int idx, unsigned char arg5, unsigned char arg6);
void SetFourShortsAtIndex(ShortArrays0204c654 *arr, int idx, short a, short b, short c, short d);

extern Offsets_0216c98a data_ov002_0216c98a;

// USA: func_ov002_0215ad70
extern "C" ARM void func_ov002_0215ad70(unsigned char *obj) {
    struct Elem_0205d81c *elem =
        _Z23FindElementByC40205d81cP15Struct_0205d81ci((struct Struct_0205d81c *) (obj + 0x2c8 + 0xc00), 0x1c);
    if (elem == 0) {
        return;
    }
    int baseX             = (short) (*(short *) ((char *) elem + 0xac) * 8);
    int baseY             = (short) (*(short *) ((char *) elem + 0xae) * 8);
    Offsets_0216c98a offs = data_ov002_0216c98a;
    unsigned char k       = 0;
    unsigned short tile   = 0x16;
    for (unsigned char row = 0; row < 4; row++) {
        for (unsigned char col = 0; col < 4; col++) {
            short idx;
            int py;
            short dx;
            dx       = offs.v[col];
            short dy = offs.v[row];
            short px = (short) (dx + baseX);
            py       = (short) (dy + baseY);
            _Z22SetEntryFields02154bcciiPvihh(px, py, *(void **) (obj + 0x1000 + 0xa68), tile++, (unsigned char) (k * 4 + 0xc),
                                              0xff);
            idx = (short) (col + row * 4);
            if (*(short *) (obj + 0x1c00 + 6) == idx) {
                _Z22SetEntryFields02154bcciiPvihh(px, py, *(void **) (obj + 0x1000 + 0xa68), 0x11, 8, 0xff);
            }
            SetFourShortsAtIndex((ShortArrays0204c654 *) elem, idx, dx, dy, 0x18, 0x18);
            k++;
        }
    }
    elem = _Z23FindElementByC40205d81cP15Struct_0205d81ci((struct Struct_0205d81c *) (obj + 0x2c8 + 0xc00), 0x1d);
    if (elem == 0) {
        return;
    }
    short x2 = *(volatile short *) ((char *) elem + 0xac);
    short y2 = *(volatile short *) ((char *) elem + 0xae);
    _Z22SetEntryFields02154bcciiPvihh((short) (x2 * 8) + 0x10, (short) (y2 * 8) + 0x18, *(void **) (obj + 0x1000 + 0xa68),
                                      0x14, 0x54, 8);
}
