#include <globaldefs.h>

struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310 *c, int key);
int AppendFrameTag02041c08(char *dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag_02041ea4(char *dst, int cursor);
const char *CallFunc020e0434With02153694_020e51cc(int key);
int AppendString02042058(char *dst, const char *src);
int AppendLineTag02041cc0(char *dst, int a);
int AppendXYTag_02041a90(char *dst, int x, int y);
int AppendPaletteTag_02041e70(char *dst, int palette);
int AppendNameTag_02041b70(char *dst, int n, const char *name);
extern "C" void func_ov002_02156080(void *self, short *out, short *outCount);
extern "C" int func_ov002_02161920(void *self);

// USA: func_ov002_0215f4e8
extern "C" ARM void func_ov002_0215f4e8(unsigned char *base, char *dst, int flag) {
    if (dst == NULL) return;

    int cursor = *(short *) (base + 0x1bfe);
    if (flag) {
        AppendFrameTag02041c08(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag_02041ea4(dst, cursor);
    AppendString02042058(dst, CallFunc020e0434With02153694_020e51cc(0x16));
    AppendString02042058(dst, *(const char **) (base + 0x1000 + 0xbdc));
    AppendLineTag02041cc0(dst, 0x18);
    AppendXYTag_02041a90(dst, 0xc, 0x1f);

    short count = 0;
    short list[9];
    func_ov002_02156080(base, list, &count);
    int mode = func_ov002_02161920(base);
    for (unsigned char i = 0; i < count; i++) {
        short v = list[i];
        if (mode == 1 && v == 6) {
            AppendPaletteTag_02041e70(dst, 3);
        }
        AppendNameTag_02041b70(dst, i,
                      (const char *) GetFieldByKey020e0434((struct Container020e0310 *) (base + 0x20), (short) (v + 0xfa1)));
        if (i != count - 1) {
            AppendString02042058(dst, *(const char **) (base + 0x1000 + 0xbdc));
        }
        if (mode == 1 && v == 6) {
            AppendPaletteTag_02041e70(dst, 0xf);
        }
    }
}
