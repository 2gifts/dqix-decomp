#include "GameState/GameState.h"
#include <globaldefs.h>

struct ArrayContainsByteStruct;
struct Container020dedd0;
struct KeyMap020a0b3c;
struct S_a0b8c;
struct StoreStruct;
extern "C" int _Z22AppendFrameTag02041c08Pciiiii(char *dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char *dst, int cursor);
extern "C" char *_Z26GetGlobalField0x1c020421a0v();
unsigned char *GetFieldAt0x150(unsigned char *p);
int ArrayContainsByte(ArrayContainsByteStruct *arr, int value);
extern "C" int _Z22GetCountByType02157108Pvi(void *self, int type);
void StoreInArray0x8b0(struct StoreStruct *base, int index, int value);
extern "C" char *_Z24FindElementByKey020dedd0P17Container020dedd0i(struct Container020dedd0 *c, int key);
extern "C" void _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(const char *src, char *dst, int flag);
int AppendNameTag(char *dst, int n, const char *name);
extern "C" int _Z20AppendString02042058PcPKc(char *dst, const char *src);
extern "C" int _Z26CountNonZeroValues020a0b8cP7S_a0b8c(struct S_a0b8c *s);
extern "C" int _Z24LookupValueByKey020a0b3cP14KeyMap020a0b3ci(KeyMap020a0b3c *map, int key);
extern "C" void _Z31SetElementStateOrCreate0215b918Phiii(unsigned char *self, int a, int b, int c);
extern "C" void func_02046380(void *g);
extern "C" int sprintf(char *dst, const char *fmt, ...);
extern "C" void *__clear(void *dst, int count);
extern "C" char data_ov002_0216d288[];
extern "C" char data_ov002_0216d270[];

struct F0215de9c {
    char pad[0x58];
    int pages;
    char pad2[0xc];
    int page;
};

// USA: func_ov002_0215de9c
extern "C" ARM void func_ov002_0215de9c(char *base, char *dst, int flag) {
    char nameA[0x100];
    char nameB[0x100];
    char num[0x40];
    if (dst == NULL) return;
    int cur = *(short *) (base + 0x1b00 + 0xf4) & 7;
    if (*(int *) (base + 0x1000 + 0xbb8) == 0xd) {
        if (flag) {
            _Z22AppendFrameTag02041c08Pciiiii(dst, cur, 8, 5, 5, 5);
        }
        AppendCursorTag(dst, cur);
    }
    GameState *gs = GameState::GetInstance();
    char *g       = _Z26GetGlobalField0x1c020421a0v();
    char *party   = (char *) GetPtrField0x2a04(gs);
    int actor     = *(signed char *) (base + 0x1c00 + 0x21);
    int ok        = 0;
    unsigned char *f;
    struct F0215de9c *fld = (struct F0215de9c *) (base + 0x2c8 + 0xc00) + 1;
    fld--;
    int page  = fld->page;
    int pages = fld->pages;
    if (actor >= 0 && actor <= 3) {
        ok = 1;
    }
    if (ok) {
        GameObject *m = GetCombatantWithFlag0x100(gs, actor);
        if (m == NULL) return;
        f = GetFieldAt0x150((unsigned char *) m);
        if (!ArrayContainsByte((ArrayContainsByteStruct *) party, *(signed char *) (base + 0x1c00 + 0x21))) return;
        int n     = _Z22GetCountByType02157108Pvi(base, *(signed char *) (base + 0x1c00 + 0x21));
        int extra = 0;
        if (n < 8) extra = 1;
        for (int i = 0; i < n + extra; i++) {
            func_02046380(g);
            StoreInArray0x8b0((struct StoreStruct *) g, 0, i);
            char *e = _Z24FindElementByKey020dedd0P17Container020dedd0i((struct Container020dedd0 *) (base + 0x3ec + 0x400),
                                                                        *(short *) (f + i * 2 + 0x454));
            if (e != NULL) {
                __clear(nameA, 0x100);
                _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(*(const char **) (e + 4), nameA, 0);
                AppendNameTag(dst, i, nameA);
                if (i != n - 1) {
                    _Z20AppendString02042058PcPKc(dst, *(const char **) (base + 0x1000 + 0xbdc));
                } else if (extra == 1) {
                    _Z20AppendString02042058PcPKc(dst, *(const char **) (base + 0x1000 + 0xbdc));
                }
            } else if (i == n) {
                AppendNameTag(dst, i, data_ov002_0216d288);
            }
        }
    } else {
        int end;
        int i = page * 8;
        end   = i + 8;
        int c = _Z22GetCountByType02157108Pvi(base, actor);
        if (end > c) end = c;
        pages = (_Z26CountNonZeroValues020a0b8cP7S_a0b8c((struct S_a0b8c *) party) + 7) / 8;
        for (; i < end; i++) {
            func_02046380(g);
            StoreInArray0x8b0((struct StoreStruct *) g, 0, i);
            char *e = _Z24FindElementByKey020dedd0P17Container020dedd0i((struct Container020dedd0 *) (base + 0x3ec + 0x400),
                                                                        *(short *) (party + i * 2 + 0xc));
            if (e == NULL) continue;
            __clear(nameB, 0x100);
            _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(*(const char **) (e + 4), nameB, 0);
            AppendNameTag(dst, i, nameB);
            __clear(num, 0x40);
            sprintf(num, data_ov002_0216d270,
                    _Z24LookupValueByKey020a0b3cP14KeyMap020a0b3ci((KeyMap020a0b3c *) party, *(short *) (e + 0x18)));
            _Z20AppendString02042058PcPKc(dst, num);
            if (i != end - 1) {
                _Z20AppendString02042058PcPKc(dst, *(const char **) (base + 0x1000 + 0xbdc));
            }
        }
    }
    if (pages > 1) {
        _Z31SetElementStateOrCreate0215b918Phiii((unsigned char *) base, 0xd, page, pages);
    } else {
        _Z31SetElementStateOrCreate0215b918Phiii((unsigned char *) base, 0xd, 0, 0);
    }
}
