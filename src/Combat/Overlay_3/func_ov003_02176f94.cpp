#include <globaldefs.h>
#if defined(jpn)
enum {
    kRegion89c = 0x818
};
enum {
    kNodeOffset = 0x7f0
};
enum {
    kRegion101c = 0xf98
};
enum {
    kRegion1030 = 0xfac
};
enum {
    kRegion103a = 0xfb6
};
#else
enum {
    kRegion89c = 0x89c
};
enum {
    kNodeOffset = 0x874
};
enum {
    kRegion101c = 0x101c
};
enum {
    kRegion1030 = 0x1030
};
enum {
    kRegion103a = 0x103a
};
#endif

#include "GameState/GameState.h"

struct Obj2081;
void ClearElementFlag0x20(struct Obj2081 *obj, int key);
extern "C" void _Z35SetEntryLowNibbleAndElement02080c68Pvii(void *obj, int id, int value);
void ClearSublistEntriesFlag1(void *obj, int id);
struct Container020dedd0;
struct Node02176f94;
extern "C" struct Node02176f94 *_Z24FindElementByKey020dedd0P17Container020dedd0i(struct Container020dedd0 *c, int key);
void *GetFieldAt0x150(unsigned char *obj);
struct Slots02083994;
extern "C" int _Z34CountMatchingUntilNegative02083994P13Slots02083994i(struct Slots02083994 *s, int value);
struct Container02080f8c;
extern "C" void _Z26SetEntryFirstField02080f8cP17Container02080f8cii(struct Container02080f8c *obj, int id, int value);
extern "C" int func_020dcc98(int combatantId);
struct Container02080cc0;
void SetEntryHighNibble0x13(struct Container02080cc0 *obj, int id, int value);
struct Container02080fa8;
extern "C" void _Z26SetEntryFirstField02080fa8P17Container02080fa8ii(struct Container02080fa8 *obj, int id, int value);
extern "C" int _Z24SetEntryFlagById02080b2cPvi(void *obj, int id);
void SetSublistEntriesFlag1(void *obj, int id);
void SetElementFlag0x20(struct Obj2081 *obj, int key);
extern "C" short _Z23SumKeyedLookups02086bf4Pci(char *obj, int key);
extern "C" void func_020813ec(void *obj, int key);
void *GetPtrField0x2a04(GameState *battleStruct);

struct Node02176f94 {
    char pad0[8];
    unsigned int type : 4;
    unsigned int pad8 : 28;
};

struct Menu02176f94 {
    char pad0[kRegion101c];
    int ids[4];
};

static inline int IsType02176f94(unsigned int type) {
    return type <= 7;
}

// USA: func_ov003_02176f94
extern "C" ARM void func_ov003_02176f94(char *self) {
    struct Obj2081 *elem = *(struct Obj2081 **) (self + kRegion89c);
    GameState *battle    = GameState::GetInstance();
    char *bag            = (char *) GetPtrField0x2a04(battle);

    int listId    = 0x19;
    short idHp    = 0xe9;
    short idCount = 0xeb;
    short idFlagB = 0xed;
    short idFlagA = 0xef;
    switch (*(int *) (self + kRegion1030)) {
        case 2:
            listId  = 0x1a;
            idHp    = 0xf0;
            idCount = 0xf3;
            idFlagB = 0xf6;
            idFlagA = 0xf9;
            break;
        case 3:
            idCount = 0xff;
            idFlagB = 0x103;
            idFlagA = 0x107;
            listId  = 0x1b;
            idHp    = 0xfb;
            break;
        case 4:
            listId  = 0x1c;
            idHp    = 0x10a;
            idCount = 0x10f;
            idFlagB = 0x114;
            idFlagA = 0x119;
            break;
    }

    ClearElementFlag0x20(elem, listId);
    _Z35SetEntryLowNibbleAndElement02080c68Pvii(elem, listId, 0);
    ClearSublistEntriesFlag1(elem, listId);

    bool skip                 = true;
    struct Node02176f94 *node = _Z24FindElementByKey020dedd0P17Container020dedd0i(
        (struct Container020dedd0 *) (self + kNodeOffset), *(short *) (self + kRegion103a));
    if (node != NULL) skip = IsType02176f94(node->type);
    if (!skip) {
        for (unsigned char i = 0; i < *(int *) (self + kRegion1030); i++) {
            int hp;
            short count;
            int cid;
            cid                = (signed char) ((struct Menu02176f94 *) self)->ids[i];
            hp                 = 0;
            count              = 0;
            GameObject *member = battle->GetPartyMemberByIndex(cid);
            if (member != NULL) {
                hp    = *(int *) ((char *) member + 0x134);
                count = _Z34CountMatchingUntilNegative02083994P13Slots02083994i(
                    (struct Slots02083994 *) GetFieldAt0x150((unsigned char *) member), *(short *) (self + kRegion103a));
            }
            _Z26SetEntryFirstField02080f8cP17Container02080f8cii((struct Container02080f8c *) elem, idHp, hp);
            SetEntryHighNibble0x13((struct Container02080cc0 *) elem, idHp, func_020dcc98(cid));
            _Z26SetEntryFirstField02080fa8P17Container02080fa8ii((struct Container02080fa8 *) elem, idCount, count);
            if (count != 0) {
                _Z24SetEntryFlagById02080b2cPvi(elem, idFlagA);
            } else {
                _Z24SetEntryFlagById02080b2cPvi(elem, idCount);
                _Z24SetEntryFlagById02080b2cPvi(elem, idFlagB);
            }
            idHp++;
            idCount++;
            idFlagB = idFlagB + 1;
            idFlagA = idFlagA + 1;
        }
    } else {
        SetSublistEntriesFlag1(elem, listId);
        SetElementFlag0x20(elem, listId);
    }
    _Z26SetEntryFirstField02080fa8P17Container02080fa8ii((struct Container02080fa8 *) elem, idCount,
                                                         _Z23SumKeyedLookups02086bf4Pci(bag, *(short *) (self + kRegion103a)));
    func_020813ec(elem, listId);
}
