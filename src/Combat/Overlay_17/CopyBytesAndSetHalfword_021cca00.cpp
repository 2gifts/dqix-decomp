#include <globaldefs.h>
#include "GameState/GameState.h"

int GetFieldAt0x150_02053c6c(unsigned char* combatant);

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

ARM void CopyBytesAndSetHalfword_021cca00(int unused0, unsigned char* source, GameState* game, int unused3) {
    SlotStatePayload* event = &((SlotStateEvent*)source)->payload;
    GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(game, event->combatantId);
    if (combatant == NULL) return;
    CombatantSlotStateView* slots = (CombatantSlotStateView*)GetFieldAt0x150_02053c6c((unsigned char*)combatant);
    if (slots == NULL) return;
    slots->changedSlots = event->changedSlots;
    for (int i = 0; i < 12; ++i) {
        slots->slotProperties[i + 1] = event->slotProperties[i];
    }
}
