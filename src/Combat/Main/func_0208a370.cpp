#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"
struct SelectionContext0208a370 { Random* random; };
struct SelectionTable0208a370 { char pad[0x18]; unsigned short values[6]; };
struct Combatant0208a370 { char pad[0x148]; SelectionTable0208a370* table; };
GameObject* GetCombatantWithFlag0x400(GameState*, int);
extern "C" int func_0208a03c(SelectionContext0208a370*, unsigned char, int, int*, int);
extern "C" int func_ov000_02154a04(Random*, int, int, int);
extern unsigned char data_020e8caa[];
// USA: func_0208a370
extern "C" ARM int func_0208a370(SelectionContext0208a370* ctx, int category, int combatant, int* output, int arg) {
    unsigned char* weights;
    int index;
    SelectionTable0208a370* table;
    int previous;
    table = ((Combatant0208a370*)GetCombatantWithFlag0x400(GameState::GetInstance(), combatant))->table;
    weights = data_020e8caa + category * 6;
    int roll = NextRandomMax(ctx->random, 256) + 1;
    for (index = 0; index < 6; index++) {
        if (weights[index] >= roll) break;
        roll -= weights[index];
    }
    if (index >= 6) index = 5;
    if (func_0208a03c(ctx, (unsigned char)index, combatant, output, arg)) return table->values[index];
    for (previous = index; --previous >= 0; ) {
        if (func_0208a03c(ctx, (unsigned char)previous, combatant, output, arg)) return table->values[previous];
    }
    for (; ++index < 6; ) {
        if (func_0208a03c(ctx, (unsigned char)index, combatant, output, arg)) return table->values[index];
    }
    *output = 0;
    *output = func_ov000_02154a04(ctx->random, combatant, 2, arg);
    return 2;
}
