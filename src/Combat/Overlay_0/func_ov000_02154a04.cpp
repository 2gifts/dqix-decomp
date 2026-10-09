#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Util/Random.h>
#include <std_library_functions.h>

struct TargetDefinition {
    char pad0[8];
    unsigned int field8 : 8;
    unsigned int side : 2;
    unsigned int field8a : 22;
    char pad1[8];
    unsigned int field14 : 28;
    unsigned int selection : 4;
    int field18;
    unsigned int field1c : 14;
    unsigned int repetitions : 5;
    unsigned int field1ca : 13;
};
struct CombatantGroup { char pad[0x17c]; unsigned char group; };
void* GetData02108e10();
extern "C" void* _Z24SearchBothTables02079e2cPci(char*, int);
extern "C" int func_ov000_0215e9fc(Random*, short*, int, int);
extern "C" short func_ov000_02154f30(Random*, short, int, short*);
extern "C" void _Z28PickRandomFromTable_02153d10P6RandomPs(Random*, short*);
extern "C" void func_ov000_02153d78(Random*, short, short*);
GameObject* GetCombatantWithFlag0x400(GameState*, int);
extern "C" int func_ov000_02153e78(Random*, short*, int, int, int);
extern "C" int func_ov000_0215eb1c(Random*, short*, int, int);
extern "C" signed char _Z37PickTableValueWithRandomFill_0215fbe0P6Randomi(Random*, int);
extern short data_ov000_02182af4[8];

// USA: func_ov000_02154a04
extern "C" ARM int func_ov000_02154a04(Random* random, int combatantId, int actionId, short* targets) {
    int count = 0;
    GameState::GetInstance();
    TargetDefinition* definition = (TargetDefinition*)_Z24SearchBothTables02079e2cPci((char*)GetData02108e10(), (short)actionId);
    if (!definition) return 0;
    unsigned int side = definition->side;
    unsigned int selection = definition->selection;
    if (selection == 1) {
        targets[count++] = combatantId;
    } else if (side == 1) {
        if (selection == 2 || selection == 5) {
            int available = func_ov000_0215e9fc(random, targets, 8, 1);
            targets[0] = func_ov000_02154f30(random, (short)combatantId, available, targets);
            count = 1;
        } else if (selection == 4) {
            count = func_ov000_0215e9fc(random, targets, 8, 1);
        } else if (selection == 3) {
            count = func_ov000_0215e9fc(random, targets, 8, 1);
        }
    } else if (side == 2) {
        if (selection == 2) {
            short chosen = 0;
            _Z28PickRandomFromTable_02153d10P6RandomPs(random, &chosen);
            targets[count++] = chosen;
        } else if (selection == 8) {
            short chosen = 0;
            func_ov000_02153d78(random, (short)combatantId, &chosen);
            targets[count++] = chosen;
        } else if (selection == 4) {
            GameObject* combatant = GetCombatantWithFlag0x400(GameState::GetInstance(), (short)combatantId);
            count = func_ov000_02153e78(random, targets, 8, ((CombatantGroup*)combatant)->group, 1);
        } else if (selection == 3) {
            count = func_ov000_0215eb1c(random, targets, 8, 1);
        }
    }
    short selected[8];
    unsigned short* source = (unsigned short*)data_ov000_02182af4;
    int copyCount = 8;
    unsigned short* destination = (unsigned short*)selected;
    do { *destination = *source++; destination++; } while (--copyCount);
    short* chosenTargets = selected;
    int repetitions = _Z37PickTableValueWithRandomFill_0215fbe0P6Randomi(random, (signed char)definition->repetitions);
    if (repetitions > 0) {
        for (int i = 0; i < repetitions; i++) chosenTargets[i] = targets[NextRandomMax(random, count)];
        memset(targets, 0, count * 2);
        memcpy(targets, selected, repetitions * 2);
        count = repetitions;
    }
    return count;
}
