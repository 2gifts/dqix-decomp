#include "GameState/GameState.h"
#include <globaldefs.h>

struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310 *c, int key);
int AppendFrameTag02041c08(char *dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char *dst, int cursor);
int AppendFormatted02041fac(char *buf, int a, int b);
int AppendPaletteTag(char *dst, int palette);
int AppendNameTag(char *dst, int n, const char *name);
int AppendString02042058(char *dst, const char *src);
extern "C" int func_ov002_02159774(void *base, int id, int a2, int a3, int a4);

// USA: func_ov002_0215c348
extern "C" ARM void func_ov002_0215c348(unsigned char *base, char *dst, int flag) {
    GameState *bs = GameState::GetInstance();
    int cursor    = *(short *) (base + 0x1be2);
    int n         = 0;

    if (flag) {
        AppendFrameTag02041c08(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag(dst, cursor);

    int field = GetFieldByKey020e0434((struct Container020e0310 *) (base + 0x20), 0x5dc);
    AppendFormatted02041fac(dst, field, 0x16);

    unsigned char count = *(base + 0x1c73);
    unsigned char *ids  = base + 0x1c6e;
    for (unsigned char i = 0; i < count; i++) {
        int id        = ids[i];
        GameObject *m = bs->GetPartyMemberByIndex(id);
        if (m != NULL) {
            int pal = func_ov002_02159774(base, id, 0, 1, 1);
            AppendPaletteTag(dst, pal);
            AppendNameTag(dst, n, *(const char **) ((char *) m + 0x134));
            AppendPaletteTag(dst, 0xf);
            n++;
            if (i != count - 1) {
                AppendString02042058(dst, *(const char **) (base + 0x1000 + 0xbdc));
            }
        }
    }
}
