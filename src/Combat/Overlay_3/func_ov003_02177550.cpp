#include <globaldefs.h>
#if defined(jpn)
enum {
    kRegion89c = 0x818
};
enum {
    kRegion1043 = 0xfbf
};
#else
enum {
    kRegion89c = 0x89c
};
enum {
    kRegion1043 = 0x1043
};
#endif
#include "GameState/GameState.h"

struct Obj2081;
void ClearElementFlag0x20(struct Obj2081 *obj, int key);
void SetEntryLowNibbleAndElement02080c68(void *obj, int id, int value);
void ClearSublistEntriesFlag1(void *obj, int id);
struct Container02080f8c;
void SetEntryFirstField02080f8c(struct Container02080f8c *obj, int id, int value);
void Forward0207f7acObjPlus4Size0x40(void *obj, int value);
void SetEntryHalfword0xe(void *obj, int id, int value);
struct Container02080cc0;
void SetEntryHighNibble0x13(struct Container02080cc0 *obj, int id, int value);
int SetEntryFlagById02080b2c(void *obj, int id);
struct Field150Holder02052df8;
short GetHalfwordEntryFromField150(Field150Holder02052df8 *obj, int index);
struct Container02080fa8;
void SetEntryFirstField02080fa8(struct Container02080fa8 *obj, int id, int value);
struct Container02080fc4;
void SetEntryFirstField02080fc4(struct Container02080fc4 *obj, int id, int value);
extern "C" int func_020dd4c4(int id, void *node);
extern "C" int func_ov003_021753a0(void *obj, int id, void *a, void *b);
extern "C" void func_020813ec(void *obj, int key);

extern int data_ov003_0217fb3c[];

struct Node02177550 {
    char pad0[4];
    int value;
    unsigned int kind : 4;
    unsigned int pad8 : 28;
    unsigned int lo : 7;
    unsigned int tier : 4;
    unsigned int hi : 21;
    char pad10[0x18 - 0x10];
    short count;
};

struct Menu02177550 {
    char pad0[8];
    Node02177550 *node;
    char padc[kRegion89c - 0xc];
    struct Obj2081 *elemObj;
    char pad8a0[kRegion1043 - kRegion89c - 4];
    signed char combatantId;
};

// USA: func_ov003_02177550
extern "C" ARM void func_ov003_02177550(Menu02177550 *self) {
    GameState *battle     = GameState::GetInstance();
    GameObject *combatant = GetCombatantWithFlag0x100(battle, self->combatantId);
    if (combatant == NULL) {
        return;
    }
    struct Obj2081 *elemObj;
    Node02177550 *node = self->node;
    elemObj            = self->elemObj;
    if (node == NULL) {
        return;
    }

    ClearElementFlag0x20(elemObj, 0xf);
    SetEntryLowNibbleAndElement02080c68(elemObj, 0xf, 0);
    ClearSublistEntriesFlag1(elemObj, 0xf);
    SetEntryFirstField02080f8c((struct Container02080f8c *) elemObj, 0x70, node->value);
    Forward0207f7acObjPlus4Size0x40(elemObj, 0x70);
    int ready         = func_020dd4c4(self->combatantId, node);
    unsigned int tier = node->tier;
    if (tier != 0) {
        SetEntryHalfword0xe(elemObj, 0x71, (short) (tier + 0x2f));
    }

    if (ready != 0) {
        SetEntryHalfword0xe(elemObj, 0x75, 0xb);
        SetEntryHighNibble0x13((struct Container02080cc0 *) elemObj, 0x75, 3);
        SetEntryFlagById02080b2c(elemObj, 0x72);
        SetEntryFlagById02080b2c(elemObj, 0x73);
        SetEntryFlagById02080b2c(elemObj, 0x74);
        SetEntryFlagById02080b2c(elemObj, 0x159);
        SetEntryFlagById02080b2c(elemObj, 0x15a);
    } else {
        SetEntryHighNibble0x13((struct Container02080cc0 *) elemObj, 0x75, 0xf);
        int index = data_ov003_0217fb3c[node->kind];
        if (index < 0) {
            return;
        }
        short have = GetHalfwordEntryFromField150((Field150Holder02052df8 *) combatant, index);
        if (have == node->count) {
            SetEntryHalfword0xe(elemObj, 0x75, 0x22);
            SetEntryFlagById02080b2c(elemObj, 0x72);
            SetEntryFlagById02080b2c(elemObj, 0x73);
            SetEntryFlagById02080b2c(elemObj, 0x74);
            SetEntryFlagById02080b2c(elemObj, 0x159);
            SetEntryFlagById02080b2c(elemObj, 0x15a);
        } else {
            SetEntryFlagById02080b2c(elemObj, 0x75);
            unsigned short cur;
            unsigned short max;
            if (func_ov003_021753a0(self, self->combatantId, &cur, &max) != 0) {
                SetEntryFirstField02080fa8((struct Container02080fa8 *) elemObj, 0x72, cur);
                int nibble = 0xf;
                if (cur > max) {
                    nibble = 9;
                } else if (cur < max) {
                    nibble = 5;
                }
                SetEntryHighNibble0x13((struct Container02080cc0 *) elemObj, 0x73, nibble);
                SetEntryFirstField02080fa8((struct Container02080fa8 *) elemObj, 0x73, max);
                SetEntryFlagById02080b2c(elemObj, 0x159);
                SetEntryFlagById02080b2c(elemObj, 0x15a);
            } else {
                float fcur;
                float fmax;
                func_ov003_021753a0(self, self->combatantId, &fcur, &fmax);
                SetEntryFirstField02080fc4((struct Container02080fc4 *) elemObj, 0x159, *(int *) &fcur);
                int nibble = 0xf;
                if (fcur > fmax) {
                    nibble = 3;
                } else if (fcur < fmax) {
                    nibble = 5;
                }
                SetEntryHighNibble0x13((struct Container02080cc0 *) elemObj, 0x15a, nibble);
                SetEntryFirstField02080fc4((struct Container02080fc4 *) elemObj, 0x15a, *(int *) &fmax);
                SetEntryFlagById02080b2c(elemObj, 0x72);
                SetEntryFlagById02080b2c(elemObj, 0x73);
            }
        }
    }

    func_020813ec(elemObj, 0xf);
}
