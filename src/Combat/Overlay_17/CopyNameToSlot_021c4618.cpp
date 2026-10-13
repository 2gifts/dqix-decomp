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

ARM void CopyNameToSlot_021c4618(int unused0, char* source, GameState* game, GameResources* resources) {
    PartyNameEvent* event = (PartyNameEvent*)source;
    unsigned char partyIndex = event->combatantId;
    GameObject* combatant = GetCombatantWithFlag0x100(game, partyIndex);
    if (combatant == NULL) return;
#if defined(jpn)
    sprintf(((CombatantNameView*)combatant)->displayName, &data_020ef078, event->name);
    strcpy(resources->partyNames[partyIndex], event->name);
#else
    FormatAndCopyName02052958((char*)combatant, event->name, 1);
    strcpy(resources->partyNames[partyIndex], ((CombatantNameView*)combatant)->displayName);
#endif
}
