#include "GameState/GameState.h"
#include "std_library_functions.h"
#include <globaldefs.h>

struct S_a0b8c;
struct S020a0bcc;
struct S_a0af4;
struct KeyMap020a095c;
struct ObjStruct_021e1474;
struct Container020dedd0;
struct Struct_0205d81c;
extern "C" int _Z26CountNonZeroValues020a0b8cP7S_a0b8c(struct S_a0b8c *s);
extern "C" void _Z19ClearArrays020a0bccP9S020a0bcc(struct S020a0bcc *s);
extern "C" int _Z20FindKeyIndex020a0af4P7S_a0af4i(struct S_a0af4 *s, int key);
extern "C" void _Z26AddKeyValueClamped020a095cP14KeyMap020a095cii(struct KeyMap020a095c *m, int key, int val);
extern "C" void _Z22ClearElements_021e1518Pv(void *p);
extern "C" void _Z32RefreshEntryStatusFlags_021e1474P18ObjStruct_021e1474P17Container020dedd0(struct ObjStruct_021e1474 *obj,
                                                                                              struct Container020dedd0 *c);
extern "C" void _Z19BuildChain_021e1870PvS_iii(void *a, void *b, int c, int d, int e);
extern "C" void _Z19BuildChain_021e1814PvS_iii(void *a, void *b, int c, int d, int e);
struct Elem0215b458 {
    char pad[0xc5];
    unsigned char flags;
};
extern "C" struct Elem0215b458 *_Z23FindElementByC40205d81cP15Struct_0205d81ci(struct Struct_0205d81c *s, int key);
extern "C" int GetInventoryItemByID(char *self, int idx, int member);
extern "C" void func_0205d7a0(void *p, int idx);
extern "C" void func_ov002_0215b9a4(void *base, int a, int b);

struct Item0215b458 {
    char pad[0x18];
    short key;
};
struct Node0215b458 {
    struct Node0215b458 *next;
    struct Item0215b458 *item;
};
struct Party0215b458 {
    short *keys;
    signed char *vals;
};

// USA: func_ov002_0215b458
extern "C" ARM void func_ov002_0215b458(char *base, int flag) {
    GameState *gs;
    char *sub;
    int sel;
    short *keys;
    struct Party0215b458 *party;
    int count;
    signed char *vals;
    struct Node0215b458 *node;
    gs    = GameState::GetInstance();
    party = (struct Party0215b458 *) GetPtrField0x2a04(gs);
    sel   = GetInventoryItemByID(base, *(short *) (base + 0x1b00 + 0xe8), *(signed char *) (base + 0x1c00 + 0x20));
    keys  = party->keys;
    vals  = party->vals;
    count = _Z26CountNonZeroValues020a0b8cP7S_a0b8c((struct S_a0b8c *) party);
    if (count == 0) return;

    sub = base + 4;
    _Z22ClearElements_021e1518Pv(sub + 0x800);
    _Z32RefreshEntryStatusFlags_021e1474P18ObjStruct_021e1474P17Container020dedd0(
        (struct ObjStruct_021e1474 *) (sub + 0x800), (struct Container020dedd0 *) (base + 0x3ec + 0x400));
    if (*(unsigned char *) (base + 0x2000 + 0x48d) == 2) {
        _Z19BuildChain_021e1870PvS_iii(sub + 0x800, (void *) 1, -1, -1, 0);
        *(unsigned char *) (base + 0x2000 + 0x48d) = 1;
    } else {
        _Z19BuildChain_021e1814PvS_iii(sub + 0x800, (void *) 1, -1, -1, 0);
        *(unsigned char *) (base + 0x2000 + 0x48d) = 2;
    }
    memset(*(void **) (base + 0x2000 + 0x534), 0, 0x140);
    memset(*(void **) (base + 0x2000 + 0x538), 0, 0xa0);
    memcpy(*(void **) (base + 0x2000 + 0x534), keys, count * 2);
    memcpy(*(void **) (base + 0x2000 + 0x538), vals, count);
    _Z19ClearArrays020a0bccP9S020a0bcc((struct S020a0bcc *) party);

    for (node = *(struct Node0215b458 **) (sub + 0x800); node != NULL; node = node->next) {
        struct Item0215b458 *item = node->item;
        if (item == NULL) continue;
        short key = item->key;
        for (short j = 0; j < count; j++) {
            if (key == (*(short **) (base + 0x2000 + 0x534))[j]) {
                _Z26AddKeyValueClamped020a095cP14KeyMap020a095cii((struct KeyMap020a095c *) party, key,
                                                                  (*(signed char **) (base + 0x2000 + 0x538))[j]);
                break;
            }
        }
    }

    if (sel >= 0 && flag) {
        int idx = _Z20FindKeyIndex020a0af4P7S_a0af4i((struct S_a0af4 *) party, sel);
        if (idx >= 0) {
            *(short *) (base + 0x1b00 + 0xe8) = idx;
            func_0205d7a0(base + 0x2c8 + 0xc00, idx);
            struct Elem0215b458 *e =
                _Z23FindElementByC40205d81cP15Struct_0205d81ci((struct Struct_0205d81c *) (base + 0x2c8 + 0xc00), 5);
            if (e != NULL) {
                e->flags &= ~2;
            }
        }
    }
    func_ov002_0215b9a4(base, 5, 0);
}
