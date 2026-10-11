#include <globaldefs.h>

struct Container020e0310;

extern "C" void *func_0202ae18(void);
extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" unsigned char *_ZN9GameState21GetPartyMemberByIndexEi(void *gs, int idx);
extern "C" int func_ov002_02159774(void *self, int idx, int a, int b, int c);
extern "C" void _Z22AppendFrameTag02041c08Pciiiii(char *buf, int x, int a, int b, int c, int d);
void AppendCursorTag(char *buf, int x);
extern "C" const char *_Z21GetFieldByKey020e0434P17Container020e0310i(Container020e0310 *tbl, int key);
extern "C" void _Z23AppendFormatted02041facPcii(char *buf, int str, int n);
void AppendPaletteTag(char *buf, int pal);
void AppendNameTag(char *buf, int i, const char *str);
extern "C" void _Z20AppendString02042058PcPKc(char *buf, const char *str);

// USA: func_ov002_0215c72c
extern "C" ARM void func_ov002_0215c72c(char *self, char *buf, int frame) {
    if (buf == 0) return;
    func_0202ae18();
    void *gs = _ZN9GameState11GetInstanceEv();
    short x  = *(short *) (self + 0x1be6);
    int n    = 0;
    if (frame) _Z22AppendFrameTag02041c08Pciiiii(buf, x, 8, 5, 5, 5);
    AppendCursorTag(buf, x);
    _Z23AppendFormatted02041facPcii(
        buf, (int) _Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310 *) (self + 0x20), 0x44c), 0x18);
    for (int i = 0; i < *(signed char *) (self + 0x1c73); i++) {
        unsigned char *m = _ZN9GameState21GetPartyMemberByIndexEi(gs, ((signed char *) (self + 0x1c6e))[i]);
        if (m != 0) {
            AppendPaletteTag(buf, func_ov002_02159774(self, ((signed char *) (self + 0x1c6e))[i], 0, 1, 1));
            AppendNameTag(buf, n, *(const char **) (m + 0x134));
            AppendPaletteTag(buf, 0xf);
            _Z20AppendString02042058PcPKc(buf, *(const char **) (self + 0x1bdc));
            n++;
        }
    }
    AppendNameTag(buf, n, _Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310 *) (self + 0x20), 0x44d));
    if (*(unsigned char *) (self + 0x2485) == 0) {
        _Z20AppendString02042058PcPKc(buf, *(const char **) (self + 0x1bdc));
        AppendNameTag(buf, n + 1, _Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310 *) (self + 0x20), 0x44e));
    }
}
