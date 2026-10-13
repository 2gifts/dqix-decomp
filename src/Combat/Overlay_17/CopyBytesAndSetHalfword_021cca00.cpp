#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
#define CopyBytesAndSetHalfword_021cca00 func_ov017_021ccea8
#endif

int GetFieldAt0x150(unsigned char* combatant);

struct SlotStatePayload {
    unsigned short combatantId;
    unsigned short changedSlots;
    unsigned char slotProperties[12];
};

struct SlotStateEvent {
    unsigned char tag;
    unsigned char reserved[3];
    SlotStatePayload payload;
};

struct CombatantSlotStateView {
    char unknown000[0x186];
    unsigned char slotProperties[13];
#if defined(jpn)
    char unknown193[0x8b8 - 0x193];
#else
    char unknown193[0x950 - 0x193];
#endif
    int lastChangedSlot;
    unsigned short changedSlots;
};

#if defined(jpn)
extern "C"
#endif
ARM void CopyBytesAndSetHalfword_021cca00(int unused0, unsigned char* source, GameState* game, int unused3) {
    SlotStatePayload* event = &((SlotStateEvent*)source)->payload;
    GameObject* combatant = GetCombatantWithFlag0x100(game, event->combatantId);
    if (combatant == NULL) return;
    CombatantSlotStateView* slots = (CombatantSlotStateView*)GetFieldAt0x150((unsigned char*)combatant);
    if (slots == NULL) return;
    slots->changedSlots = event->changedSlots;
    for (int i = 0; i < 12; ++i) {
        slots->slotProperties[i + 1] = event->slotProperties[i];
    }
}
