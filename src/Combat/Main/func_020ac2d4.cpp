#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"
struct PackedBattleFlag020ac2d4 { unsigned short value; };
struct OutputBattleFlag020ac2d4 {
    unsigned short key;
    unsigned short bit0:1, bit1:1, rest:14;
};
struct BattleFlagView020ac2d4 { char pad[0x7800]; PackedBattleFlag020ac2d4 entries[0x1d7]; };
struct BattleStateView020ac2d4 { char unknown0[0x2c4]; BattleFlagView020ac2d4 battle; };
// USA: func_020ac2d4
extern "C" ARM int func_020ac2d4(void*, short* keys, OutputBattleFlag020ac2d4* output, int count) {
    BattleFlagView020ac2d4* view = &((BattleStateView020ac2d4*)GameState::GetInstance())->battle;
    for (int i = 0; i < count; i++) {
        int key = keys[i];
        if (key >= 0) {
            int found = 0;
            PackedBattleFlag020ac2d4* entry = view->entries;
            unsigned int index = 0;
            for (; index < 0x1d7; entry++, index++) {
                int current = (entry->value & 0xfffc) >> 2;
                if (current <= 0) { found = 1; break; }
                if (current == key) { found = 1; break; }
            }
            if (found) {
                OutputBattleFlag020ac2d4 value;
                value.key = key;
                value.bit0 = (entry->value & 2) >> 1;
                value.bit1 = entry->value & 1;
                memcpy(&output[i], &value, 4);
            }
        }
    }
    return 1;
}
