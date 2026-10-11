#include <globaldefs.h>

struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310 *c, int key);
int AppendFrameTag02041c08(char *dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char *dst, int cursor);
const char *CallFunc020e0434With02153694(int key);
int AppendString02042058(char *dst, const char *src);
int AppendLineTag02041cc0(char *dst, int a);
int AppendXYTag(char *dst, int x, int y);
int AppendPaletteTag(char *dst, int palette);
int AppendNameTag(char *dst, int n, const char *name);
extern "C" void func_ov002_02156080(void *self, short *out, short *outCount);
extern "C" int func_ov002_02161920(void *self);

// USA: func_ov002_0215f4e8
extern "C" ARM void func_ov002_0215f4e8(unsigned char *base, char *dst, int flag) {
    if (dst == NULL) return;

    int cursor = *(short *) (base + 0x1bfe);
    if (flag) {
        AppendFrameTag02041c08(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag(dst, cursor);
    AppendString02042058(dst, CallFunc020e0434With02153694(0x16));
    AppendString02042058(dst, *(const char **) (base + 0x1000 + 0xbdc));
    AppendLineTag02041cc0(dst, 0x18);
    AppendXYTag(dst, 0xc, 0x1f);

    short count = 0;
    short list[9];
    func_ov002_02156080(base, list, &count);
    int mode = func_ov002_02161920(base);
    for (unsigned char i = 0; i < count; i++) {
        short v = list[i];
        if (mode == 1 && v == 6) {
            AppendPaletteTag(dst, 3);
        }
        AppendNameTag(dst, i,
                      (const char *) GetFieldByKey020e0434((struct Container020e0310 *) (base + 0x20), (short) (v + 0xfa1)));
        if (i != count - 1) {
            AppendString02042058(dst, *(const char **) (base + 0x1000 + 0xbdc));
        }
        if (mode == 1 && v == 6) {
            AppendPaletteTag(dst, 0xf);
        }
    }
}
