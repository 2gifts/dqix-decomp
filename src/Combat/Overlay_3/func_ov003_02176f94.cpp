// USA: func_ov003_02176f94
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
void ClearElementFlag0x20_02080c20(struct Obj2081 *obj, int key);
void SetEntryLowNibbleAndElement02080c68(void *obj, int id, int value);
void ClearSublistEntriesFlag1_02080bac(void *obj, int id);
struct Container020dedd0;
struct Node02176f94;
struct Node02176f94 *FindElementByKey020dedd0(struct Container020dedd0 *c, int key);
void *GetFieldAt0x150_02053c6c(unsigned char *obj);
struct Slots02083994;
int CountMatchingUntilNegative02083994(struct Slots02083994 *s, int value);
struct Container02080f8c;
void SetEntryFirstField02080f8c(struct Container02080f8c *obj, int id, int value);
extern "C" int func_020dcc98(int combatantId);
struct Container02080cc0;
void SetEntryHighNibble0x13(struct Container02080cc0 *obj, int id, int value);
struct Container02080fa8;
void SetEntryFirstField02080fa8(struct Container02080fa8 *obj, int id, int value);
int SetEntryFlagById02080b2c(void *obj, int id);
void SetSublistEntriesFlag1_02080b54(void *obj, int id);
void SetElementFlag0x20_02080c04(struct Obj2081 *obj, int key);
short SumKeyedLookups02086bf4(char *obj, int key);
extern "C" void func_020813ec(void *obj, int key);
void *GetPtrField0x2a04_02010828(GameState *battleStruct);

struct Node02176f94 {
    char pad0[8];
    unsigned int type : 4;
    unsigned int pad8 : 28;
};

struct Menu02176f94 {
    unsigned char unknown[kRegion89c];
    Obj2081* menu;
    unsigned char unknownBeforeMembers[kRegion101c - kRegion89c - 4];
    int memberIds[4];
    unsigned char unknownBeforeCount[kRegion1030 - kRegion101c - 16];
    int memberCount;
    unsigned char unknownBeforeItem[kRegion103a - kRegion1030 - 4];
    short selectedItem;
};

static inline int ShouldHideMemberCounts(unsigned int itemType) {
    return itemType <= 7;
}

extern "C" ARM void func_ov003_02176f94(Menu02176f94* self) {
    struct Obj2081 *elem = self->menu;
    GameState *battle    = GameState::GetInstance();
    char *bag            = (char *) GetPtrField0x2a04_02010828(battle);

    int listId    = 0x19;
    short idMember    = 0xe9;
    short idCount = 0xeb;
    short idFlagB = 0xed;
    short idFlagA = 0xef;
    switch (self->memberCount) {
        case 2:
            listId  = 0x1a;
            idMember    = 0xf0;
            idCount = 0xf3;
            idFlagB = 0xf6;
            idFlagA = 0xf9;
            break;
        case 3:
            idCount = 0xff;
            idFlagB = 0x103;
            idFlagA = 0x107;
            listId  = 0x1b;
            idMember    = 0xfb;
            break;
        case 4:
            listId  = 0x1c;
            idMember    = 0x10a;
            idCount = 0x10f;
            idFlagB = 0x114;
            idFlagA = 0x119;
            break;
    }

    ClearElementFlag0x20_02080c20(elem, listId);
    SetEntryLowNibbleAndElement02080c68(elem, listId, 0);
    ClearSublistEntriesFlag1_02080bac(elem, listId);

    bool skip                 = true;
    struct Node02176f94 *node = FindElementByKey020dedd0(
        (struct Container020dedd0 *) ((char*)self + kNodeOffset), self->selectedItem);
    if (node != NULL) skip = ShouldHideMemberCounts(node->type);
    if (!skip) {
        for (unsigned char i = 0; i < self->memberCount; i++) {
            int memberData;
            short count;
            int cid;
            cid                = (signed char) self->memberIds[i];
            memberData         = 0;
            count              = 0;
            GameObject *member = battle->GetPartyMemberByIndex(cid);
            if (member != NULL) {
                memberData = (int)member->baseStats_;
                count = CountMatchingUntilNegative02083994(
                    (struct Slots02083994 *) GetFieldAt0x150_02053c6c((unsigned char *) member), self->selectedItem);
            }
            SetEntryFirstField02080f8c((struct Container02080f8c *) elem, idMember, memberData);
            SetEntryHighNibble0x13((struct Container02080cc0 *) elem, idMember, func_020dcc98(cid));
            SetEntryFirstField02080fa8((struct Container02080fa8 *) elem, idCount, count);
            if (count != 0) {
                SetEntryFlagById02080b2c(elem, idFlagA);
            } else {
                SetEntryFlagById02080b2c(elem, idCount);
                SetEntryFlagById02080b2c(elem, idFlagB);
            }
            idMember++;
            idCount++;
            idFlagB = idFlagB + 1;
            idFlagA = idFlagA + 1;
        }
    } else {
        SetSublistEntriesFlag1_02080b54(elem, listId);
        SetElementFlag0x20_02080c04(elem, listId);
    }
    SetEntryFirstField02080fa8((struct Container02080fa8 *) elem, idCount,
                                                         SumKeyedLookups02086bf4(bag, self->selectedItem));
    func_020813ec(elem, listId);
}
