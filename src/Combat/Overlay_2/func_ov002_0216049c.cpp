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
GameObject *GetCombatantWithFlag0x100(GameState *gameState, int combatantId);
extern "C" int func_ov002_02159774(void *base, int id, int a2, int a3, int a4);
extern "C" void func_ov002_02157480(void *obj, int *arr);

static inline int IsPartySlot0216049c(int id) {
    return (id >= 0 && id <= 3) ? 1 : 0;
}

// USA: func_ov002_0216049c
extern "C" ARM void func_ov002_0216049c(unsigned char *base, char *dst, int flag) {
    if (dst == NULL) return;

    GameState *gs = GameState::GetInstance();
    GameObject *m;
    int id;
    int cursor = *(short *) (base + 0x1c08);
    int ids[4];
    func_ov002_02157480(base, ids);

    if (flag) {
        _Z22AppendFrameTag02041c08Pciiiii(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag(dst, cursor);

    int field = _Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310 *) (base + 0x20), 0x1004);
    _Z23AppendFormatted02041facPcii(dst, field, 0x10);

    for (int i = 0; i < 4; i++) {
        id = ids[i];
        if (!IsPartySlot0216049c(id)) continue;
        m = GetCombatantWithFlag0x100(gs, id);
        if (m == NULL) return;
        if (i != 0) {
            _Z20AppendString02042058PcPKc(dst, *(const char **) (base + 0x1000 + 0xbdc));
        }
        int pal = func_ov002_02159774(base, id, 0, 1, 1);
        AppendPaletteTag(dst, pal);
        AppendNameTag(dst, i, *(const char **) ((char *) m + 0x134));
        AppendPaletteTag(dst, 0xf);
    }
}
