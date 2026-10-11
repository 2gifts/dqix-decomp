#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

#if defined(jpn)
enum { kRegionValue150_144 = 0x144 };
#else
enum { kRegionValue150_144 = 0x150 };
#endif

struct Flags0217839c {
    unsigned int word0;
    unsigned int pad4 : 27;
    unsigned int bit27 : 1;
    unsigned int bit28 : 1;
    unsigned int bit29 : 1;
    unsigned int pad30 : 2;
};

struct Slot0217839c {
    Flags0217839c* flags;
    unsigned char pad4[0x18 - 4];
    short value18;
};

struct Entry0217839c {
    unsigned char pad0[8];
    unsigned int kind : 4;
    unsigned int pad8 : 28;
};

struct Mode0217839c {
    unsigned char pad0[0x49c];
    unsigned char bit0 : 1;
    unsigned char pad49c : 7;
};

extern unsigned char data_ov003_0217fb60[];

// USA: func_ov003_0217839c
// JPN: func_ov003_0217727c
extern "C" ARM int func_ov003_0217839c(int id, void* entry) {
    if (((Entry0217839c*)entry)->kind != 7) return 0;
    GameObject* combatant = GetCombatantWithFlag0x100(GameState::GetInstance(), id);
    if (combatant == 0) return 0;

    unsigned char i;
    uintptr_t base = *(uintptr_t*)((char*)combatant + kRegionValue150_144);
    uintptr_t address = base + 0x2d4;
    if (address == 0) return 0;
    if (*(short*)(address + 0x18) != 0x4680) return 0;

    unsigned char selected[2];
    i = 0;
    while (i < 8) {
        unsigned char index = data_ov003_0217fb60[i];
        if (index == 0xff) break;
        uintptr_t slotAddress = base + 0x194 + ((unsigned int)index << 5);
        if (slotAddress != 0) {
            Slot0217839c* slot = (Slot0217839c*)slotAddress;
            if (slot->value18 >= 0) {
                Flags0217839c* flags = slot->flags;
                if (flags != 0 && !flags->bit29) {
                    selected[0] = flags->bit27 ? 1 : 0;
                    selected[1] = flags->bit28 ? 1 : 0;
                    if (selected[((Mode0217839c*)base)->bit0] == 0) return 1;
                }
            }
        }
        ++i;
    }
    return 0;
}
