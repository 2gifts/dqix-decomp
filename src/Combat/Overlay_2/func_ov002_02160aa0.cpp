#include <globaldefs.h>

struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310 *c, int key);
int AppendFrameTag02041c08(char *dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag_02041ea4(char *dst, int cursor);
int AppendPaletteTag_02041e70(char *dst, int palette);
int AppendNameTag_02041b70(char *dst, int n, const char *name);
int AppendString02042058(char *dst, const char *src);
int NextIndexOrZero_0215a9b4(void *base, short i);
int GetShortFromTable0206e3d4(int a, int b);
void SetElementStateOrCreate0215b918(unsigned char *self, int a, int b, int c);
extern "C" char *func_0205ec34(void);
extern "C" char data_ov002_0216d2b4[];

// USA: func_ov002_02160aa0
extern "C" ARM void func_ov002_02160aa0(unsigned char *base, char *dst, int flag) {
    if (dst == NULL) return;

    short c                                    = *(short *) (base + 0x1c00 + 0xc);
    int cursor                                 = c % 16;
    *(unsigned char *) (base + 0x2000 + 0x484) = c / 16;
    if (flag) {
        AppendFrameTag02041c08(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag_02041ea4(dst, cursor);

    short n = 0;
    unsigned char end;
    unsigned char i = *(unsigned char *) (base + 0x2000 + 0x484) << 4;
    end             = i + 0x10;
    char *save      = func_0205ec34();
    for (; i < end; i++) {
        cursor = GetShortFromTable0206e3d4((int) save, NextIndexOrZero_0215a9b4(base, i));
        if (cursor == 0) {
            AppendPaletteTag_02041e70(dst, 0xf);
            AppendNameTag_02041b70(dst, n,
                          (const char *) GetFieldByKey020e0434(
                              (struct Container020e0310 *) (base + 0x20), 0x119c + 1));
        } else if (*(unsigned int *) (base + 0x2000 + 0x480) & (1 << (cursor - 1))) {
            AppendPaletteTag_02041e70(dst, 0xf);
            AppendNameTag_02041b70(dst, n,
                          (const char *) GetFieldByKey020e0434(
                              (struct Container020e0310 *) (base + 0x20), (short) (cursor + 0x119d)));
        } else {
            AppendPaletteTag_02041e70(dst, 0xf);
            AppendNameTag_02041b70(dst, n,
                          (const char *) GetFieldByKey020e0434(
                              (struct Container020e0310 *) (base + 0x20), 0x119c));
        }
        n++;
        if (i & 1) {
            AppendString02042058(dst, *(const char **) (base + 0x1000 + 0xbdc));
        } else {
            AppendString02042058(dst, data_ov002_0216d2b4);
        }
    }
    AppendPaletteTag_02041e70(dst, 0xf);
    SetElementStateOrCreate0215b918(base, 0x22, *(unsigned char *) (base + 0x2000 + 0x484), 2);
}
