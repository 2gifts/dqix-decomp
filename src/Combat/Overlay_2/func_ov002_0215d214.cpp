#include "GameState/GameState.h"
#include <globaldefs.h>

struct Container020dedd0;
struct Container020e0310;
struct StoreStruct;
struct Struct0200fb08;

struct Entry_0215d214 {
    int f0;
    unsigned int id : 12;
    unsigned int rest : 20;
};

struct Stats_0215d214 {
    unsigned int a0 : 10;
    unsigned int b0 : 10;
    unsigned int c0 : 10;
    unsigned int p0 : 2;
    unsigned int a4 : 10;
    unsigned int b4 : 10;
    unsigned int c4 : 10;
    unsigned int p4 : 2;
    unsigned int a8 : 10;
    unsigned int r8 : 22;
};

struct NameObj_0215d214 {
    int f0;
    int f4;
    unsigned int lo8 : 24;
    unsigned int kind : 2;
    unsigned int hi8 : 6;
};

void *GetFieldAt0x150(unsigned char *member);
extern "C" char *_Z24FindElementByKey020dedd0P17Container020dedd0i(struct Container020dedd0 *c, int key);
extern "C" char *_Z26GetGlobalField0x1c020421a0v();
extern "C" void func_02046380(void *messages);
extern "C" void _Z30InitObjFromCombatantId020e4bf4Pvi(void *obj, int combatantId);
extern "C" int func_ov002_02159774(void *self, int idx, int a, int b, int c);
extern "C" int _Z24NormalizeField5_0200fb08P14Struct0200fb08(Struct0200fb08 *s);
extern "C" char *_Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310 *c, int key);
extern "C" int sprintf(char *dst, const char *fmt, ...);
extern "C" char *strstr(const char *str, const char *substr);
extern "C" void *memcpy(void *dst, const void *src, unsigned int n);
void StoreInArray0x8b0(StoreStruct *messages, int index, int value);
extern "C" void func_02046608(void *messages, int a, const char *format, char *output, int size, int b, int c);

extern "C" unsigned char data_ov002_0216cac4[];
extern "C" unsigned char data_ov002_0216cac5[];
extern "C" char data_ov002_0216d280[];
extern "C" char data_ov002_0216d285[];

// USA: func_ov002_0215d214
extern "C" ARM void func_ov002_0215d214(char *self, char *dst, int unused) {
    char tmp[4];
    NameObj_0215d214 nameObj;
    char buf[0x200];
    if (dst == NULL) return;
    GameState *gs              = GameState::GetInstance();
    *(short *) (self + 0x1c26) = -1;
    unsigned char *ids         = (unsigned char *) (self + 0x68 + 0x1c00);
    short v                    = *(short *) (self + 0x1bfa);
    if (v >= 0 && v < 0x20) {
        *(short *) (self + 0x1c26) = (*(Entry_0215d214 **) (self + v * 4 + 0x24a0))->id;
    }
    if (*(short *) (self + 0x1c26) < 0) {
        if (*(unsigned char *) (self + 0x1c84) == 7) {
            ids = (unsigned char *) (self + 0x6e + 0x1c00);
        }
    }
    int cid = ids[*(short *) (self + 0x1bec)];
    char *c = (char *) GetCombatantWithFlag0x100(gs, cid);
    if (c == 0) return;
    Stats_0215d214 *pm = (Stats_0215d214 *) GetFieldAt0x150((unsigned char *) c);
    if (pm == 0) return;
    char *e = 0;
    if (*(short *) (self + 0x1c26) < 0) {
        e = _Z24FindElementByKey020dedd0P17Container020dedd0i((struct Container020dedd0 *) (self + 0x3ec + 0x400),
                                                              *(short *) (self + 0x1c22));
        if (e == 0) return;
    }
    char *msgs = _Z26GetGlobalField0x1c020421a0v();
    func_02046380(msgs);
    _Z30InitObjFromCombatantId020e4bf4Pvi(&nameObj, cid);
    *(void **) msgs = &nameObj;
    int key;
    char *s130 = *(char **) (c + 0x130);
    char *s134 = *(char **) (c + 0x134);
    int val    = *(unsigned short *) (s130 + 4);
    int max    = *(unsigned short *) (s134 + 0x30);
    key        = 0x4ba;
    int show   = 1;
    if (e != 0) {
        switch (*(short *) (e + 0x18)) {
            case 0x55ff:
            case 0x5600:
            case 0x5601: show = 0;
            case 0x561e:
                max = *(unsigned short *) (s134 + 0x32);
                val = *(unsigned short *) (s130 + 6);
                key = 0x4bb;
                break;
            case 0x561f:
                val = pm->a0;
                key = 0x1103;
                break;
            case 0x5622:
                val = pm->c0;
                key = 0x1104;
                break;
            case 0x5621:
                val = pm->b0;
                key = 0x1105;
                break;
            case 0x5619:
                val = pm->b4;
                key = 0x1106;
                break;
            case 0x5620:
                val = pm->a4;
                key = 0x1107;
                break;
            case 0x5623:
                val = pm->a8;
                key = 0x1108;
                break;
            case 0x5624:
                val = pm->c4;
                key = 0x1109;
                break;
            case 0x5625:
                val = *(unsigned short *) ((char *) pm + 0x564);
                key = 0x110a;
                break;
            case 0x561d: break;
            default: show = 0; break;
        }
    } else if (*(short *) (self + 0x1c26) >= 0) {
        show = 0;
    }
    int n    = func_ov002_02159774(self, cid, 1, 1, 1);
    int arg  = 0xf;
    int mark = 0;
    if (!show) {
        int which = -1;
        int st    = **(int **) (c + 0x130);
        if (st & 1) {
            which = 2;
            key   = 0x110d;
            arg   = 9;
        } else if (st & 2) {
            which = 0;
            key   = 0x110b;
            arg   = 0xc;
        } else if (st & 4) {
            key   = 0x110c;
            arg   = n;
            which = 1;
        }
        if (which >= 0) {
            int x = _Z24NormalizeField5_0200fb08P14Struct0200fb08((Struct0200fb08 *) GameState::GetInstance());
            for (int j = 0; j < 5; j++) {
                if (x == data_ov002_0216cac4[j * 7]) {
                    mark = (data_ov002_0216cac5 + j * 7 + nameObj.kind)[which * 2];
                    break;
                }
            }
        }
    }
    if (n == 3) {
        arg = 3;
    }
    sprintf(buf, _Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310 *) (self + 0x20), key), arg, n);
    if (mark != 0) {
        char *p = strstr(buf, data_ov002_0216d280);
        if (p != 0) {
            sprintf(tmp, data_ov002_0216d285, mark);
            memcpy(p + 4, tmp, 2);
        }
    }
    StoreInArray0x8b0((StoreStruct *) msgs, 0, val);
    StoreInArray0x8b0((StoreStruct *) msgs, 1, max);
    func_02046608(msgs, 10, buf, dst, 0x100, 0, 0);
}
