#include <globaldefs.h>
#include <GameState/GameState.h>

void* GetPtrField0x2a04_02010828(GameState*);

extern "C" ARM void func_ov000_0217ee7c(signed char* indices, signed char* count,
                                     int removedIndex, int mode)
{
    unsigned char* inventory = static_cast<unsigned char*>(GetPtrField0x2a04_02010828(GameState::GetInstance()));
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
