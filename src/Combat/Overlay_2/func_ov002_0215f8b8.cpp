#include "GameState/GameState.h"
#include <globaldefs.h>

struct Container020e0310;
struct Struct0200fb08;
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310 *c, int key);
extern "C" int _Z22AppendFrameTag02041c08Pciiiii(char *dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char *dst, int cursor);
extern "C" int _Z23AppendFormatted02041facPcii(char *buf, int a, int b);
int AppendXTag(char *dst, int x);
int AppendXYTag(char *dst, int x, int y);
int AppendWidthTag(char *dst, int w);
extern "C" int _Z21AppendLineTag02041cc0Pci(char *dst, int a);
int AppendPaletteTag(char *dst, int palette);
int AppendNameTag(char *dst, int n, const char *name);
extern "C" int _Z20AppendString02042058PcPKc(char *dst, const char *src);
extern "C" int _Z24NormalizeField5_0200fb08P14Struct0200fb08(struct Struct0200fb08 *p);
int GetField0x3acValue(GameState *gs);
unsigned char *GetFieldAt0x150(unsigned char *p);
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
        _Z22AppendFrameTag02041c08Pciiiii(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag(dst, cursor);
    int title = _Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310 *) (base + 0x20), 0xfa2);
    AppendXTag(dst, (0xf0 - func_020420e8(title, 0)) >> 1);
    _Z23AppendFormatted02041facPcii(dst, title, 0xf);

    int n                    = 0;
    GameState *gs            = GameState::GetInstance();
    unsigned char count      = *(base + 0x1000 + 0xc73);
    signed char *ids         = (signed char *) (base + 0x1c00 + 0x6e);
    int mode                 = _Z24NormalizeField5_0200fb08P14Struct0200fb08((struct Struct0200fb08 *) gs);
    struct XPair0215f8b8 *xs = &data_ov002_0216ca70[mode];
    signed char *ws          = &data_ov002_0216ca10[mode * 2];
    __clear(wa, 8);
    __clear(wb, 8);
    AppendWidthTag(wa, ws[0]);
    AppendWidthTag(wb, ws[1]);
    int me = GetField0x3acValue(gs);
    int k1 = count + 1;
    int k2 = k1 + count + 1;
    for (unsigned char i = 0; i < count; i++) {
        int id        = ids[i];
        GameObject *m = gs->GetPartyMemberByIndex(id);
        if (m == NULL) continue;
        AppendPaletteTag(dst, func_ov002_02159774(base, id, 0, 1, 1));
        title = (int) m->baseStats_;
        _Z20AppendString02042058PcPKc(dst, (const char *) title);
        AppendXTag(dst, 0x4a);
        AppendPaletteTag(dst, 0xf);
        short key = (signed char) *(int *) (GetFieldAt0x150((unsigned char *) m) + 0x94c) + 0x109c;
        if (id == me) key = 0x109b;
        AppendNameTag(
            dst, n,
            (const char *) _Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310 *) (base + 0x20), key));
        AppendXTag(dst, xs->a);
        AppendNameTag(dst, k1, wa);
        AppendXTag(dst, xs->b);
        AppendNameTag(dst, k2, wb);
        _Z20AppendString02042058PcPKc(dst, *(const char **) (base + 0x1000 + 0xbdc));
        n++;
        k1++;
        k2++;
    }
    AppendXYTag(dst, 0x4a, data_ov002_0216ca44[count]);
    AppendNameTag(
        dst, n,
        (const char *) _Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310 *) (base + 0x20), 0x11fa));
    _Z21AppendLineTag02041cc0Pci(dst, data_ov002_0216ca1c[count]);
}
