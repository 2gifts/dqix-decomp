#include "GameState/GameState.h"
#include <globaldefs.h>

struct Obj02046574;
struct StoreStruct;
struct Container020e0310;
extern "C" char *_Z26GetGlobalField0x1c020421a0v();
GameObject *GetCombatantWithFlag0x100(GameState *gameState, int combatantId);
unsigned char *GetFieldAt0x150(unsigned char *p);
extern "C" void _Z22SetIndexedName02046574P11Obj02046574iPc(struct Obj02046574 *obj, int index, char *str);
void StoreInArray0x8b0(struct StoreStruct *base, int index, int value);
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310 *c, int key);
int AppendPaletteTag(char *dst, int palette);
extern "C" int _Z20AppendString02042058PcPKc(char *dst, const char *src);
void SetByteInRange(unsigned char *messages, int index, unsigned char digits);
void SetByteAtIndex(unsigned char *messages, int index, unsigned char value);
extern "C" void func_02046380(void *g);
extern "C" int func_020420e8(const char *text, int large);
extern "C" int sprintf(char *dst, const char *fmt, ...);
extern "C" void *__clear(void *dst, int count);
extern "C" int func_ov017_021bdbcc(GameResources *r);
extern "C" void func_02046608(void *messages, int a, const char *format, char *output, int size, int b, int c);
extern "C" char data_ov002_0216d2a1[];

static inline unsigned short LdH(char *p, int off) {
    unsigned short v = *(unsigned short *) (p + off);
    return v;
}

// USA: func_ov002_0215e644
extern "C" ARM void func_ov002_0215e644(char *base, char *dst) {
    char num[0x10];
    char tag[0x20];
    char text[0x400];
    if (dst == NULL) return;
    char *g       = _Z26GetGlobalField0x1c020421a0v();
    GameObject *m = GetCombatantWithFlag0x100(GameState::GetInstance(), *(signed char *) (base + 0x1c00 + 0x20));
    if (m == NULL) return;
    unsigned char *f = GetFieldAt0x150((unsigned char *) m);
    if (f == NULL) return;
    func_02046380(g);
    _Z22SetIndexedName02046574P11Obj02046574iPc((struct Obj02046574 *) g, 0, *(char **) ((char *) m + 0x134));
    int x1 = (0x40 - func_020420e8(*(const char **) ((char *) m + 0x134), 0)) >> 1;
    StoreInArray0x8b0((struct StoreStruct *) g, 0, LdH(*(char **) ((char *) m + 0x130), 4));
    StoreInArray0x8b0((struct StoreStruct *) g, 1, LdH(*(char **) ((char *) m + 0x134), 0x30));
    StoreInArray0x8b0((struct StoreStruct *) g, 2, LdH(*(char **) ((char *) m + 0x130), 6));
    StoreInArray0x8b0((struct StoreStruct *) g, 3, LdH(*(char **) ((char *) m + 0x134), 0x32));
    StoreInArray0x8b0((struct StoreStruct *) g, 4, *(unsigned short *) (f + *(int *) (f + 0x950) * 2 + 0x16c));
    StoreInArray0x8b0((struct StoreStruct *) g, 5, LdH(*(char **) ((char *) m + 0x134), 0x34));
    StoreInArray0x8b0((struct StoreStruct *) g, 6, LdH(*(char **) ((char *) m + 0x134), 0x36));
    StoreInArray0x8b0((struct StoreStruct *) g, 7, (*(unsigned int *) f << 12) >> 22);
    int job          = *(int *) (f + 0x950);
    GameResources *v = func_ov017_0218b5b0();
    if (func_ov017_021bdbcc(v)) job = 0;
    char *s = (char *) _Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310 *) (base + 0x20),
                                                                      (short) (job + 0x834));
    int x2  = (0x40 - func_020420e8(s, 0)) >> 1;
    if (func_ov017_021bdbcc(v)) {
        _Z22SetIndexedName02046574P11Obj02046574iPc((struct Obj02046574 *) g, 1, s);
    } else if (*(int *) ((char *) m + 0x1c4) == 0) {
        _Z22SetIndexedName02046574P11Obj02046574iPc((struct Obj02046574 *) g, 1, s);
    }
    unsigned char lv = *(f + *(int *) (f + 0x950) + 0x186);
    if (lv != 0) {
        sprintf(num, data_ov002_0216d2a1, lv);
        __clear(tag, 0x20);
        int pal = 5;
        if (lv == 10) pal = 0xd;
        AppendPaletteTag(tag, pal);
        _Z20AppendString02042058PcPKc(tag, num);
        AppendPaletteTag(tag, 0xf);
        _Z22SetIndexedName02046574P11Obj02046574iPc((struct Obj02046574 *) g, 2, tag);
    }
    for (int i = 0; i < 8; i++) {
        int dg = 3;
        if (i == 4) dg = 2;
        SetByteInRange((unsigned char *) g, i, dg);
    }
    for (int i = 0; i < 8; i++) {
        SetByteAtIndex((unsigned char *) g, i, 1);
    }
    sprintf(text,
            (const char *) _Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310 *) (base + 0x20), 0x7d0),
            x1, x2);
    func_02046608(g, 0xa, text, dst, 0x100, 0, 0);
}
