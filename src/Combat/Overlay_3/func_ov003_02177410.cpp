#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj2081;
void ClearElementFlag0x20(struct Obj2081* obj, int key);
void SetEntryLowNibbleAndElement02080c68(void* obj, int id, int value);
struct TableRef02081214;
void* FindEntryInTableRef(struct TableRef02081214* ref, int key);
void SetSublistEntryField28_0208077c(void* obj, int id, short value);
struct Container02080cc0;
void SetEntryHighNibble0x13(struct Container02080cc0* obj, int id, int value);
struct Container02080f8c;
void SetEntryFirstField02080f8c(struct Container02080f8c* obj, int id, int value);
void Forward0207f7acObjPlus4Size0x40(void* obj, int value);
extern "C" void func_020813ec(void* obj, int key);

struct SlotList02177410 {
    unsigned char index[8];
};
extern SlotList02177410 data_ov003_0217faa4;

struct Slot02177410 {
    char pad0[4];
    int value;
    unsigned int kind : 4;
    unsigned int pad8 : 28;
    char padc[0x18 - 0xc];
    short count;
    char pad1a[0x20 - 0x1a];
};

struct Status02177410 {
    char pad0[0x194];
    Slot02177410 slots[8];
};

struct Combatant02177410 {
    char pad0[0x150];
    Status02177410* status;
};

struct Menu02177410 {
    char pad0[0x89c];
    struct Obj2081* elemObj;
    char pad8a0[0x1043 - 0x8a0];
    signed char combatantId;
};

// USA: func_ov003_02177410
extern "C" ARM void func_ov003_02177410(Menu02177410* self) {
    GameState* battle = GameState::GetInstance();
    struct Obj2081* elemObj = self->elemObj;
    ClearElementFlag0x20(elemObj, 0xe);
    SetEntryLowNibbleAndElement02080c68(elemObj, 0xe, 0);

    Combatant02177410* combatant = (Combatant02177410*)GetCombatantWithFlag0x100(battle, self->combatantId);
    if (combatant == NULL) {
        return;
    }

    SlotList02177410 list = data_ov003_0217faa4;
    int defaultValue = (int)FindEntryInTableRef((struct TableRef02081214*)elemObj, 0x14);
    for (short i = 0; i < 8; i++) {
        short id = i + 0x68;
        int value = defaultValue;
        int nibble = 3;
        unsigned char index = list.index[i];
        if (index != 0xff) {
            Slot02177410* slot = &combatant->status->slots[index];
            if (slot == NULL) {
                continue;
            }
            if (slot->count > 0 && slot->kind != 0xb) {
                value = slot->value;
                nibble = 0xf;
            }
        }
        SetSublistEntryField28_0208077c(elemObj, id, 0xd);
        SetEntryHighNibble0x13((struct Container02080cc0*)elemObj, id, nibble);
        SetEntryFirstField02080f8c((struct Container02080f8c*)elemObj, id, value);
        Forward0207f7acObjPlus4Size0x40(elemObj, id);
    }

    func_020813ec(elemObj, 0xe);
}
