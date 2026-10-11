#include <globaldefs.h>
#if defined(jpn)
enum { kRegion950 = 0x8b8 };
enum { kRegion76 = 0x46 };
#else
enum { kRegion950 = 0x950 };
enum { kRegion76 = 0x76 };
#endif
#include "GameState/GameState.h"

struct CombatantData_02167b34 {
    unsigned int value0 : 10;
    unsigned int value1 : 10;
    unsigned int value2 : 10;
    unsigned int value3 : 10;
    unsigned int value4 : 10;
    unsigned int value5 : 10;
    unsigned int value6 : 10;
    unsigned int value7 : 10;
    unsigned int value8 : 10;
    unsigned int value9 : 10;
    unsigned char pad10[0x138 - 0x10];
    int wordTable[0xd];
    unsigned short halfTable[0xd];
    unsigned char byteTable[0x464 - 0x186];
    unsigned char entryTable[0x49c - 0x464];
    unsigned char flag : 1;
    unsigned char pad49d[kRegion950 - 0x49d];
    int index;
};

struct Wrapper02168088;
struct Menu_02167b34 {
    unsigned char pad0[0x10];
    void* list;
    unsigned char pad14[kRegion76 - 0x14];
    signed char combatantId;
};

void* GetFieldAt0x150(unsigned char* obj);
extern "C" void func_02083e28(void* data, int arg);
extern "C" void func_ov003_02167e28(Menu_02167b34* menu, BaseCombatStats* stats, int flag, unsigned char index, int byteValue, int halfValue, int wordValue);
extern "C" void func_ov003_02167fa4(Menu_02167b34* menu, int flag, unsigned char* table);
extern "C" void _Z31SetEntryFieldsForRange_02168088P15Wrapper02168088Pi(struct Wrapper02168088* obj, int* arr);
extern "C" void func_020813ec(void* list, int arg);

static inline BaseCombatStats* GetBaseStats(GameObject* c) {
    BaseCombatStats* stats = c->baseStats_;
    return stats;
}

// JPN: func_ov003_02167a0c
// USA: func_ov003_02167b34
extern "C" ARM void func_ov003_02167b34(Menu_02167b34* menu) {
    GameObject* combatant = GetCombatantWithFlag0x100(GameState::GetInstance(), menu->combatantId);
    if (combatant == 0) return;
    CombatantData_02167b34* data = (CombatantData_02167b34*)GetFieldAt0x150((unsigned char*)combatant);
    func_02083e28(data, 0);
    func_ov003_02167e28(menu, GetBaseStats(combatant), data->flag, data->index, data->byteTable[data->index], data->halfTable[data->index], data->wordTable[data->index]);
    func_ov003_02167fa4(menu, data->index & 0xff, data->entryTable);
    int values[12];
    values[0] = data->value0;
    values[1] = data->value1;
    values[2] = data->value2;
    values[3] = data->value3;
    values[4] = data->value4;
    values[5] = data->value5;
    values[6] = data->value6;
    values[7] = data->value7;
    values[8] = data->value8;
    values[9] = combatant->baseStats_->primaryStats.attack;
    values[10] = combatant->baseStats_->primaryStats.defense;
    values[11] = data->value9;
    _Z31SetEntryFieldsForRange_02168088P15Wrapper02168088Pi((struct Wrapper02168088*)menu, values);
    func_020813ec(menu->list, 0);
}
