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

int GetFieldAt0x150(unsigned char* obj);
extern "C" struct Entry02087574* _Z27FindEntryBySignedId02087574P18EntryTable02087574i(struct EntryTable02087574* obj, int id);

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020875c4
extern "C" ARM void _Z33ArchiveEntryToCombatantField0x150P18EntryTable02087574ii(
    struct EntryTable02087574* table, int id, int memberIndex) {
    struct Entry02087574* entry = _Z27FindEntryBySignedId02087574P18EntryTable02087574i(table, id);
    if (entry == 0) {
        return;
    }
    GameObject* member = GameState::GetInstance()->GetPartyMemberByIndex(memberIndex);
    if (member == 0) {
        return;
    }
    unsigned char* field = (unsigned char*)GetFieldAt0x150((unsigned char*)member);
    if (field == 0) {
        return;
    }
    memcpy(field + 0x54 + 0x400, entry, 0x10);
    memset(entry, 0, 0x14);
    entry->id = -1;
}
