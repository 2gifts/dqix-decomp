#include <globaldefs.h>

#if defined(jpn)
#define ClearFourEntries_02191b70 func_ov017_02192738
#endif

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

// USA: func_ov017_02191b70
#if defined(jpn)
extern "C"
#endif
ARM void ClearFourEntries_02191b70(void* resources) {
    PendingCombatantUpdatesView* updates = (PendingCombatantUpdatesView*)resources;
    PendingCombatantUpdate* entry = updates->entries;
    for (int index = 0; index < 4; ++index) {
        entry->pending = 0;
        entry->value = 0;
        ++entry;
    }
}
