#include "GameState/GameState.h"
#include <globaldefs.h>

struct StoreStruct;
struct Container020e0310;
struct Cur0215fcc0 {
    int hdr;
    unsigned short currHP;
    unsigned short currMP;
};
struct Xs0215fcc0 {
    int v[5];
};
int GetFieldByKey020e0434(struct Container020e0310 *c, int key);
int AppendYTag(char *dst, int y);
int AppendXTag(char *dst, int x);
int AppendWidthTag(char *dst, int w);
int AppendString02042058(char *dst, const char *src);
int AppendFormatted02041fac(char *buf, int a, int b);
const char *CallFunc020e0434With02153694(int key);
char *GetGlobalField0x1c020421a0();
void StoreInArray0x8b0(struct StoreStruct *base, int index, int value);
void SetByteInRange(unsigned char *messages, int index, unsigned char digits);
void SetByteAtIndex(unsigned char *messages, int index, unsigned char value);
extern "C" void func_02046380(void *g);
extern "C" int func_020420e8(const char *text, int large);
extern "C" int sprintf(char *dst, const char *fmt, ...);
extern "C" void *__clear(void *dst, int count);
extern "C" char data_ov002_0216d285[];
extern "C" char data_ov002_0216d2ae[];
extern "C" char data_ov002_0216d2b3[];
extern "C" struct Xs0215fcc0 data_ov002_0216ca30;

// USA: func_ov002_0215fcc0
extern "C" ARM void func_ov002_0215fcc0(char *base, char *dst) {
    char line[0x200];
    char tmp[0x100];
    char numA[0x10];
    char numB[0x10];
    GameObject *m;
    if (dst == NULL) return;
    GameState *gs = GameState::GetInstance();
    short k1      = 0x10fe;
    short k2      = 0x1112;
    m             = gs->GetPartyMemberByIndex(*(signed char *) (base + 0x1c00 + 0x20));
    if (m == NULL) return;
    const char *name = *(const char **) ((char *) m + 0x134);
    int w            = func_020420e8(name, 0);
    __clear(line, 0x200);
    char *f = *(char **) ((char *) m + 0x150);
    int val;
    int lv = *(unsigned char *) (f + *(int *) (f + 0x950) + 0x186);
    val    = *(unsigned short *) (f + *(int *) (f + 0x950) * 2 + 0x16c);
    if (lv != 0) {
        const char *title =
            (const char *) GetFieldByKey020e0434((struct Container020e0310 *) (base + 0x20), (short) (lv + 0x8fc));
        AppendYTag(line, 4);
        AppendString02042058(line, name);
        AppendWidthTag(line, 0x10);
        AppendString02042058(line, title);
        AppendWidthTag(line, 4);
        AppendString02042058(line, CallFunc020e0434With02153694(0x3f3));
        __clear(numA, 0x10);
        sprintf(numA, data_ov002_0216d285, val);
        AppendString02042058(line, numA);
    } else {
        AppendYTag(line, 4);
        AppendString02042058(line, name);
        AppendWidthTag(line, 0x12);
        AppendString02042058(line, CallFunc020e0434With02153694(0x3f3));
        __clear(numB, 0x10);
        sprintf(numB, data_ov002_0216d285, val);
        AppendString02042058(line, numB);
    }
    __clear(tmp, 0x100);
    sprintf(tmp, data_ov002_0216d2ae, CallFunc020e0434With02153694(0x3f3), val);
    int tw = w + 0x12 + func_020420e8(tmp, 0);
    if (lv != 0) tw += 9;
    int x                             = (0x80 - tw) >> 1;
    *(short *) (base + 0x2400 + 0x5c) = w + x + 1;
    AppendXTag(dst, x);
    AppendString02042058(dst, line);
    AppendFormatted02041fac(dst, (int) data_ov002_0216d2b3, 0x10);
    unsigned char *g = (unsigned char *) GetGlobalField0x1c020421a0();
    func_02046380(g);
    struct Xs0215fcc0 xs = data_ov002_0216ca30;
    int stats[7]         = {
        (*(struct Cur0215fcc0 **) ((char *) m + 0x130))->currHP,
        m->baseStats_->primaryStats.maxHP,
        (*(struct Cur0215fcc0 **) ((char *) m + 0x130))->currMP,
        m->baseStats_->primaryStats.maxMP,
        m->baseStats_->primaryStats.attack,
        m->baseStats_->primaryStats.defense,
        m->baseStats_->primaryStats.agility,
    };
    for (int i = 0; i < 7; i++) {
        SetByteAtIndex(g, i, 1);
        SetByteInRange(g, i, 3);
        StoreInArray0x8b0((struct StoreStruct *) g, i, stats[i]);
    }
    for (int i = 0; i < 5; i++) {
        AppendString02042058(dst, (const char *) GetFieldByKey020e0434((struct Container020e0310 *) (base + 0x20), k1++));
        AppendXTag(dst, xs.v[i]);
        AppendString02042058(dst, (const char *) GetFieldByKey020e0434((struct Container020e0310 *) (base + 0x20), k2++));
        if (i != 4) {
            AppendString02042058(dst, *(const char **) (base + 0x1000 + 0xbdc));
        }
    }
}
