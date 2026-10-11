#include "GameState/GameState.h"
#include <globaldefs.h>

struct Container020e0310;
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310 *c, int key);
extern "C" int _Z22AppendFrameTag02041c08Pciiiii(char *dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char *dst, int cursor);
extern "C" int _Z23AppendFormatted02041facPcii(char *buf, int a, int b);
int AppendPaletteTag(char *dst, int palette);
int AppendNameTag(char *dst, int n, const char *name);
extern "C" int _Z20AppendString02042058PcPKc(char *dst, const char *src);
extern "C" int func_ov002_02159774(void *base, int id, int a2, int a3, int a4);

// USA: func_ov002_0215e9c4
extern "C" ARM void func_ov002_0215e9c4(unsigned char *base, char *dst, int flag) {
    if (dst == NULL) return;

    GameState *bs = GameState::GetInstance();
    int cursor    = *(short *) (base + 0x1bf8);

    if (flag) {
        _Z22AppendFrameTag02041c08Pciiiii(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag(dst, cursor);

    int field = _Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310 *) (base + 0x20), 3);
    _Z23AppendFormatted02041facPcii(dst, field, 0x16);

    for (int i = 0; i < *(signed char *) (base + 0x1c73); i++) {
        GameObject *m = bs->GetPartyMemberByIndex(((signed char *) (base + 0x1c6e))[i]);
        if (m != NULL) {
            int pal = func_ov002_02159774(base, ((signed char *) (base + 0x1c6e))[i], 0, 1, 1);
            AppendPaletteTag(dst, pal);
            AppendNameTag(dst, i, *(const char **) ((char *) m + 0x134));
            AppendPaletteTag(dst, 0xf);
            if (i != *(signed char *) (base + 0x1c73) - 1) {
                _Z20AppendString02042058PcPKc(dst, *(const char **) (base + 0x1000 + 0xbdc));
            }
        }
    }
}
