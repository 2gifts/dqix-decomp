#include <globaldefs.h>

#if defined(jpn)
enum { kCountOffset = 0xc6, kAfterCountOffset = 0xc7, kEntriesOffset = 0x430, kStatsOffset = 0x144 };
#else
enum { kCountOffset = 0x86, kAfterCountOffset = 0x87, kEntriesOffset = 0x3f0, kStatsOffset = 0x150 };
#endif

#include <GameState/GameState.h>

struct BattleEquipmentEntry {
    unsigned char unknown00[8];
    unsigned int category : 4;
    unsigned int unknownFlags : 28;
    unsigned char unknown0c[0xc];
    short count;
    unsigned char unknown1a[6];
};
struct BattleEquipmentView {
    unsigned char unknown00[0x194];
    BattleEquipmentEntry entries[8];
};
struct BattleEquipmentList {
    unsigned char unknown00[0x4c];
    int partyIndex;
    unsigned char unknown50[kCountOffset - 0x50];
    signed char entryCount;
    unsigned char unknown87[kEntriesOffset - kAfterCountOffset];
    BattleEquipmentEntry* entries[16];
};
extern "C" {
    char* _Z25GetCombatantWithFlag0x100P9GameStatei(GameState*, unsigned int);
    void* _Z15GetFieldAt0x150Ph(void*);
    extern unsigned char data_ov000_02183380[8];
    void _Z28SetPointerField0x3f002171b68PviS_(BattleEquipmentList*, int, BattleEquipmentEntry*);
}

// USA: func_ov000_02171c04
// JPN: func_ov000_021734b0
extern "C" ARM void func_ov000_02171c04(BattleEquipmentList* list)
{
    signed char partyIndex = list->partyIndex;
    int valid = partyIndex >= 0 && partyIndex <= 3;
    if (valid) {
        char* actor = _Z25GetCombatantWithFlag0x100P9GameStatei(GameState::GetInstance(), partyIndex);
        if (actor && _Z15GetFieldAt0x150Ph(actor)) {
            list->entryCount = 0;
            for (signed char slot = 0; slot < 16; ++slot) {
                BattleEquipmentEntry* entry = list->entries[slot];
                if (!entry)
                    break;
                int equipmentCategory = entry->category <= 7;
                if (equipmentCategory)
                    break;
                ++list->entryCount;
            }
            unsigned char nextSlot = (list->entryCount + 3) & ~3;
            for (unsigned char slot = nextSlot; slot < 16; ++slot)
                list->entries[slot] = NULL;
            unsigned char equipmentOrder[8];
            unsigned int bytes = sizeof(equipmentOrder);
            unsigned char* output = equipmentOrder;
            const unsigned char* input = data_ov000_02183380;
            do {
                unsigned char value = *input;
                *output = value;
                ++input;
                ++output;
            } while (--bytes);
            for (unsigned char slot = 0; slot < 8; ++slot) {
                BattleEquipmentView* equipment = *reinterpret_cast<BattleEquipmentView**>(actor + kStatsOffset);
                BattleEquipmentEntry* entry = &equipment->entries[equipmentOrder[slot]];
                if (entry && entry->count > 0) {
                    int equipmentCategory = entry->category <= 7;
                    if (equipmentCategory) {
                        _Z28SetPointerField0x3f002171b68PviS_(list, nextSlot, entry);
                        ++nextSlot;
                    }
                }
            }
        }
    }
}
