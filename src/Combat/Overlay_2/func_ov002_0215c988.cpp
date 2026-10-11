#include "GameState/GameState.h"
#include <globaldefs.h>

struct UnkStruct0205c508;
struct StoreStruct;
struct Container020dedd0;
struct S_a0b8c;
struct KeyMap020a0b3c;
struct Struct_0205d81c;

extern "C" int _Z22AppendFrameTag02041c08Pciiiii(char *dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char *dst, int cursor);
extern "C" char *_Z26GetGlobalField0x1c020421a0v();
extern "C" void _Z26ComputeProductSums0205c508P17UnkStruct0205c508PiS1_(struct UnkStruct0205c508 *s, int *out1, int *out2);
void *GetFieldAt0x150(unsigned char *member);
extern "C" int _Z22GetCountByType02157108Pvi(void *self, int type);
extern "C" void func_02046380(void *messages);
void StoreInArray0x8b0(StoreStruct *messages, int index, int value);
extern "C" char *_Z24FindElementByKey020dedd0P17Container020dedd0i(struct Container020dedd0 *c, int key);
extern "C" void *__clear(void *destination, int count);
extern "C" void _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(const char *src, char *dst, int flag);
int AppendNameTag(char *dst, int n, const char *name);
extern "C" int _Z20AppendString02042058PcPKc(char *dst, const char *src);
void *GetPtrField0x2a04(GameState *gameState);
extern "C" int _Z26CountNonZeroValues020a0b8cP7S_a0b8c(struct S_a0b8c *s);
extern "C" int _Z24LookupValueByKey020a0b3cP14KeyMap020a0b3ci(KeyMap020a0b3c *map, int key);
extern "C" int sprintf(char *dst, const char *fmt, ...);
extern "C" void _Z31SetElementStateOrCreate0215b918Phiii(unsigned char *self, int a, int b, int c);
extern "C" char *_Z23FindElementByC40205d81cP15Struct_0205d81ci(struct Struct_0205d81c *s, int key);

extern "C" char data_ov002_0216d270[];

// USA: func_ov002_0215c988
extern "C" ARM void func_ov002_0215c988(char *self, char *dst, int flag) {
    char nameBuf[0x100];
    char nameBuf2[0x100];
    char numBuf[0x40];
    int first;
    int last;
    if (dst == NULL) return;
    int cursor = *(short *) (self + 0x1be8) & 7;
    if (flag) {
        _Z22AppendFrameTag02041c08Pciiiii(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag(dst, cursor);
    GameState *gs = GameState::GetInstance();
    char *msgs    = _Z26GetGlobalField0x1c020421a0v();
    char *obj     = self + 0x2c8 + 0xc00;
    int page      = *(int *) (obj + 0x68);
    int pages     = *(int *) (obj + 0x58);
    _Z26ComputeProductSums0205c508P17UnkStruct0205c508PiS1_((struct UnkStruct0205c508 *) (obj + 0x54), &first, &last);
    int id = *(signed char *) (self + 0x1c20);
    int ok = (id >= 0 && id <= 3) ? 1 : 0;
    if (ok) {
        page              = 0;
        pages             = 1;
        unsigned char *pm = (unsigned char *) GetFieldAt0x150((unsigned char *) GetCombatantWithFlag0x100(gs, id));
        int n             = _Z22GetCountByType02157108Pvi(self, id);
        int k             = 0;
        for (int i = 0; i < n; i++) {
            func_02046380(msgs);
            StoreInArray0x8b0((StoreStruct *) msgs, 0, k);
            char *e = _Z24FindElementByKey020dedd0P17Container020dedd0i((struct Container020dedd0 *) (self + 0x3ec + 0x400),
                                                                        *(short *) (pm + i * 2 + 0x454));
            if (e != 0) {
                __clear(nameBuf, 0x100);
                _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(*(char **) (e + 4), nameBuf, 0);
                AppendNameTag(dst, k, nameBuf);
                if (i != n - 1) {
                    _Z20AppendString02042058PcPKc(dst, *(char **) (self + 0x1bdc));
                }
            }
            k++;
        }
    } else if (id == 4) {
        unsigned char *party = (unsigned char *) GetPtrField0x2a04(gs);
        int cnt              = _Z26CountNonZeroValues020a0b8cP7S_a0b8c((struct S_a0b8c *) party);
        if (*(int *) (self + 0x1bb8) == 4) {
            first = 0;
            last  = 8;
            if (cnt < 8) {
                last = cnt;
            }
            pages = (cnt + 7) / 8;
            page  = 0;
        }
        if (pages == 0) {
            pages = 1;
        }
        int k = 0;
        for (int i = first; i < last; i++) {
            func_02046380(msgs);
            StoreInArray0x8b0((StoreStruct *) msgs, 0, k);
            char *e = _Z24FindElementByKey020dedd0P17Container020dedd0i((struct Container020dedd0 *) (self + 0x3ec + 0x400),
                                                                        *(short *) (party + i * 2 + 0xc));
            if (e != 0) {
                __clear(nameBuf2, 0x100);
                _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(*(char **) (e + 4), nameBuf2, 0);
                AppendNameTag(dst, k, nameBuf2);
                __clear(numBuf, 0x40);
                sprintf(numBuf, data_ov002_0216d270,
                        _Z24LookupValueByKey020a0b3cP14KeyMap020a0b3ci((KeyMap020a0b3c *) party, *(short *) (e + 0x18)));
                _Z20AppendString02042058PcPKc(dst, numBuf);
                if (i != last - 1) {
                    _Z20AppendString02042058PcPKc(dst, *(char **) (self + 0x1bdc));
                }
            }
            k++;
        }
    }
    int on = 0;
    if (pages > 1) {
        _Z31SetElementStateOrCreate0215b918Phiii((unsigned char *) self, 5, page, pages);
        on = 1;
    } else {
        _Z31SetElementStateOrCreate0215b918Phiii((unsigned char *) self, 5, on, on);
    }
    unsigned char *el =
        (unsigned char *) _Z23FindElementByC40205d81cP15Struct_0205d81ci((struct Struct_0205d81c *) (self + 0x2c8 + 0xc00), 5);
    if (el != 0) {
        if (on) {
            el[0xc5] |= 8;
        } else {
            el[0xc5] &= ~8;
        }
    }
}
