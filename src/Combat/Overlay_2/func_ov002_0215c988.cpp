#include "GameState/GameState.h"
#include <globaldefs.h>

struct UnkStruct0205c508;
struct StoreStruct;
struct Container020dedd0;
struct S_a0b8c;
struct KeyMap020a0b3c;
struct Struct_0205d81c;

int AppendFrameTag02041c08(char *dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag_02041ea4(char *dst, int cursor);
char *GetGlobalField0x1c020421a0();
void ComputeProductSums0205c508(struct UnkStruct0205c508 *s, int *out1, int *out2);
void *GetFieldAt0x150_02053c6c(unsigned char *member);
int GetCountByType02157108(void *self, int type);
extern "C" void func_02046380(void *messages);
void StoreInArray0x8b0_020465c0(StoreStruct *messages, int index, int value);
char *FindElementByKey020dedd0(struct Container020dedd0 *c, int key);
extern "C" void *__clear(void *destination, int count);
void CopyTextAndUppercaseIfFlagged0206819c(const char *src, char *dst, int flag);
int AppendNameTag_02041b70(char *dst, int n, const char *name);
int AppendString02042058(char *dst, const char *src);
void *GetPtrField0x2a04_02010828(GameState *gameState);
int CountNonZeroValues020a0b8c(struct S_a0b8c *s);
int LookupValueByKey020a0b3c(KeyMap020a0b3c *map, int key);
extern "C" int sprintf(char *dst, const char *fmt, ...);
void SetElementStateOrCreate0215b918(unsigned char *self, int a, int b, int c);
char *FindElementByC40205d81c(struct Struct_0205d81c *s, int key);

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
        AppendFrameTag02041c08(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag_02041ea4(dst, cursor);
    GameState *gs = GameState::GetInstance();
    char *msgs    = GetGlobalField0x1c020421a0();
    char *obj     = self + 0x2c8 + 0xc00;
    int page      = *(int *) (obj + 0x68);
    int pages     = *(int *) (obj + 0x58);
    ComputeProductSums0205c508((struct UnkStruct0205c508 *) (obj + 0x54), &first, &last);
    int id = *(signed char *) (self + 0x1c20);
    int ok = (id >= 0 && id <= 3) ? 1 : 0;
    if (ok) {
        page              = 0;
        pages             = 1;
        unsigned char *pm = (unsigned char *) GetFieldAt0x150_02053c6c((unsigned char *) GetCombatantWithFlag0x100_0200ff1c(gs, id));
        int n             = GetCountByType02157108(self, id);
        int k             = 0;
        for (int i = 0; i < n; i++) {
            func_02046380(msgs);
            StoreInArray0x8b0_020465c0((StoreStruct *) msgs, 0, k);
            char *e = FindElementByKey020dedd0((struct Container020dedd0 *) (self + 0x3ec + 0x400),
                                                                        *(short *) (pm + i * 2 + 0x454));
            if (e != 0) {
                __clear(nameBuf, 0x100);
                CopyTextAndUppercaseIfFlagged0206819c(*(char **) (e + 4), nameBuf, 0);
                AppendNameTag_02041b70(dst, k, nameBuf);
                if (i != n - 1) {
                    AppendString02042058(dst, *(char **) (self + 0x1bdc));
                }
            }
            k++;
        }
    } else if (id == 4) {
        unsigned char *party = (unsigned char *) GetPtrField0x2a04_02010828(gs);
        int cnt              = CountNonZeroValues020a0b8c((struct S_a0b8c *) party);
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
            StoreInArray0x8b0_020465c0((StoreStruct *) msgs, 0, k);
            char *e = FindElementByKey020dedd0((struct Container020dedd0 *) (self + 0x3ec + 0x400),
                                                                        *(short *) (party + i * 2 + 0xc));
            if (e != 0) {
                __clear(nameBuf2, 0x100);
                CopyTextAndUppercaseIfFlagged0206819c(*(char **) (e + 4), nameBuf2, 0);
                AppendNameTag_02041b70(dst, k, nameBuf2);
                __clear(numBuf, 0x40);
                sprintf(numBuf, data_ov002_0216d270,
                        LookupValueByKey020a0b3c((KeyMap020a0b3c *) party, *(short *) (e + 0x18)));
                AppendString02042058(dst, numBuf);
                if (i != last - 1) {
                    AppendString02042058(dst, *(char **) (self + 0x1bdc));
                }
            }
            k++;
        }
    }
    int on = 0;
    if (pages > 1) {
        SetElementStateOrCreate0215b918((unsigned char *) self, 5, page, pages);
        on = 1;
    } else {
        SetElementStateOrCreate0215b918((unsigned char *) self, 5, on, on);
    }
    unsigned char *el =
        (unsigned char *) FindElementByC40205d81c((struct Struct_0205d81c *) (self + 0x2c8 + 0xc00), 5);
    if (el != 0) {
        if (on) {
            el[0xc5] |= 8;
        } else {
            el[0xc5] &= ~8;
        }
    }
}
