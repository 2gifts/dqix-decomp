// External entry names follow the fork's symbols.txt at b399f53.
// Local argument views remain provisional; see contribution interface notes.
#include <globaldefs.h>
#include <GameState/GameState.h>

// The inventory accessor consumes the game state pointer.
extern "C" void* _Z17GetPtrField0x2a04P9GameState(GameState*);

// Filters a party-index list, then fills holes while preserving index order.
// Mode 1 keeps current party members; mode 2 removes one valid party index.
extern "C" ARM void func_ov000_0217ee7c(signed char* indices, signed char* count,
                                     int removedIndex, int mode)
{
    unsigned char* inventory = static_cast<unsigned char*>(_Z17GetPtrField0x2a04P9GameState(GameState::GetInstance()));
    signed char remaining = *count;
    switch (mode) {
    case 0:
        break;
    case 1:
        for (signed char slot = 0; slot < *count; ++slot) {
            signed char selected = indices[slot];
            int present = 0;
            for (signed char party = 0; party < inventory[0xf7c]; ++party) {
                if (selected == (inventory + party)[0xf78]) {
                    present = true;
                    break;
                }
            }
            if (!present) {
                --remaining;
                indices[slot] = -1;
            }
        }
        break;
    case 2:
        int valid = removedIndex >= 0 && removedIndex <= 3;
        if (valid) {
            for (signed char slot = 0; slot < remaining; ++slot) {
                if (removedIndex == indices[slot]) {
                    --remaining;
                    indices[slot] = -1;
                    break;
                }
            }
        }
        break;
    }
    for (signed char slot = 0; slot < *count - 1; ++slot) {
        if (indices[slot] < 0) {
            for (signed char next = slot + 1; next < *count; ++next) {
                if (indices[next] >= 0) {
                    indices[slot] = indices[next];
                    indices[next] = -1;
                    break;
                }
            }
        }
    }
    *count = remaining;
}
