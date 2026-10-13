#include <globaldefs.h>
#include <GameState/GameState.h>
#include "Combat/CombatantDisplay.h"
#include "System/Matrix.h"

int ClassifyFlag0x800RatioTier02027bd0(int);
void SetElementFields0202756c(void*, int, int, int, unsigned char, unsigned char, unsigned short, unsigned char, int, int);
#if defined(jpn)
#define data_020e7034 data_020e78d5
#endif
extern unsigned char data_020e7034[];

// USA: func_0201fdd0
extern "C" ARM void func_0201fdd0(Display0201fdd0* self, int row, int combatant, int amount, int maximum, int digitX, int digitY, int barX, int barY, int fillCode, int frameCode, unsigned int bank) {
    int number;
    int digit;
    void* elements;
    int bankOffset;
    int combatantOffset;
    int startX;
    int startY;
    unsigned short color;
    GameState* game = GameState::GetInstance();
    elements = func_ov017_0218b5b0()->unknown_ptr_36d0;
    if (!game->GetPartyMemberByIndex(combatant)) return;
    startX = digitX;
    startY = digitY;
    digit = 0;
    number = amount;
    color = data_020e7034[ClassifyFlag0x800RatioTier02027bd0(combatant)];
    do {
        bankOffset = bank * 12;
        combatantOffset = combatant * 3 + 20;
        int value = number % 10;
        number /= 10;
        int y = (int)(self->y + (float)startY);
        int element = digit + combatantOffset;
        element += bankOffset;
        SetElementFields0202756c(elements, (startX + ((row << 6) - (digit << 3))) << 12, y << 12, (value + 13) & 0xff, element & 0xff, 0, color, 255, 4096, 4096);
        ++digit;
    } while (number > 0);
    if (amount <= 0) return;
    fix32_t ratio = fix32_Divide(amount << 12, maximum << 12);
    fix32_t scale = fix32_Divide(0x31000, 0x20000);
    fix32_t fillScale = FIX32_MULTIPLY(ratio, scale);
    if (fillScale < 40) fillScale = 40;
    fix32_t frameX = (barX + (row << 6)) << 12;
    fix32_t frameY = (int)(4096.0f * (self->y + (float)barY));
    SetElementFields0202756c(elements, frameX, frameY, fillCode & 0xff, (combatant + 44 + bank * 8) & 0xff, 0, 6, (combatant + bank * 4) & 0xff, fillScale, 4096);
    SetElementFields0202756c(elements, frameX, frameY, frameCode & 0xff, (combatant + 48 + bank * 8) & 0xff, 0, 6, 255, 4096, 4096);
}
