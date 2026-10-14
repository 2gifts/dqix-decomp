#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct BattleNode0215f1ac { char pad_0[0x20]; unsigned short combatant; };
struct BattleRecord0215f1ac { short key; char pad_2[0x10 - 2]; BattleNode0215f1ac* head; char pad_14[0x28 - 0x14]; };
struct BattleEvents0215f1ac { char pad_0[0x8e20]; int actionCount; char pad_8e24[0x8e78 - 0x8e24]; BattleRecord0215f1ac* records; int count; };
struct BattleRule0215f1ac { char pad_0[0x10]; unsigned int flags; char pad_14[0x2c - 0x14]; unsigned int field_0 : 14; unsigned int category : 6; unsigned int field_20 : 12; };
struct List02160094;

BattleRule0215f1ac* SearchBothTables02079e2c(char*, int);
int TestBit6At0x2f4_02085180(unsigned char*);
int ClassifyField0x81fe_ov000_0215fc60(char*);
BattleNode0215f1ac* GetNodeAtIndex02160094(List02160094*, int);
extern "C" void func_ov000_0215f500(BattleRecord0215f1ac*, BattleRecord0215f1ac*);
extern const int data_ov000_02182aac[3];
extern int data_ov000_02182a58[2];
struct CombatantView0215f1ac { char pad_0[0x150]; unsigned char* status; };

// USA: func_ov000_0215f1ac
extern "C" ARM void func_ov000_0215f1ac(BattleEvents0215f1ac* events) {
    GameState* state = GameState::GetInstance();
    ActionDataTables* data = GetData02108e10_020797dc();
    int moved = 0;
    for (int i = events->count - 1; i >= moved; i--) {
        BattleRecord0215f1ac* record = &events->records[i];
        BattleRule0215f1ac* rule = SearchBothTables02079e2c((char*)data, record->key);
        if (!rule || !(rule->flags & 0x80000)) continue;
        unsigned short id = record->head->combatant;
        unsigned char partyMember = id <= 3;
        if (!partyMember) continue;
        GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(state, id);
        if (!combatant || !TestBit6At0x2f4_02085180(((CombatantView0215f1ac*)combatant)->status)) continue;
        BattleRecord0215f1ac saved;
        memcpy(&saved, record, 0x28);
        memmove(events->records + 1, events->records, i * 0x28);
        moved++;
        i++;
        memcpy(events->records, &saved, 0x28);
    }
    for (int categoryIndex = 0; categoryIndex < 3; categoryIndex++) {
        int moved = 0;
        for (int i = events->count - 1; i >= moved; i--) {
            BattleRecord0215f1ac* records = events->records;
            BattleRule0215f1ac* rule = SearchBothTables02079e2c((char*)data, records[i].key);
            if (!rule || rule->category != data_ov000_02182aac[categoryIndex]) continue;
            BattleRecord0215f1ac saved;
            memcpy(&saved, &records[i], 0x28);
            memmove(events->records + 1, events->records, i * 0x28);
            moved++;
            i++;
            memcpy(events->records, &saved, 0x28);
        }
    }
    int trailingCategories[1] = { data_ov000_02182a58[1] };
    for (int categoryIndex = 0; categoryIndex < 1; categoryIndex++) {
        int category;
        int remaining = events->count;
        int i = 0;
        for (; i < remaining; i++) {
            category = trailingCategories[categoryIndex];
            BattleRecord0215f1ac* records = events->records;
            BattleRule0215f1ac* rule = SearchBothTables02079e2c((char*)data, records[i].key);
            if (!rule || rule->category != category) continue;
            BattleRecord0215f1ac saved;
            memcpy(&saved, &records[i], 0x28);
            int recordCount = events->count;
            if (i < recordCount - 1) {
                memmove(&events->records[i], &events->records[i + 1], (recordCount - i - 1) * 0x28);
                remaining--;
                i--;
            }
            memcpy(&events->records[events->count - 1], &saved, 0x28);
        }
    }
    if (ClassifyField0x81fe_ov000_0215fc60((char*)events)) {
        BattleRecord0215f1ac* first = events->records;
        BattleRecord0215f1ac* second = first + 1;
        BattleNode0215f1ac* node = GetNodeAtIndex02160094((List02160094*)first, 0);
        if (events->count == 1) {
            second = events->records;
            first = 0;
        } else if (node && node->combatant) {
            BattleRecord0215f1ac saved = *first;
            func_ov000_0215f500(first, second);
            func_ov000_0215f500(second, &saved);
        }
        int actionCount = events->actionCount;
        node = GetNodeAtIndex02160094((List02160094*)second, 0);
        if (node && actionCount <= 1) second->key = actionCount == 0 ? 0x16e : 1;
        if (first) first->key = 0x1f7;
    }
}
