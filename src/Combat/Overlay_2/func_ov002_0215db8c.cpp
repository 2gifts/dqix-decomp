#include <globaldefs.h>
#include "GameState/GameState.h"

struct Container020e0310;

extern "C" unsigned char *_ZN9GameState21GetPartyMemberByIndexEi(void *gs, int idx);
extern "C" void func_ov002_02157424(void *self, int *slots);
extern "C" int func_ov002_02159774(void *self, int idx, int a, int b, int c);
void AppendFrameTag02041c08(char *buf, int x, int a, int b, int c, int d);
void AppendCursorTag(char *buf, int x);
const char *GetFieldByKey020e0434(Container020e0310 *tbl, int key);
void AppendFormatted02041fac(char *buf, int str, int n);
void AppendPaletteTag(char *buf, int pal);
void AppendNameTag(char *buf, int i, const char *str);
void AppendString02042058(char *buf, const char *str);

// USA: func_ov002_0215db8c
extern "C" ARM void func_ov002_0215db8c(char *self, char *buf, int frame) {
    int slots[7];
    if (buf == 0) return;
    void *gs  = GameState::GetInstance();
    short x   = *(short *) (self + 0x1bf0);
    short key = 0x76d;
    func_ov002_02157424(self, slots);
    if (frame) AppendFrameTag02041c08(buf, x, 8, 5, 5, 5);
    AppendCursorTag(buf, x);
    AppendFormatted02041fac(
        buf, (int) GetFieldByKey020e0434((Container020e0310 *) (self + 0x20), 0x76c), 0x10);
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
            AppendNameTag(buf, i, GetFieldByKey020e0434((Container020e0310 *) (self + 0x20), key++));
        }
        if (i != n - 1) AppendString02042058(buf, *(const char **) (self + 0x1bdc));
    }
}
