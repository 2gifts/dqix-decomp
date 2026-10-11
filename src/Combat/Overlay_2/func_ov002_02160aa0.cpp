#include <globaldefs.h>

struct Container020e0310;
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310 *c, int key);
extern "C" int _Z22AppendFrameTag02041c08Pciiiii(char *dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char *dst, int cursor);
int AppendPaletteTag(char *dst, int palette);
int AppendNameTag(char *dst, int n, const char *name);
extern "C" int _Z20AppendString02042058PcPKc(char *dst, const char *src);
extern "C" int _Z24NextIndexOrZero_0215a9b4Pvs(void *base, short i);
extern "C" int _Z25GetShortFromTable0206e3d4ii(int a, int b);
extern "C" void _Z31SetElementStateOrCreate0215b918Phiii(unsigned char *self, int a, int b, int c);
extern "C" char *func_0205ec34(void);
extern "C" char data_ov002_0216d2b4[];

// USA: func_ov002_02160aa0
extern "C" ARM void func_ov002_02160aa0(unsigned char *base, char *dst, int flag) {
    if (dst == NULL) return;

    short c                                    = *(short *) (base + 0x1c00 + 0xc);
    int cursor                                 = c % 16;
    *(unsigned char *) (base + 0x2000 + 0x484) = c / 16;
    if (flag) {
        _Z22AppendFrameTag02041c08Pciiiii(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag(dst, cursor);

    short n = 0;
    unsigned char end;
    unsigned char i = *(unsigned char *) (base + 0x2000 + 0x484) << 4;
    end             = i + 0x10;
    char *save      = func_0205ec34();
    for (; i < end; i++) {
        cursor = _Z25GetShortFromTable0206e3d4ii((int) save, _Z24NextIndexOrZero_0215a9b4Pvs(base, i));
        if (cursor == 0) {
            AppendPaletteTag(dst, 0xf);
            AppendNameTag(dst, n,
                          (const char *) _Z21GetFieldByKey020e0434P17Container020e0310i(
                              (struct Container020e0310 *) (base + 0x20), 0x119c + 1));
        } else if (*(unsigned int *) (base + 0x2000 + 0x480) & (1 << (cursor - 1))) {
            AppendPaletteTag(dst, 0xf);
            AppendNameTag(dst, n,
                          (const char *) _Z21GetFieldByKey020e0434P17Container020e0310i(
                              (struct Container020e0310 *) (base + 0x20), (short) (cursor + 0x119d)));
        } else {
            AppendPaletteTag(dst, 0xf);
            AppendNameTag(dst, n,
                          (const char *) _Z21GetFieldByKey020e0434P17Container020e0310i(
                              (struct Container020e0310 *) (base + 0x20), 0x119c));
        }
        n++;
        if (i & 1) {
            _Z20AppendString02042058PcPKc(dst, *(const char **) (base + 0x1000 + 0xbdc));
        } else {
            _Z20AppendString02042058PcPKc(dst, data_ov002_0216d2b4);
        }
    }
    AppendPaletteTag(dst, 0xf);
    _Z31SetElementStateOrCreate0215b918Phiii(base, 0x22, *(unsigned char *) (base + 0x2000 + 0x484), 2);
}
