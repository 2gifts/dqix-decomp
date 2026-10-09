#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct0217193c;
struct Struct02171614;
struct Struct02171b3c;
struct S02171698;
struct S021719c0;
struct Holder0209a9dc;
struct BitArray020839dc;
struct Slots02083960;
struct Container02083554;
struct FlagObj_021dce1c;
struct CommandEntry {
    char pad0[8];
    unsigned int category : 4;
    unsigned int learnedType : 5;
    unsigned int reserved9 : 1;
    unsigned int availability : 2;
    unsigned int reserved12 : 20;
    char padc[8];
    unsigned short bitIndex;
    char pad16[2];
    unsigned int typeReserved : 12;
    unsigned int commandType : 4;
    unsigned int reserved16 : 16;
};
struct Element020de650 {
    char pad0[8];
    unsigned int category : 4;
    unsigned int learnedType : 5;
    unsigned int reserved9 : 23;
    char padc[8];
    unsigned short bitIndex;
    char pad16[10];
};
struct Entry02083554 {
    char pad0[8];
    unsigned int category : 4;
    unsigned int reserved4 : 28;
    char padc[0xc];
    short id;
    char pad1a[6];
};
struct Container020dedd0 { char data[0x18]; };
struct Container_021dae60 { char pad0[0xd0]; Container020dedd0 commands; };
struct CommandSlot {
    char pad0[0x10];
    unsigned char selections[8];
    signed char selection;
    char pad19[0x87 - 0x19];
    unsigned char eligible;
};
struct LearnedCommands {
    char pad0[0x454];
    short equipped[8];
    char pad464[0x488 - 0x464];
    short equipment[9];
    char pad49a[0x950 - 0x49a];
    int useSpecialList;
};
struct CombatantView { char pad0[0x150]; LearnedCommands* commands; };
struct AbilityEntry { unsigned short id, command; char pad4[6]; unsigned short order; };
struct Entry0209a9dc { unsigned short id, command; };
struct PartyRoster { char pad0[0xf78]; unsigned char ids[4]; unsigned char count; };
struct StatusView {
    char pad0[0x22];
    unsigned short reserved0 : 2;
    unsigned short blocked : 4;
    unsigned short reserved6 : 10;
};

int GetFieldAt0x150(unsigned char*);
extern "C" CommandSlot* _Z21FindSlotById_021dae60P18Container_021dae60i(Container_021dae60*, int);
extern "C" void _Z29ZeroArr1a4AndFlag0x840217193cP14Struct0217193c(Struct0217193c*);
extern "C" void _Z28ZeroArr9cAndFlag0x8202171614P14Struct02171614(Struct02171614*);
extern "C" Element020de650* _Z24FindElementByKey020dedd0P17Container020dedd0i(Container020dedd0*, int);
void SetBitInArray0x8ec(unsigned char*, int);
void ClearBitInArray0x8ec(unsigned char*, int);
int TestBitInArray0x8ec(unsigned char*, int);
extern "C" int _Z28CollectSetBitIndices020839dcP16BitArray020839dcPhi(BitArray020839dc*, unsigned char*, int);
extern "C" Entry0209a9dc* _Z21FindEntryById0209a9dcP14Holder0209a9dci(Holder0209a9dc*, int);
char* GetData02108e10();
extern "C" CommandEntry* _Z24SearchBothTables02079e2cPci(char*, int);
extern "C" void _Z30SetFieldAndUpdateCount02171640P9S02171698ii(S02171698*, int, int);
extern "C" void _Z30SetFieldAndUpdateCount02171968P9S021719c0ii(S021719c0*, int, int);
extern "C" int _Z26CountPositiveSlots02083960P13Slots02083960(Slots02083960*);
extern "C" void _Z29ZeroArr3f0AndFlag0x8602171b3cP14Struct02171b3c(Struct02171b3c*);
extern "C" void _Z28SetPointerField0x3f002171b68PviS_(void*, int, void*);
extern "C" Entry02083554* _Z29FindEntryByShortField02083554P17Container02083554i(Container02083554*, int);
int CheckFlag0x14Bit0x10Set(unsigned char*);
extern "C" int _Z22IsFlagBit8Set_021dce1cP16FlagObj_021dce1c(FlagObj_021dce1c*);
extern "C" AbilityEntry* func_0209a594(void*, int);
extern "C" int func_0209ab7c(Holder0209a9dc*, GameObject*, unsigned char*);

// USA: func_ov026_021dc8fc
extern "C" ARM void func_ov026_021dc8fc(void*, void*, void*, Container_021dae60* work,
                                        void* abilities, Holder0209a9dc* holder, int id) {
    GameState* game = GameState::GetInstance();
    GameObject* object = GetCombatantWithFlag0x100(game, id);
    if (!object) return;
    LearnedCommands* learned = (LearnedCommands*)GetFieldAt0x150((unsigned char*)object);
    if (!learned) return;
    CommandSlot* slot = _Z21FindSlotById_021dae60P18Container_021dae60i(work, id);
    if (!slot) return;
    _Z29ZeroArr1a4AndFlag0x840217193cP14Struct0217193c((Struct0217193c*)slot);
    _Z28ZeroArr9cAndFlag0x8202171614P14Struct02171614((Struct02171614*)slot);
    short commandIds[0x11f];
    unsigned char extraIds[0x42];
    CommandEntry* entries[0xd5];
    int equippedIds[8];
    int count = 0;
    memset(commandIds, -1, sizeof(commandIds));
    for (int key = 0x56f9; key <= 0x5712; ++key) {
        short* equipped = ((CombatantView*)object)->commands->equipped;
        int found = 0;
        for (int i = 0; i < 8; ++i) {
            if (key == equipped[i]) { found = 1; break; }
        }
        Element020de650* entry = _Z24FindElementByKey020dedd0P17Container020dedd0i(&work->commands, (short)key);
        if (entry && entry->learnedType == 0x1f) {
            if (found) SetBitInArray0x8ec((unsigned char*)learned, entry->bitIndex);
            else ClearBitInArray0x8ec((unsigned char*)learned, entry->bitIndex);
        }
    }
    for (unsigned short i = 0; i < 0x11f; ++i) {
        if (TestBitInArray0x8ec((unsigned char*)learned, i)) {
            AbilityEntry* ability = func_0209a594(abilities, i);
            if (ability && ability->command) {
                commandIds[ability->order] = ability->command;
                ++count;
            }
        }
    }
    for (int i = 0; i < 0x11e; ++i) {
        if (commandIds[i] < 0) {
            for (int j = i + 1; j < 0x11f; ++j) {
                if (commandIds[j] >= 0) {
                    commandIds[i] = commandIds[j];
                    commandIds[j] = -1;
                    break;
                }
            }
        }
    }
    int extraCount;
    if (((CombatantView*)object)->commands->useSpecialList == 0)
        extraCount = _Z28CollectSetBitIndices020839dcP16BitArray020839dcPhi((BitArray020839dc*)learned, extraIds, 0x80);
    else extraCount = func_0209ab7c(holder, object, extraIds);
    for (int i = 0; i < extraCount; ++i) {
        Entry0209a9dc* entry = _Z21FindEntryById0209a9dcP14Holder0209a9dci(holder, extraIds[i]);
        if (entry && entry->command) commandIds[count++] = entry->command;
    }
    char* commandTable = GetData02108e10();
    for (int i = 0; i < count; ++i) entries[i] = _Z24SearchBothTables02079e2cPci(commandTable, commandIds[i]);
    int secondaryCount = 0;
    int commandIndex;
    int primaryCount = 0;
    for (commandIndex = 0; commandIndex < count; ++commandIndex) {
        CommandEntry* entry = entries[commandIndex];
        if (entry && (entry->availability & 2)) {
            if (entry->commandType == 2) {
                _Z30SetFieldAndUpdateCount02171640P9S02171698ii((S02171698*)slot, secondaryCount, (int)entry);
                ++secondaryCount;
            } else if (entry->commandType == 1) {
                _Z30SetFieldAndUpdateCount02171968P9S021719c0ii((S021719c0*)slot, primaryCount, (int)entry);
                ++primaryCount;
            }
        }
    }
    int equippedCount = _Z26CountPositiveSlots02083960P13Slots02083960((Slots02083960*)learned);
    for (int i = 0; i < 8; ++i) equippedIds[i] = learned->equipped[i];
    short* equipment = learned->equipment;
    int stored;
    unsigned char order[8] = {7, 8, 0, 1, 6, 4, 5, 0xff};
    int equipmentIndex;
    stored = 0;
    _Z29ZeroArr3f0AndFlag0x8602171b3cP14Struct02171b3c((Struct02171b3c*)slot);
    for (equipmentIndex = 0; equipmentIndex < 16; ++equipmentIndex) {
        if (equipmentIndex < 8) {
            if (equipmentIndex < equippedCount) {
                Element020de650* entry = _Z24FindElementByKey020dedd0P17Container020dedd0i(&work->commands, (short)equippedIds[equipmentIndex]);
                if (entry) {
                    _Z28SetPointerField0x3f002171b68PviS_(slot, stored, entry);
                    ++stored;
                }
            }
        } else {
            if (equipmentIndex == 8) {
                if (stored > 4) stored = 8;
                else if (stored > 0) stored = 4;
            }
            unsigned char index = order[equipmentIndex - 8];
            if (index == 0xff) continue;
            Entry02083554* entry = _Z29FindEntryByShortField02083554P17Container02083554i((Container02083554*)learned, equipment[index]);
            if (entry && entry->id > 0) {
                int usable = entry->category <= 7 ? 1 : 0;
                if (usable) {
                    _Z28SetPointerField0x3f002171b68PviS_(slot, stored, entry);
                    ++stored;
                }
            }
        }
    }
    int listed = 0;
    slot->eligible = 0;
    PartyRoster* roster = (PartyRoster*)GetPtrField0x2a04(game);
    for (int i = 0; i < roster->count; ++i) {
        if (id == roster->ids[i]) { listed = 1; break; }
    }
    GameObject* combatant = game->GetCombatantByIndex(id);
    if (combatant) {
        if (CheckFlag0x14Bit0x10Set((unsigned char*)combatant->currentStats_) ||
            ((StatusView*)combatant->currentStats_)->blocked ||
            _Z22IsFlagBit8Set_021dce1cP16FlagObj_021dce1c((FlagObj_021dce1c*)combatant)) {
            slot->eligible = 0;
            slot->selections[slot->selection] = 100;
        } else if (listed) slot->eligible = 1;
    }
}
