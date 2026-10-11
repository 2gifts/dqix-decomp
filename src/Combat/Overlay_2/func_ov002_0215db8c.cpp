#include <globaldefs.h>

struct Container020e0310;

extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" unsigned char *_ZN9GameState21GetPartyMemberByIndexEi(void *gs, int idx);
extern "C" void func_ov002_02157424(void *self, int *slots);
extern "C" int func_ov002_02159774(void *self, int idx, int a, int b, int c);
extern "C" void _Z22AppendFrameTag02041c08Pciiiii(char *buf, int x, int a, int b, int c, int d);
void AppendCursorTag(char *buf, int x);
extern "C" const char *_Z21GetFieldByKey020e0434P17Container020e0310i(Container020e0310 *tbl, int key);
extern "C" void _Z23AppendFormatted02041facPcii(char *buf, int str, int n);
void AppendPaletteTag(char *buf, int pal);
void AppendNameTag(char *buf, int i, const char *str);
extern "C" void _Z20AppendString02042058PcPKc(char *buf, const char *str);

// USA: func_ov002_0215db8c
extern "C" ARM void func_ov002_0215db8c(char *self, char *buf, int frame) {
    int slots[7];
    if (buf == 0) return;
    void *gs  = _ZN9GameState11GetInstanceEv();
    short x   = *(short *) (self + 0x1bf0);
    short key = 0x76d;
    func_ov002_02157424(self, slots);
    if (frame) _Z22AppendFrameTag02041c08Pciiiii(buf, x, 8, 5, 5, 5);
    AppendCursorTag(buf, x);
    _Z23AppendFormatted02041facPcii(
        buf, (int) _Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310 *) (self + 0x20), 0x76c), 0x10);
    int slot;
    int n = *(int *) (self + 0x1c38) + 1;
    int i;
    for (i = 0; i < n; i++) {
        slot   = slots[i];
        int ok = (slot >= 0 && slot <= 3);
        if (ok) {
            unsigned char *m = _ZN9GameState21GetPartyMemberByIndexEi(gs, slot);
            if (m != 0) {
                AppendPaletteTag(buf, func_ov002_02159774(self, slot, 0, 1, 1));
                AppendNameTag(buf, i, *(const char **) (m + 0x134));
                AppendPaletteTag(buf, 0xf);
            }
        } else {
            AppendNameTag(buf, i, _Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310 *) (self + 0x20), key++));
        }
        if (i != n - 1) _Z20AppendString02042058PcPKc(buf, *(const char **) (self + 0x1bdc));
    }
}
