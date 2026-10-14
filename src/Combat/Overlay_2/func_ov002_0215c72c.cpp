#include <globaldefs.h>

struct Container020e0310;

extern "C" void *func_0202ae18(void);
extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" unsigned char *_ZN9GameState21GetPartyMemberByIndexEi(void *gs, int idx);
extern "C" int func_ov002_02159774(void *self, int idx, int a, int b, int c);
void AppendFrameTag02041c08(char *buf, int x, int a, int b, int c, int d);
void AppendCursorTag(char *buf, int x);
const char *GetFieldByKey020e0434(Container020e0310 *tbl, int key);
void AppendFormatted02041fac(char *buf, int str, int n);
void AppendPaletteTag(char *buf, int pal);
void AppendNameTag(char *buf, int i, const char *str);
void AppendString02042058(char *buf, const char *str);

// USA: func_ov002_0215c72c
extern "C" ARM void func_ov002_0215c72c(char *self, char *buf, int frame) {
    if (buf == 0) return;
    func_0202ae18();
    void *gs = _ZN9GameState11GetInstanceEv();
    short x  = *(short *) (self + 0x1be6);
    int n    = 0;
    if (frame) AppendFrameTag02041c08(buf, x, 8, 5, 5, 5);
    AppendCursorTag(buf, x);
    AppendFormatted02041fac(
        buf, (int) GetFieldByKey020e0434((Container020e0310 *) (self + 0x20), 0x44c), 0x18);
    for (int i = 0; i < *(signed char *) (self + 0x1c73); i++) {
        unsigned char *m = _ZN9GameState21GetPartyMemberByIndexEi(gs, ((signed char *) (self + 0x1c6e))[i]);
        if (m != 0) {
            AppendPaletteTag(buf, func_ov002_02159774(self, ((signed char *) (self + 0x1c6e))[i], 0, 1, 1));
            AppendNameTag(buf, n, *(const char **) (m + 0x134));
            AppendPaletteTag(buf, 0xf);
            AppendString02042058(buf, *(const char **) (self + 0x1bdc));
            n++;
        }
    }
    AppendNameTag(buf, n, GetFieldByKey020e0434((Container020e0310 *) (self + 0x20), 0x44d));
    if (*(unsigned char *) (self + 0x2485) == 0) {
        AppendString02042058(buf, *(const char **) (self + 0x1bdc));
        AppendNameTag(buf, n + 1, GetFieldByKey020e0434((Container020e0310 *) (self + 0x20), 0x44e));
    }
}
