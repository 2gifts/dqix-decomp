#include <globaldefs.h>
#if defined(jpn)
enum {
    kRegion800 = 0x77c
};
enum {
    kRegion89c = 0x818
};
enum {
    kRegion8a0 = 0x81c
};
enum {
    kRegion100c = 0xf88
};
enum {
    kRegion1018 = 0xf94
};
enum {
    kRegion1043 = 0xfbf
};
#else
enum {
    kRegion800 = 0x800
};
enum {
    kRegion89c = 0x89c
};
enum {
    kRegion8a0 = 0x8a0
};
enum {
    kRegion100c = 0x100c
};
enum {
    kRegion1018 = 0x1018
};
enum {
    kRegion1043 = 0x1043
};
#endif
#include "GameState/GameState.h"

extern "C" void *memset(void *dst, int value, unsigned int length);
extern "C" int func_ov003_02179e44(void *obj);
struct Obj2081;
void ClearElementFlag0x20_02080c20(struct Obj2081 *obj, int key);
void SetEntryLowNibbleAndElement02080c68(void *obj, int id, int value);
void SetSublistEntriesFlag1_02080b54(void *obj, int id);
void SetSublistEntriesFlag2_02080608(void *obj, int id);
unsigned char GetTableByte0207ca94(int index);
int CountPositiveEntries0207c638(void *base, unsigned int index);
int FindNthPositiveShort0207c6b8(unsigned char *obj, unsigned int index, int target);
int SetEntryFlagById02080b40(void *obj, int id);
int LookupValueByEntryKey02081010(void *obj, int key);
struct Container02080f8c;
void SetEntryFirstField02080f8c(struct Container02080f8c *obj, int id, int value);
struct Container02080cc0;
void SetEntryHighNibble0x13(struct Container02080cc0 *obj, int id, int value);
unsigned char *GetFieldAt0x150_02053c6c(unsigned char *obj);
struct Slots02083960;
int CountPositiveSlots02083960(struct Slots02083960 *slots);
extern "C" int func_020dcc98(int combatantId);
struct S_a0b8c;
int CountNonZeroValues020a0b8c(struct S_a0b8c *p);
struct Container02080fa8;
void SetEntryFirstField02080fa8(struct Container02080fa8 *obj, int id, int value);
struct Container020dedd0;
struct Element020de650 {
    char pad0[4];
    int value;
    char pad8[0x1a - 8];
    unsigned short count;
};
struct Element020de650 *FindElementByKey020dedd0(struct Container020dedd0 *c, int key);
void Forward0207f7acObjPlus4Size0x40_020805f4(void *obj, int value);
void ClearSublistEntryFlag2_020806c4(void *obj, int id);
extern "C" void func_ov003_0217818c(void *self, struct Element020de650 *elem, int id, int value);
void SetEntryHalfword0xe_0208103c(void *obj, int id, int value);
void DispatchEntryOp0x8_0208108c(void *obj, int id);
extern "C" void func_020813ec(void *obj, int key);

struct ListMenu_02177938 {
    unsigned char pad0[kRegion89c];
    struct Obj2081 *elemObj;
    unsigned char pad8a0[kRegion100c - kRegion8a0];
    short mode;
    short cursor;
    short field_0x1010;
    short tableCursor;
    short page;
    short pageCount;
    unsigned char pad1018[kRegion1043 - kRegion1018];
    signed char combatantId;
};

// USA: func_ov003_02177938
extern "C" ARM void func_ov003_02177938(ListMenu_02177938 *self) {
    func_ov003_02179e44(self);
    GameState *battle       = GameState::GetInstance();
    unsigned char *list     = (unsigned char *) GetPtrField0x2a04_02010828(battle);
    struct Obj2081 *elemObj = self->elemObj;
    int hasAny              = 1;
    short idA               = 0x8b;
    short idB               = 0x93;
    short idC               = 0x9b;
    short msg               = 0x3c;
    int showPages;
    short ids[8];

    ClearElementFlag0x20_02080c20(elemObj, 0x15);
    SetEntryLowNibbleAndElement02080c68(elemObj, 0x15, 0);
    SetSublistEntriesFlag1_02080b54(elemObj, 0x15);
    SetSublistEntriesFlag2_02080608(elemObj, 0x15);
    showPages = 0;
    memset(ids, 0xff, sizeof(ids));

    if (self->mode == 0x77) {
        short tableIndex   = self->tableCursor - 0x11e;
        unsigned int table = GetTableByte0207ca94(tableIndex);
        msg += tableIndex + 1;
        int count       = CountPositiveEntries0207c638(list + 0x1d4, table);
        self->pageCount = (count + 7) / 8;
        if (self->pageCount == 0) {
            self->pageCount = 1;
        }
        if (count > 8) {
            count = 8;
        }
        for (short i = 0; i < count; i++) {
            ids[i] = FindNthPositiveShort0207c6b8(list + 0x1d4, table, i);
        }
        SetEntryFlagById02080b40(elemObj, 0x8a);
        SetEntryFirstField02080f8c((struct Container02080f8c *) elemObj, 0x8a,
                                   LookupValueByEntryKey02081010(elemObj, self->tableCursor));
        SetEntryHighNibble0x13((struct Container02080cc0 *) elemObj, 0x8a, 0xf);
        showPages = 1;
        hasAny    = count != 0;
    } else {
        int inParty = 0;
        if (self->combatantId >= 0 && self->combatantId <= 3) {
            inParty = 1;
        }
        if (inParty) {
            GameObject *member = battle->GetPartyMemberByIndex(self->combatantId);
            if (member != NULL) {
                unsigned char *learned = GetFieldAt0x150_02053c6c((unsigned char *) member);
                int count              = CountPositiveSlots02083960((struct Slots02083960 *) learned);
                for (int i = 0; i < count; i++) {
                    ids[i] = ((short *) (learned + 0x454))[i];
                }
                SetEntryFlagById02080b40(elemObj, 0x8a);
                SetEntryFirstField02080f8c((struct Container02080f8c *) elemObj, 0x8a, *(int *) ((char *) member + 0x134));
                SetEntryHighNibble0x13((struct Container02080cc0 *) elemObj, 0x8a, func_020dcc98(self->combatantId));
                hasAny = count != 0;
            } else {
                SetSublistEntriesFlag1_02080b54(elemObj, 0x15);
            }
        } else {
            int count = CountNonZeroValues020a0b8c((struct S_a0b8c *) list);
            if (count > 8) {
                count = 8;
            }
            for (short i = 0; i < count; i++) {
                ids[i] = ((short *) (list + 0xc))[i];
            }
            SetEntryFlagById02080b40(elemObj, 0x8a);
            SetEntryFirstField02080f8c((struct Container02080f8c *) elemObj, 0x8a,
                                       LookupValueByEntryKey02081010(elemObj, 0x7a));
            SetEntryHighNibble0x13((struct Container02080cc0 *) elemObj, 0x8a, 0xf);
            showPages = 1;
            hasAny    = count != 0;
        }
    }

    if (showPages != 0) {
        SetEntryFirstField02080fa8((struct Container02080fa8 *) elemObj, 0xa3, self->page + 1);
        SetEntryFirstField02080fa8((struct Container02080fa8 *) elemObj, 0xa4, self->pageCount);
        SetEntryFlagById02080b40(elemObj, 0xa3);
        SetEntryFlagById02080b40(elemObj, 0xa4);
        SetEntryFlagById02080b40(elemObj, 0xa5);
    }

    for (unsigned char i = 0; i < 8; i++) {
        int value = 0;
        int count = 0;
        if (ids[i] > 0) {
            struct Element020de650 *elem = FindElementByKey020dedd0((struct Container020dedd0 *) ((unsigned char *) self + kRegion800 + 0x74), ids[i]);
            if (elem != NULL) {
                count = elem->count;
                value = elem->value;
            }
            Forward0207f7acObjPlus4Size0x40_020805f4(elemObj, idA);
            ClearSublistEntryFlag2_020806c4(elemObj, idA);
            SetEntryFirstField02080f8c((struct Container02080f8c *) elemObj, idA, value);
            SetEntryFirstField02080fa8((struct Container02080fa8 *) elemObj, idB, count);
            SetEntryFlagById02080b40(elemObj, idA);
            SetEntryFlagById02080b40(elemObj, idB);
            SetEntryFlagById02080b40(elemObj, idC);
            func_ov003_0217818c(self, elem, idB, idC);
        }
        idA = idA + 1;
        idB = idB + 1;
        idC = idC + 1;
    }

    if (hasAny == 0) {
        SetEntryHalfword0xe_0208103c(elemObj, 0x143, msg);
        SetEntryFlagById02080b40(elemObj, 0x143);
        SetEntryFlagById02080b40(elemObj, 0x144);
        DispatchEntryOp0x8_0208108c(elemObj, 0x143);
        DispatchEntryOp0x8_0208108c(elemObj, 0x144);
    }
    func_020813ec(elemObj, 0x15);
}
