#include <globaldefs.h>
#include <GameState/GameState.h>

struct Display0201fdd0 { char pad[16]; float y; };
extern "C" int _Z34ClassifyFlag0x800RatioTier02027bd0i(int);
extern "C" void _Z24SetElementFields0202756cPviiihhthii(void*, int, int, int, unsigned char, unsigned char, unsigned short, unsigned char, int, int);
extern "C" int fix32_Divide(int, int);
extern unsigned char data_020e7034[] __attribute__((aligned(4)));

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
    color = data_020e7034[_Z34ClassifyFlag0x800RatioTier02027bd0i(combatant)];
    do {
        bankOffset = bank * 12;
        combatantOffset = combatant * 3 + 20;
        int value = number % 10;
        number /= 10;
        int y = (int)(self->y + (float)startY);
        int element = digit + combatantOffset;
        element += bankOffset;
        _Z24SetElementFields0202756cPviiihhthii(elements, (startX + ((row << 6) - (digit << 3))) << 12, y << 12, (value + 13) & 0xff, element & 0xff, 0, color, 255, 4096, 4096);
        ++digit;
    } while (number > 0);
    if (amount <= 0) return;
    int ratio = fix32_Divide(amount << 12, maximum << 12);
    int scale = fix32_Divide(0x31000, 0x20000);
    amount = (int)(((long long)ratio * scale + 0x800) >> 12);
    if (amount < 40) amount = 40;
    row = (barX + (row << 6)) << 12;
    int y = (int)(4096.0f * (self->y + (float)barY));
    _Z24SetElementFields0202756cPviiihhthii(elements, row, y, fillCode & 0xff, (combatant + 44 + bank * 8) & 0xff, 0, 6, (combatant + bank * 4) & 0xff, amount, 4096);
    _Z24SetElementFields0202756cPviiihhthii(elements, row, y, frameCode & 0xff, (combatant + 48 + bank * 8) & 0xff, 0, 6, 255, 4096, 4096);
}
