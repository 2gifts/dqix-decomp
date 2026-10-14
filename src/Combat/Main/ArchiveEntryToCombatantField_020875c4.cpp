#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

struct Entry02087574 {
    unsigned char data[0x10];
    signed char id;
    unsigned char pad2[3];
};

struct EntryTable02087574 {
    unsigned char pad[0xf2c];
    struct Entry02087574 entries[3];
};

int GetFieldAt0x150_02053c6c(unsigned char* obj);
struct Entry02087574* FindEntryBySignedId02087574(struct EntryTable02087574* obj, int id);

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020875c4
ARM void ArchiveEntryToCombatantField0x150_020875c4(
    struct EntryTable02087574* table, int id, int memberIndex) {
    struct Entry02087574* entry = FindEntryBySignedId02087574(table, id);
    if (entry == 0) {
        return;
    }
    GameObject* member = GameState::GetInstance()->GetPartyMemberByIndex(memberIndex);
    if (member == 0) {
        return;
    }
    unsigned char* field = (unsigned char*)GetFieldAt0x150_02053c6c((unsigned char*)member);
    if (field == 0) {
        return;
    }
    memcpy(field + 0x54 + 0x400, entry, 0x10);
    memset(entry, 0, 0x14);
    entry->id = -1;
}
