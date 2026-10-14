#include "GameState/GameState.h"
#include <globaldefs.h>

struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310 *c, int key);
int AppendFrameTag02041c08(char *dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag_02041ea4(char *dst, int cursor);
int AppendFormatted02041fac(char *buf, int a, int b);
int AppendPaletteTag_02041e70(char *dst, int palette);
int AppendNameTag_02041b70(char *dst, int n, const char *name);
int AppendString02042058(char *dst, const char *src);
extern "C" int func_ov002_02159774(void *base, int id, int a2, int a3, int a4);

// USA: func_ov002_0215d72c
extern "C" ARM void func_ov002_0215d72c(unsigned char *base, char *dst, int flag) {
    if (dst == NULL) return;

    GameState::GetInstance();
    int cursor = *(short *) (base + 0x1bee);

    if (flag) {
        AppendFrameTag02041c08(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag_02041ea4(dst, cursor);

    int field = GetFieldByKey020e0434((struct Container020e0310 *) (base + 0x20), 0x514);
    AppendFormatted02041fac(dst, field, 0x10);

    for (int i = 0; i < *(base + 0x1c6d) + 1; i++) {
        int id;
        if (i < *(base + 0x1c6d)) {
            id = *(base + 0x1c68 + i);
        } else {
            id = 4;
        }
        if (id == 4) {
            AppendNameTag_02041b70(dst, i,
                          (const char *) GetFieldByKey020e0434(
                              (struct Container020e0310 *) (base + 0x20), 0x515));
            return;
        }
        int pal = func_ov002_02159774(base, id, 1, 0, 0);
        AppendPaletteTag_02041e70(dst, pal);
        AppendNameTag_02041b70(dst, i, (const char *) (base + 0x1ab0 + id * 0x3c));
        AppendPaletteTag_02041e70(dst, 0xf);
        AppendString02042058(dst, *(const char **) (base + 0x1000 + 0xbdc));
    }
}
