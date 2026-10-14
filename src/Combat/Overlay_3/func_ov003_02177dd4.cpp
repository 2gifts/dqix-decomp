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
#endif
#include "GameState/GameState.h"

unsigned char GetTableByte0207ca94(int index);
int ComputePositiveCount_02175f90(void *obj);
struct S_a0b8c;
int CountNonZeroValues020a0b8c(struct S_a0b8c *p);
struct Obj2081;
void ClearElementFlag0x20_02080c20(struct Obj2081 *obj, int key);
void SetEntryLowNibbleAndElement02080c68(void *obj, int id, int value);
void ClearSublistEntriesFlag1_02080bac(void *obj, int id);
void ClearSublistEntriesFlag2_0208065c(void *obj, int id);
void SetOrClearEntryFlag0x102081130(void *obj, int id, int set);
void AddSublistEntryFlag2_020806b0(void *obj, int id);
int SetEntryFlagById02080b2c(void *obj, int id);
short FindNthPositiveShort0207c6b8(unsigned char *obj, unsigned int index, int target);
struct Container020dedd0 {
    unsigned char data[kRegion89c - kRegion800 - 0x74];
};
struct Element020de650 {
    char pad0[4];
    int value;
    char pad8[0x1a - 8];
    unsigned short count;
};
struct Element020de650 *FindElementByKey020dedd0(struct Container020dedd0 *c, int key);
int GetNthPositiveEntryValue_0207c72c(void *obj, unsigned int index, short n);
extern "C" void func_ov003_0217818c(void *self, struct Element020de650 *elem, int id, int value);
void Forward0207f7acObjPlus4Size0x40_020805f4(void *obj, int value);
struct Container02080f8c;
void SetEntryFirstField02080f8c(struct Container02080f8c *obj, int id, int value);
struct Container02080fa8;
void SetEntryFirstField02080fa8(struct Container02080fa8 *obj, int id, int value);
int LookupValueByEntryKey02081010(void *obj, int key);
extern "C" void func_020813ec(void *obj, int key);

struct ListMenu_02177dd4 {
    unsigned char pad0[kRegion800 + 0x74];
    struct Container020dedd0 container;
    struct Obj2081 *elemObj;
    unsigned char pad8a0[kRegion100c - kRegion8a0];
    short mode;
    short cursor;
    short field_0x1010;
    short tableCursor;
    short page;
    short pageCount;
};

// USA: func_ov003_02177dd4
extern "C" ARM void func_ov003_02177dd4(ListMenu_02177dd4 *self) {
    unsigned char *list = (unsigned char *) GetPtrField0x2a04_02010828(GameState::GetInstance());
    unsigned int table  = 0;
    short hdr;
    short idD;
    short pageId;
    short pageCountId;
    short key;
    int count;
    short *keys             = 0;
    signed char *vals       = 0;
    struct Obj2081 *elemObj = self->elemObj;
    int group               = 0x16;
    hdr                     = 0xa6;
    short idA               = 0xa7;
    short idB               = 0xaf;
    short idC               = 0xb7;
    idD                     = 0xbf;
    short idE               = 0xc7;
    pageId                  = 0xcf;
    pageCountId             = 0xd0;
    short perPage           = 8;

    if (self->mode == 0x77) {
        short tableIndex = self->tableCursor - 0x11e;
        table            = GetTableByte0207ca94(tableIndex);
        count            = ComputePositiveCount_02175f90(self);
        self->pageCount  = (count + 4) / 5;
        if (self->pageCount == 0) {
            self->pageCount = 1;
        }
        idA         = 0x127;
        key         = tableIndex + 0x11e;
        group       = 0x1e;
        hdr         = 0x126;
        idB         = 0x12c;
        idC         = 0x131;
        idD         = 0x136;
        idE         = 0x13b;
        pageId      = 0x140;
        pageCountId = 0x141;
        perPage     = 5;
    } else {
        count = CountNonZeroValues020a0b8c((struct S_a0b8c *) list);
        keys  = (short *) (list + 0xc);
        vals  = (signed char *) (list + 0x13c);
        key   = 0x7a;
    }

    ClearElementFlag0x20_02080c20(elemObj, group);
    SetEntryLowNibbleAndElement02080c68(elemObj, group, 0);
    ClearSublistEntriesFlag1_02080bac(elemObj, group);
    ClearSublistEntriesFlag2_0208065c(elemObj, group);
    SetOrClearEntryFlag0x102081130(elemObj, group, perPage < count);

    short i              = self->page * perPage;
    short end            = i + perPage;
    for (; i < end; i++) {
        if (count <= i) {
            AddSublistEntryFlag2_020806b0(elemObj, idA);
            SetEntryFlagById02080b2c(elemObj, idA);
            SetEntryFlagById02080b2c(elemObj, idB);
            SetEntryFlagById02080b2c(elemObj, idC);
            SetEntryFlagById02080b2c(elemObj, idD);
            SetEntryFlagById02080b2c(elemObj, idE);
        } else {
            int value = 0;
            int num   = 0;
            short k;
            if (keys != 0) {
                k = keys[i];
            } else {
                k = FindNthPositiveShort0207c6b8(list + 0x1d4, table, i);
            }
            struct Element020de650 *elem = FindElementByKey020dedd0(&self->container, k);
            if (elem != NULL) {
                value = elem->value;
                num   = elem->count;
            }
            int extra;
            if (vals != 0) {
                extra = vals[i];
            } else {
                extra = GetNthPositiveEntryValue_0207c72c(list + 0x1d4, table, i);
            }
            func_ov003_0217818c(self, elem, idB, idC);
            Forward0207f7acObjPlus4Size0x40_020805f4(elemObj, idA);
            SetEntryFirstField02080f8c((struct Container02080f8c *) elemObj, idA, value);
            SetEntryFirstField02080fa8((struct Container02080fa8 *) elemObj, idB, num);
            SetEntryFirstField02080fa8((struct Container02080fa8 *) elemObj, idE, extra);
        }
        idA++;
        idB++;
        idC++;
        idD++;
        idE++;
    }

    SetEntryFirstField02080f8c((struct Container02080f8c *) elemObj, hdr, LookupValueByEntryKey02081010(elemObj, key));
    SetEntryFirstField02080fa8((struct Container02080fa8 *) elemObj, pageId, self->page + 1);
    SetEntryFirstField02080fa8((struct Container02080fa8 *) elemObj, pageCountId, self->pageCount);
    func_020813ec(elemObj, group);
}
