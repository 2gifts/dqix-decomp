#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct;
struct Init0207d7c0;

struct Entry0207d9bc {
    unsigned short id;
    unsigned short field2;
    signed char field4;
    unsigned char field5;
    char pad6[2];
    signed char bytes[4];
};

void* FindEntryByFlagByte(unsigned char* arr, int offset);
void InitStruct0207d7c0(struct Init0207d7c0* o);
struct Entry0207d9bc* FindEntryByHalfword(struct Entry0207d9bc* arr, unsigned short key);
extern "C" void* func_0202ae18(void);
int TestBitBySignedByteIndex(struct SearchStruct* obj, int value);
int CheckEntryBytes0207d978(struct Entry0207d9bc* arr, unsigned short key);
GameObject* GetCombatantWithFlag0x1000(GameState* battleStruct, int combatantId);
int GetSignedByte0x2d0(void* obj);

// USA: func_0207d7f4
extern "C" ARM int func_0207d7f4(struct Entry0207d9bc* entries, unsigned short id, int charId, int flag,
                      signed char field4, unsigned short field2, unsigned char field5) {
    signed char v;
    GameState* game = GameState::GetInstance();
    struct Entry0207d9bc* entry;
    struct SearchStruct* search;
    GameObject* combatant;
    int i;

    if (flag != 0) {
        entry = (struct Entry0207d9bc*)FindEntryByFlagByte((unsigned char*)entries, charId);
        if (entry != NULL && entry->id != id) {
            InitStruct0207d7c0((struct Init0207d7c0*)entry);
        }
    }
    entry = FindEntryByHalfword(entries, id);
    if (entry == NULL) {
        entry = FindEntryByHalfword(entries, 0);
        if (entry == NULL) return 0;
        InitStruct0207d7c0((struct Init0207d7c0*)entry);
        entry->id = id;
        search = (struct SearchStruct*)func_0202ae18();
        for (i = 0; i < 4; i++) {
            if (!TestBitBySignedByteIndex(search, i) || game->GetPartyMemberByIndex(i) == NULL)
                entry->bytes[i] = 0;
        }
    } else if (game->GetGameObjectByIndex(charId) == NULL) {
        entry->bytes[charId] = 0;
        return CheckEntryBytes0207d978(entries, id);
    }
    v = (signed char)flag;
    entry->bytes[charId] = v;
    for (i = 0; i < 4; i++) {
        combatant = GetCombatantWithFlag0x1000(game, i);
        if (combatant != NULL && GetSignedByte0x2d0(combatant) == charId)
            entry->bytes[i] = v;
    }
    if (flag != 0 && entry->field4 < 0 && field4 >= 0) {
        entry->field4 = field4;
        entry->field2 = field2;
        entry->field5 = field5;
    }
    return CheckEntryBytes0207d978(entries, id);
}
