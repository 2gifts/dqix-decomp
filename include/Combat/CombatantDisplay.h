#pragma once

struct Display0201fdd0 {
    unsigned char unknown0[16];
    float y;
};

extern "C" void func_0201fdd0(Display0201fdd0* display, int row, int combatant,
                             int amount, int maximum, int digitX, int digitY,
                             int barX, int barY, int fillCode, int frameCode,
                             unsigned int bank);
void SubmitFlag0x800CombatantDataA0201fca0(Display0201fdd0* display, int row, int combatant);
void SubmitFlag0x800CombatantDataB0201fd38(Display0201fdd0* display, int row, int combatant);

typedef char VerifyCombatantDisplaySize[sizeof(Display0201fdd0) == 20 ? 1 : -1];
