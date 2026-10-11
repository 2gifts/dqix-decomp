#include <globaldefs.h>
#include "GameState/GameState.h"

struct BattleEquipmentEntry {
    unsigned char unknown00[8];
    unsigned int category : 4;
    unsigned int unknownFlags : 28;
    unsigned char unknown0c[0xc];
    short itemId;
    unsigned char unknown1a[6];
};
struct BattleEquipmentView {
    unsigned char unknown00[0x194];
    BattleEquipmentEntry entries[8];
};
struct Container020dedd0;
struct BattleEquipmentList {
    Container020dedd0* inventory;
    unsigned char unknown04[0x4c - 0x4];
    int partyIndex;
};

BattleEquipmentEntry* FindElementByKey020dedd0(Container020dedd0* c, int key);
extern "C" unsigned char data_ov000_02183388[8];

// USA: func_ov000_02171d90
extern "C" ARM BattleEquipmentEntry* func_ov000_02171d90(BattleEquipmentList* list, int itemId) {
    if (itemId < 0) {
        return NULL;
    }
    char* actor = (char*)GetCombatantWithFlag0x100(GameState::GetInstance(), list->partyIndex);
    if (actor) {
        unsigned char equipmentOrder[8];
        unsigned int bytes = sizeof(equipmentOrder);
        unsigned char* output = equipmentOrder;
        const unsigned char* input = data_ov000_02183388;
        do {
            unsigned char value = *input;
            *output = value;
            ++input;
            ++output;
        } while (--bytes);
        for (unsigned char slot = 0; slot < 8; ++slot) {
#if defined(jpn)
            BattleEquipmentView* equipment = *reinterpret_cast<BattleEquipmentView**>(actor + 0x144);
#else
            BattleEquipmentView* equipment = *reinterpret_cast<BattleEquipmentView**>(actor + 0x150);
#endif
            BattleEquipmentEntry* entry = &equipment->entries[equipmentOrder[slot]];
            if (entry && entry->itemId > 0) {
                int equipmentCategory = entry->category <= 7;
                if (equipmentCategory && entry->itemId == itemId) {
                    return entry;
                }
            }
        }
    }
    return FindElementByKey020dedd0(list->inventory, itemId);
}
