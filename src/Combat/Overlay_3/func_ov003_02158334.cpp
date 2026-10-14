#include <globaldefs.h>
#if defined(jpn)
enum { kRegion1f2 = 0x1ee };
#else
enum { kRegion1f2 = 0x1f2 };
#endif
#include "GameState/GameState.h"

struct CombatantStatus {
    unsigned int flags;
    unsigned short hp;
};

struct CombatantProfile {
    char name[0x30];
    unsigned short maxHP;
};

struct Combatant {
    char unk_0[0x130];
    CombatantStatus* status;
    CombatantProfile* profile;
};

struct EntryList;

struct PartyStatusPanel {
    char unk_0[0x18];
    EntryList* entries;
    char unk_1c[kRegion1f2 - 0x1c];
    unsigned char memberIds[4];
    unsigned char memberCount;
};

struct Container02080f8c;
void SetEntryFirstField02080f8c(Container02080f8c*, int, int);
struct Container02080cc0;
void SetEntryHighNibble0x13(Container02080cc0*, int, int);
extern "C" void func_020813ec(EntryList*, int);

// USA: func_ov003_02158334
extern "C" ARM void func_ov003_02158334(PartyStatusPanel* self) {
    GameState* gs = GameState::GetInstance();
    int rows = 3;
    int id = 10;

    switch (self->memberCount) {
    case 3:
        rows = 4;
        id = 0xc;
        break;
    case 4:
        rows = 5;
        id = 0xf;
        break;
    }

    EntryList* entries = self->entries;
    for (unsigned char i = 0; i < self->memberCount; i++) {
        Combatant* member = (Combatant*)GetCombatantWithFlag0x100_0200ff1c(gs, self->memberIds[i]);
        if (member != NULL) {
            int color = 0xf;
            SetEntryFirstField02080f8c((Container02080f8c*)entries, id, (int)member->profile->name);

            int maxHP = member->profile->maxHP;
            float ratio;
            if (maxHP == 0.0f) {
                ratio = 0.0f;
            } else {
                int hp = member->status->hp;
                ratio = (float)hp / maxHP;
            }
            if (ratio <= 0.25f) color = 0xd;
            if (ratio <= 0.08f) color = 0xb;
            if (member->status->flags & 1) color = 9;

            SetEntryHighNibble0x13((Container02080cc0*)entries, id, color);
        }
        id = (short)(id + 1);
    }

    func_020813ec(entries, rows);
}
