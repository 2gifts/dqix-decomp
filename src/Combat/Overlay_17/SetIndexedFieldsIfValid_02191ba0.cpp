#include <globaldefs.h>

struct PendingCombatantUpdate {
    unsigned char pending;
    unsigned char unknown1;
    unsigned short value;
};

struct PendingCombatantUpdatesView {
#if defined(jpn)
    unsigned char unknown0000[0x41ec];
#else
    unsigned char unknown0000[0x449c];
#endif
    PendingCombatantUpdate entries[4];
};

// USA: func_ov017_02191ba0
ARM void SetIndexedFieldsIfValid_02191ba0(char* resources, int index, unsigned short value) {
    int valid = index >= 0 && index <= 3;
    if (!valid) return;
    PendingCombatantUpdatesView* updates = (PendingCombatantUpdatesView*)resources;
    updates->entries[index].value = value;
    updates->entries[index].pending = 1;
}
