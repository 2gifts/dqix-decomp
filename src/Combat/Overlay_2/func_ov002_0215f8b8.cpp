#include "GameState/GameState.h"
#include <globaldefs.h>

struct Container020e0310;
struct Struct0200fb08;
int GetFieldByKey020e0434(struct Container020e0310 *c, int key);
int AppendFrameTag02041c08(char *dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag_02041ea4(char *dst, int cursor);
int AppendFormatted02041fac(char *buf, int a, int b);
int AppendXTag_02041a28(char *dst, int x);
int AppendXYTag_02041a90(char *dst, int x, int y);
int AppendWidthTag_02041acc(char *dst, int w);
int AppendLineTag02041cc0(char *dst, int a);
int AppendPaletteTag_02041e70(char *dst, int palette);
int AppendNameTag_02041b70(char *dst, int n, const char *name);
int AppendString02042058(char *dst, const char *src);
int NormalizeField5_0200fb08(struct Struct0200fb08 *p);
int GetField0x3acValue_020100a8(GameState *gs);
unsigned char *GetFieldAt0x150_02053c6c(unsigned char *p);
extern "C" int func_020420e8(int str, int a);
extern "C" void *__clear(void *dst, int count);
extern "C" int func_ov002_02159774(void *base, int id, int a2, int a3, int a4);
struct XPair0215f8b8 {
    short a;
    short b;
};
extern "C" struct XPair0215f8b8 data_ov002_0216ca70[];
extern "C" signed char data_ov002_0216ca10[];
extern "C" int data_ov002_0216ca44[];
extern "C" int data_ov002_0216ca1c[];

struct Named0215f8b8 {
    char pad[0x134];
    const char *name;
};
// USA: func_ov002_0215f8b8
extern "C" ARM void func_ov002_0215f8b8(unsigned char *base, char *dst, int flag) {
    char wa[8];
    char wb[8];
    if (dst == NULL) return;

    int cursor = *(short *) (base + 0x1c00 + 2);
    if (flag) {
        AppendFrameTag02041c08(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag_02041ea4(dst, cursor);
    int title = GetFieldByKey020e0434((struct Container020e0310 *) (base + 0x20), 0xfa2);
    AppendXTag_02041a28(dst, (0xf0 - func_020420e8(title, 0)) >> 1);
    AppendFormatted02041fac(dst, title, 0xf);

    int n                    = 0;
    GameState *gs            = GameState::GetInstance();
    unsigned char count      = *(base + 0x1000 + 0xc73);
    signed char *ids         = (signed char *) (base + 0x1c00 + 0x6e);
    int mode                 = NormalizeField5_0200fb08((struct Struct0200fb08 *) gs);
    struct XPair0215f8b8 *xs = &data_ov002_0216ca70[mode];
    signed char *ws          = &data_ov002_0216ca10[mode * 2];
    __clear(wa, 8);
    __clear(wb, 8);
    AppendWidthTag_02041acc(wa, ws[0]);
    AppendWidthTag_02041acc(wb, ws[1]);
    int me = GetField0x3acValue_020100a8(gs);
    int k1 = count + 1;
    int k2 = k1 + count + 1;
    for (unsigned char i = 0; i < count; i++) {
        int id        = ids[i];
        GameObject *m = gs->GetPartyMemberByIndex(id);
        if (m == NULL) continue;
        AppendPaletteTag_02041e70(dst, func_ov002_02159774(base, id, 0, 1, 1));
        title = (int) m->baseStats_;
        AppendString02042058(dst, (const char *) title);
        AppendXTag_02041a28(dst, 0x4a);
        AppendPaletteTag_02041e70(dst, 0xf);
        short key = (signed char) *(int *) (GetFieldAt0x150_02053c6c((unsigned char *) m) + 0x94c) + 0x109c;
        if (id == me) key = 0x109b;
        AppendNameTag_02041b70(
            dst, n,
            (const char *) GetFieldByKey020e0434((struct Container020e0310 *) (base + 0x20), key));
        AppendXTag_02041a28(dst, xs->a);
        AppendNameTag_02041b70(dst, k1, wa);
        AppendXTag_02041a28(dst, xs->b);
        AppendNameTag_02041b70(dst, k2, wb);
        AppendString02042058(dst, *(const char **) (base + 0x1000 + 0xbdc));
        n++;
        k1++;
        k2++;
    }
    AppendXYTag_02041a90(dst, 0x4a, data_ov002_0216ca44[count]);
    AppendNameTag_02041b70(
        dst, n,
        (const char *) GetFieldByKey020e0434((struct Container020e0310 *) (base + 0x20), 0x11fa));
    AppendLineTag02041cc0(dst, data_ov002_0216ca1c[count]);
}
