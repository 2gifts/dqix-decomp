#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

#if defined(jpn)
extern char data_020ef078;
#endif

void FormatAndCopyName02052958(char* combatant, char* name, int formatDisplayName);

struct PartyNameEvent {
    unsigned char tag;
    unsigned char reserved[3];
    unsigned char combatantId;
    char name[15];
};

struct CombatantNameView {
    char unknown000[0x134];
    char* displayName;
};

struct PartyNameCacheView {
#if defined(jpn)
    char unknown0000[0x413c];
    char names[4][12];
#else
    char unknown0000[0x435c];
    char names[4][48];
#endif
};

ARM void CopyNameToSlot_021c4618(int unused0, char* source, GameState* game, char* resourceBase) {
    PartyNameEvent* event = (PartyNameEvent*)source;
    unsigned char partyIndex = event->combatantId;
    GameObject* combatant = GetCombatantWithFlag0x100(game, partyIndex);
    if (combatant == NULL) return;
    PartyNameCacheView* cache = (PartyNameCacheView*)resourceBase;
#if defined(jpn)
    sprintf(((CombatantNameView*)combatant)->displayName, &data_020ef078, event->name);
    strcpy(cache->names[partyIndex], event->name);
#else
    FormatAndCopyName02052958((char*)combatant, event->name, 1);
    strcpy(cache->names[partyIndex], ((CombatantNameView*)combatant)->displayName);
#endif
}
